#ifndef EventCornerH
#define EventCornerH

#include "Event.h"

class EventCorner : public Event {
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);
        String getName();
};

#endif
