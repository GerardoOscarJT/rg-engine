//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventOblique.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

void EventOblique::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _viewport->getCamera()->perspective = 2;
        _scene->Repaint();
}

String EventOblique::getName() {
        return "oblique";
}