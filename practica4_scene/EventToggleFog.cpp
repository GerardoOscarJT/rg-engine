#include <vcl.h>
#pragma hdrstop

#include "EventToggleFog.h"

#pragma package(smart_init)

void EventToggleFog::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _scene->fog_enabled = !_scene->fog_enabled;
        _scene->Repaint();
}

String EventToggleFog::getName() {
        return "toggle-fog";
}
