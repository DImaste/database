object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'SQLite Tree'
  ClientHeight = 405
  ClientWidth = 690
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 89
    Top = 370
    Width = 66
    Height = 13
    Caption = '                      '
  end
  object Label2: TLabel
    Left = 89
    Top = 382
    Width = 75
    Height = 13
    Caption = '                         '
  end
  object Label3: TLabel
    Left = 488
    Top = 370
    Width = 84
    Height = 13
    Caption = '                            '
  end
  object Label4: TLabel
    Left = 488
    Top = 382
    Width = 78
    Height = 13
    Caption = '                          '
  end
  object Button1: TButton
    Left = 8
    Top = 370
    Width = 75
    Height = 25
    Caption = 'Bomb'
    TabOrder = 0
    OnClick = Button1Click
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 8
    Top = 8
    Width = 673
    Height = 356
    Header.AutoSizeIndex = 0
    Header.Font.Charset = DEFAULT_CHARSET
    Header.Font.Color = clWindowText
    Header.Font.Height = -11
    Header.Font.Name = 'Tahoma'
    Header.Font.Style = []
    TabOrder = 1
    TreeOptions.MiscOptions = [toAcceptOLEDrop, toFullRepaintOnResize, toGridExtensions, toInitOnSave, toToggleOnDblClick, toWheelPanning, toEditOnClick]
    TreeOptions.PaintOptions = [toHotTrack, toShowButtons, toShowDropmark, toShowHorzGridLines, toShowRoot, toShowTreeLines, toShowVertGridLines, toThemeAware, toUseBlendedImages, toFullVertGridLines, toUseBlendedSelection]
    TreeOptions.SelectionOptions = [toFullRowSelect]
    OnGetText = VirtualStringTree1GetText
    Columns = <
      item
        Position = 0
      end
      item
        Position = 1
        Width = 150
      end
      item
        Position = 2
        Width = 470
      end>
  end
  object Button2: TButton
    Left = 320
    Top = 370
    Width = 75
    Height = 25
    Caption = 'Delete string'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 401
    Top = 370
    Width = 75
    Height = 25
    Caption = 'Clear Table'
    TabOrder = 3
    OnClick = Button3Click
  end
end
