object Form1: TForm1
  Left = 336
  Top = 160
  Width = 924
  Height = 620
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 8
    Top = 8
    Width = 305
    Height = 185
    Caption = 'Panel1'
    PopupMenu = PopupMenu1
    TabOrder = 0
    OnMouseDown = Panel1MouseDown
  end
  object Panel3: TPanel
    Left = 8
    Top = 392
    Width = 305
    Height = 185
    Caption = 'Panel1'
    PopupMenu = PopupMenu1
    TabOrder = 1
    OnMouseDown = Panel3MouseDown
  end
  object Panel2: TPanel
    Left = 8
    Top = 200
    Width = 305
    Height = 185
    Caption = 'Panel1'
    PopupMenu = PopupMenu1
    TabOrder = 2
    OnMouseDown = Panel2MouseDown
  end
  object Panel4: TPanel
    Left = 320
    Top = 200
    Width = 585
    Height = 377
    Caption = 'Panel4'
    PopupMenu = PopupMenu1
    TabOrder = 3
    OnMouseDown = Panel4MouseDown
  end
  object PopupMenu1: TPopupMenu
    MenuAnimation = [maLeftToRight]
    OnPopup = PopupMenu1Popup
    Left = 408
    Top = 40
    object Camaras1: TMenuItem
      Caption = 'Cámaras'
    end
  end
end
