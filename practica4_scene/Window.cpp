//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm1::FormCreate(TObject *Sender) {

        _last_viewport = NULL;
        _scene = new Scene3D();

        // Agregamos 4 vistas básicas de cámara:
        Camera3D * cam1 = new Camera3D();
        cam1->name = "Alzado";
        cam1->eye->x = 0;
        cam1->eye->y = 100;
        cam1->eye->z = 0;
        _scene->cameras->push_back(cam1);

        Camera3D * cam2 = new Camera3D();
        cam2->name = "Perfil";
        cam2->eye->x = 100;
        cam2->eye->y = 0;
        cam2->eye->z = 0;
        _scene->cameras->push_back(cam2);

        Camera3D * cam3 = new Camera3D();
        cam3->name = "Planta";
        cam3->eye->x = 0;
        cam3->eye->y = 0;
        cam3->eye->z = 100;
        _scene->cameras->push_back(cam3);

        Camera3D * cam4 = new Camera3D();
        cam4->name = "Perspectiva";
        cam4->eye->x = 300;
        cam4->eye->y = 400;
        cam4->eye->z = 300;
        cam4->perspective = true;
        _scene->cameras->push_back(cam4);

        // Agrego 4 puertos de vista vinculados con los 4 paneles

        _vp1 = new ViewPort3D(Panel1->Handle, Panel1->Width, Panel1->Height);
        _vp1->camera = cam1;
        _scene->viewports->push_back(_vp1);

        _vp2 = new ViewPort3D(Panel2->Handle, Panel2->Width, Panel2->Height);
        _vp2->camera = cam2;
        _scene->viewports->push_back(_vp2);

        _vp3 = new ViewPort3D(Panel3->Handle, Panel3->Width, Panel3->Height);
        _vp3->camera = cam3;
        _scene->viewports->push_back(_vp3);

        _vp4 = new ViewPort3D(Panel4->Handle, Panel4->Width, Panel4->Height);
        _vp4->camera = cam4;
        _scene->viewports->push_back(_vp4);


        _scene->Repaint();
        _last_viewport = _vp4;

}

void __fastcall TForm1::FormDestroy(TObject *Sender) {
        delete _scene;
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
        _scene->Repaint();
}
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift) {

        if (_last_viewport != NULL) {
                                PV3D look_eye(
                                        _last_viewport->camera->eye->x - _last_viewport->camera->look->x,
                                        _last_viewport->camera->eye->y - _last_viewport->camera->look->y,
                                        _last_viewport->camera->eye->z - _last_viewport->camera->look->z,
                                        0
                                );
                                double module_xy = sqrt(pow(_last_viewport->camera->eye->x,2)+pow(_last_viewport->camera->eye->y,2));
                                //double module = look_eye.len();
                                double angle = atan2l(
                                        look_eye.x,
                                        look_eye.y
                                );
                                Caption = AnsiString(Key);

                switch (Key) {
                        case 37:
                                angle -= 0.1;

                                _last_viewport->camera->eye->x = module_xy*sin(angle);
                                _last_viewport->camera->eye->y = module_xy*cos(angle);
                                break;
                        case 39:
                                angle += 0.1;
                                _last_viewport->camera->eye->x = module_xy*sin(angle);
                                _last_viewport->camera->eye->y = module_xy*cos(angle);
                                break;
                        case 38:
                                _last_viewport->camera->eye->z += 10;
                                break;
                        case 40:
                                _last_viewport->camera->eye->z -= 10;
                                break;

                        case 187: // mas
                                _last_viewport->camera->eye->x /= 1.02;
                                _last_viewport->camera->eye->y /= 1.02;
                                _last_viewport->camera->eye->z /= 1.02;
                                break;
                        case 189: // menos
                                _last_viewport->camera->eye->x *= 1.02;
                                _last_viewport->camera->eye->y *= 1.02;
                                _last_viewport->camera->eye->z *= 1.02;
                                break;

                }
                _scene->Repaint();
        }
}void __fastcall TForm1::FormPaint(TObject *Sender) {
        _scene->Repaint();
}

void __fastcall TForm1::FormResize(TObject *Sender) {
        _scene->Repaint();
}

void __fastcall TForm1::PopupMenu1Popup(TObject *Sender) {
        Camaras1->Clear();

        list<Camera3D*>::iterator it;
        Camera3D *cam;
        for (it = _scene->cameras->begin();it != _scene->cameras->end(); it++) {
                TMenuItem * tmi = new TMenuItem(NULL);
                tmi->Caption = cam->name;
                Camaras1->Insert(0, tmi);
        }
}

void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y){
        _last_viewport = _vp1;
}

void __fastcall TForm1::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {
        _last_viewport = _vp2;
}

void __fastcall TForm1::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {
        _last_viewport = _vp3;
}

void __fastcall TForm1::Panel4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {
        _last_viewport = _vp4;
}

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled) {
      _last_viewport->camera->eye->x *= 1.08;
      _last_viewport->camera->eye->y *= 1.08;
      _last_viewport->camera->eye->z *= 1.08;
      _scene->Repaint();
}

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled) {
        _last_viewport->camera->eye->x /= 1.08;
        _last_viewport->camera->eye->y /= 1.08;
        _last_viewport->camera->eye->z /= 1.08;
        _scene->Repaint();
}

