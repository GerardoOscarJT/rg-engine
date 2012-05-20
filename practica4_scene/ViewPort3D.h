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


        Camera3D* getCamera();
        void setCamera(Camera3D* cam);
        void RecalculateViewport();
        void swapBuffers();


        void findCoordinates(int scX, int scY, GLint *colores);
private:
        HDC _hdc;
        HGLRC _hrc;
        int *_width;
        int *_height;
        Camera3D* _camera;

        void view();
        void projection();
};


#endif
 