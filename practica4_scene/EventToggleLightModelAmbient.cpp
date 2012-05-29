#include <vcl.h>
#pragma hdrstop

#include "EventToggleLightModelAmbient.h"

#pragma package(smart_init)




bool EventToggleLightModelAmbient::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {
        return false;
}


void EventToggleLightModelAmbient::top(ViewPort3D *_viewport, Scene3D *_scene) {

        if (activated) {
                GLfloat w[] = {0,0,0,0};
                glLightModelfv(GL_LIGHT_MODEL_AMBIENT, w);
        } else {
                GLfloat w[] = {0.2,0.2,0.2,0.1};
                glLightModelfv(GL_LIGHT_MODEL_AMBIENT, w);
        }

        activated = !activated;

        _scene->Repaint();
}


String EventToggleLightModelAmbient::getName() {
        return "toggle-light-model-ambient";
}

