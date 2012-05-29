#include <vcl.h>
#pragma hdrstop

#include "EventToggleMaterialing.h"

#pragma package(smart_init)

void EventToggleMaterialing::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _scene->materialing_enabled = !_scene->materialing_enabled; 
}

String EventToggleMaterialing::getName() {
        return "toggle-materialing";
}
