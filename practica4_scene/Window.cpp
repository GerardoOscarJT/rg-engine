#include <vcl.h>
#pragma hdrstop
#include "Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


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
        cam3->eye->y = 0.1;
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


        // ESCENA 1 (coche + epitrocoide) //////////////////////////////////////
        _epicar = new EpiCar3D();
        _glass = new Glass3D();

        //_cyl = new Cylinder3D(150, 30, 30, true, true);
        //_cyl->RecalculateMesh();
        //_scene->main_figure->elements->push_back(_cyl);


        // Meto el epicar en la escena principal y recargo el panel de estructura
                /*
                _scene->main_figure->elements->clear();
                _scene->main_figure->elements->push_back(_epicar);
                _scene->Repaint();*/



                _scene->main_figure->elements->clear();
                _scene->main_figure->elements->push_back(_glass);
                _glass->RecalculateMesh();
                _scene->Repaint();
                


                //_glass->Repaint();

                Structure->Items->Clear();
                LoadStructure(_scene->main_figure, NULL);




        _scene->Repaint();
        _last_viewport = _vp4;
        Shape4->Pen->Color = clLime;

        RecalculateGUI();
}

void __fastcall TForm1::FormDestroy(TObject *Sender) {
        delete _scene;
        _scene = NULL;
}

void __fastcall TForm1::Button3Click(TObject *Sender) {
        if (_scene != NULL)
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



        if (Key == 65) {
                Structure->Items->Clear();
                LoadStructure(_scene->main_figure, NULL);
        }

        if (Key == 90) {
                // Girar coche a la izquierda

                if (Shift.Contains(ssShift)) {
                        _epicar->setTime(_epicar->getTime()-0.002);
                } else if (Shift.Contains(ssCtrl)) {
                        _epicar->setTime(_epicar->getTime()-0.2);
                } else {
                        _epicar->setTime(_epicar->getTime()-0.02);
                }

                /*
                _vp4->camera->look->x = _epicar->car->translation->x;
                _vp4->camera->look->y = _epicar->car->translation->y;
                _vp4->camera->look->z = _epicar->car->translation->z;
                */

                _scene->Repaint();
        } else if (Key == 88) {
                // Girar coche a la derecha
                if (Shift.Contains(ssShift)) {
                        _epicar->setTime(_epicar->getTime()+0.002);
                } else if (Shift.Contains(ssCtrl)) {
                        _epicar->setTime(_epicar->getTime()+0.2);
                } else {
                        _epicar->setTime(_epicar->getTime()+0.02);
                }

                /*
                _vp4->camera->look->x = _epicar->car->translation->x;
                _vp4->camera->look->y = _epicar->car->translation->y;
                _vp4->camera->look->z = _epicar->car->translation->z;
                */

                _scene->Repaint();
        }

        if (Key == 67) {
                _scene->main_figure->elements->clear();
                _scene->main_figure->elements->push_back(_epicar);
                _scene->Repaint();
        }

        if(Key == 74 || Key == 106) {
                _epicar->epi->showNormals = true;
                _scene->Repaint();
        }

        if(Key == 75 || Key == 107) {
                _epicar->epi->showNormals = false;
                _scene->Repaint();
        }

        if(Key == 71 || Key == 103) {
                _epicar->epi->filled = false;
                _glass->filled = false;
                _scene->Repaint();
        }

        if(Key == 72 || Key == 104) {
                _epicar->epi->filled = true;
                _glass->filled = true;
                _scene->Repaint();
        }

}

void __fastcall TForm1::FormPaint(TObject *Sender) {
        if (_scene != NULL)
                _scene->Repaint();
}

void __fastcall TForm1::FormResize(TObject *Sender) {
        RecalculateGUI();
        if (_scene != NULL)
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

        Shape1->Pen->Color = clGreen;
        Shape2->Pen->Color = clGreen;
        Shape3->Pen->Color = clGreen;
        Shape4->Pen->Color = clGreen;

        Shape1->Pen->Color = clLime;

        _last_viewport = _vp1;
}

void __fastcall TForm1::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {

        Shape1->Pen->Color = clGreen;
        Shape2->Pen->Color = clGreen;
        Shape3->Pen->Color = clGreen;
        Shape4->Pen->Color = clGreen;

        Shape2->Pen->Color = clLime;

        _last_viewport = _vp2;
}

void __fastcall TForm1::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {

        Shape1->Pen->Color = clGreen;
        Shape2->Pen->Color = clGreen;
        Shape3->Pen->Color = clGreen;
        Shape4->Pen->Color = clGreen;

        Shape3->Pen->Color = clLime;

        _last_viewport = _vp3;
}

void __fastcall TForm1::Panel4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y) {

        Shape1->Pen->Color = clGreen;
        Shape2->Pen->Color = clGreen;
        Shape3->Pen->Color = clGreen;
        Shape4->Pen->Color = clGreen;

        Shape4->Pen->Color = clLime;

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

void __fastcall TForm1::LoadStructure(Figure3D *figure, TTreeNode* node) {

        TTreeNode *new_node = Structure->Items->AddChild(node, figure->human_name + " [" + figure->getName() + "]");

        if (figure->getName() == "Group") {
                Group3D * G = dynamic_cast<Group3D*>(figure);

                list<Figure3D*>::iterator it;
                Figure3D *F;
                for (it = G->elements->begin(); it != G->elements->end(); it++) {
                        F = *it;
                        LoadStructure(F, new_node);
                }
        }
}

void __fastcall TForm1::RecalculateGUI() {

        int margin = 2; //px

        MainPanel->Top = 0;
        MainPanel->Left = 0;
        MainPanel->Width = Form1->ClientWidth;
        MainPanel->Height = Form1->ClientHeight;

        if (ToolBar->Visible) {
                MainPanel->Top = ToolBar->Height;
                MainPanel->Height -= ToolBar->Height;
        }

        if (StatusBar->Visible)
                MainPanel->Height -= StatusBar->Height;

        // Paneles interiores
        RightPanel->Width = 300;
        RightPanel->Top = 0;
        RightPanel->Height = MainPanel->ClientHeight;
        RightPanel->Left = MainPanel->ClientWidth - RightPanel->Width;

        LeftPanel->Top = margin;
        LeftPanel->Left = margin;
        LeftPanel->Height = MainPanel->ClientHeight -  2*margin;
        LeftPanel->Width = MainPanel->ClientWidth - RightPanel->Width - 2*margin;

        // Viewports

        int left = 300;

        Shape1->Top = 0 + margin;
        Shape1->Left = 0 + margin;
        Shape1->Width = left - 2*margin;
        Shape1->Height = LeftPanel->ClientHeight/3 - 2*margin;

        Shape2->Top = LeftPanel->ClientHeight/3 + margin;
        Shape2->Left = 0 + margin;
        Shape2->Width = left - 2*margin;
        Shape2->Height = LeftPanel->ClientHeight/3 - 2*margin;

        Shape3->Top = LeftPanel->ClientHeight*2/3 + margin;
        Shape3->Left = 0 + margin;
        Shape3->Width = left - 2*margin;
        Shape3->Height = LeftPanel->ClientHeight/3 - 2*margin;

        Shape4->Top = LeftPanel->ClientHeight/3 + margin;
        Shape4->Left = left + margin;
        Shape4->Width = LeftPanel->ClientWidth - left - 2*margin ;
        Shape4->Height = LeftPanel->ClientHeight*2/3 - 2*margin;


        Panel1->Left = Shape1->Left + 1;
        Panel1->Top = Shape1->Top + 1;
        Panel1->Width = Shape1->Width - 2;
        Panel1->Height = Shape1->Height - 2;

        Panel2->Left = Shape2->Left + 1;
        Panel2->Top = Shape2->Top + 1;
        Panel2->Width = Shape2->Width - 2;
        Panel2->Height = Shape2->Height - 2;

        Panel3->Left = Shape3->Left + 1;
        Panel3->Top = Shape3->Top + 1;
        Panel3->Width = Shape3->Width - 2;
        Panel3->Height = Shape3->Height - 2;

        Panel4->Left = Shape4->Left + 1;
        Panel4->Top = Shape4->Top + 1;
        Panel4->Width = Shape4->Width - 2;
        Panel4->Height = Shape4->Height - 2;






}








void __fastcall TForm1::Copa1Click(TObject *Sender)
{
        _showGlass = true;        
}
//---------------------------------------------------------------------------

