//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "EventMoveCamera.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String EventMoveCamera::getName() {
        return "move";
}

bool EventMoveCamera::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {

        if (type=="KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key==90) { // z
                        _viewport->getCamera()->move(PV3D(0,0,velocity));
                        _scene->Repaint();
                        return true;
                }
                if (key==65) { // a
                        _viewport->getCamera()->move(PV3D(0,0,-velocity));
                        _scene->Repaint();
                        return true;
                }

                if (key==88) { // x
                        _viewport->getCamera()->move(PV3D(velocity,0,0));
                        _scene->Repaint();
                        return true;
                }
                if (key==83) { // s
                        _viewport->getCamera()->move(PV3D(-velocity,0,0));
                        _scene->Repaint();
                        return true;
                }

                if (key==89) { // y
                        _viewport->getCamera()->move(PV3D(0,velocity,0));
                        _scene->Repaint();
                        return true;
                }
                if (key==54) { // 6
                        _viewport->getCamera()->move(PV3D(0,-velocity,0));
                        _scene->Repaint();
                        return true;
                }
        }
        return false;

}
