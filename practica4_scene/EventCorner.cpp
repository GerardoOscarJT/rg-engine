//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventCorner.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventCorner::getName() {
        return "corner";
}

bool EventCorner::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {
        if (key==67) { // c
                _viewport->camera->corner();
                _scene->Repaint();
                return true;
        }
        return false;
}
