[TextLabel]
Group = Label
FontColor = #FontColor#
FontSize = ( #LabelHeight# / 1.5 )
FontWeight = 700
AntiAlias = 1

[TextFramerate]
StringEffect = Border
FontEffectColor = 0,0,0,255
FontSize = #FramerateCounterSize#
FontColor = #FontColor#
FontWeight = 400
AntiAlias = 1

[TextFramerateMini]
FontSize = (#FramerateCounterSize# / 4)
FontWeight = 600
FontColor = #FontColor#
AntiAlias = 1

[Bar]
BarColor = #BarColorSafe#
SolidColor = #BarBackgroundColor#
Y = #BarTop#
W = #BarWidth#
H = #BarHeight#

[TextMini]
FontColor = #BackgroundColor#
FontSize = (#BarHeight# / 9)
StringAlign = CenterCenter
FontWeight = 600
Y = ( #BarTop# + (#BarHeight# / #BarDivisor# / 2))
Text = %1
Percentual = 1
DynamicVariables = 1
AntiAlias = 1

[Background]
Meter = Shape
Shape = Rectangle 0,0,[CalcWidth],([SpacerFramerate:YH]-#Padding#) | Fill Color #BackgroundColor#
DynamicVariables = 1