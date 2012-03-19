object Form1: TForm1
  Left = 46
  Top = 158
  AutoScroll = False
  Caption = 'cer'
  ClientHeight = 635
  ClientWidth = 990
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001001010100001000400280100001600000028000000100000002000
    000001000400000000000000000000000000000000000000000000000000FF00
    00000000FF000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000002222
    2222222222222221122222211222222110000001122222202222222202222220
    2222222202222202222222222022220222222222202220222222222222022022
    2222222222021122222222222211112222222222221122002222222200222222
    002222002222222222022022222222222221122222222222222112222222FFFF
    0000E7E70000E0070000EFF70000EFF70000DFFB0000DFFB0000BFFD0000BFFD
    00003FFC00003FFC0000CFF30000F3CF0000FDBF0000FE7F0000FE7F0000}
  KeyPreview = True
  Menu = MainMenu1
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
  object StatusBar: TStatusBar
    Left = 0
    Top = 616
    Width = 990
    Height = 19
    Panels = <>
    SimplePanel = False
  end
  object MainPanel: TPanel
    Left = 8
    Top = 64
    Width = 969
    Height = 545
    BevelOuter = bvNone
    BorderWidth = 10
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clCaptionText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    object LeftPanel: TPanel
      Left = 8
      Top = 8
      Width = 649
      Height = 529
      BevelOuter = bvNone
      Color = clBlack
      TabOrder = 0
      object Shape1: TShape
        Left = 112
        Top = 112
        Width = 137
        Height = 105
        Brush.Style = bsClear
        Pen.Color = clGreen
      end
      object Shape2: TShape
        Left = 120
        Top = 120
        Width = 137
        Height = 105
        Brush.Style = bsClear
        Pen.Color = clGreen
      end
      object Shape3: TShape
        Left = 128
        Top = 128
        Width = 137
        Height = 105
        Brush.Style = bsClear
        Pen.Color = clGreen
      end
      object Shape4: TShape
        Left = 136
        Top = 136
        Width = 137
        Height = 105
        Brush.Style = bsClear
        Pen.Color = clGreen
      end
      object Panel1: TPanel
        Left = 24
        Top = 96
        Width = 81
        Height = 25
        Caption = 'Panel1'
        TabOrder = 0
        OnMouseDown = Panel1MouseDown
      end
      object Panel3: TPanel
        Left = 24
        Top = 160
        Width = 81
        Height = 25
        Caption = 'Panel3'
        TabOrder = 1
        OnMouseDown = Panel3MouseDown
      end
      object Panel2: TPanel
        Left = 24
        Top = 128
        Width = 81
        Height = 25
        Caption = 'Panel2'
        TabOrder = 2
        OnMouseDown = Panel2MouseDown
      end
      object Panel4: TPanel
        Left = 120
        Top = 128
        Width = 81
        Height = 57
        Caption = 'Panel4'
        TabOrder = 3
        OnMouseDown = Panel4MouseDown
      end
      object ListBox1: TListBox
        Left = 528
        Top = 8
        Width = 105
        Height = 57
        TabStop = False
        BorderStyle = bsNone
        Color = clBlack
        ItemHeight = 13
        Items.Strings = (
          'uno'
          'dos'
          'tres')
        TabOrder = 4
        Visible = False
      end
    end
    object RightPanel: TScrollBox
      Left = 661
      Top = 7
      Width = 300
      Height = 530
      HorzScrollBar.Visible = False
      VertScrollBar.Smooth = True
      VertScrollBar.Style = ssFlat
      VertScrollBar.Tracking = True
      Anchors = []
      BorderStyle = bsNone
      Color = 8192
      ParentColor = False
      TabOrder = 1
      object Button3: TButton
        Left = 48
        Top = 696
        Width = 113
        Height = 249
        Caption = 'Button3'
        TabOrder = 0
        TabStop = False
      end
      object Panel5: TPanel
        Left = 0
        Top = -1
        Width = 281
        Height = 306
        BevelOuter = bvNone
        Caption = 'Panel5'
        ParentColor = True
        TabOrder = 1
        object Structure: TTreeView
          Left = 8
          Top = 8
          Width = 265
          Height = 281
          Indent = 19
          ParentColor = True
          TabOrder = 0
          TabStop = False
          OnClick = StructureClick
          Items.Data = {
            01000000200000000000000000000000FFFFFFFFFFFFFFFF0000000001000000
            076578616D706C651D0000000000000000000000FFFFFFFFFFFFFFFF00000000
            00000000046F74726F}
        end
      end
    end
  end
  object ToolBar: TToolBar
    Left = 0
    Top = 0
    Width = 990
    Height = 25
    AutoSize = True
    ButtonHeight = 25
    ButtonWidth = 26
    Caption = 'ToolBar'
    DockSite = True
    EdgeBorders = []
    EdgeInner = esNone
    EdgeOuter = esNone
    Flat = True
    TabOrder = 2
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Caption = 'ToolButton1'
      ImageIndex = 0
    end
    object ToolButton2: TToolButton
      Left = 26
      Top = 0
      Caption = 'ToolButton2'
      ImageIndex = 1
    end
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 32
    object Archivo1: TMenuItem
      Caption = 'Archivo'
    end
    object Copa1: TMenuItem
      Caption = 'Copa'
      OnClick = Copa1Click
    end
    object Ayuda1: TMenuItem
      Caption = 'Ayuda'
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 8
    Top = 32
    object Camaras1: TMenuItem
      Caption = 'Camaras'
    end
  end
end
