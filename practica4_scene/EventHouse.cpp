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
        //_house->elements->push_back(wall);

        // Introduzco las paredes especiales
        wall = new Box3D(); // Pared 5
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        //_house->elements->push_back(wall);

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

        /*
        Box3D *caja_verde = new Box3D();
        caja_verde->x = 100;
        caja_verde->y = 100;
        caja_verde->z = 100;
        caja_verde->RecalculateMesh();
        caja_verde->color = new Color3D(0,1,0);

        caja_verde->translation->x = 600;
        caja_verde->translation->y = 190;

        _house->elements->push_back(caja_verde);
        */

        // Suelo ///////////////////////////////////////////////////////////////
        Box3D *suelo = new Box3D();
        suelo->color = new Color3D(0.7,0.7,0.2);
        suelo->x = 450;
        suelo->y = 460;
        suelo->z = 1;
        suelo->RecalculateMesh();
        suelo->translation->x = 440;
        suelo->translation->z = -1;
        _house->elements->push_back(suelo);


        // Estanteria //////////////////////////////////////////////////////////
        Group3D *estanteria = new Group3D();
        estanteria->human_name = "Estantería";
        estanteria->translation->x = 480;
        estanteria->translation->y = 420;
        _house->elements->push_back(estanteria);

        Color3D *color_tabla = new Color3D(0.98,0.98,0.98);


        Box3D *tabla;

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 80;
        tabla->y = 40;
        tabla->z = 5;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 0;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 80;
        tabla->y = 40;
        tabla->z = 5;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 145;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 5;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 0;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 5;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 75;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);






        // Cama ////////////////////////////////////////////////////////////////
        Group3D *cama = new Group3D();
        cama->human_name = "Cama";
        cama->translation->x = 600;
        cama->translation->y = 270;
        _house->elements->push_back(cama);


        Group3D *somier = new Group3D();
        somier->color = new Color3D(0.2,0.2,0.2);
        somier->human_name = "Somier";
        cama->elements->push_back(somier);

        // Patas del somier:
        Box3D *pata;

        // Pata 1
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 2
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 3
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Pata 4
        pata = new Box3D();
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Esqueleto del somier:
        pata = new Box3D();
        pata->x = 90;
        pata->y = 180;
        pata->z = 5;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 0;
        pata->translation->z = 25;
        somier->elements->push_back(pata);


        Box3D *colchon = new Box3D();
        colchon->x = 86;
        colchon->y = 176;
        colchon->z = 20;
        colchon->RecalculateMesh();
        colchon->color = new Color3D(0.91,0.9,0.8);
        colchon->translation->x = 2;
        colchon->translation->y = 2;
        colchon->translation->z = 30;
        cama->elements->push_back(colchon);


        Box3D *almohada = new Box3D();
        almohada->x = 86;
        almohada->y = 25;
        almohada->z = 15;
        almohada->RecalculateMesh();
        almohada->color = new Color3D(0.8,0.8,0.9);
        almohada->translation->x = 2;
        almohada->translation->y = 153;
        almohada->translation->z = 51;
        cama->elements->push_back(almohada);


        Box3D *cabecero = new Box3D();
        cabecero->x = 110;
        cabecero->y = 5;
        cabecero->z = 110;
        cabecero->RecalculateMesh();
        cabecero->color = color_tabla;
        cabecero->translation->x = -10;
        cabecero->translation->y = 180;
        cama->elements->push_back(cabecero);

        Box3D *piecero = new Box3D();
        piecero->x = 90;
        piecero->y = 5;
        piecero->z = 60;
        piecero->RecalculateMesh();
        piecero->color = color_tabla;
        piecero->translation->y = -5;
        cama->elements->push_back(piecero);








        //                                                                    //
        //                FIN HABITACIÓN DE LA DERECHA FIN                    //
        ////////////////////////////////////////////////////////////////////////


        _scene->main_figure->elements->push_back(_house);
        _scene->Repaint();
}

String EventHouse::getName() {
        return "house";
}
