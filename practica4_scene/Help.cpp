#include <vcl.h>
#pragma hdrstop

#include "Help.h"

#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm2 *Form2;

__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}

void __fastcall TForm2::FormCreate(TObject *Sender)
{
        char buf[2000];
        getcwd(buf, sizeof(buf));
        String cwd = AnsiString(buf);
        String url = "file:///"+cwd+"/help/index.html";
        CppWebBrowser1->Navigate(WideString(url));
}

void __fastcall TForm2::FormResize(TObject *Sender)
{
        CppWebBrowser1->Top = 0;
        CppWebBrowser1->Left = 0;
        CppWebBrowser1->Width = Form2->ClientWidth;
        CppWebBrowser1->Height = Form2->ClientHeight;

}


