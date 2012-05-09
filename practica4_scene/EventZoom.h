#ifndef EventZoomH
#define EventZoomH

#include "Event.h"

class EventZoom:public Event {
public:

        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);
        String getName();
};



#endif
