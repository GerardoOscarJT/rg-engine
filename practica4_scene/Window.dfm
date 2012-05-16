object Form1: TForm1
  Left = 413
  Top = 155
  AutoScroll = False
  Caption = 'RG Engine'
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
  OnKeyUp = FormKeyUp
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
        OnMouseMove = Panel1MouseMove
      end
      object Panel3: TPanel
        Left = 24
        Top = 160
        Width = 81
        Height = 25
        Caption = 'Panel3'
        TabOrder = 1
        OnMouseDown = Panel3MouseDown
        OnMouseMove = Panel3MouseMove
      end
      object Panel2: TPanel
        Left = 24
        Top = 128
        Width = 81
        Height = 25
        Caption = 'Panel2'
        TabOrder = 2
        OnMouseDown = Panel2MouseDown
        OnMouseMove = Panel2MouseMove
      end
      object Panel4: TPanel
        Left = 120
        Top = 128
        Width = 81
        Height = 57
        Caption = 'Panel4'
        TabOrder = 3
        OnMouseDown = Panel4MouseDown
        OnMouseMove = Panel4MouseMove
      end
      object Panel11: TPanel
        Left = 304
        Top = 16
        Width = 281
        Height = 145
        BevelOuter = bvNone
        Color = clBlack
        TabOrder = 4
        Visible = False
        object ListBox1: TListBox
          Left = 176
          Top = 8
          Width = 105
          Height = 57
          TabStop = False
          BorderStyle = bsNone
          Color = 25098
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ItemHeight = 13
          ParentFont = False
          TabOrder = 0
        end
        object Edit1: TEdit
          Left = 32
          Top = 72
          Width = 249
          Height = 21
          BorderStyle = bsNone
          Color = 25600
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWhite
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          Text = 'Edit1'
          OnKeyUp = Edit1KeyUp
        end
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
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clMenuText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      object Panel5: TPanel
        Left = 0
        Top = -1
        Width = 281
        Height = 298
        BevelOuter = bvNone
        Caption = 'Panel5'
        ParentColor = True
        TabOrder = 0
        object Structure: TTreeView
          Left = 8
          Top = 8
          Width = 265
          Height = 281
          BorderStyle = bsNone
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
      object Panel6: TPanel
        Left = 0
        Top = 296
        Width = 281
        Height = 153
        BevelOuter = bvNone
        Caption = 'Panel6'
        ParentColor = True
        TabOrder = 1
        object GroupBox1: TGroupBox
          Left = 8
          Top = 0
          Width = 265
          Height = 145
          Caption = ' Position '
          TabOrder = 0
          object Label1: TLabel
            Left = 8
            Top = 16
            Width = 25
            Height = 13
            Alignment = taCenter
            AutoSize = False
            Caption = 'Abs'
          end
          object Label2: TLabel
            Left = 40
            Top = 16
            Width = 25
            Height = 13
            Alignment = taCenter
            AutoSize = False
            Caption = 'Rel'
            Color = clLime
            ParentColor = False
          end
          object Label6: TLabel
            Left = 254
            Top = 16
            Width = 3
            Height = 13
            Alignment = taRightJustify
          end
          object Panel7: TPanel
            Left = 8
            Top = 32
            Width = 249
            Height = 105
            TabOrder = 0
            object Label3: TLabel
              Left = 16
              Top = 13
              Width = 7
              Height = 13
              Caption = 'X'
            end
            object Label4: TLabel
              Left = 16
              Top = 45
              Width = 7
              Height = 13
              Caption = 'Y'
            end
            object Label5: TLabel
              Left = 16
              Top = 77
              Width = 7
              Height = 13
              Caption = 'Z'
            end
            object TrackBar1: TTrackBar
              Left = 24
              Top = 8
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 100
              Min = -100
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 0
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar1Change
              OnEnter = TrackBar1Enter
              OnExit = TrackBar1Exit
            end
            object TrackBar2: TTrackBar
              Left = 24
              Top = 40
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 100
              Min = -100
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 1
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar2Change
              OnEnter = TrackBar2Enter
              OnExit = TrackBar2Exit
            end
            object TrackBar3: TTrackBar
              Left = 24
              Top = 72
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 100
              Min = -100
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 2
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar3Change
              OnEnter = TrackBar3Enter
              OnExit = TrackBar3Exit
            end
          end
        end
      end
      object Panel8: TPanel
        Left = 0
        Top = 446
        Width = 281
        Height = 160
        BevelOuter = bvNone
        TabOrder = 2
        object GroupBox2: TGroupBox
          Left = 8
          Top = 8
          Width = 265
          Height = 145
          Caption = 'Rotation'
          TabOrder = 0
          object Label7: TLabel
            Left = 8
            Top = 16
            Width = 25
            Height = 13
            Alignment = taCenter
            AutoSize = False
            Caption = 'Abs'
          end
          object Label8: TLabel
            Left = 40
            Top = 16
            Width = 25
            Height = 13
            Alignment = taCenter
            AutoSize = False
            Caption = 'Rel'
            Color = clLime
            ParentColor = False
          end
          object Label12: TLabel
            Left = 254
            Top = 16
            Width = 3
            Height = 13
            Alignment = taRightJustify
          end
          object Panel9: TPanel
            Left = 8
            Top = 32
            Width = 249
            Height = 105
            TabOrder = 0
            object Label9: TLabel
              Left = 16
              Top = 13
              Width = 7
              Height = 13
              Caption = 'X'
            end
            object Label10: TLabel
              Left = 16
              Top = 45
              Width = 7
              Height = 13
              Caption = 'Y'
            end
            object Label11: TLabel
              Left = 16
              Top = 77
              Width = 7
              Height = 13
              Caption = 'Z'
            end
            object TrackBar4: TTrackBar
              Left = 24
              Top = 8
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 360
              Min = -360
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 0
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar4Change
              OnEnter = TrackBar4Enter
              OnExit = TrackBar4Exit
            end
            object TrackBar5: TTrackBar
              Left = 24
              Top = 40
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 360
              Min = -360
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 1
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar5Change
              OnEnter = TrackBar5Enter
              OnExit = TrackBar5Exit
            end
            object TrackBar6: TTrackBar
              Left = 24
              Top = 72
              Width = 217
              Height = 25
              BorderWidth = 1
              LineSize = 0
              Max = 360
              Min = -360
              Orientation = trHorizontal
              PageSize = 1
              Frequency = 1
              Position = 0
              SelEnd = 0
              SelStart = 0
              TabOrder = 2
              TickMarks = tmBottomRight
              TickStyle = tsAuto
              OnChange = TrackBar6Change
              OnEnter = TrackBar6Enter
              OnExit = TrackBar6Exit
            end
          end
        end
      end
      object Panel10: TPanel
        Left = 0
        Top = 603
        Width = 281
        Height = 330
        BevelOuter = bvNone
        TabOrder = 3
        object GroupBox3: TGroupBox
          Left = 8
          Top = 0
          Width = 265
          Height = 225
          Caption = 'Epitrocoide'
          TabOrder = 0
          object Label13: TLabel
            Left = 8
            Top = 32
            Width = 7
            Height = 13
            Caption = 'A'
          end
          object Label15: TLabel
            Left = 8
            Top = 64
            Width = 7
            Height = 13
            Caption = 'B'
          end
          object Label16: TLabel
            Left = 8
            Top = 96
            Width = 8
            Height = 13
            Caption = 'H'
          end
          object Label17: TLabel
            Left = 8
            Top = 128
            Width = 8
            Height = 13
            Caption = 'R'
          end
          object Label18: TLabel
            Left = 8
            Top = 160
            Width = 14
            Height = 13
            Caption = 'nR'
          end
          object Label19: TLabel
            Left = 8
            Top = 192
            Width = 14
            Height = 13
            Caption = 'nQ'
          end
          object TrackBar7: TTrackBar
            Left = 48
            Top = 24
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 0
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar7Chage
          end
          object TrackBar9: TTrackBar
            Left = 48
            Top = 56
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 1
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar7Chage
          end
          object TrackBar10: TTrackBar
            Left = 48
            Top = 88
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 2
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar7Chage
          end
          object TrackBar11: TTrackBar
            Left = 48
            Top = 120
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 3
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar11Change
          end
          object TrackBar12: TTrackBar
            Left = 48
            Top = 152
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 4
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar12Change
          end
          object TrackBar13: TTrackBar
            Left = 48
            Top = 184
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 5
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar13Change
          end
        end
        object GroupBox4: TGroupBox
          Left = 8
          Top = 0
          Width = 265
          Height = 145
          Caption = 'Box'
          TabOrder = 1
          Visible = False
          object Label14: TLabel
            Left = 16
            Top = 32
            Width = 11
            Height = 13
            Caption = 'W'
          end
          object Label20: TLabel
            Left = 16
            Top = 72
            Width = 6
            Height = 13
            Caption = 'L'
          end
          object Label21: TLabel
            Left = 16
            Top = 112
            Width = 8
            Height = 13
            Caption = 'H'
          end
          object TrackBar8: TTrackBar
            Left = 40
            Top = 24
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 0
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar8Change
          end
          object TrackBar14: TTrackBar
            Left = 40
            Top = 64
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 1
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar14Change
          end
          object TrackBar15: TTrackBar
            Left = 40
            Top = 104
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 2
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar15Change
          end
        end
        object GroupBox5: TGroupBox
          Left = 8
          Top = 0
          Width = 265
          Height = 145
          Caption = 'Cylinder'
          TabOrder = 2
          Visible = False
          object Label22: TLabel
            Left = 8
            Top = 32
            Width = 8
            Height = 13
            Caption = 'H'
          end
          object Label23: TLabel
            Left = 8
            Top = 72
            Width = 15
            Height = 13
            Caption = 'RT'
          end
          object Label24: TLabel
            Left = 8
            Top = 112
            Width = 15
            Height = 13
            Caption = 'RB'
          end
          object TrackBar16: TTrackBar
            Left = 40
            Top = 24
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 0
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar16Change
          end
          object TrackBar17: TTrackBar
            Left = 40
            Top = 64
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 1
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar17Change
          end
          object TrackBar18: TTrackBar
            Left = 40
            Top = 104
            Width = 209
            Height = 25
            Max = 500
            Orientation = trHorizontal
            Frequency = 1
            Position = 0
            SelEnd = 0
            SelStart = 0
            TabOrder = 2
            TickMarks = tmBottomRight
            TickStyle = tsAuto
            OnChange = TrackBar18Change
          end
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
    Images = ImageList1
    TabOrder = 2
    object ToolButton2: TToolButton
      Left = 0
      Top = 0
      Caption = 'ToolButton2'
      ImageIndex = 4
      OnClick = ToolButton2Click
    end
    object ToolButton3: TToolButton
      Left = 26
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton4: TToolButton
      Left = 34
      Top = 0
      Caption = 'ToolButton4'
      ImageIndex = 2
      Style = tbsCheck
      OnClick = ToolButton4Click
    end
    object ToolButton5: TToolButton
      Left = 60
      Top = 0
      Caption = 'ToolButton5'
      ImageIndex = 3
      Style = tbsCheck
      OnClick = ToolButton5Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 40
    Top = 32
    object Archivo1: TMenuItem
      Caption = '&Archivo'
      object Salir1: TMenuItem
        Caption = 'Salir'
      end
    end
    object Ayuda1: TMenuItem
      Caption = 'A&yuda'
      object Manualdeayuda1: TMenuItem
        Caption = 'Manual de ayuda'
        ShortCut = 112
        OnClick = Manualdeayuda1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Acercade1: TMenuItem
        Caption = 'Acerca de...'
        OnClick = Acercade1Click
      end
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 8
    Top = 32
    object Camaras1: TMenuItem
      Caption = 'Camaras'
    end
  end
  object ImageList1: TImageList
    Left = 168
    Top = 32
    Bitmap = {
      494C010105000900040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000003000000001002000000000000030
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF840000FF84
      0000FF840000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      000000000000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      000000000000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF840000FF84
      0000FF840000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      000000000000FF840000FF840000FF8400000000000000000000C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF8400000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF840000FF840000FF84
      00000000000000000000C4A88900C4A88900C4A88900C4A88900C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF840000FF840000FF84
      00000000000000000000C4A88900C4A88900C4A88900C4A88900C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF840000FF840000FF84
      00000000000000000000C4A88900C4A88900C4A88900C4A88900C4A88900C4A8
      8900C4A88900C4A8890000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E
      4E00000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000FF000000FF000000FF000000000000000000
      0000000000000000000000000000000000000000000075757500000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF00000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000757575000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000000000000000000000007575
      7500000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000757575000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF0000000000000000000000000000000000FF0000000000000000000000
      000000000000FF00000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000007575750075757500757575007575750075757500000000007575
      7500757575007575750075757500000000000000000000000000000000000000
      000000000000FF00000000000000000000000000FF0000000000000000000000
      00000000000000000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000FF0000000000FF00FF000000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF00000000000000000000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF4E4E00FF4E4E0000000000000000000000
      00000000000000000000000000000000000000000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000000000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF4E4E00FF4E4E00FF4E4E00FF4E4E00000000000000
      000000000000000000000000000000000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF0000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E000000
      000000000000000000000000000000000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E
      4E0000000000000000000000000000000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF0000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF4E
      4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E
      4E00FF4E4E00000000000000000000000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF0000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000FF00000000000000FF00000000000000FF000000
      0000000000000000000000000000000000000000000000000000FF4E4E00FF4E
      4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E
      4E00FF4E4E00FF4E4E00000000000000000000000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000000000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FF000000FF000000FF00000000000000
      00000000000000000000000000000000000000000000FF4E4E00FF4E4E00FF4E
      4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E4E00FF4E
      4E00FF4E4E00FF4E4E00FF4E4E00000000000000000000000000FF0000000000
      0000000000000000000000000000FF000000FF00000000000000000000000000
      000000000000FF00000000000000000000000000000000000000000000000000
      0000000000007575750000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000FF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF0000000000000000000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000300000000100010000000000800100000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFF000000000000F8C3000000000000
      C0C3000000000000D8C3000000000000DFFF000000000000DFFF000000000000
      D8C3000000000000C0C3000000000000D8C3000000000000DFFF000000000000
      DFFF000000000000DFFF0000000000008C030000000000008C03000000000000
      8C03000000000000FFFF000000000000FFFFFFFF001F003FF00FFC3F3FCFBFDF
      FE7FFBDF5FD7DFEFFE7FF7EF6FDBEF77FE7FEFF777DDF77BFE7FEFF77800FB7D
      FE7FEFF77BDEFC00FE7FDFFB7BDEFF7FFE7FBFFD7BDEFF7FFC3F7FFE7BDEFF7F
      F81F7FFE001EFF7FF00F7FFEBBEEFF7FE0077FFEDBF6FD5FC003BFFDEBFAFE3F
      8001DE7BF3FCFF7FFFFFE187F800FFFF00000000000000000000000000000000
      000000000000}
  end
end
