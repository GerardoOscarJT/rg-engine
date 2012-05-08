#include <vcl.h>
#pragma hdrstop

#include "EventGlass.h"
#pragma package(smart_init)


void EventGlass::top(ViewPort3D *_viewport, Scene3D *_scene) {
        Revolution3D *glass = new Revolution3D();

        glass->color = new Color3D(1,1,1);
        glass->n = 8;

        glass->points->push_back(new PV3D(0,0,8));
        glass->points->push_back(new PV3D(0,0,8));
        glass->points->push_back(new PV3D(0,0,8));
        glass->points->push_back(new PV3D(50,0,0));
        glass->points->push_back(new PV3D(50,0,2));
        glass->points->push_back(new PV3D(4,0,10));
        glass->points->push_back(new PV3D(4,0,100));
        glass->points->push_back(new PV3D(4,0,100));
        glass->points->push_back(new PV3D(100,0,200));
        glass->points->push_back(new PV3D(99,0,201));
        glass->points->push_back(new PV3D(98,0,200));
        glass->points->push_back(new PV3D(0,0,102));
        glass->points->push_back(new PV3D(0,0,102));

        glass->RecalculateMesh();

        _scene->main_figure->elements->push_back(glass);
        _scene->Repaint();
}

String EventGlass::getName() {
        return "glass";
}

