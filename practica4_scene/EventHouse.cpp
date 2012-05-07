#include <vcl.h>
#pragma hdrstop

#include "EventHouse.h"
#pragma package(smart_init)


void EventHouse::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _house = new Group3D();

        //_house->rotation->z = 180;

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
        wall->translation->x = 460;
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

        wall = new Box3D(); // Pared 7
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);


        ////////////////////////////////////////////////////////////////////////
        //                    HABITACIÓN DE LA IZQUIERDA                      //
        //                                                                    //

        // AQUÍ DENTRO METE EL CÓDIGO DE LA HABITACIÓN DE LA IZQUIERDA
        // ESTO LO HACE RUBÉN.
        // LA HABITACIÓN DE LA IZQUIERDA ESTÁ SEÑALADA CON UNA CAJA ROJA EN MEDIO

        Box3D *caja_roja = new Box3D();
        caja_roja->x = 100;
        caja_roja->y = 100;
        caja_roja->z = 100;
        caja_roja->RecalculateMesh();
        caja_roja->color = new Color3D(1,0,0);

        caja_roja->translation->x = 190;
        caja_roja->translation->y = 190;

        _house->elements->push_back(caja_roja);



        //                                                                    //
        //                FIN HABITACIÓN DE LA IZQUIERDA FIN                  //
        ////////////////////////////////////////////////////////////////////////




        ////////////////////////////////////////////////////////////////////////
        //                    HABITACIÓN DE LA DERECHA                        //
        //                                                                    //

        // AQUÍ DENTRO METER EL CÓDIGO DE LA HABITACIÓN DE LA IZQUIERDA
        // ESTO LO HACE GERARDO.
        // LA HABITACIÓN DE LA DERECHA ESTÁ SEÑALADA CON UNA CAJA VERDE EN MEDIO

        Box3D *caja_verde = new Box3D();
        caja_verde->x = 100;
        caja_verde->y = 100;
        caja_verde->z = 100;
        caja_verde->RecalculateMesh();
        caja_verde->color = new Color3D(0,1,0);

        caja_verde->translation->x = 600;
        caja_verde->translation->y = 190;

        _house->elements->push_back(caja_verde);



        //                                                                    //
        //                FIN HABITACIÓN DE LA DERECHA FIN                    //
        ////////////////////////////////////////////////////////////////////////


        _scene->main_figure->elements->push_back(_house);
        _scene->Repaint();
}

String EventHouse::getName() {
        return "house";
}
