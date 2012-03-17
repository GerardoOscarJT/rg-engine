#include <vcl.h>
#pragma hdrstop
#include "Mesh3D.h"
#pragma package(smart_init)


Mesh3D::Mesh3D() {
        color = NULL;
        mode = 2;
        vertices = new list<Vertex3D*>();
        faces = new list<Face3D*>();
}

Mesh3D::~Mesh3D() {
        if (color != NULL)
                delete color;

        clearLists();
        delete faces;
        delete vertices;
}

void Mesh3D::clearLists() {
        // Borramos faces
        list<Face3D*>::iterator it_face;
        Face3D *face;
        for (it_face = faces->begin(); it_face != faces->end(); it_face++) {
                face = *it_face;
                delete face;
        }

        // Borramos vertices
        list<Vertex3D*>::iterator it_vertex;
        Vertex3D *vertex;
        for (it_vertex = vertices->begin(); it_vertex != vertices->end(); it_vertex++) {
                vertex = *it_vertex;
                delete vertex;
        }
        delete faces;
        delete vertices;

        vertices = new list<Vertex3D*>();
        faces = new list<Face3D*>();
}


void Mesh3D::RecalculateNormals(Face3D &f) {
        // TODO: completar
        int nx = 0, ny = 0, nz = 0; //Componentes del vector normal

        list<Vertex3D*>::iterator it;
        Vertex3D* v3d, *suc_v3d;
        //for(int j = 0; j < 3; j++) {  //3 debería ser el número de vértices - 1 de la cara
        for(it = f.vertices->begin(); it != f.vertices->end(); it++) {
                v3d = *it;
                if(++it != f.vertices->end()) {
                        suc_v3d = *(it); //Le doy el siguiente
                        it--; //Pero una vez lo tengo, vuelvo a dejar donde estaba
                }
                else {
                        it--;
                        suc_v3d = *(f.vertices->begin());
                }
                nx += (v3d->y - suc_v3d->y)*(v3d->z + suc_v3d->z);
                ny += (v3d->z - suc_v3d->z)*(v3d->x + suc_v3d->x);
                nz += (v3d->x - suc_v3d->x)*(v3d->y + suc_v3d->y);
        }

        f.normal->x = nx;
        f.normal->y = ny;
        f.normal->z = nz;
        f.normal->normalize();

}


void Mesh3D::Repaint() {
        // TODO: completar esto


        glPushMatrix();

        glTranslated(translation->x, translation->y, translation->z);

        glRotated(rotation->x, 1,0,0);
        glRotated(rotation->y, 0,1,0);
        glRotated(rotation->z, 0,0,1);




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


        glPopMatrix();

}


String Mesh3D::getName() {
        return "Mesh3D";
}

