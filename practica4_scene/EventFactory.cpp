#include <vcl.h>
#pragma hdrstop

#include "EventFactory.h"

Event* EventFactory::createEvent(String name) {
        if (name == "roll")
                return new EventRoll();

        return NULL;
}



list<String> EventFactory::getEvents() {
        list<String> registered_events;

        registered_events.push_back("roll");
        registered_events.push_back("otro1");
        registered_events.push_back("otro2");
        registered_events.push_back("otro3");

        return registered_events;
}

#pragma package(smart_init)
