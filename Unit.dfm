object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1050#1086#1076#1080#1088#1086#1074#1097#1080#1082
  ClientHeight = 410
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
    Left = 480
    Top = 8
    Width = 84
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1090#1077#1083#1077#1092#1086#1085#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 35
    Width = 88
    Height = 13
    Caption = #1058#1077#1082#1089#1090' '#1089#1086#1086#1073#1097#1077#1085#1080#1103
  end
  object Label3: TLabel
    Left = 8
    Top = 257
    Width = 79
    Height = 13
    Caption = 'PDU '#1089#1086#1086#1073#1097#1077#1085#1080#1077
  end
  object Edit2: TEdit
    Left = 8
    Top = 8
    Width = 57
    Height = 21
    TabOrder = 5
    Text = 'Edit2'
    Visible = False
  end
  object Edit1: TEdit
    Left = 480
    Top = 27
    Width = 191
    Height = 21
    TabOrder = 0
    Text = '+'
    OnChange = Edit1Change
    OnKeyPress = Edit1KeyPress
  end
  object Memo1: TMemo
    Left = 480
    Top = 54
    Width = 191
    Height = 146
    ReadOnly = True
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 3
    Width = 97
    Height = 25
    Caption = #1047#1072#1082#1086#1076#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 214
    Width = 90
    Height = 25
    Caption = #1056#1072#1089#1082#1086#1076#1080#1088#1086#1074#1072#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit3: TEdit
    Left = 8
    Top = 54
    Width = 449
    Height = 19
    AutoSize = False
    TabOrder = 4
  end
  object Edit4: TEdit
    Left = 8
    Top = 276
    Width = 673
    Height = 21
    TabOrder = 6
  end
  object Memo2: TMemo
    Left = 9
    Top = 303
    Width = 673
    Height = 90
    ReadOnly = True
    TabOrder = 7
  end
  object Button3: TButton
    Left = 520
    Top = 214
    Width = 113
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1042#1057#1045
    TabOrder = 8
    OnClick = Button3Click
  end
end
