#ifndef Light3DH
#define Light3DH

#include <gl\gl.h>
#include <gl\glu.h>

#include "Figure3D.h";
#include "Color3D.h"

class Light3D:public Figure3D {
public:
        Light3D();

        void Enable();
        void Disable();
        bool isEnabled();

        Color3D *diffuse;
        Color3D *specular;
        Color3D *ambient;

        void Repaint();
        String getName();


        static void initializeLights();

        static Light3D* lights[8];
private:
        bool _enabled;
        int _gl_index;
};

Light3D* Light3D::lights[8];

#endif
 