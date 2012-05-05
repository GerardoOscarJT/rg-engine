//---------------------------------------------------------------------------

#ifndef WindowH
#define WindowH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "Scene3D.h"
#include "EpiCar3D.h"
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <map.h>
#include "Revolution3D.h"
#include <ImgList.hpp>
#include "LeftRoomFurn.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Ayuda1;
        TStatusBar *StatusBar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Camaras1;
        TPanel *MainPanel;
        TToolBar *ToolBar;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TPanel *LeftPanel;
        TScrollBox *RightPanel;
        TPanel *Panel1;
        TPanel *Panel3;
        TPanel *Panel2;
        TPanel *Panel4;
        TListBox *ListBox1;
        TShape *Shape1;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TPanel *Panel5;
        TTreeView *Structure;
        TImageList *ImageList1;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TMenuItem *Salir1;
        TPanel *Panel6;
        TGroupBox *GroupBox1;
        TPanel *Panel7;
        TLabel *Label1;
        TLabel *Label2;
        TTrackBar *TrackBar1;
        TTrackBar *TrackBar2;
        TLabel *Label3;
        TLabel *Label4;
        TTrackBar *TrackBar3;
        TLabel *Label5;
        TLabel *Label6;
        TPanel *Panel8;
        TGroupBox *GroupBox2;
        TLabel *Label7;
        TLabel *Label8;
        TPanel *Panel9;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TTrackBar *TrackBar4;
        TTrackBar *TrackBar5;
        TTrackBar *TrackBar6;
        TLabel *Label12;
        TPanel *Panel10;
        TGroupBox *GroupBox3;
        TTrackBar *TrackBar7;
        TLabel *Label13;
        TLabel *Label15;
        TTrackBar *TrackBar9;
        TLabel *Label16;
        TTrackBar *TrackBar10;
        TLabel *Label17;
        TTrackBar *TrackBar11;
        TLabel *Label18;
        TTrackBar *TrackBar12;
        TLabel *Label19;
        TTrackBar *TrackBar13;
        TGroupBox *GroupBox4;
        TLabel *Label14;
        TLabel *Label20;
        TLabel *Label21;
        TTrackBar *TrackBar8;
        TTrackBar *TrackBar14;
        TTrackBar *TrackBar15;
        TGroupBox *GroupBox5;
        TTrackBar *TrackBar16;
        TTrackBar *TrackBar17;
        TTrackBar *TrackBar18;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall PopupMenu1Popup(TObject *Sender);
        void __fastcall Panel1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel4MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall FormMouseWheelDown(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseWheelUp(TObject *Sender,
          TShiftState Shift, TPoint &MousePos, bool &Handled);
        void __fastcall StructureClick(TObject *Sender);
        void __fastcall ToolButton1Click(TObject *Sender);
        void __fastcall ToolButton2Click(TObject *Sender);
        void __fastcall ToolButton4Click(TObject *Sender);
        void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall TrackBar1Enter(TObject *Sender);
        void __fastcall TrackBar1Exit(TObject *Sender);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall TrackBar2Enter(TObject *Sender);
        void __fastcall TrackBar2Exit(TObject *Sender);
        void __fastcall TrackBar3Change(TObject *Sender);
        void __fastcall TrackBar3Enter(TObject *Sender);
        void __fastcall TrackBar3Exit(TObject *Sender);
        void __fastcall TrackBar4Change(TObject *Sender);
        void __fastcall TrackBar4Enter(TObject *Sender);
        void __fastcall TrackBar4Exit(TObject *Sender);
        void __fastcall TrackBar5Change(TObject *Sender);
        void __fastcall TrackBar6Change(TObject *Sender);
        void __fastcall TrackBar5Enter(TObject *Sender);
        void __fastcall TrackBar5Exit(TObject *Sender);
        void __fastcall TrackBar6Enter(TObject *Sender);
        void __fastcall TrackBar6Exit(TObject *Sender);
        void __fastcall TrackBar7Chage(TObject *Sender);
        void __fastcall TrackBar12Change(TObject *Sender);
        void __fastcall TrackBar13Change(TObject *Sender);
        void __fastcall TrackBar11Change(TObject *Sender);
        void __fastcall TrackBar8Change(TObject *Sender);
        void __fastcall TrackBar14Change(TObject *Sender);
        void __fastcall TrackBar15Change(TObject *Sender);
        void __fastcall TrackBar16Change(TObject *Sender);
        void __fastcall TrackBar17Change(TObject *Sender);
        void __fastcall TrackBar18Change(TObject *Sender);
        void __fastcall Panel4MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Panel1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Panel2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Panel3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations

        Scene3D *_scene;

        ViewPort3D *_last_viewport;

        ViewPort3D *_vp1;
        ViewPort3D *_vp2;
        ViewPort3D *_vp3;
        ViewPort3D *_vp4;

        void __fastcall RecalculateGUI();


        EpiCar3D *_epicar;
        LeftRoomFurn *_leftRoomFurn;
        //Borrar al terminar de experimentar
        //Box3D *box;

        map<TTreeNode*, Figure3D*> *_editable_figures;

        Revolution3D *_copa;

        Figure3D* _selected_figure;
        Epitrochoid3D *_selected_epitrochoid;
        Box3D* _selected_box;
        Cylinder3D *_selected_cylinder;


        void __fastcall LoadStructure(Figure3D *figure, TTreeNode* node);

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
