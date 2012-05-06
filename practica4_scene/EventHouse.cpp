#include <vcl.h>
#pragma hdrstop

#include "EventHouse.h"
#pragma package(smart_init)


void EventHouse::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _house = new Group3D();

        _house->rotation->z = 180;

        // Introduzco las 6 columnas

        Color3D *color_columnas = new Color3D(0,1,1);
        Box3D *col;

        col = new Box3D(); // Columna 1
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 2
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 3
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 4
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 5
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 6
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);


        // Introduzco las paredes lisas

        Color3D *color_paredes = new Color3D(0,0,0.8);
        Box3D *wall;

        wall = new Box3D(); // Pared 1
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 3
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 0;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 4
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        // Introduzco las paredes especiales
        wall = new Box3D(); // Pared 5
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 6
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 880;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);




        _scene->main_figure->elements->push_back(_house);
        _scene->Repaint();
}

String EventHouse::getName() {
        return "house";
}
