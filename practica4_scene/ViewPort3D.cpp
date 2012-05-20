#include <vcl.h>
#pragma hdrstop
#include "ViewPort3D.h"
#pragma package(smart_init)

ViewPort3D::ViewPort3D(void * hWnd, int& width, int& height) {
        _hdc = GetDC(hWnd);
        _width = &width;
        _height = &height;
        _camera = NULL;

        PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),
                1,
                PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
                PFD_TYPE_RGBA,
                32,
                0,0,0,0,0,0,
                0,0,
                0,0,0,0,0,
                32,
                0,
                0,
                PFD_MAIN_PLANE,
                0,
                0,0,0
        };

        pfd.iLayerType = PFD_MAIN_PLANE;

        SetPixelFormat(_hdc, ChoosePixelFormat(_hdc, &pfd), &pfd);        
        _hrc = wglCreateContext(_hdc);

}


Camera3D* ViewPort3D::getCamera() {
        return _camera;
}

void ViewPort3D::setCamera(Camera3D* cam) {
        _camera = cam;
        if (cam != NULL)
                _camera->inicializa(*_width, *_height);
}

void ViewPort3D::makeCurrent() {
        glEnable(GL_DEPTH_TEST);

        glEnable(GL_FRONT_AND_BACK);


        if(wglMakeCurrent(_hdc, _hrc) == false)
                ShowMessage("Could not make ViewPort3D current :·(");        //glClearColor(0.0f, 0.001f, 0.0f, 1.0f);        glClearColor(0.0, 0.01, 0.0, 1.0);                       }

ViewPort3D::~ViewPort3D() {
        wglDeleteContext(_hdc);
}

void ViewPort3D::swapBuffers(){
        SwapBuffers(_hdc);
}

void ViewPort3D::RecalculateViewport() {
        _camera->recalculateCamera(*_width, *_height);        // Puerto de vista        glViewport(0, 0, *_width, *_height);
}

void ViewPort3D::findCoordinates(int scX, int scY, GLint *colores) {

        GLint coords[4];
        glGetIntegerv(GL_VIEWPORT, coords);

        int glY = coords[3] - scY;

        glReadBuffer(GL_FRONT);
        glReadPixels(scX , glY , 1 , 1 , GL_RGB , GL_FLOAT , colores);

}


