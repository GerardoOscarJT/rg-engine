#include <vcl.h>
#pragma hdrstop
#include "Group3D.h"
#pragma package(smart_init)




Group3D::Group3D() : Figure3D() {
        elements = new list<Figure3D*>();
        color = NULL;
}


Group3D::~Group3D() {
        delete elements;
        if (color != NULL)
                delete color;
        //Figure3D* f3d;

        /*if(elements->size() > 0) {
                list<Figure3D*>::iterator it_lf;
                Figure3D* f3d;

                for(it_lf = elements->begin(); it_lf != elements->end(); it_lf++) {
                        f3d = *it_lf;
                        delete f3d;
                }
        }

        delete figures;*/

}

/*
void Group3D::addFigure(Figure3D *&f) {
        figures->push_back(f);
}
*/

void Group3D::Repaint() {
        glPushMatrix();
        //list<Figure3D*>::iterator it_lf;
        //Figure3D* f3d;
        /*for(it_lf = figures->begin(); it_lf != figures->end(); it_lf++) {
                f3d = *it_lf;
                f3d->Repaint();
        }*/

        glTranslated(translation->x, translation->y, translation->z);

        glRotated(rotation->x, 1,0,0);
        glRotated(rotation->y, 0,1,0);
        glRotated(rotation->z, 0,0,1);

        glScaled(scale->x, scale->y, scale->z);


        if (color != NULL)
                glColor3f(color->r, color->g, color->b);

        list<Figure3D*>::iterator it;
        Figure3D* figure;

        for (it = elements->begin(); it != elements->end(); it++) {
                figure = *it;
                figure->Repaint();
        }

        glPopMatrix();
}


/**


void Mesh3D::Repaint() {
        // TODO: completar esto






        list<Face3D*>::iterator it;
        Face3D *face;

        for (it=faces->begin(); it != faces->end(); it++) {
                face = *it;
                glBegin(GL_POLYGON);
                //glBegin(GL_LINE_LOOP);
                glColor3f(0,1,1);
                list<Vertex3D*>::iterator itp;
                Vertex3D *vertex;
                for (itp = face->vertices->begin(); itp != face->vertices->end(); itp++) {
                        vertex = *itp;
                        glNormal3f(face->normal->x, face->normal->y, face->normal->z);
                        glVertex3f(vertex->x, vertex->y, vertex->z);

                }
                glEnd();
        }




}
*/



String Group3D::getName() {
        return "Group";
}
