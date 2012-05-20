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


}

void Group3D::Repaint() {
        glPushMatrix();

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
                bool status = figure->selected;
                figure->selected |= selected;
                figure->Repaint();

                figure->selected = status;
        }

        glPopMatrix();
}



String Group3D::getName() {
        return "Group";
}
