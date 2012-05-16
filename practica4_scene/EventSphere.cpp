#include <vcl.h>
#pragma hdrstop
#include "EventSphere.h"
#pragma package(smart_init)

String EventSphere::getName() {
        return "sphere";
}

void EventSphere::top(ViewPort3D *_viewport, Scene3D *_scene) {
        _sphere = new Sphere3D(20,20,20);
        _sphere->color = new Color3D(1,1,0);
        _sphere->filled = true;
        //_sphere->showNormals = true;
        _sphere->RecalculateMesh();
        _scene->main_figure->elements->push_back(_sphere);
        _scene->Repaint();
}

bool EventSphere::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {

        if (type=="KeyDown") {

                // Para controlar la velocidad de giro con Control y Shift
                double velocity = 1; // Velocidad normal
                if (shift.Contains(ssShift)) {
                        velocity = 10; // Velocidad alta
                } else if (shift.Contains(ssCtrl)) {
                        velocity = 0.1; // Velocidad lenta
                }

                if (key==90) { // z
                        _sphere->translation->z += velocity;
                        _scene->Repaint();
                        return true;
                }
                if (key==65) { // a
                        _sphere->translation->z -= velocity;
                        _scene->Repaint();
                        return true;
                }

                if (key==88) { // x
                        _sphere->translation->x += velocity;
                        _scene->Repaint();
                        return true;
                }
                if (key==83) { // s
                        _sphere->translation->x -= velocity;
                        _scene->Repaint();
                        return true;
                }

                if (key==89) { // y
                        _sphere->translation->y += velocity;
                        _scene->Repaint();
                        return true;
                }
                if (key==54) { // 6
                        _sphere->translation->y -= velocity;
                        _scene->Repaint();
                        return true;
                }






        }








        return false;
}

