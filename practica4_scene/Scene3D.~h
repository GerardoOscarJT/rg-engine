#ifndef Scene3DH
#define Scene3DH

#include <list.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include "ViewPort3D.h"


#include "Cylinder3D.h"

#include "Epitrochoid3D.h"

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
        GLfloat PosicionLuz0[4];

        Box3D *_box;
        Cylinder3D* _cylinder;


        Epitrochoid3D * _epi;



};



#endif
