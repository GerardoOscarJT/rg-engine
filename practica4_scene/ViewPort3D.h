#ifndef ViewPort3DH
#define ViewPort3DH

#include <gl\gl.h>
#include <gl\glu.h>
#include "Camera3D.h"


class ViewPort3D {
public:
        ViewPort3D(void * hWnd, int& width, int& height);
        ~ViewPort3D();
        void makeCurrent();


        void RecalculateViewport();

        void swapBuffers();

        Camera3D* camera;

private:
        HDC _hdc;
        HGLRC _hrc;
        int *_width;
        int *_height;
};


#endif
 