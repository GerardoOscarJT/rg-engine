#ifndef EventPitchH
#define EventPitchH


#include "Event.h"

class EventPitch : public Event {
public:
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);
        String getName();
};


#endif
 