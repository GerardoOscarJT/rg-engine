#include <vcl.h>
#pragma hdrstop

#include "Light3D.h"
#pragma package(smart_init)




Light3D::Light3D() {
        _gl_index = -1;
        diffuse = new Color3D(0.7,0.7,0.7);
        specular = new Color3D(0.7,0.7,0.7);
        ambient = new Color3D(0.7,0.7,0.7);
}

void Light3D::initializeLights() {
        for (int i=0; i<8; i++) {
                lights[i] = NULL;
        }
}


void Light3D::Enable() {

        // Busco si esta luz no está en la lista de luces
        Light3D* busca=NULL;
        for (int i=0; i<8; i++) {
                if (lights[i] == this)
                        busca = this;
        }

        // Si la luz no está en la lista, la inserto (si hay hueco)
        if (busca == NULL)
                for (int i=0; i<8; i++)
                        if (lights[i] == NULL) {
                                lights[i] = this;
                                this->_gl_index = i;
                                break;
                        }

}

void Light3D::Disable() {
        // Elimino esta luz de la lista de luces
        for (int i=0; i<8; i++)
                if (lights[i] == this)
                        lights[i] = NULL;

        int GL_LIGHT=GL_LIGHT0;
        switch (_gl_index) {
                case 1: GL_LIGHT = GL_LIGHT1; break;
                case 2: GL_LIGHT = GL_LIGHT2; break;
                case 3: GL_LIGHT = GL_LIGHT3; break;
                case 4: GL_LIGHT = GL_LIGHT4; break;
                case 5: GL_LIGHT = GL_LIGHT5; break;
                case 6: GL_LIGHT = GL_LIGHT6; break;
                case 7: GL_LIGHT = GL_LIGHT7; break;
        }
        glDisable(GL_LIGHT);

        this->_gl_index = -1;
}

bool Light3D::isEnabled() {
        return _gl_index>-1 && _gl_index<8;
}

void Light3D::Repaint() {

        if (isEnabled()) {
                int GL_LIGHT=GL_LIGHT0;
                switch (_gl_index) {
                        case 1: GL_LIGHT = GL_LIGHT1; break;
                        case 2: GL_LIGHT = GL_LIGHT2; break;
                        case 3: GL_LIGHT = GL_LIGHT3; break;
                        case 4: GL_LIGHT = GL_LIGHT4; break;
                        case 5: GL_LIGHT = GL_LIGHT5; break;
                        case 6: GL_LIGHT = GL_LIGHT6; break;
                        case 7: GL_LIGHT = GL_LIGHT7; break;
                }

                glEnable(GL_LIGHT);


                GLfloat p[] = {this->translation->x, this->translation->y, this->translation->z, 1};
                GLfloat sd[] = {0,0,-1, 0};


                GLfloat d[] = {diffuse->r, diffuse->g, diffuse->b, 1};
                GLfloat s[] = {specular->r, specular->g, specular->b, 1};
                GLfloat a[] = {ambient->r, ambient->g, ambient->b, 1};

                glLightfv(GL_LIGHT, GL_POSITION, p);

                glLightfv(GL_LIGHT, GL_DIFFUSE, d);
                glLightfv(GL_LIGHT, GL_SPECULAR, s);
                glLightfv(GL_LIGHT, GL_AMBIENT, a);

                glLightf(GL_LIGHT, GL_CONSTANT_ATTENUATION, 1);
                //glLightf(GL_LIGHT, GL_LINEAR_ATTENUATION, 1);


                // Para cono:
                glLightf(GL_LIGHT, GL_SPOT_CUTOFF, 60);
                glLightf(GL_LIGHT, GL_SPOT_EXPONENT, 32);
                glLightfv(GL_LIGHT, GL_SPOT_DIRECTION, sd);
        }
}


String Light3D::getName() {
        return "Light";
}

