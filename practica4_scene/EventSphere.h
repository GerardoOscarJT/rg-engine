#ifndef EventSphereH
#define EventSphereH

#include "Event.h"
#include "Sphere3D.h"
#include "Box3D.h"

class EventSphere:public Event {
public:

        String getName();
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);

private:
        Sphere3D *_sphere;


};




#endif
 