//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventZRotate.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventZRotate::getName() {
        return "z_rotate";
}

bool EventZRotate::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {

        if (type=="KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key==38) { // flecha arriba
                        _viewport->camera->zRotate(true);
                        _scene->Repaint();
                        return true;
                }
                if (key==40) { // flecha abajo
                        _viewport->camera->zRotate(false);
                        _scene->Repaint();
                        return true;
                }
        }
        return false;

}
