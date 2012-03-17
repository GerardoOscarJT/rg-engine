#include <vcl.h>
#pragma hdrstop
#include "Scene3D.h"
#pragma package(smart_init)



Scene3D::Scene3D() {
        cameras = new list<Camera3D*>();
        viewports = new list<ViewPort3D*>();

        main_figure = new Group3D();

        // TODO: Quitar stubs:
        _epi = new Epitrochoid3D();
        _cylinder = new Cylinder3D(150,30,30, true, false);
        _cylinder->RecalculateMesh();



        Group3D *rueda = new Group3D(); // Rueda completa (goma + tapacubos)
                Cylinder3D * goma = new Cylinder3D(1, 3, 3, true, true);
                        goma->human_name = "Goma";
                        goma->color = new Color3D(.2, .2, .2);
                        goma->RecalculateMesh();
                rueda->elements->push_back(goma);

                Cylinder3D * tapacubos = new Cylinder3D(0.2, 2, 2, true, true);
                        tapacubos->human_name = "Tapacubos";
                        tapacubos->color = new Color3D(1, .8, .8);
                        tapacubos->RecalculateMesh();
                        tapacubos->translation->z = 1;
                rueda->elements->push_back(tapacubos);

        Group3D* grupo1 = new Group3D(); // coche
                grupo1->rotation->z = 20;
                grupo1->color = new Color3D(0.8,0.2,0.2);
                Group3D* grupo2 = new Group3D(); // grupo caja
                        Box3D* box1 = new Box3D(); // Chasis
                                box1->human_name = "Chasis";
                                box1->x = 10;
                                box1->y = 28;
                                box1->z = 5;
                                box1->translation->y = -14;
                                box1->translation->x = -5;
                                box1->translation->z = 1;
                                box1->RecalculateMesh();
                        grupo2->elements->push_back(box1);
                        Box3D* box2 = new Box3D(); // Ventanas
                                box2->human_name = "Ventanas";
                                box2->x = 8;
                                box2->y = 12;
                                box2->z = 3;
                                box2->translation->y = -8;
                                box2->translation->x = -4;
                                box2->translation->z = 6;
                                box2->RecalculateMesh();
                        grupo2->elements->push_back(box2);
                grupo1->elements->push_back(grupo2);

                Group3D* grupo3 = new Group3D(); // Grupo rueda delantera (izq)
                Group3D* grupo4 = new Group3D(); // Grupo rueda delantera (der)
                Group3D* grupo5 = new Group3D(); // Grupo rueda trasera (izq)
                Group3D* grupo6 = new Group3D(); // Grupo rueda trasera (der)





                        grupo3->elements->push_back(rueda);
                                grupo3->translation->x = -5.1;
                                grupo3->translation->y = 9;
                                grupo3->translation->z = 2;
                                grupo3->rotation->y = -90;
                        grupo4->elements->push_back(rueda);
                                grupo4->translation->x = 5.1;
                                grupo4->translation->y = 9;
                                grupo4->translation->z = 2;
                                grupo4->rotation->y = 90;
                        grupo5->elements->push_back(rueda);
                                grupo5->translation->x = -5.1;
                                grupo5->translation->y = -8;
                                grupo5->translation->z = 2;
                                grupo5->rotation->y = -90;
                        grupo6->elements->push_back(rueda);
                                grupo6->translation->x = 5.1;
                                grupo6->translation->y = -8;
                                grupo6->translation->z = 2;
                                grupo6->rotation->y = 90;
                grupo1->elements->push_back(grupo3);
                grupo1->elements->push_back(grupo4);
                grupo1->elements->push_back(grupo5);
                grupo1->elements->push_back(grupo6);




        main_figure->elements->push_back(_epi);
        main_figure->elements->push_back(grupo1);



}

Scene3D::~Scene3D() {

        delete main_figure;

        // TODO: Eliminar también el contenido de las listas
        // (primero viewports y después cámaras):

        list<ViewPort3D*>::iterator it_vp;
        for (it_vp = viewports->begin(); it_vp != viewports->end(); it_vp++)
                delete *it_vp;

        delete viewports;


        list<Camera3D*>::iterator it_c;
        for (it_c = cameras->begin(); it_c != cameras->end(); it_c++)
                delete *it_c;

        delete cameras;

        delete _epi; // TODO: Es un STUB
        delete _cylinder;
}

void Scene3D::Repaint() {
        list<ViewPort3D*>::iterator it;
        ViewPort3D * vp;
        for (it = viewports->begin(); it != viewports->end(); it++) {
                vp = *it;
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
