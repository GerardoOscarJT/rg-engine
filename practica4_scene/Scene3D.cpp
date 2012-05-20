#include <vcl.h>
#pragma hdrstop
#include "Scene3D.h"
#pragma package(smart_init)



Scene3D::Scene3D() {
        cameras = new list<Camera3D*>();
        viewports = new list<ViewPort3D*>();

        main_figure = new Group3D();
        main_figure->human_name = "Escena principal";

        // TODO: Quitar stubs:
}

Scene3D::~Scene3D() {

        delete main_figure;

        // TODO: Eliminar tambi�n el contenido de las listas
        // (primero viewports y despu�s c�maras):

        list<ViewPort3D*>::iterator it_vp;
        for (it_vp = viewports->begin(); it_vp != viewports->end(); it_vp++)
                delete *it_vp;

        delete viewports;


        list<Camera3D*>::iterator it_c;
        for (it_c = cameras->begin(); it_c != cameras->end(); it_c++)
                delete *it_c;

        delete cameras;
}

void Scene3D::Repaint() {

        list<ViewPort3D*>::iterator it;
        ViewPort3D * vp;
        for (it = viewports->begin(); it != viewports->end(); it++) {
                vp = *it;
                if (vp->getCamera() != NULL)
                        RepaintViewPort(vp);
        }
}

void Scene3D::RepaintViewPort(ViewPort3D* vp) {
        vp->makeCurrent();
        vp->RecalculateViewport();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glClearColor(0.6,0.7,0.8,1.0);

        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        //Luz0
        glEnable(GL_LIGHT0);
        GLfloat LuzDifusa[]={1.0,1.0,1.0,1.0};
        glLightfv(GL_LIGHT0,GL_DIFFUSE,LuzDifusa);
        GLfloat LuzAmbiente[]={0.3,0.3,0.3,1.0};
        glLightfv(GL_LIGHT0,GL_AMBIENT,LuzAmbiente);
        PosicionLuz0[0]=25.0; PosicionLuz0[1]=25.0;
        PosicionLuz0[2]=0.0; PosicionLuz0[3]=1.0;
        glLightfv(GL_LIGHT0, GL_POSITION, PosicionLuz0);

        glEnable(GL_COLOR_MATERIAL);
        glMaterialf(GL_FRONT, GL_SHININESS, 0.1);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_NORMALIZE);
        glShadeModel(GL_SMOOTH);   //Defecto

        glLightfv(GL_LIGHT0,GL_POSITION,PosicionLuz0);

        DrawAxis();

        main_figure->Repaint();

        glFlush();

        vp->swapBuffers();
}


void Scene3D::DrawAxis() {
        glBegin(GL_LINES);
                glColor3f(1,0,0);
                glVertex3f(0,0,0);
                glVertex3f(2000,0,0);

                glColor3f(0,1,0);
                glVertex3f(0,0,0);
                glVertex3f(0,2000,0);

                glColor3f(0,0,1);
                glVertex3f(0,0,0);
                glVertex3f(0,0,2000);

                glColor3f(0.4,0,0);
                glVertex3f(0,0,0);
                glVertex3f(-2000,0,0);

                glColor3f(0,0.4,0);
                glVertex3f(0,0,0);
                glVertex3f(0,-2000,0);

                glColor3f(0,0,0.4);
                glVertex3f(0,0,0);
                glVertex3f(0,0,-2000);

        glEnd();

}

void Scene3D::color(int scX, int scY, GLint *colores) {

        GLint coords[4];
        glGetIntegerv(GL_VIEWPORT, coords);

        GLdouble mv[16];
        glGetDoublev(GL_MODELVIEW_MATRIX, mv);

        GLdouble pro[16];
        glGetDoublev(GL_PROJECTION_MATRIX, pro);

        int glY = coords[3] - scY;

        /*glReadBuffer(GL_FRONT);
        glReadPixels(scX, glY, 1, 1, GL_RGB, GL_INT, colores);*/

        GLint pick_col[3];
        glReadPixels(scX , glY , 3 , 3 , GL_RGB , GL_INT , pick_col);
        
}

