//---------------------------------------------------------------------------

#ifndef EventAroundAxisH
#define EventAroundAxisH

#include "Event.h"

class EventAroundAxis : public Event {

public:
        String getName();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);

};

#endif
