#include <vcl.h>
#pragma hdrstop

#include "EventKineBuildings.h"
#pragma package(smart_init)


void EventKineBuildings::top(ViewPort3D *_viewport, Scene3D *_scene) {

        Box3D *caja;



        // 1
        caja = new Box3D();
        caja->x = 400;
        caja->y = 600;
        caja->z = 300;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0,0);
        caja->translation->x = 200;
        caja->translation->y = 0;
        _scene->main_figure->elements->push_back(caja);

        // 2
        caja = new Box3D();
        caja->x = 400;
        caja->y = 400;
        caja->z = 100;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0,0);
        caja->translation->x = 200;
        caja->translation->y = 800;
        _scene->main_figure->elements->push_back(caja);

        // 3
        caja = new Box3D();
        caja->x = 400;
        caja->y = 1600;
        caja->z = 350;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0,0);
        caja->translation->x = -600;
        caja->translation->y = 0;
        _scene->main_figure->elements->push_back(caja);

        // 4
        caja = new Box3D();
        caja->x = 800;
        caja->y = 400;
        caja->z = 1000;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0.8,0.8);
        caja->translation->x = 200;
        caja->translation->y = 1400;
        _scene->main_figure->elements->push_back(caja);

        // 5
        caja = new Box3D();
        caja->x = 400;
        caja->y = 400;
        caja->z = 1000;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0.8,0.8);
        caja->translation->x = 400;
        caja->translation->y = 1800;
        _scene->main_figure->elements->push_back(caja);

        // 6
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 1000;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = -1200;
        caja->translation->y = 1800;
        _scene->main_figure->elements->push_back(caja);

        // 7
        caja = new Box3D();
        caja->x = 1200;
        caja->y = 1200;
        caja->z = 1000;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0.2,0);
        caja->translation->x = -600;
        caja->translation->y = 2800;
        _scene->main_figure->elements->push_back(caja);

        // 8
        caja = new Box3D();
        caja->x = 800;
        caja->y = 800;
        caja->z = 2000;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0.4,0);
        caja->translation->x = -400;
        caja->translation->y = 3000;
        _scene->main_figure->elements->push_back(caja);

        // 9
        caja = new Box3D();
        caja->x = 400;
        caja->y = 400;
        caja->z = 2800;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,1,0);
        caja->translation->x = -200;
        caja->translation->y = 3200;
        _scene->main_figure->elements->push_back(caja);


        // 10
        caja = new Box3D();
        caja->x = 800;
        caja->y = 400;
        caja->z = 200;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0.2);
        caja->translation->x = 1200;
        caja->translation->y = 1800;
        _scene->main_figure->elements->push_back(caja);

        // 11
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 200;
        caja->RecalculateMesh();
        caja->color = new Color3D(0.7,0,0.7);
        caja->translation->x = 2200;
        caja->translation->y = 1800;
        _scene->main_figure->elements->push_back(caja);

        // 12
        caja = new Box3D();
        caja->x = 600;
        caja->y = 600;
        caja->z = 100;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,0,0);
        caja->translation->x = 1400;
        caja->translation->y = 2600;
        _scene->main_figure->elements->push_back(caja);

        // 13
        caja = new Box3D();
        caja->x = 500;
        caja->y = 500;
        caja->z = 200;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,1,0);
        caja->translation->x = 1450;
        caja->translation->y = 2650;
        _scene->main_figure->elements->push_back(caja);

        // 14
        caja = new Box3D();
        caja->x = 400;
        caja->y = 400;
        caja->z = 300;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 1500;
        caja->translation->y = 2700;
        _scene->main_figure->elements->push_back(caja);

        // 15
        caja = new Box3D();
        caja->x = 100;
        caja->y = 100;
        caja->z = 1600;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,1);
        caja->translation->x = 1650;
        caja->translation->y = 2850;
        _scene->main_figure->elements->push_back(caja);


        // 16
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 100;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = 1200;
        _scene->main_figure->elements->push_back(caja);


        // 17
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 100;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = 1200;
        _scene->main_figure->elements->push_back(caja);

        // 18
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 1400;
        caja->translation->z = 66;
        _scene->main_figure->elements->push_back(caja);

        // 19
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 1500;
        caja->translation->z = 66;
        _scene->main_figure->elements->push_back(caja);

        // 20
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 1300;
        caja->translation->z = 66;
        _scene->main_figure->elements->push_back(caja);






        // 21
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 200;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = 600;
        _scene->main_figure->elements->push_back(caja);


        // 22
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 200;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = 600;
        _scene->main_figure->elements->push_back(caja);

        // 23
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 800;
        caja->translation->z = 200;
        _scene->main_figure->elements->push_back(caja);

        // 24
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 900;
        caja->translation->z = 200;
        _scene->main_figure->elements->push_back(caja);

        // 25
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 700;
        caja->translation->z = 200;
        _scene->main_figure->elements->push_back(caja);




        // 26
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 300;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = 0;
        _scene->main_figure->elements->push_back(caja);


        // 27
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 300;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = 0;
        _scene->main_figure->elements->push_back(caja);

        // 28
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 200;
        caja->translation->z = 300;
        _scene->main_figure->elements->push_back(caja);

        // 29
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 300;
        caja->translation->z = 300;
        _scene->main_figure->elements->push_back(caja);

        // 30
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = 100;
        caja->translation->z = 300;
        _scene->main_figure->elements->push_back(caja);



        // 31
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 400;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = -600;
        _scene->main_figure->elements->push_back(caja);


        // 32
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 400;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = -600;
        _scene->main_figure->elements->push_back(caja);

        // 33
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -400;
        caja->translation->z = 400;
        _scene->main_figure->elements->push_back(caja);

        // 34
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -300;
        caja->translation->z = 400;
        _scene->main_figure->elements->push_back(caja);

        // 35
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -500;
        caja->translation->z = 400;
        _scene->main_figure->elements->push_back(caja);







        // 36
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 500;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = -1200;
        _scene->main_figure->elements->push_back(caja);


        // 37
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 500;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = -1200;
        _scene->main_figure->elements->push_back(caja);

        // 38
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -1000;
        caja->translation->z = 500;
        _scene->main_figure->elements->push_back(caja);

        // 39
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -900;
        caja->translation->z = 500;
        _scene->main_figure->elements->push_back(caja);

        // 40
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -1100;
        caja->translation->z = 500;
        _scene->main_figure->elements->push_back(caja);








        // 41
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 600;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 2200;
        caja->translation->y = -1800;
        _scene->main_figure->elements->push_back(caja);


        // 42
        caja = new Box3D();
        caja->x = 600;
        caja->y = 400;
        caja->z = 600;
        caja->RecalculateMesh();
        caja->color = new Color3D(0,0,1);
        caja->translation->x = 3000;
        caja->translation->y = -1800;
        _scene->main_figure->elements->push_back(caja);

        // 43
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -1600;
        caja->translation->z = 600;
        _scene->main_figure->elements->push_back(caja);

        // 44
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -1500;
        caja->translation->z = 600;
        _scene->main_figure->elements->push_back(caja);

        // 45
        caja = new Box3D();
        caja->x = 200;
        caja->y = 20;
        caja->z = 20;
        caja->RecalculateMesh();
        caja->color = new Color3D(1,1,0);
        caja->translation->x = 2800;
        caja->translation->y = -1700;
        caja->translation->z = 600;
        _scene->main_figure->elements->push_back(caja);



}


String EventKineBuildings::getName() {
        return "kine-buildings";
}
