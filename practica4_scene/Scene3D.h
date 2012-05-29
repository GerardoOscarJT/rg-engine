#ifndef Scene3DH
#define Scene3DH

#include <list.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "ViewPort3D.h"
#include "Group3D.h";

#include "Cylinder3D.h"

#include "Epitrochoid3D.h"

#include "Box3D.h"
#include "Light3D.h"


class Scene3D {
public:
        Scene3D();
        ~Scene3D();

        void Repaint();

        list<Camera3D*> *cameras;
        list<ViewPort3D*> *viewports;

        Group3D * main_figure;

        void DrawAxis();

        void color(int scX, int scY, GLint *color);

        bool lighting_enabled;
        bool materialing_enabled;

        // FOG:
        bool fog_enabled;
        float fog_density;
        float fog_start;
        float fog_end;
        int fog_mode;



private:

        void RepaintViewPort(ViewPort3D*);

};



#endif
