#include <vcl.h>
#pragma hdrstop
#include "EventYaw.h"
#pragma package(smart_init)


bool EventYaw::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {

        if (type == "KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key == 39) {
                        // Flecha derecha
                        _viewport->getCamera()->yaw(-velocity);
                        _scene->Repaint();
                        return true;
                }
                if (key == 37) {
                        // Flecha izquierda
                        _viewport->getCamera()->yaw(velocity);
                        _scene->Repaint();
                        return true;
                }
        }

        return false;
}
String EventYaw::getName() {
        return "yaw";
}
