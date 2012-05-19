#include <vcl.h>
#pragma hdrstop

#include "EventZoom.h"
#pragma package(smart_init)


bool EventZoom::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {

        if (type == "KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                /*
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }
                */

                if (key == 187) {
                        // + (acercar zoom)
                        //_viewport->camera->z(-velocity);
                        _viewport->camera->zoomIn(true);
                        _scene->Repaint();
                        return true;
                }
                if (key == 189) {
                        // - (alejar zoom)
                        //_viewport->camera->roll(velocity);
                        _viewport->camera->zoomOut(true);                        
                        _scene->Repaint();
                        return true;
                }
        }

        return false;
}

String EventZoom::getName() {
        return "zoom";
}
