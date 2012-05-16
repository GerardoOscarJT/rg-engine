#include <vcl.h>
#pragma hdrstop

#include "EventKine.h"
#pragma package(smart_init)

EventKine::EventKine() {
        acceleration_coeficient = 0.4;
        decceleration_coeficient = 0.9;
        breaking_coeficient = -2.8;
        acceleration_max = 5;
        acceleration_min = -10;

        kine_position_velocity = 10;
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
                if (key == 38) // Flecha arriba
                        key_accelerate = 1;

                if (key == 40) // Flecha abajo
                        key_break = 1;

                if (key == 37) // Flecha izquierda
                        key_left = 1;

                if (key == 39) // Flecha derecha
                        key_right = 1;

        }

        if (type == "KeyUp") {
                if (key == 38) // Flecha arriba
                        key_accelerate = 0;

                if (key == 40) // Flecha abajo
                        key_break = 0;

                if (key == 37) // Flecha izquierda
                        key_left = 0;

                if (key == 39) // Flecha derecha
                        key_right = 0;
        }

        return false;
}

void EventKine::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _last_viewport = _viewport;
        _scene->main_figure->elements->push_back(buildFloor());
        buildKine();
        _scene->main_figure->elements->push_back(_kine);        

        // Bucle de animación

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
                _kine->rotation->z-= 15;

        if (key_left)
                _kine->rotation->z+= 15;



        double velocity_max = 100;
        double velocity_min = 0;

        kine_position_velocity += kine_position_acceleration;
        if (kine_position_velocity < velocity_min)
                kine_position_velocity = velocity_min;
        if (kine_position_velocity > velocity_max)
                kine_position_velocity = velocity_max;



        _kine->translation->x += kine_position_velocity*cos(_kine->rotation->z*(4*atan(1))/180);
        _kine->translation->y += kine_position_velocity*sin(_kine->rotation->z*(4*atan(1))/180);







        _last_viewport->camera->look->x = _kine->translation->x;
        _last_viewport->camera->look->y = _kine->translation->y;
        _last_viewport->camera->recalculateCameraAxis();
        _last_viewport->camera->setModelViewMatrix();

}


Group3D * EventKine::buildFloor() {
        Group3D *floor = new Group3D();

        Box3D* cell;

        Color3D *color1 = new Color3D(1,1,1);
        Color3D *color2 = new Color3D(1,0,0);

        double side = 200;

        for (int i = -4; i<4; i++) {
                for (int j = -4; j<4; j++) {
                                cell = new Box3D();
                                cell->x = side-1;
                                cell->y = side-1;
                                cell->z = 1;
                                cell->RecalculateMesh();
                                cell->translation->x = i*side;
                                cell->translation->y = j*side;
                                cell->translation->z = -1;

                        if ( (i+j)%2 == 0) {
                                cell->color = color1;
                        } else {
                                cell->color = color2;
                        }

                        floor->elements->push_back(cell);

                }
        }





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




}

String EventKine::getName() {
        return "kine";
}
