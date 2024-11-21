object Form1: TForm1
  Left = 379
  Top = 208
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'MNIST_FCNN'
  ClientHeight = 545
  ClientWidth = 962
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox2: TGroupBox
    Left = 0
    Top = 160
    Width = 405
    Height = 383
    TabOrder = 0
    object Button2: TButton
      Left = 207
      Top = 50
      Width = 75
      Height = 25
      Caption = 'random open'
      TabOrder = 0
      OnClick = Button2Click
    end
    object Panel2: TPanel
      Left = 294
      Top = 50
      Width = 103
      Height = 25
      BevelOuter = bvNone
      TabOrder = 1
    end
    object Button3: TButton
      Left = 19
      Top = 107
      Width = 75
      Height = 25
      Caption = 'load params'
      TabOrder = 2
      OnClick = Button3Click
    end
    object StringGrid1: TStringGrid
      Left = 117
      Top = 86
      Width = 263
      Height = 292
      ColCount = 2
      DefaultColWidth = 120
      DefaultRowHeight = 15
      FixedCols = 0
      RowCount = 50000
      FixedRows = 0
      TabOrder = 3
    end
    object Button4: TButton
      Left = 19
      Top = 151
      Width = 75
      Height = 25
      Caption = 'w0 1st row'
      TabOrder = 4
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 19
      Top = 204
      Width = 75
      Height = 25
      Caption = 'w1'
      TabOrder = 5
      OnClick = Button5Click
    end
    object Button10: TButton
      Left = 19
      Top = 284
      Width = 75
      Height = 25
      Caption = 'b0'
      TabOrder = 6
      OnClick = Button10Click
    end
    object Button11: TButton
      Left = 19
      Top = 314
      Width = 75
      Height = 25
      Caption = 'b1'
      TabOrder = 7
      OnClick = Button11Click
    end
    object Button14: TButton
      Left = 19
      Top = 175
      Width = 75
      Height = 25
      Caption = 'w0 last row'
      TabOrder = 8
      OnClick = Button14Click
    end
    object Button6: TButton
      Left = 19
      Top = 234
      Width = 75
      Height = 25
      Caption = 'w2'
      TabOrder = 9
      OnClick = Button6Click
    end
    object Button8: TButton
      Left = 19
      Top = 345
      Width = 75
      Height = 25
      Caption = 'b2'
      TabOrder = 10
      OnClick = Button8Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 0
    Top = 5
    Width = 201
    Height = 155
    Caption = ' stream '
    TabOrder = 1
    object Image1: TImage
      Left = 16
      Top = 19
      Width = 160
      Height = 120
    end
  end
  object GroupBox4: TGroupBox
    Left = 204
    Top = 5
    Width = 201
    Height = 155
    Caption = ' frame '
    TabOrder = 2
    object Image2: TImage
      Left = 16
      Top = 19
      Width = 160
      Height = 120
      Stretch = True
    end
  end
  object StringGrid3: TStringGrid
    Left = 656
    Top = 7
    Width = 300
    Height = 536
    ColCount = 28
    DefaultColWidth = 18
    DefaultRowHeight = 18
    Enabled = False
    FixedCols = 0
    RowCount = 28
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Arial'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goTabs, goThumbTracking]
    ParentFont = False
    TabOrder = 3
  end
  object Button1: TButton
    Left = 207
    Top = 177
    Width = 75
    Height = 25
    Caption = 'open picture'
    TabOrder = 4
    OnClick = Button1Click
  end
  object Panel1: TPanel
    Left = 294
    Top = 177
    Width = 75
    Height = 25
    BevelOuter = bvNone
    TabOrder = 5
  end
  object GroupBox5: TGroupBox
    Left = 3
    Top = 167
    Width = 198
    Height = 75
    Caption = ' camera '
    TabOrder = 6
    object Button7: TButton
      Left = 5
      Top = 15
      Width = 75
      Height = 25
      Caption = 'on'
      TabOrder = 0
    end
  end
  object Button13: TButton
    Left = 440
    Top = 288
    Width = 185
    Height = 57
    Caption = 'clear'
    TabOrder = 7
    OnClick = Button13Click
  end
  object Panel3: TPanel
    Left = 440
    Top = 24
    Width = 185
    Height = 121
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -67
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object Button15: TButton
    Left = 440
    Top = 168
    Width = 185
    Height = 81
    Caption = 'res'
    TabOrder = 9
    OnClick = Button15Click
  end
  object OpenPictureDialog1: TOpenPictureDialog
    InitialDir = 'bmp'
    Left = 360
    Top = 32
  end
  object SavePictureDialog1: TSavePictureDialog
    DefaultExt = 'bmp'
    InitialDir = 'c:\bmp'
    Left = 360
    Top = 64
  end
end
