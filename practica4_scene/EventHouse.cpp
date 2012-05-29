#include <vcl.h>
#pragma hdrstop

#include "EventHouse.h"
#pragma package(smart_init)

EventHouse::EventHouse() {
    _encendida = false;
    _cerrada = true;
    _hab_der = false;
    _pers1_cerr = true;
    _pers2_cerr = true;
}

void EventHouse::top(ViewPort3D *_viewport, Scene3D *_scene) {
        BMPRGBA *im = new BMPRGBA();
        GLuint text;
        if(im->cargaBMP("mad2.bmp")){
                glGenTextures(1, &text);
                glBindTexture(GL_TEXTURE_2D, text);

                int cols = im->getCols();
                int fils = im->getRows();

                /*gluBuild2DMipmaps (
                        GL_TEXTURE_2D, GL_RGBA, cols, fils, GL_RGBA,
                        GL_UNSIGNED_BYTE, im
                        );*/

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                                GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                                GL_LINEAR);

                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                //GLfloat micolor[] = {1.0,1.0,0.0,1.0};
                //glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, micolor);

                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, cols, fils,
                                0, GL_RGB, GL_UNSIGNED_BYTE, im->getBMP());
        }
        else return;

        BMPRGBA *im2 = new BMPRGBA();

        if(im2->cargaBMP("bulkypix.bmp")){
                glGenTextures(1, &text2);
                glBindTexture(GL_TEXTURE_2D, text2);

                int cols = im2->getCols();
                int fils = im2->getRows();

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, cols, fils,
                                0, GL_RGB, GL_UNSIGNED_BYTE, im2->getBMP());

                /*gluBuild2DMipmaps (
                        GL_TEXTURE_2D, GL_RGBA, cols, fils, GL_RGBA,
                        GL_UNSIGNED_BYTE, im
                        );*/

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                                GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                                GL_LINEAR);

                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                //GLfloat micolor[] = {1.0,1.0,0.0,1.0};
                //glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, micolor);

                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        }
        else return;

        BMPRGBA *im3 = new BMPRGBA();
        GLuint text3;
        if(im3->cargaBMP("suelo.bmp")){
                glGenTextures(1, &text3);
                glBindTexture(GL_TEXTURE_2D, text3);

                int cols = im3->getCols();
                int fils = im3->getRows();

                /*gluBuild2DMipmaps (
                        GL_TEXTURE_2D, GL_RGB, cols, fils, GL_RGB,
                        GL_UNSIGNED_BYTE, im3
                        ); */

                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                                GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                                GL_LINEAR);

                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                //GLfloat micolor[] = {0.545,0.27,0.0,0.074};
                //glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, micolor);

                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, cols, fils,
                                0, GL_RGB, GL_UNSIGNED_BYTE, im3->getBMP());
        }
        else return;

        _house = new Group3D();

        luz_direccional = new Light3D();
        luz_direccional->translation->x = -1;
        luz_direccional->translation->y = -1;
        luz_direccional->translation->z = -1;
        luz_direccional->translation->t = 0;
        luz_direccional->cut_off = 180;
        _house->elements->push_back(luz_direccional);




        Group3D *lampara = new Group3D();
        lampara->human_name = "Lampara";
        lampara->translation->x = 200;
        lampara->translation->y = 200;
        lampara->translation->z = 250;
        _house->elements->push_back(lampara);

        pantalla = new Cylinder3D(30, 10, 40, true, false);
        pantalla->human_name = "Pantalla";
        pantalla->color = new Color3D(0,0.5,0);
        pantalla->RecalculateMesh();
        lampara->elements->push_back(pantalla);

        bombilla = new Light3D();
        bombilla->human_name = "Bombilla";
        bombilla->cut_off = 60;
        lampara->elements->push_back(bombilla);

        

        //_house->rotation->z = 180;

        // Introduzco las 6 columnas

        Color3D *color_columnas = new Color3D(0,1,1);
        Box3D *col;

        col = new Box3D(); // Columna 1
        col->human_name = "Columna 1";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 2
        col->human_name = "Columna 2";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 3
        col->human_name = "Columna 3";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 0;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 4
        col->human_name = "Columna 4";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 0;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 5
        col->human_name = "Columna 5";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 430;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);

        col = new Box3D(); // Columna 6
        col->human_name = "Columna 6";
        col->color = color_columnas;
        col->x = 30;    col->y = 30;    col->z = 250;
        col->translation->x = 860;        col->translation->y = 430;
        col->RecalculateMesh();        _house->elements->push_back(col);


        // Introduzco las paredes lisas

        Color3D *color_paredes = new Color3D(0,0,0.8);
        Box3D *wall;

        /*wall = new Box3D(); // Pared 1
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 1  parte derecha
        wall->human_name = "Pared 1 derecha";
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte izquierda
        wall->human_name = "Pared 1 izquierda";
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 260;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte inferior
        wall->human_name = "Pared 1 inferior";
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 200;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 1 parte superior
        wall->human_name = "Pared 1 superior";
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 200;
        wall->translation->z = 155;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        /*wall = new Box3D(); // Pared 2
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 2  parte derecha
        wall->color = color_paredes;
        wall->human_name = "Pared 2 derecha";
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2 parte izquierda
        wall->human_name = "Pared 2 izquierda";
        wall->color = color_paredes;
        wall->x = 170;  wall->y = 10; wall->z = 250;
        wall->translation->x = 690;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2  parte inferior
        wall->human_name = "Pared 2 inferior";
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 630;
        wall->translation->y = 0;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 2 superior
        wall->human_name = "Pared 2 superior";
        wall->color = color_paredes;
        wall->x = 60;  wall->y = 10; wall->z = 95;
        wall->translation->x = 630;
        wall->translation->z = 155;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 3
        wall->human_name = "Pared 3";
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 0;
        wall->translation->y = 30;
        wall->y_div = 16;
        wall->z_div = 16;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 4
        wall->human_name = "Pared 4";
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 30;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        //_house->elements->push_back(wall);

        //Introduzco las paredes especiales
        wall = new Box3D(); // Pared 5
        wall->color = color_paredes;
        wall->x = 400;  wall->y = 10; wall->z = 250;
        wall->translation->x = 460;
        wall->translation->y = 450;
        wall->RecalculateMesh();
        wall->human_name = "Pared 5";
        //_house->elements->push_back(wall);

        wall = new Box3D(); // Pared 6
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 880;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        wall->human_name = "Pared 6";
        _house->elements->push_back(wall);

        /*wall = new Box3D(); // Pared 7
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 400; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);*/

        wall = new Box3D(); // Pared 7   parte izquierda
        wall->human_name = "Pared 7 izquierda";
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 160; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 30;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 7   parte derecha
        wall->human_name = "Pared 7 derecha";
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 160; wall->z = 250;
        wall->translation->x = 440;
        wall->translation->y = 270;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);

        wall = new Box3D(); // Pared 7   parte superior
        wall->human_name = "Pared 7 superior";
        wall->color = color_paredes;
        wall->x = 10;  wall->y = 80; wall->z = 70;
        wall->translation->x = 440;
        wall->translation->y = 190;
        wall->translation->z = 180;
        wall->RecalculateMesh();
        _house->elements->push_back(wall);


        ////////////////////////////////////////////////////////////////////////
        //                    HABITACIÓN DE LA IZQUIERDA                      //
        //                                                                    //

        // AQUÍ DENTRO METE EL CÓDIGO DE LA HABITACIÓN DE LA IZQUIERDA
        // ESTO LO HACE RUBÉN.
        // LA HABITACIÓN DE LA IZQUIERDA ESTÁ SEÑALADA CON UNA CAJA ROJA EN MEDIO

        /*Box3D *caja_roja = new Box3D();
        caja_roja->x = 100;
        caja_roja->y = 100;
        caja_roja->z = 100;
        caja_roja->RecalculateMesh();
        caja_roja->color = new Color3D(1,0,0);

        caja_roja->translation->x = 190;
        caja_roja->translation->y = 190;

        _house->elements->push_back(caja_roja);*/




        Group3D *persiana_izq = new Group3D();
                persiana_izq->human_name = "persianaIzq";
                Cylinder3D *braz_der = new Cylinder3D(70,3,3,true,true);
                braz_der->color = new Color3D(1,1,1);
                braz_der->translation->y = -5;
                braz_der->RecalculateMesh();
                persiana_izq->elements->push_back(braz_der);
                Cylinder3D *braz_izq = new Cylinder3D(70,3,3,true,true);
                braz_izq->translation->x = 60;
                braz_izq->translation->y = -5;
                braz_izq->color = new Color3D(1,1,1);
                braz_izq->RecalculateMesh();
                persiana_izq->elements->push_back(braz_izq);
                pala1_izq = new Box3D();
                pala1_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala1_izq->x = 56;
                pala1_izq->y = 15;
                pala1_izq->z = 2;
                pala1_izq->translation->x = 3;
                pala1_izq->translation->y = -5;
                pala1_izq->translation->z = 55;
                pala1_izq->rotation->x = 90;
                pala1_izq->RecalculateMesh();
                persiana_izq->elements->push_back(pala1_izq);
                pala2_izq = new Box3D();
                pala2_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala2_izq->x = 56;
                pala2_izq->y = 15;
                pala2_izq->z = 2;
                pala2_izq->translation->x = 3;
                pala2_izq->translation->y = -5;
                pala2_izq->translation->z = 40;
                pala2_izq->rotation->x = 90;
                pala2_izq->RecalculateMesh();
                persiana_izq->elements->push_back(pala2_izq);
                pala3_izq = new Box3D();
                pala3_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala3_izq->x = 56;
                pala3_izq->y = 15;
                pala3_izq->z = 2;
                pala3_izq->translation->x = 3;
                pala3_izq->translation->y = -5;
                pala3_izq->translation->z = 25;
                pala3_izq->rotation->x = 90;
                pala3_izq->RecalculateMesh();
                persiana_izq->elements->push_back(pala3_izq);
                pala4_izq = new Box3D();
                pala4_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala4_izq->x = 56;
                pala4_izq->y = 15;
                pala4_izq->z = 2;
                pala4_izq->translation->x = 3;
                pala4_izq->translation->y = -5;
                pala4_izq->translation->z = 10;
                pala4_izq->rotation->x = 90;
                pala4_izq->RecalculateMesh();
                persiana_izq->elements->push_back(pala4_izq);
                persiana_izq->translation->x = 200;
                persiana_izq->translation->z = 90;
                _house->elements->push_back(persiana_izq);


        Box3D *sueloIzq = new Box3D();
        sueloIzq->human_name = "Suelo Izquierdo";
        sueloIzq->color = new Color3D(0,1,0);
        sueloIzq->x = 445;
        sueloIzq->y = 460;
        sueloIzq->z = 1;
        sueloIzq->translation->z = -1;
        sueloIzq->textura = text3;        
        sueloIzq->RecalculateMesh();
        _house->elements->push_back(sueloIzq);

        LeftRoomFurn *roomFurn = new LeftRoomFurn();
        roomFurn->human_name = "Muebles Habitación Izquierda";
        roomFurn->translation->x = 150;
        roomFurn->translation->y = 150;
        _house->elements->push_back(roomFurn);

        /*Box3D *tele = new Box3D();
        tele->color = new Color3D(0,0,0);
        tele->x = 120;
        tele->y = 12;
        tele->z = 60;
        tele->translation->x = 250;
        tele->translation->y = 11;
        tele->translation->z = 100;
        tele->RecalculateMesh();*/
        Group3D *tele = new Group3D();
                tele->human_name = "Tele";
                Box3D *carcasa = new Box3D();
                carcasa->human_name = "Carcasa";
                carcasa->color = new Color3D(0,0.01,0);
                carcasa->x = 120;
                carcasa->y = 12;
                carcasa->z = 60;
                carcasa->RecalculateMesh();
        tele->elements->push_back(carcasa);
                _pantalla = new Box3D();
                _pantalla->human_name = "Pantalla";
                _pantalla->color = new Color3D(0,0.01,0);
                _pantalla->x = 100;
                _pantalla->y = 0;
                _pantalla->z = 40;
                _pantalla->x_div = 1;
                _pantalla->y_div = 1;
                _pantalla->z_div = 1;
                _pantalla->translation->x = 10;
                _pantalla->translation->y = 12.1;
                _pantalla->translation->z = 10;
                _pantalla->RecalculateMesh();

        tele->translation->x = 50;
        tele->translation->y = 1;
        tele->translation->z = 100;
        tele->elements->push_back(_pantalla);

        _house->elements->push_back(tele);




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
        suelo->human_name = "Suelo derecho";
        suelo->color = new Color3D(0.7,0.7,0.2);
        suelo->x = 450;
        suelo->y = 460;
        suelo->z = 1;
        suelo->textura = text3;        
        suelo->RecalculateMesh();
        suelo->translation->x = 440;
        suelo->translation->z = -1;
        _house->elements->push_back(suelo);


        // Estanteria //////////////////////////////////////////////////////////
        Group3D *estanteria = new Group3D();
        estanteria->human_name = "Estantería";
        estanteria->translation->x = 560;
        estanteria->translation->y = 50;
        estanteria->rotation->z = 180;
        _house->elements->push_back(estanteria);

        Color3D *color_tabla = new Color3D(0.98,0.98,0.98);


        Box3D *tabla;

        tabla = new Box3D();
        tabla->human_name = "Balda 1";
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
        tabla->human_name = "Balda 2";
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
        tabla->human_name = "Balda 3";
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
        tabla->human_name = "Balda 4";
        tabla->color = color_tabla;
        tabla->x = 5;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 75;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 2;
        tabla->y = 40;
        tabla->z = 140;
        tabla->RecalculateMesh();
        tabla->translation->x = 39;
        tabla->translation->y = 0;
        tabla->translation->z = 5;
        estanteria->elements->push_back(tabla);


        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 38.5;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 74;
        estanteria->elements->push_back(tabla);

        tabla = new Box3D();
        tabla->color = color_tabla;
        tabla->x = 70;
        tabla->y = 40;
        tabla->z = 2;
        tabla->RecalculateMesh();
        tabla->translation->x = 5;
        tabla->translation->y = 0;
        tabla->translation->z = 109.5;
        estanteria->elements->push_back(tabla);



        // Libros sobre la estantería

        Box3D *libro;

        libro = new Box3D();
        libro->color = new Color3D(1,0,0);
        libro->human_name = "Linux Kernel Architecture Book";
        libro->x = 24;
        libro->y = 19;
        libro->z = 6;
        libro->RecalculateMesh();
        libro->translation->x = 8;
        libro->translation->y = 0;
        libro->translation->z = 150;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(1,1,1);
        libro->human_name = "Core Java 2 Vol1";
        libro->x = 24;
        libro->y = 17;
        libro->z = 5;
        libro->RecalculateMesh();
        libro->translation->x = 7;
        libro->translation->y = 0;
        libro->translation->z = 156;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0.1,0.1,0.1);
        libro->human_name = "Ecuaciones Diferenciales";
        libro->x = 24;
        libro->y = 19;
        libro->z = 4;
        libro->RecalculateMesh();
        libro->translation->x = 8;
        libro->translation->y = 0;
        libro->translation->z = 161;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0,0,.5);
        libro->human_name = "Programming in C++";
        libro->x = 24;
        libro->y = 18;
        libro->z = 6;
        libro->RecalculateMesh();
        libro->translation->x = 7;
        libro->translation->y = 0;
        libro->translation->z = 165;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0,0.8,0);
        libro->human_name = "The Green Book";
        libro->x = 6;
        libro->y = 18;
        libro->z = 24;
        libro->RecalculateMesh();
        libro->translation->x = 33;
        libro->translation->y = 0;
        libro->translation->z = 150;
        libro->rotation->y = -4;
        estanteria->elements->push_back(libro);

        libro = new Box3D();
        libro->color = new Color3D(0.9,0.9,0.4);
        libro->human_name = "The Yellow Book";
        libro->x = 6;
        libro->y = 18;
        libro->z = 24;
        libro->RecalculateMesh();
        libro->translation->x = 39;
        libro->translation->y = 0;
        libro->translation->z = 150;
        libro->rotation->y = -4;
        estanteria->elements->push_back(libro);








        // Cama ////////////////////////////////////////////////////////////////
        Group3D *cama = new Group3D();
        cama->human_name = "Cama";
        cama->translation->x = 710;
        cama->translation->y = 195;
        cama->rotation->z = 180;
        _house->elements->push_back(cama);


        Group3D *somier = new Group3D();
        somier->color = new Color3D(0.2,0.2,0.2);
        somier->human_name = "Somier";
        cama->elements->push_back(somier);

        // Patas del somier:
        Box3D *pata;

        // Pata 1
        pata = new Box3D();
        pata->human_name = "Pata 1";
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 2
        pata = new Box3D();
        pata->human_name = "Pata 2";
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 10;
        somier->elements->push_back(pata);

        // Pata 3
        pata = new Box3D();
        pata->human_name = "Pata 3";
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Pata 4
        pata = new Box3D();
        pata->human_name = "Pata 4";
        pata->x = 5;
        pata->y = 5;
        pata->z = 25;
        pata->RecalculateMesh();
        pata->translation->x = 85;
        pata->translation->y = 165;
        somier->elements->push_back(pata);

        // Esqueleto del somier:
        pata = new Box3D();
        pata->human_name = "Pata";
        pata->x = 90;
        pata->y = 180;
        pata->z = 5;
        pata->RecalculateMesh();
        pata->translation->x = 0;
        pata->translation->y = 0;
        pata->translation->z = 25;
        somier->elements->push_back(pata);


        Box3D *colchon = new Box3D();
        colchon->human_name = "Colchon";
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
        almohada->human_name = "Almohada";
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
        cabecero->human_name = "Cabecero";
        cabecero->x = 110;
        cabecero->y = 5;
        cabecero->z = 80;
        cabecero->RecalculateMesh();
        cabecero->color = color_tabla;
        cabecero->translation->x = -10;
        cabecero->translation->y = 180;
        cama->elements->push_back(cabecero);

        /*
        Box3D *piecero = new Box3D();
        piecero->human_name = "Piecero";
        piecero->x = 90;
        piecero->y = 5;
        piecero->z = 60;
        piecero->RecalculateMesh();
        piecero->color = color_tabla;
        piecero->translation->y = -5;
        cama->elements->push_back(piecero);
        */

        Group3D *persiana_der = new Group3D();
                persiana_der->human_name = "persianaDer";
                Cylinder3D *braz2_der = new Cylinder3D(70,3,3,true,true);
                braz2_der->color = new Color3D(1,1,1);
                braz2_der->translation->y = -5;
                braz2_der->RecalculateMesh();
                persiana_der->elements->push_back(braz2_der);
                Cylinder3D *braz2_izq = new Cylinder3D(70,3,3,true,true);
                braz2_izq->translation->x = 60;
                braz2_izq->translation->y = -5;
                braz2_izq->color = new Color3D(1,1,1);
                braz2_izq->RecalculateMesh();
                persiana_der->elements->push_back(braz2_izq);
                pala21_izq = new Box3D();
                pala21_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala21_izq->x = 56;
                pala21_izq->y = 15;
                pala21_izq->z = 2;
                pala21_izq->translation->x = 3;
                pala21_izq->translation->y = -5;
                pala21_izq->translation->z = 55;
                pala21_izq->rotation->x = 90;
                pala21_izq->RecalculateMesh();
                persiana_der->elements->push_back(pala21_izq);
                pala22_izq = new Box3D();
                pala22_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala22_izq->x = 56;
                pala22_izq->y = 15;
                pala22_izq->z = 2;
                pala22_izq->translation->x = 3;
                pala22_izq->translation->y = -5;
                pala22_izq->translation->z = 40;
                pala22_izq->rotation->x = 90;
                pala22_izq->RecalculateMesh();
                persiana_der->elements->push_back(pala22_izq);
                pala23_izq = new Box3D();
                pala23_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala23_izq->x = 56;
                pala23_izq->y = 15;
                pala23_izq->z = 2;
                pala23_izq->translation->x = 3;
                pala23_izq->translation->y = -5;
                pala23_izq->translation->z = 25;
                pala23_izq->rotation->x = 90;
                pala23_izq->RecalculateMesh();
                persiana_der->elements->push_back(pala23_izq);
                pala24_izq = new Box3D();
                pala24_izq->color = new Color3D(0.8588, 0.5764, 0.4392);
                pala24_izq->x = 56;
                pala24_izq->y = 15;
                pala24_izq->z = 2;
                pala24_izq->translation->x = 3;
                pala24_izq->translation->y = -5;
                pala24_izq->translation->z = 10;
                pala24_izq->rotation->x = 90;
                pala24_izq->RecalculateMesh();
                persiana_der->elements->push_back(pala24_izq);
                persiana_der->translation->x = 630;
                persiana_der->translation->z = 90;
                _house->elements->push_back(persiana_der);






        //                                                                    //
        //                FIN HABITACIÓN DE LA DERECHA FIN                    //
        ////////////////////////////////////////////////////////////////////////

      /////////////////////////// GRUPO PUERTA ///////////////////////////////
        puerta = new Group3D();
                puerta->human_name = "Puerta";
                Box3D *madero = new Box3D();
                madero->human_name = "Madero";
                madero->color = new Color3D(0.545, 0.27, 0.0745);
                madero->x = 10;
                madero->y = 80;
                madero->z = 180;
                madero->x_div = 1;
                madero->y_div = 1;
                madero->z_div = 1;
                madero->textura = text;
                madero->RecalculateMesh();
        puerta->elements->push_back(madero);
                Sphere3D *pomo_izq = new Sphere3D();
                pomo_izq->human_name = "Pomo izquierdo";
                pomo_izq->color = new Color3D(0,0.01,0);
                pomo_izq->radius = 5;
                pomo_izq->translation->x = 15;
                pomo_izq->translation->y = 65;
                pomo_izq->translation->z = 80;
                pomo_izq->RecalculateMesh();
        puerta->elements->push_back(pomo_izq);
                Sphere3D *pomo_der = new Sphere3D();
                pomo_der->human_name = "Pomo derecho";
                pomo_der->color = new Color3D(0,0.01,0);
                pomo_der->radius = 5;
                pomo_der->translation->x = -5;
                pomo_der->translation->y = 65;
                pomo_der->translation->z = 80;
                pomo_der->RecalculateMesh();
        puerta->elements->push_back(pomo_der);

                puerta->translation->x = 440;
                puerta->translation->y = 190;
        _house->elements->push_back(puerta);

        

        _scene->main_figure->elements->push_back(_house);
        _scene->Repaint();
}

String EventHouse::getName() {
        return "house";
}

bool EventHouse::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {

        if (type == "KeyDown") {

        // Para la lámpara (s):
        if (key == 83) {
                if (bombilla->isEnabled()) {
                        bombilla->Disable();
                        pantalla->color->g = 0.5;

                } else {
                        bombilla->Enable();
                        pantalla->color->g = 1;
                }
                _scene->Repaint();
        }

        // Para la luz remota (r):
        if (key == 82) {
                if (luz_direccional->isEnabled()) {
                        luz_direccional->Disable();
                } else {
                        luz_direccional->Enable();
                }
                _scene->Repaint();
        }


        if(key == 84) {

            if(_encendida) {
                _encendida = !_encendida;
                 delete _pantalla->color;
                _pantalla->color = new Color3D(0,0,0);
                _pantalla->textura = -1;
                _scene->Repaint();
            }
            else{
                _encendida = !_encendida;
                delete _pantalla->color;
                _pantalla->color = new Color3D(0,0,1);
                _pantalla->textura = text2;
                _scene->Repaint();
            }
            return true;
        }

        if(key == 80) {
                //double pi = 4*atan(1);
                if(_cerrada) {
                        _cerrada = !_cerrada;
                        //double inc_ang = 9;
                        for(int i=0; i<10;i++) {
                                /*double ang = i*inc_ang;
                                puerta->rotation->x *= cos(ang);
                                puerta->rotation->y *= sin(ang);*/
                                puerta->rotation->z += 9;
                                _scene->Repaint();
                        }
                }
                else {
                        _cerrada = !_cerrada;
                        //double inc_ang = 9;
                        for(int i=0; i<10;i++) {
                                /*double ang = i*inc_ang;
                                puerta->rotation->x *= cos(ang);
                                puerta->rotation->y *= sin(ang);*/
                                puerta->rotation->z -= 9;
                                _scene->Repaint();
                        }
                }
                return true;
        }

        /*
        if(key == 67) {
                if(_hab_der) {
                        _hab_der = !_hab_der;
                        _viewport->camera = _viewport->cameras[0];
                }
                else {
                        _hab_der = !_hab_der;
                        _viewport->camera = _viewport->cameras[1];
                }
                _scene->Repaint();
                return true;
        }
        */

        if(key == 49) {
                if(_pers1_cerr) {
                        for(int i = 0; i < 10; i++) {
                                pala1_izq->rotation->x -= 9;
                                pala2_izq->rotation->x -= 9;
                                pala3_izq->rotation->x -= 9;
                                pala4_izq->rotation->x -= 9;
                                _scene->Repaint();
                        }

                        while(pala4_izq->translation->z < 49) {

                                if(pala2_izq->translation->z < 53)
                                pala2_izq->translation->z += 2;

                                if(pala3_izq->translation->z < 51)
                                pala3_izq->translation->z += 2;

                                pala4_izq->translation->z += 2;

                                _scene->Repaint();
                        }
                        _pers1_cerr = false;
                }
                else {

                        while(pala4_izq->translation->z > 10) {

                                if(pala2_izq->translation->z > 40)
                                pala2_izq->translation->z -= 2;

                                if(pala3_izq->translation->z > 25)
                                pala3_izq->translation->z -= 2;

                                pala4_izq->translation->z -= 2;

                                _scene->Repaint();
                        }

                         for(int i = 0; i < 10; i++) {
                                pala1_izq->rotation->x += 9;
                                pala2_izq->rotation->x += 9;
                                pala3_izq->rotation->x += 9;
                                pala4_izq->rotation->x += 9;
                                _scene->Repaint();
                        }
                        _pers1_cerr = true;
                }
                return true;
        }

        if(key == 50) {
                if(_pers2_cerr) {
                        for(int i = 0; i < 10; i++) {
                                pala21_izq->rotation->x -= 9;
                                pala22_izq->rotation->x -= 9;
                                pala23_izq->rotation->x -= 9;
                                pala24_izq->rotation->x -= 9;
                                _scene->Repaint();
                        }
                        while(pala24_izq->translation->z < 49) {

                                if(pala22_izq->translation->z < 53)
                                pala22_izq->translation->z += 2;

                                if(pala23_izq->translation->z < 51)
                                pala23_izq->translation->z += 2;

                                pala24_izq->translation->z += 2;

                                _scene->Repaint();
                        }
                        _pers2_cerr = false;
                }
                else {

                        while(pala24_izq->translation->z > 10) {

                                if(pala22_izq->translation->z > 40)
                                pala22_izq->translation->z -= 2;

                                if(pala23_izq->translation->z > 25)
                                pala23_izq->translation->z -= 2;

                                pala24_izq->translation->z -= 2;

                                _scene->Repaint();
                        }

                         for(int i = 0; i < 10; i++) {
                                pala21_izq->rotation->x += 9;
                                pala22_izq->rotation->x += 9;
                                pala23_izq->rotation->x += 9;
                                pala24_izq->rotation->x += 9;
                                _scene->Repaint();
                        }
                        _pers2_cerr = true;
                }
                return true;
        }

        }
        else if(type == "MouseDown") {

                GLint colores[3];
                _viewport->findCoordinates(X,Y, colores);

                if((colores[0] == 0) && (colores[1] == 0) && (colores[2] == 0)) {
                        if(_encendida) {
                        _encendida = !_encendida;
                        delete _pantalla->color;
                        _pantalla->color = new Color3D(0,0,0);
                        _scene->Repaint();
                }
                else{
                        _encendida = !_encendida;
                        delete _pantalla->color;
                        _pantalla->color = new Color3D(0,0,1);
                        _scene->Repaint();
                }
                return true;
                }
        }




        return false;

}

//bool EventHouse::eventMouse(ViewPort3D *_viewport, Scene3D *_scene, TShiftState shift, int X, int Y) {

        //GLdouble glX, glY;

        //GLint colores[3];
        //_viewport->findCoordinates(X,Y, colores);
        //_scene->color(X, Y, colores);

        /*if((glX > 200 && glX < 280)
                && (glY > 200 && glY < 280)) {
                         _pantalla->color = new Color3D(0,0,1);
                         _scene->Repaint();
                         return true;
                }*/

        //double x_obj = (_viewport->camera->eye->x) - glX;
        //double y_obj = (_viewport->camera->eye->y) - glY;

        /*if((x_obj > 190 && x_obj < 210)
                && (y_obj > 210 && y_obj < 230)) {
                         _pantalla->color = new Color3D(0,0,1);
                         _scene->Repaint();
                         return true;
                }*/

        //return false;

//}
