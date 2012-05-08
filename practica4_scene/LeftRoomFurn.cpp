//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LeftRoomFurn.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

LeftRoomFurn::LeftRoomFurn() {
        human_name = "MueblesHabitacionIzquierda";

        //Mesa
        Box3D *tabl_mesa = new Box3D();
                tabl_mesa->human_name = "Tablero Mesa";
                tabl_mesa->color = new Color3D(0.545, 0.27, 0.0745);
                tabl_mesa->x = 20;
                tabl_mesa->y = 20;
                tabl_mesa->z = 2;
                tabl_mesa->translation->x = -10;
                tabl_mesa->translation->y = -10;
                tabl_mesa->translation->z = 10;
                tabl_mesa->divisiones = 2;
                tabl_mesa->RecalculateMesh();

        Cylinder3D *pata = new Cylinder3D(10, 2, 2, false, true);
                pata->human_name = "Pata mesa";
                pata->color = new Color3D(0.545, 0.27, 0.0745);
                pata->RecalculateMesh();

        table = new Group3D();
        table->human_name = "Mesa";
        table->elements->push_back(tabl_mesa);
        table->elements->push_back(pata);
        table->translation->x = 0;
        table->translation->y = 0;

      //Grupo Silla
        _chair = new Group3D();
                _chair->human_name = "Silla";
                Box3D *respaldo = new Box3D();
                        respaldo->color = new Color3D(0.545, 0.27, 0.0745);
                        respaldo->x = 6;
                        respaldo->y = 2;
                        respaldo->z = 12;
                        respaldo->translation->y = 10;
                        respaldo->translation->z = 8;
                        respaldo->divisiones = 2;
                        respaldo->RecalculateMesh();
                _chair->elements->push_back(respaldo);

                Box3D *asiento = new Box3D();
                        asiento->color = new Color3D(0.545, 0.27, 0.0745);
                        asiento->x = 6;
                        asiento->y = -8;
                        asiento->z = 1;
                        asiento->translation->y = 12;
                        asiento->translation->z = 7; //asiento->showNormals = true;
                        asiento->divisiones = 2;
                        asiento->RecalculateMesh();
                _chair->elements->push_back(asiento);

                Cylinder3D *pata_del_der = new Cylinder3D(7, 1, 1, false, true);
                        pata_del_der->color = new Color3D(0.545, 0.27, 0.0745);
                        pata_del_der->translation->x = 1.5;
                        pata_del_der->translation->y = 5.5;
                        pata_del_der->RecalculateMesh();
                _chair->elements->push_back(pata_del_der);

                Cylinder3D *pata_del_izq = new Cylinder3D(7, 1, 1, false, true);
                        pata_del_izq->color = new Color3D(0.545, 0.27, 0.0745);
                        pata_del_izq->translation->x = 4.5;
                        pata_del_izq->translation->y = 5.5;
                        pata_del_izq->RecalculateMesh();
                _chair->elements->push_back(pata_del_izq);

                Cylinder3D *pata_tras_der = new Cylinder3D(7, 1, 1, false, true);
                        pata_tras_der->color = new Color3D(0.545, 0.27, 0.0745);
                        pata_tras_der->translation->x = 1.5;
                        pata_tras_der->translation->y = 10.5;
                        pata_tras_der->RecalculateMesh();
                _chair->elements->push_back(pata_tras_der);

                Cylinder3D *pata_tras_izq = new Cylinder3D(7, 1, 1, false, true);
                        pata_tras_izq->color = new Color3D(0.545, 0.27, 0.0745);
                        pata_tras_izq->translation->x = 4.5;
                        pata_tras_izq->translation->y = 10.5;
                        pata_tras_izq->RecalculateMesh();
                _chair->elements->push_back(pata_tras_izq);

        //Sillas
        chair1 = new Group3D();
                chair1->human_name = "Silla 1";
                chair1->elements->push_back(_chair);
                chair1->color = new Color3D(0.545, 0.27, 0.0745);
                chair1->translation->x = -2;
                chair1->translation->y = 10;
                chair1->rotation->z = 0;

        chair2 = new Group3D();
                chair2->human_name = "Silla 2";
                chair2->elements->push_back(_chair);
                chair2->color = new Color3D(0.545, 0.27, 0.0745);
                chair2->translation->x = -10;
                chair2->translation->y = -2;
                chair2->rotation->z = 90;

        chair3 = new Group3D();
                chair3->human_name = "Silla 3";
                chair3->elements->push_back(_chair);
                chair3->color = new Color3D(0.545, 0.27, 0.0745);
                chair3->translation->x = 2;
                chair3->translation->y = -10;
                chair3->rotation->z = 180;

        chair4 = new Group3D();
                chair4->human_name = "Silla 4";
                chair4->elements->push_back(_chair);
                chair4->color = new Color3D(0.545, 0.27, 0.0745);
                chair4->translation->x = 10;
                chair4->translation->y = 2;
                chair4->rotation->z = -90;

        //Grupo de plato. Tiene un plato y una epitrocoide
        Group3D *grupoPlato = new Group3D();
                grupoPlato->human_name = "Grupo Plato";
                Disk3D *plate = new Disk3D(0,3,50,1);
                plate->color = new Color3D(1,1,1);
                plate->translation->z = 12.2;
                plate->RecalculateMesh();
        grupoPlato->elements->push_back(plate);
                Epitrochoid3D *epi = new Epitrochoid3D();
                epi->color = new Color3D(.1, 1, 1);
                epi->a = 0.6;
                epi->b = 0.2;
                epi->h = 0.3;
                epi->r = 0.3;
                epi->translation->z = 12.3;
                epi->nP = 6;
                epi->nQ = 16;
                epi->RecalculateMesh();
        grupoPlato->elements->push_back(epi);


        //Platos
        Group3D *plate1 = new Group3D();
                plate1->human_name = "Plato 1";
                plate1->elements->push_back(grupoPlato);
                plate1->translation->x = 7;
                plate1->translation->y = 0;

        Group3D *plate2 = new Group3D();
                plate2->human_name = "Plato 2";
                plate2->elements->push_back(grupoPlato);
                plate2->translation->x = 0;
                plate2->translation->y = 7;

        Group3D *plate3 = new Group3D();
                plate3->human_name = "Plato 3";
                plate3->elements->push_back(grupoPlato);
                plate3->translation->x = -7;
                plate3->translation->y = 0;

        Group3D *plate4 = new Group3D();
                plate4->human_name = "Plato 4";
                plate4->elements->push_back(grupoPlato);
                plate4->translation->x = 0;
                plate4->translation->y = -7;

        //Servilletas. ¡Ojo!, tiene los palillos también
        _napkin = new Group3D();
                _napkin->human_name = "Servilleta";
                Box3D *servilleta = new Box3D();
                        servilleta->color = new Color3D(0.8, 0.6, 0);
                        servilleta->x = 4;
                        servilleta->y = 2;
                        servilleta->z = 0.1;
                        servilleta->translation->x = -2;
                        servilleta->translation->y = -1;
                        servilleta->translation->z = 12.3;
                        servilleta->divisiones = 2;
                        servilleta->RecalculateMesh();
                _napkin->elements->push_back(servilleta);
                Cylinder3D *pal_izq = new Cylinder3D(4,0.05,0.05,true,true);
                        pal_izq->color = new Color3D(0,0,0);
                        pal_izq->translation->x = -2;
                        pal_izq->translation->y = -0.5;
                        pal_izq->translation->z = 12.4;
                        pal_izq->rotation->y = 90;
                        pal_izq->RecalculateMesh();
                _napkin->elements->push_back(pal_izq);
                Cylinder3D *pal_der = new Cylinder3D(4,0.05,0.05,true,true);
                        pal_der->color = new Color3D(0,0,0);
                        pal_der->translation->x = -2;
                        pal_der->translation->y = 0.5;
                        pal_der->translation->z = 12.4;
                        pal_der->rotation->y = 90;
                        pal_der->RecalculateMesh();
                _napkin->elements->push_back(pal_der);
                Revolution3D *copa = new Revolution3D();
                        copa->color = new Color3D(1,1,1);
                        copa->points->push_back(new PV3D(0,0,0.08));
                        copa->points->push_back(new PV3D(0,0,0.08));
                        copa->points->push_back(new PV3D(0,0,0.08));
                        copa->points->push_back(new PV3D(0.5,0,0));
                        copa->points->push_back(new PV3D(0.5,0,0.02));
                        copa->points->push_back(new PV3D(0.04,0,0.1));
                        copa->points->push_back(new PV3D(0.04,0,1));
                        copa->points->push_back(new PV3D(0.04,0,1));
                        copa->points->push_back(new PV3D(1,0,2));
                        copa->points->push_back(new PV3D(0.99,0,2.01));
                        copa->points->push_back(new PV3D(0.98,0,2));
                        copa->points->push_back(new PV3D(0,0,1.02));
                        copa->points->push_back(new PV3D(0,0,1.02));
                        copa->translation->x = 0;//1;
                        copa->translation->y = 9;
                        copa->translation->z = 12.2;
                        copa->n = 8;
                        copa->RecalculateMesh();
                _napkin->elements->push_back(copa);

        servilleta1 = new Group3D();
                servilleta1->human_name = "Servilleta 1";
                servilleta1->elements->push_back(_napkin);
                servilleta1->translation->x = 7;
                servilleta1->translation->y = -4.5;
        servilleta2 = new Group3D();
                servilleta2->human_name = "Servilleta 2";
                servilleta2->elements->push_back(_napkin);
                servilleta2->translation->x = 4.5;
                servilleta2->translation->y = 7;
                servilleta2->rotation->z = 90;
        servilleta3 = new Group3D();
                servilleta3->human_name = "Servilleta 3";
                servilleta3->elements->push_back(_napkin);
                servilleta3->translation->x = -7;
                servilleta3->translation->y = 4.5;
                servilleta3->rotation->z = 180;
        servilleta4 = new Group3D();
                servilleta4->human_name = "Servilleta 4";
                servilleta4->elements->push_back(_napkin);
                servilleta4->translation->x = -4.5;
                servilleta4->translation->y = -7;
                servilleta4->rotation->z = 270;

       /*translation->x = 20;
       translation->y = 0;
       translation->z = -50;*/
       scale->x = 4;
       scale->y = 4;
       scale->z = 4;
       elements->push_back(table);
       elements->push_back(chair1);
       elements->push_back(chair2);
       elements->push_back(chair3);
       elements->push_back(chair4);
       elements->push_back(plate1);
       elements->push_back(plate2);
       elements->push_back(plate3);
       elements->push_back(plate4);
       elements->push_back(servilleta1);
       elements->push_back(servilleta2);
       elements->push_back(servilleta3);
       elements->push_back(servilleta4);
}

