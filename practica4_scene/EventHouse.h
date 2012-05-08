#ifndef EventHouseH
#define EventHouseH

#include "Event.h"
#include "LeftRoomFurn.h"
#include "Sphere3D.h"

class EventHouse:public Event {
public:
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();

        EventHouse();
private:
        Group3D *_house;

        Box3D *_pantalla;

        bool _encendida; //�Est� la tele encendida?

        Group3D *puerta;

        bool _cerrada;
};



#endif
 