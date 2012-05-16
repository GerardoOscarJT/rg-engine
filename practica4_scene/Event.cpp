#include <vcl.h>
#pragma hdrstop

#include "Event.h"




#pragma package(smart_init)


bool Event::event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift) {
        return false;
}

void Event::top(ViewPort3D *_viewport, Scene3D *_scene) {
        
}

/*bool Event::eventMouse(ViewPort3D *_viewport, Scene3D *_scene, TShiftState shift, int X, int Y) {
        return false;
} */

