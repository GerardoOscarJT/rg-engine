#ifndef EventFactoryH
#define EventFactoryH

#include <list.h>
#include "EventRoll.h"
#include "EventPitch.h"
#include "EventYaw.h"
#include "EventGlass.h"
#include "EventHouse.h"
#include "EventZoom.h"
#include "EventSphere.h"
#include "EventOrthogonal.h"
#include "EventAlongAxis.h"
#include "EventPerspective.h"
#include "EventOblique.h"
#include "EventAroundAxis.h"
#include "EventMoveCamera.h"
#include "EventZRotate.h"
#include "EventCorner.h"
#include "EventScam.h"
#include "EventBox.h"
#include "EventKine.h"
#include "EventKineBuildings.h"
#include "EventToggleLighting.h"
#include "EventToggleMaterialing.h"
#include "EventToggleLightModelAmbient.h"
#include "EventFog.h"
#include "EventToggleFog.h"

class EventFactory {
public:
        static Event* createEvent(String);
        static list<String> * getEvents();
};


#endif
