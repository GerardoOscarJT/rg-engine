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

        bool _encendida; //¿Está la tele encendida?

        Group3D *puerta;

        bool _cerrada;

        bool _hab_der;

        bool _pers1_cerr;

        Box3D *pala1_izq;
        Box3D *pala2_izq;
        Box3D *pala3_izq;
        Box3D *pala4_izq;

        bool _pers2_cerr;

        Box3D *pala21_izq;
        Box3D *pala22_izq;
        Box3D *pala23_izq;
        Box3D *pala24_izq;
};



#endif
 