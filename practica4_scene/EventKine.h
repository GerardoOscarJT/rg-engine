
#ifndef EventKineH
#define EventKineH

#include "Event.h"
#include "Sphere3D.h"
#include "Flat3D.h"
#include "Light3D.h"


class EventKine:public Event {

public:

        EventKine();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift, int X, int Y);
        void top(ViewPort3D *_viewport, Scene3D *_scene);
        String getName();


private:
        Group3D *_kine;
        Group3D *_kine_body;

        void Step();
        void buildKine();
        Group3D * buildFloor();

        Light3D *_light_main;


        double kine_position_velocity;
        double kine_position_acceleration;
        double kine_rotation_velocity;
        double kine_rotation_acceleration;


        double acceleration_coeficient;
        double decceleration_coeficient;
        double breaking_coeficient;
        double acceleration_max;
        double acceleration_min;

        int key_accelerate;
        int key_break;
        int key_left;
        int key_right;

        Camera3D *cam_back;
        Camera3D *cam_top;

        ViewPort3D *_last_viewport;
};


#endif
 