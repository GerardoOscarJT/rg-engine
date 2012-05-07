//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventAroundAxis.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventAroundAxis::getName() {
        return "around_axis";
}

bool EventAroundAxis::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {

        if (type=="KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key==90) { // z
                        _viewport->camera->xyRotate(true);
                        _scene->Repaint();
                        return true;
                }
                if (key==65) { // a
                        _viewport->camera->xyRotate(false);
                        _scene->Repaint();
                        return true;
                }

                if (key==88) { // x
                        _viewport->camera->turnX(true);
                        _scene->Repaint();
                        return true;
                }
                if (key==83) { // s
                        _viewport->camera->turnX(false);
                        _scene->Repaint();
                        return true;
                }

                if (key==89) { // y
                        _viewport->camera->turnY(true);
                        _scene->Repaint();
                        return true;
                }
                if (key==54) { // 6
                        _viewport->camera->turnY(false);
                        _scene->Repaint();
                        return true;
                }

        }
        return false;

}

