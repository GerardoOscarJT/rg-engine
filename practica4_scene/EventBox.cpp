//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventBox.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

bool EventBox::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {
        return false;
}

void EventBox::top(ViewPort3D *_viewport, Scene3D *_scene) {

        Box3D *box = new Box3D();
        box->color = new Color3D(1,0.1,0.4);
        box->x = 40;
        box->y = 40;
        box->z = 40;
        box->x_div = 2;
        box->y_div = 2;
        box->z_div = 2;
        //box->showNormals = true;
        box->RecalculateMesh();

        _scene->main_figure->elements->push_back(box);
        _scene->Repaint();

}

String EventBox::getName() {
return "box";
}
