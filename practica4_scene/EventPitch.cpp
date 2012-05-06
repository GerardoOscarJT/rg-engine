#include <vcl.h>
#pragma hdrstop

#include "EventPitch.h"
#pragma package(smart_init)


bool EventPitch::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {

        if (type == "KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key == 38) {
                        // Flecha arriba
                        _viewport->camera->pitch(-velocity);
                        _scene->Repaint();
                        return true;
                }
                if (key == 40) {
                        // Flecha abajo
                        _viewport->camera->pitch(velocity);
                        _scene->Repaint();
                        return true;
                }
        }

        return false;
}

String EventPitch::getName() {
        return "pitch";
}
