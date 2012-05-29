#ifndef EventAlongAxisH
#define EventAlongAxisH

#include "Event.h"

class EventAlongAxis : public Event {

public:
        String getName();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift,int X, int Y);

};

#endif
