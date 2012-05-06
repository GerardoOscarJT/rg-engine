#include <vcl.h>
#pragma hdrstop
#include "EpiCar3D.h"
#pragma package(smart_init)


EpiCar3D::EpiCar3D() {

        human_name = "EpiCar";

        // Rueda completa //////////////////////////////////////////////////////
        _wheel = new Group3D(); // Rueda completa (goma + tapacubos)
                _wheel->human_name = "Rueda";
                Cylinder3D * goma = new Cylinder3D(1, 3, 3, true, true);
                        goma->human_name = "Goma";
                        goma->color = new Color3D(.2, .2, .2);
                        goma->RecalculateMesh();
                _wheel->elements->push_back(goma);

                Cylinder3D * tapacubos = new Cylinder3D(0.2, 2, 2, true, true);
                        tapacubos->human_name = "Tapacubos";
                        tapacubos->color = new Color3D(1, .8, .8);
                        tapacubos->RecalculateMesh();
                        tapacubos->translation->z = 1;
                _wheel->elements->push_back(tapacubos);

                Cylinder3D * valvula = new Cylinder3D(0.1, .2, .2, true, true);
                        valvula->human_name = "Válvula";
                        valvula->color = new Color3D(0, .9, 0);
                        valvula->RecalculateMesh();
                        valvula->translation->z = 1;
                        valvula->translation->x = 2.5;
                _wheel->elements->push_back(valvula);

        // Monto las 4 ruedas //////////////////////////////////////////////////

        // Grupo rueda delantera (izq)
        _wheel1 = new Group3D();
        _wheel1->human_name = "Rueda delantera izquierda";
        _wheel1->elements->push_back(_wheel);
                _wheel1->translation->x = -5.1;
                _wheel1->translation->y = 9;
                _wheel1->translation->z = 2;
                _wheel1->rotation->y = -90;

        // Grupo rueda delantera (der)
        _wheel2 = new Group3D();
        _wheel2->human_name = "Rueda delantera derecha";
        _wheel2->elements->push_back(_wheel);
                _wheel2->translation->x = 5.1;
                _wheel2->translation->y = 9;
                _wheel2->translation->z = 2;
                _wheel2->rotation->y = 90;

        // Grupo rueda trasera (izq)
        _wheel3 = new Group3D();
        _wheel3->human_name = "Rueda trasera izquierda";
        _wheel3->elements->push_back(_wheel);
                _wheel3->translation->x = -5.1;
                _wheel3->translation->y = -8;
                _wheel3->translation->z = 2;
                _wheel3->rotation->y = -90;

        // Grupo rueda trasera (der)
        _wheel4 = new Group3D();
        _wheel4->human_name = "Rueda trasera derecha";
        _wheel4->elements->push_back(_wheel);
                _wheel4->translation->x = 5.1;
                _wheel4->translation->y = -8;
                _wheel4->translation->z = 2;
                _wheel4->rotation->y = 90;

        // Monto el chasis /////////////////////////////////////////////////////
        _chassis = new Group3D;
        _chassis->human_name = "Bastidor";
        _chassis->color = new Color3D(1,0.2,0.2);
                Box3D* box1 = new Box3D(); // Chasis
                        box1->human_name = "Chasis";
                        box1->x = 10;
                        box1->y = 28;
                        box1->z = 5;
                        box1->translation->y = -14;
                        box1->translation->x = -5;
                        box1->translation->z = 1; 
                        box1->RecalculateMesh();
                _chassis->elements->push_back(box1);
                Box3D* box2 = new Box3D(); // Ventanas
                        box2->human_name = "Ventanas";
                        box2->x = 8;
                        box2->y = 12;
                        box2->z = 3;
                        box2->translation->y = -8;
                        box2->translation->x = -4;
                        box2->translation->z = 6;
                        box2->RecalculateMesh();
                _chassis->elements->push_back(box2);

        // Monto el coche completo
        car = new Group3D();
        car->human_name = "Coche";
        Group3D *car_rotation = new Group3D();
                car_rotation->human_name = "Coche rotado";
                car_rotation->rotation->y = -90;
                car_rotation->rotation->y = 0;
                car_rotation->elements->push_back(_chassis);
                car_rotation->elements->push_back(_wheel1);
                car_rotation->elements->push_back(_wheel2);
                car_rotation->elements->push_back(_wheel3);
                car_rotation->elements->push_back(_wheel4);
        car->elements->push_back(car_rotation);


        elements->push_back(car);


        // Monto la epitrocoide
        epi = new Epitrochoid3D();
        epi->human_name = "Epitrocoide";
        epi->nQ = 100; //Este 100 que valga lo que sea
        epi->nP = 64;
        epi->RecalculateMesh();
        epi->color = new Color3D(.1, 1, 1);
        elements->push_back(epi);

        setTime(0);
}


EpiCar3D::~EpiCar3D() {

}

void EpiCar3D::setTime(double time) {
        _time = time;

        // TODO: recalcular posiciones...
        PV3D p = epi->_frenet_frame.C(time);
        car->translation->x = p.x;
        car->translation->y = p.y;
        car->translation->z = p.z;


        PV3D p2 = epi->_frenet_frame.C2(time);
        double rz = atan2l(p2.y+0.0001, p2.x+0.0001)*180/(4*atan(1));
        car->rotation->z = rz;

        // Posiciones de las ruedas:
        double revolutions = 5000;
        _wheel1->rotation->x = time*revolutions;
        _wheel2->rotation->x = time*revolutions + 180;
        _wheel3->rotation->x = time*revolutions;
        _wheel4->rotation->x = time*revolutions + 180;

}

double EpiCar3D::getTime() {
        return _time;
}
