#ifndef EventScamH
#define EventScamH

#include "Event.h"

class EventScam:public Event {
public:
        String getName();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);


};

#endif
