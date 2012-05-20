#include <vcl.h>
#pragma hdrstop

#include "EventKine.h"
#pragma package(smart_init)

EventKine::EventKine() {
        acceleration_coeficient = 0.2;
        decceleration_coeficient = 0.95;
        breaking_coeficient = -0.8;
        acceleration_max = 5;
        acceleration_min = -10;

        kine_position_velocity = 0;
        kine_position_acceleration = 0;
        kine_rotation_velocity = 0;
        kine_rotation_acceleration = 0;

        key_accelerate = 0;
        key_break = 0;
        key_left = 0;
        key_right = 0;

}

bool EventKine::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {
        _last_viewport = _viewport;

        if (type == "KeyDown") {
                if (key == 38) { // Flecha arriba
                        key_accelerate = 1;
                        return true;
                }

                if (key == 40) { // Flecha abajo
                        key_break = 1;
                        return true;
                }

                if (key == 37) { // Flecha izquierda
                        key_left = 1;
                        return true;
                }

                if (key == 39) { // Flecha derecha
                        key_right = 1;
                        return true;
                }

        }

        if (type == "KeyUp") {
                if (key == 38) { // Flecha arriba
                        key_accelerate = 0;
                        return true;
                }

                if (key == 40) { // Flecha abajo
                        key_break = 0;
                        return true;
                }

                if (key == 37) { // Flecha izquierda
                        key_left = 0;
                        return true;
                }

                if (key == 39) { // Flecha derecha
                        key_right = 0;
                        return true;
                }
        }

        return false;
}

void EventKine::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _last_viewport = _viewport;
        _scene->main_figure->elements->push_back(buildFloor());
        buildKine();
        _scene->main_figure->elements->push_back(_kine);


        cam_back = new Camera3D();
        cam_back->name = "Kine:back";
        cam_back->perspective = 0;
        _scene->cameras->push_back(cam_back);
        _viewport->setCamera(cam_back);

        cam_top = new Camera3D();
        cam_top->name = "Kine:top";
        cam_top->perspective = 0;
        _scene->cameras->push_back(cam_top);

        Sleep(200);

        while (Application->Active) {
                Sleep(1);
                Application->ProcessMessages();
                Step();
                _scene->Repaint();
        }
}


void EventKine::Step() {

        if (key_break) { // Freno;
                kine_position_acceleration += breaking_coeficient;
                if (kine_position_acceleration < acceleration_min)
                        kine_position_acceleration = acceleration_min;
        } else if (key_accelerate) { // Acelero:
                kine_position_acceleration += acceleration_coeficient;
                if (kine_position_acceleration > acceleration_max)
                        kine_position_acceleration = acceleration_max;
        } else { // Decelero:
                kine_position_acceleration *= decceleration_coeficient;
                kine_position_velocity *= decceleration_coeficient;
        }

        // Calculamos la inclinación del robot en función de la aceleración

        _kine_body->rotation->y = kine_position_acceleration*kine_position_velocity/10;


        if (key_right)
                _kine->rotation->z-= 10;

        if (key_left)
                _kine->rotation->z+= 10;



        double velocity_max = 33;
        double velocity_min = 0;

        kine_position_velocity += kine_position_acceleration;
        if (kine_position_velocity < velocity_min)
                kine_position_velocity = velocity_min;
        if (kine_position_velocity > velocity_max)
                kine_position_velocity = velocity_max;
        if (kine_position_velocity<0.001)
                kine_position_acceleration = 0;





        _kine->translation->x += kine_position_velocity*cos(_kine->rotation->z*(4*atan(1))/180);
        _kine->translation->y += kine_position_velocity*sin(_kine->rotation->z*(4*atan(1))/180);



        Camera3D *cam;
        ///////////////////////////////////////////////
        // ANIMACIÓN DE LA CÁMARA BACK ////////////////
        ///////////////////////////////////////////////

        cam = cam_back;

        // Calculamos la animación de la cámara:
        double distance = 40-270*(kine_position_velocity/velocity_max);
        cam->look->x = _kine->translation->x;
        cam->look->y = _kine->translation->y;
        cam->look->z = 50;

        // Posicion ideal de la camara:
        double pi_x = _kine->translation->x + distance*cos((_kine->rotation->z+180)*(4*atan(1))/180);
        double pi_y = _kine->translation->y + distance*sin((_kine->rotation->z+180)*(4*atan(1))/180);
        double pi_z = 60 - 30*(kine_position_velocity/velocity_max);

        // Posicion actual de la camara:
        double pa_x = cam->eye->x;
        double pa_y = cam->eye->y;
        double pa_z = cam->eye->z;

        // Posición real de la cámara
        cam->eye->x += (pi_x-pa_x)*0.1;
        cam->eye->y += (pi_y-pa_y)*0.1;
        cam->eye->z += (pi_z-pa_z)*0.1;

        cam->recalculateCameraAxis();
        cam->setModelViewMatrix();


        ///////////////////////////////////////////////
        // ANIMACIÓN DE LA CÁMARA TOP /////////////////
        ///////////////////////////////////////////////

        
        cam = cam_top;

        cam->look->x = _kine->translation->x;
        cam->look->y = _kine->translation->y;
        cam->look->z = 50;

        cam->eye->x = _kine->translation->x-1;
        cam->eye->y = _kine->translation->y;
        cam->eye->z = 500+1600*(kine_position_velocity/velocity_max);

        cam->recalculateCameraAxis();
        cam->setModelViewMatrix();

}


Group3D * EventKine::buildFloor() {
        Group3D *floor = new Group3D();

        Flat3D* cell;

        Color3D *color1 = new Color3D(1,1,1);
        //Color3D *color2 = new Color3D(1,0,0);

        double side = 200;
        int l = 20;

        for (int i = -l; i<l; i++) {
                for (int j = -l; j<l; j++) {
                        if ( (i+j)%2 == 0) {
                                cell = new Flat3D();
                                cell->x = side;
                                cell->y = side;
                                cell->RecalculateMesh();
                                cell->translation->x = i*side;
                                cell->translation->y = j*side;
                                cell->translation->z = -0.1;
                                cell->color = new Color3D();

                                cell->color->r = 0;
                                if (i*j>0) {
                                        cell->color->r = (double) abs(i)/(double)l;;
                                }
                                cell->color->g = 1-(double) abs(i)/(double)l;
                                cell->color->b = 1-(double) abs(j)/(double)l;

                                cell->color->g *= (1-(double) abs(i)/(double)l) * (1-(double) abs(j)/(double)l);
                                cell->color->b *= (1-(double) abs(i)/(double)l) * (1-(double) abs(j)/(double)l);


                                floor->elements->push_back(cell);
                        }
                }
        }

        cell = new Flat3D();
        cell->x = 2*side*l;
        cell->y = 2*side*l;
        cell->RecalculateMesh();
        cell->translation->x = -l*side;
        cell->translation->y = -l*side;
        cell->translation->z = -0.2;
        cell->color = color1;
        floor->elements->push_back(cell);





        return floor;
}



void EventKine::buildKine() {
        _kine = new Group3D();
        _kine->human_name = "Kine";


        _kine_body = new Group3D();

        Cylinder3D *body = new Cylinder3D();
        body->color = new Color3D(1,1,0);
        body->height = 40;
        body->rad_top = 20;
        body->rad_bottom = 20;
        body->RecalculateMesh();
        _kine_body->elements->push_back(body);

        Sphere3D *head = new Sphere3D();
        head->color = new Color3D(1,1,0);
        head->radius = 20;
        head->RecalculateMesh();
        head->translation->z = 40;
        _kine_body->elements->push_back(head);


        _kine->elements->push_back(_kine_body);


        Cylinder3D *wheel1 = new Cylinder3D();
        wheel1->color = new Color3D(0.4,0.4,0.4);
        wheel1->rad_top = 15;
        wheel1->rad_bottom = 15;
        wheel1->height = 5;
        wheel1->RecalculateMesh();
        wheel1->translation->z = 0;
        wheel1->translation->y = -20;
        wheel1->rotation->x = 90;
        _kine->elements->push_back(wheel1);

        Cylinder3D *wheel2 = new Cylinder3D();
        wheel2->color = new Color3D(0.4,0.4,0.4);
        wheel2->rad_top = 15;
        wheel2->rad_bottom = 15;
        wheel2->height = 5;
        wheel2->RecalculateMesh();
        wheel2->translation->z = 0;
        wheel2->translation->y = 20;
        wheel2->rotation->x = -90;
        _kine->elements->push_back(wheel2);

        _kine->translation->z = 15;
        _kine->rotation->z = 90;


        _kine->scale->x = 0.4;
        _kine->scale->y = 0.4;
        _kine->scale->z = 0.4;


}

String EventKine::getName() {
        return "kine";
}
