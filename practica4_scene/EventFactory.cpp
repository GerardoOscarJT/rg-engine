#include <vcl.h>
#pragma hdrstop

#include "EventFactory.h"

Event* EventFactory::createEvent(String name) {
        if (name == "roll")
                return new EventRoll();
        if (name == "pitch")
                return new EventPitch();
        if (name == "yaw")
                return new EventYaw();
        if (name == "glass")
                return new EventGlass();
        if (name == "house")
                return new EventHouse();
        if (name == "zoom")
                return new EventZoom();
        if (name == "sphere")
                return new EventSphere();
        if(name == "orthogonal")
                return new EventOrthogonal();

        return NULL;
}



list<String>* EventFactory::getEvents() {
        list<String> *registered_events = new list<String>();

        registered_events->push_back("roll");
        registered_events->push_back("pitch");
        registered_events->push_back("yaw");
        registered_events->push_back("glass");
        registered_events->push_back("house");
        registered_events->push_back("zoom");
        registered_events->push_back("sphere");
        registered_events->push_back("orthogonal");
        registered_events->sort();

        return registered_events;
}

#pragma package(smart_init)
