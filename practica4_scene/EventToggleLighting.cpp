#include <vcl.h>
#pragma hdrstop

#include "EventToggleLighting.h"
#pragma package(smart_init)

void EventToggleLighting::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _scene->lighting_enabled = !_scene->lighting_enabled;
        _scene->Repaint(); 
}

String EventToggleLighting::getName() {
        return "toggle-lighting";
}
