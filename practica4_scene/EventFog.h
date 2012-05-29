#ifndef EventFogH
#define EventFogH

#include <gl\gl.h>
#include <gl\glu.h>

#include "Event.h"

class EventFog : public Event {
public:

        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();



};





#endif
 