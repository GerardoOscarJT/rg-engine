#ifndef Scene3DH
#define Scene3DH

#include <list.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "ViewPort3D.h"

#include "Epitrochoid.h"
#include "Box3D.h"


class Scene3D {
public:
        Scene3D();
        ~Scene3D();

        void Repaint();

        list<Camera3D*> *cameras;
        list<ViewPort3D*> *viewports;

        void DrawAxis();
private:

        void RepaintViewPort(ViewPort3D*);
        //Epitrochoid _ep;

        Box3D *_box;

};



#endif
