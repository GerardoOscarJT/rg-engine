//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventOrthogonal.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventOrthogonal::getName() {
        return "orthogonal";
}

void EventOrthogonal::top(ViewPort3D *_viewport, Scene3D *_scene) {

        _viewport->camera->perspective = 1;
        _scene->Repaint();

}
