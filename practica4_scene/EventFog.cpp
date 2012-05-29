#include <vcl.h>
#pragma hdrstop

#include "EventFog.h"

#pragma package(smart_init)



bool EventFog::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y) {
        if (type == "KeyDown") {
                if (key == 76) { // tecla L: Factor lineal
                        _scene->fog_mode = GL_LINEAR;
                        _scene->Repaint();
                        return true;
                }

                if (key == 69) { // tecla E: Factor exponencial
                        _scene->fog_mode = GL_EXP;
                        _scene->Repaint();
                        return true;
                }

                if (key == 50) { // tecla 2: Factor exponencial cuadrado
                        _scene->fog_mode = GL_EXP2;
                        _scene->Repaint();
                        return true;
                }

                if (key == 68) { // tecla D: sube la density
                        _scene->fog_density *= 2;
                        if (_scene->fog_density >1)
                                _scene->fog_density = 1;
                                
                        _scene->Repaint();
                        return true;
                }

                if (key == 67) { // tecla C: baja la density
                        _scene->fog_density /= 2;
                        if (_scene->fog_density <0.00001)
                                _scene->fog_density = 0.00001;

                        _scene->Repaint();
                        return true;
                }


        }
        return false;
}

void EventFog::top(ViewPort3D *_viewport, Scene3D *_scene) {

}

String EventFog::getName() {
        return "fog";
}
