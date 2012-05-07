//---------------------------------------------------------------------------

#ifndef EventZRotateH
#define EventZRotateH

#include "Event.h"

class EventZRotate : public Event {
public:
        String getName();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);
};

#endif
