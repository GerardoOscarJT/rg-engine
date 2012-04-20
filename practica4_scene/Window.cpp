#include <vcl.h>
#pragma hdrstop
#include "Window.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
void __fastcall TForm1::FormCreate(TObject *Sender) {


        _selected_figure = NULL;
        _selected_epitrochoid = NULL;
        _selected_box = NULL;  

        _last_viewport = NULL;
        _scene = new Scene3D();

        _editable_figures = new map<TTreeNode*, Figure3D*>() ;



        // Agregamos 4 vistas básicas de cámara:
        PV3D eye(0, 100, 0);
        PV3D look(0, 0, -1);
        PV3D up(0, 0, 1, 0);
        Camera3D * cam1 = new Camera3D(Panel1->Width, Panel1->Height, eye, look, up);
        cam1->name = "Alzado";
        /*cam1->eye->x = 0;
        cam1->eye->y = 100;
        cam1->eye->z = 0;*/
        _scene->cameras->push_back(cam1);

        eye.x=100;
        eye.y = 0;
        eye.z = 0; 
        Camera3D * cam2 = new Camera3D(Panel1->Width, Panel1->Height, eye, look, up);
        cam2->name = "Perfil";
        /*cam2->eye->x = 100;
        cam2->eye->y = 0;
        cam2->eye->z = 0;*/
        _scene->cameras->push_back(cam2);

        eye.x = 0;
        eye.y = 0.1;
        eye.z = 100;
        Camera3D * cam3 = new Camera3D(Panel1->Width, Panel1->Height, eye, look, up);
        cam3->name = "Planta";
        /*cam3->eye->x = 0;
        cam3->eye->y = 0.1;
        cam3->eye->z = 100;*/
        _scene->cameras->push_back(cam3);

        eye.x = 300;
        eye.y = 400;
        eye.z = 300;
        Camera3D * cam4 = new Camera3D(Panel1->Width, Panel1->Height, eye, look, up);
        cam4->name = "Perspectiva";
        /*cam4->eye->x = 300;
        cam4->eye->y = 400;
        cam4->eye->z = 300;*/
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


        // ESCENA 2 (copa) /////////////////////////////////////////////////////
        _copa = new Revolution3D();

        _copa->color = new Color3D(1,1,1);

        _copa->n = 64;
        //_copa->n = 2;

        _copa->points->push_back(new PV3D(0,0,8));
        _copa->points->push_back(new PV3D(0,0,8));
        _copa->points->push_back(new PV3D(0,0,8));
        _copa->points->push_back(new PV3D(50,0,0));
        _copa->points->push_back(new PV3D(50,0,2));
        _copa->points->push_back(new PV3D(4,0,10));
        _copa->points->push_back(new PV3D(4,0,100));
        _copa->points->push_back(new PV3D(4,0,100));
        _copa->points->push_back(new PV3D(100,0,200));
        _copa->points->push_back(new PV3D(99,0,201));
        _copa->points->push_back(new PV3D(98,0,200));
        _copa->points->push_back(new PV3D(0,0,102));
        _copa->points->push_back(new PV3D(0,0,102));

        _copa->RecalculateMesh();

        // recargo el panel de estructura
        Structure->Items->Clear();
        LoadStructure(_scene->main_figure, NULL);

        _scene->Repaint();
        _last_viewport = _vp4;
        Shape4->Pen->Color = clLime;

        WindowState = wsMaximized;

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
                                if(!Structure->Focused()) {
                                        angle -= 0.1;

                                        _last_viewport->camera->eye->x = module_xy*sin(angle);
                                        _last_viewport->camera->eye->y = module_xy*cos(angle);
                                }
                                break;
                        case 39:
                                if(!Structure->Focused()) {
                                        angle += 0.1;
                                        _last_viewport->camera->eye->x = module_xy*sin(angle);
                                        _last_viewport->camera->eye->y = module_xy*cos(angle);
                                }
                                break;
                        case 38:
                                if(!Structure->Focused()) {
                                        _last_viewport->camera->eye->z += 10;
                                }
                                break;
                        case 40:
                                if(!Structure->Focused()) {
                                        _last_viewport->camera->eye->z -= 10;
                                }
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
                        case 85:
                                _last_viewport->camera->roll(10);
                                break;
                        /*case 79: //o
                                _last_viewport->camera->perspective = 2;
                                _last_viewport->RecalculateViewport();
                                break;*/
                }
                _scene->Repaint();
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

        _editable_figures->insert(map<TTreeNode*, Figure3D*>::value_type(new_node, figure));        

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

void __fastcall TForm1::StructureClick(TObject *Sender){

        TTreeNode *sel = Structure->Selected;

        if (sel != NULL) {

        Structure->SetFocus();

        map<TTreeNode*, Figure3D*>::iterator it;

        it = _editable_figures->find(sel);

        AnsiString name = it->second->getName();

        _selected_figure = it->second;

        if (name == "Box") {
                // Montar paneles de caja, etc.
                Box3D *box = dynamic_cast<Box3D*>(it->second);
                _selected_box = box;
                //Hacemos visible el panel de la caja
                TrackBar8->Position = box->x;
                TrackBar14->Position = box->y;
                TrackBar15->Position = box->z;
                Panel10->Visible = true;
                GroupBox3->Visible = false;
                GroupBox4->Visible = true;
                GroupBox5->Visible = false;
        }
        else if(name == "Cylinder") {
                Cylinder3D *cylinder = dynamic_cast<Cylinder3D*>(it->second);
                _selected_cylinder = cylinder;
                TrackBar16->Position = cylinder->height;
                TrackBar17->Position = cylinder->rad_top;
                TrackBar18->Position = cylinder->rad_bottom;
                Panel10->Visible = true;
                GroupBox3->Visible = false;
                GroupBox4->Visible = false;
                GroupBox5->Visible = true;
        }

        else if (name == "Epitrochoid") {
                // Montar paneles de caja, etc.
                Epitrochoid3D *epitrochoid = dynamic_cast<Epitrochoid3D*>(it->second);
                _selected_epitrochoid = epitrochoid;
                TrackBar7->Position = epitrochoid->a;
                Panel10->Visible = true;
                //Hacemos visible el panel de la epitrocoide
                GroupBox3->Visible = true;
                GroupBox4->Visible = false;
                GroupBox5->Visible = false;
        } else {
                _selected_epitrochoid = NULL;
                Panel10->Visible = false;
        }




        _scene->Repaint();
        }
}

void __fastcall TForm1::ToolButton1Click(TObject *Sender) {
        _scene->main_figure->elements->clear();
        _scene->main_figure->elements->push_back(_copa);
        _scene->Repaint();
        Structure->Items->Clear();
        LoadStructure(_scene->main_figure, NULL);
}

void __fastcall TForm1::ToolButton2Click(TObject *Sender) {
        _scene->main_figure->elements->clear();
        _scene->main_figure->elements->push_back(_epicar);
        _scene->Repaint();
        Structure->Items->Clear();
        LoadStructure(_scene->main_figure, NULL);
}

void __fastcall TForm1::ToolButton4Click(TObject *Sender) {
                _epicar->epi->filled = !ToolButton4->Down;
                _copa->filled = !ToolButton4->Down;
                _scene->Repaint();
}

void __fastcall TForm1::ToolButton5Click(TObject *Sender)
{
        _epicar->epi->showNormals = ToolButton5->Down;
        _copa->showNormals = ToolButton5->Down;
        _scene->Repaint();
}
//---------------------------------------------------------------------------





void __fastcall TForm1::TrackBar1Change(TObject *Sender) {
        FocusControl(TrackBar1);
        TrackBar1->SelStart = min(0, TrackBar1->Position);
        TrackBar1->SelEnd = max(0, TrackBar1->Position);


        if (_selected_figure != NULL) {
                _selected_figure->translation->x += TrackBar1->Position - TrackBar1->Tag;
                TrackBar1->Tag = TrackBar1->Position;
                Label6->Caption = "Delta X "+AnsiString(TrackBar1->Position);
                _scene->Repaint();
        }
        FocusControl(TrackBar1);
}
//---------------------------------------------------------------------------










void __fastcall TForm1::TrackBar1Enter(TObject *Sender)
{
        TrackBar1->Position = 0;
        TrackBar1->Tag = 0;
}

void __fastcall TForm1::TrackBar1Exit(TObject *Sender)
{
        TrackBar1->Tag = 0;
        TrackBar1->Position = 0;
}

void __fastcall TForm1::TrackBar2Change(TObject *Sender) {
        TrackBar2->SelStart = min(0, TrackBar2->Position);
        TrackBar2->SelEnd = max(0, TrackBar2->Position);

        if (_selected_figure != NULL) {
                _selected_figure->translation->y += TrackBar2->Position - TrackBar2->Tag;
                TrackBar2->Tag = TrackBar2->Position;
                Label6->Caption = "Delta Y "+AnsiString(TrackBar2->Position);
                _scene->Repaint();
        }
        FocusControl(TrackBar2);
}

void __fastcall TForm1::TrackBar2Enter(TObject *Sender) {
        TrackBar2->Position = 0;
        TrackBar2->Tag = 0;
}

void __fastcall TForm1::TrackBar2Exit(TObject *Sender) {
        TrackBar2->Tag = 0;
        TrackBar2->Position = 0;
}

void __fastcall TForm1::TrackBar3Change(TObject *Sender) {
        TrackBar3->SelStart = min(0, TrackBar3->Position);
        TrackBar3->SelEnd = max(0, TrackBar3->Position);

        if (_selected_figure != NULL) {
                _selected_figure->translation->z += TrackBar3->Position - TrackBar3->Tag;
                TrackBar3->Tag = TrackBar3->Position;
                Label6->Caption = "Delta Z "+AnsiString(TrackBar3->Position);
                _scene->Repaint();
        }
        FocusControl(TrackBar3);
}

void __fastcall TForm1::TrackBar3Enter(TObject *Sender) {
        TrackBar3->Position = 0;
        TrackBar3->Tag = 0;
}

void __fastcall TForm1::TrackBar3Exit(TObject *Sender) {
        TrackBar3->Tag = 0;
        TrackBar3->Position = 0;
}

void __fastcall TForm1::TrackBar4Change(TObject *Sender)
{
        TrackBar4->SelStart = min(0, TrackBar4->Position);
        TrackBar4->SelEnd = max(0, TrackBar4->Position);

        if (_selected_figure != NULL) {
                _selected_figure->rotation->x += TrackBar4->Position - TrackBar4->Tag;
                TrackBar4->Tag = TrackBar4->Position;
                Label12->Caption = "Delta X "+AnsiString(TrackBar4->Position)+"º";
                _scene->Repaint();
        }
        FocusControl(TrackBar4);
}

void __fastcall TForm1::TrackBar4Enter(TObject *Sender) {
        TrackBar4->Position = 0;
        TrackBar4->Tag = 0;
}

void __fastcall TForm1::TrackBar4Exit(TObject *Sender) {
        TrackBar4->Tag = 0;
        TrackBar4->Position = 0;
}

void __fastcall TForm1::TrackBar5Change(TObject *Sender)
{
        TrackBar5->SelStart = min(0, TrackBar5->Position);
        TrackBar5->SelEnd = max(0, TrackBar5->Position);

        if (_selected_figure != NULL) {
                _selected_figure->rotation->y += TrackBar5->Position - TrackBar5->Tag;
                TrackBar5->Tag = TrackBar5->Position;
                Label12->Caption = "Delta Y "+AnsiString(TrackBar5->Position)+"º";
                _scene->Repaint();
        }
        FocusControl(TrackBar5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar6Change(TObject *Sender)
{
        TrackBar6->SelStart = min(0, TrackBar6->Position);
        TrackBar6->SelEnd = max(0, TrackBar6->Position);

        if (_selected_figure != NULL) {
                _selected_figure->rotation->z += TrackBar6->Position - TrackBar6->Tag;
                TrackBar6->Tag = TrackBar6->Position;
                Label12->Caption = "Delta Z "+AnsiString(TrackBar6->Position)+"º";
                _scene->Repaint();
        }
        FocusControl(TrackBar6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar5Enter(TObject *Sender)
{
        TrackBar5->Position = 0;
        TrackBar5->Tag = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar5Exit(TObject *Sender) {
        TrackBar5->Tag = 0;
        TrackBar5->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar6Enter(TObject *Sender)
{
        TrackBar6->Position = 0;
        TrackBar6->Tag = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar6Exit(TObject *Sender)
{
        TrackBar6->Tag = 0;
        TrackBar6->Position = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar7Chage(TObject *Sender)
{
        Label13->Caption = "A: "+AnsiString(TrackBar7->Position);

        if (_selected_epitrochoid != NULL) {
                _selected_epitrochoid->a = TrackBar7->Position;
                _selected_epitrochoid->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TrackBar12Change(TObject *Sender)
{
        Label18->Caption = "nR: "+AnsiString(TrackBar12->Position);

        if (_selected_epitrochoid != NULL) {
                _selected_epitrochoid->nP = TrackBar12->Position;
                _selected_epitrochoid->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar13Change(TObject *Sender)
{
        Label19->Caption = "nQ: "+AnsiString(TrackBar13->Position);

        if (_selected_epitrochoid != NULL) {
                _selected_epitrochoid->nQ = TrackBar13->Position;
                _selected_epitrochoid->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar11Change(TObject *Sender)
{
        Label17->Caption = "R: "+AnsiString(TrackBar11->Position);

        if (_selected_epitrochoid != NULL) {
                _selected_epitrochoid->r = TrackBar11->Position;
                _selected_epitrochoid->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::TrackBar8Change(TObject *Sender)
{
        Label14->Caption = "W: " + AnsiString(TrackBar8->Position);

        if (_selected_box != NULL) {
                _selected_box->x = TrackBar8->Position;
                _selected_box->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar14Change(TObject *Sender)
{
        Label20->Caption = "L: " + AnsiString(TrackBar14->Position);

        if (_selected_box != NULL) {
                _selected_box->y = TrackBar14->Position;
                _selected_box->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar15Change(TObject *Sender)
{
        Label21->Caption = "H: " + AnsiString(TrackBar15->Position);

        if (_selected_box != NULL) {
                _selected_box->z = TrackBar15->Position;
                _selected_box->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar16Change(TObject *Sender)
{
        Label22->Caption = "H: " + AnsiString(TrackBar16->Position);

        if (_selected_cylinder != NULL) {
                _selected_cylinder->height = TrackBar16->Position;
                _selected_cylinder->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar17Change(TObject *Sender)
{
        Label23->Caption = "RT: " + AnsiString(TrackBar17->Position);

        if (_selected_cylinder != NULL) {
                _selected_cylinder->rad_top = TrackBar17->Position;
                _selected_cylinder->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrackBar18Change(TObject *Sender)
{
        Label24->Caption = "RB: " + AnsiString(TrackBar18->Position);

        if (_selected_cylinder != NULL) {
                _selected_cylinder->rad_bottom = TrackBar18->Position;
                _selected_cylinder->RecalculateMesh();
                _scene->Repaint();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel4MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        /*if(_last_viewport == _vp4) {
                Panel4->SetFocus();
        }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        /*if(_last_viewport == _vp1) {
                Panel1->SetFocus();
        }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        /*if(_last_viewport == _vp2) {
                Panel2->SetFocus();
        }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        /*if(_last_viewport == _vp3) {
                Panel3->SetFocus();
        }*/
}
//---------------------------------------------------------------------------


