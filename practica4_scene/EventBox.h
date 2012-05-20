//---------------------------------------------------------------------------

#ifndef EventBoxH
#define EventBoxH

#include "Event.h"
#include "Box3D.h"
//---------------------------------------------------------------------------

class EventBox : public Event {

public:
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

};

#endif
