#ifndef EventH
#define EventH

#include <list.h>
#include "ViewPort3D.h"
#include "Scene3D.h"

class Event {
public:
        virtual bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        virtual void top(ViewPort3D *_viewport, Scene3D *_scene);
        //virtual bool eventMouse(ViewPort3D *_viewport, Scene3D *_scene, TShiftState shift, int X, int Y);
        virtual String getName()=0;
};

#endif
