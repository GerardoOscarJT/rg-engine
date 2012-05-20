//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventPerspective.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventPerspective::getName() {
        return "perspective";
}

void EventPerspective::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _viewport->getCamera()->perspective = 0;
        _scene->Repaint();
}
