#include <vcl.h>
#pragma hdrstop

#include "EventScam.h"
#pragma package(smart_init)

String EventScam::getName() {
        return "scam";
}

bool EventScam::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {

        if (type == "KeyDown") {

                PV3D look_eye(
                _viewport->camera->eye->x - _viewport->camera->look->x,
                _viewport->camera->eye->y - _viewport->camera->look->y,
                _viewport->camera->eye->z - _viewport->camera->look->z,
                0);

                double module_xy = sqrt(pow(_viewport->camera->eye->x,2)+pow(_viewport->camera->eye->y,2));                double angle = atan2l(
                        look_eye.x,
                        look_eye.y
                );

                if (key == 37) {
                        angle -= 0.1;
                        _viewport->camera->eye->x = module_xy*sin(angle);
                        _viewport->camera->eye->y = module_xy*cos(angle);
                        _viewport->camera->recalculateCameraAxis();
                        _viewport->camera->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 39) {
                        angle += 0.1;
                        _viewport->camera->eye->x = module_xy*sin(angle);
                        _viewport->camera->eye->y = module_xy*cos(angle);
                        _viewport->camera->recalculateCameraAxis();
                        _viewport->camera->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 38) {
                        _viewport->camera->eye->z += 10;
                        _viewport->camera->recalculateCameraAxis();
                        _viewport->camera->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

                if (key == 40) {
                        _viewport->camera->eye->z -= 10;
                        _viewport->camera->recalculateCameraAxis();
                        _viewport->camera->setModelViewMatrix();
                        _scene->Repaint();
                        return true;
                }

        }
        return false;
}
