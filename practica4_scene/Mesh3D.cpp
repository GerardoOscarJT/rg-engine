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


void Mesh3D::RecalculateNormals() {
        // TODO: completar
}


void Mesh3D::Repaint() {
        // TODO: completar esto


        list<Face3D*>::iterator it;
        Face3D *face;

        for (it=faces->begin(); it != faces->end(); it++) {
                face = *it;

                glBegin(GL_POLYGON);
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


String Mesh3D::getName() {
        return "Mesh3D";
}

