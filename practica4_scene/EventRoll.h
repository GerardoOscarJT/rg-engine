#ifndef EventRollH
#define EventRollH

#include "Event.h"

class EventRoll : public Event {
public:
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        String getName();
};

#endif
