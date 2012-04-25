#ifndef EventRollH
#define EventRollH

#include "Event.h"

class EventRoll : public Event {
public:
        bool event();
        String getName();
};

#endif
