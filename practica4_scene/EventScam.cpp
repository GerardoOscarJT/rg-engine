#include <vcl.h>
#pragma hdrstop

#include "EventScam.h"
#pragma package(smart_init)

String EventScam::getName() {
        return "scam";
}

bool EventScam::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {

        if (type == "KeyDown") {

                PV3D look_eye(
                _viewport->getCamera()->eye->x - _viewport->getCamera()->look->x,
                _viewport->getCamera()->eye->y - _viewport->getCamera()->look->y,
                _viewport->getCamera()->eye->z - _viewport->getCamera()->look->z,
                0);

                double module_xy = sqrt(pow(_viewport->getCamera()->eye->x,2)+pow(_viewport->getCamera()->eye->y,2));                double angle = atan2l(
                        look_eye.x,
                        look_eye.y
                );

                if (key == 37) {
                        angle -= 0.1;
                        _viewport->getCamera()->eye->x = module_xy*sin(angle);
                        _viewport->getCamera()->eye->y = module_xy*cos(angle);
                        _viewport->getCamera()->recalculateCameraAxis();
                        _viewport->getCamera()->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 39) {
                        angle += 0.1;
                        _viewport->getCamera()->eye->x = module_xy*sin(angle);
                        _viewport->getCamera()->eye->y = module_xy*cos(angle);
                        _viewport->getCamera()->recalculateCameraAxis();
                        _viewport->getCamera()->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 38) {
                        _viewport->getCamera()->eye->z += 10;
                        _viewport->getCamera()->recalculateCameraAxis();
                        _viewport->getCamera()->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 40) {
                        _viewport->getCamera()->eye->z -= 10;
                        _viewport->getCamera()->recalculateCameraAxis();
                        _viewport->getCamera()->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

        }
        return false;
}
