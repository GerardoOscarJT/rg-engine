#ifndef EventToggleLightModelAmbientH
#define EventToggleLightModelAmbientH

#include "Event.h"

class EventToggleLightModelAmbient : public Event {
public:

        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

private:
        bool activated;


};







#endif
 