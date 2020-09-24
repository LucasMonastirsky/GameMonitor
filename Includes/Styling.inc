[Variables]
FontColor = 0,215,255
BackgroundColor = 0,0,0,200
FramerateCounterSize = 50

CpuColor = 0,175,225
GpuColor = 0,225,175
RamColor = 225,0,175

LabelHeight = 20

DivisorWidth = 0.4
DivisorColor = 255,255,255

BarHeight = 100
BarWidth = (#BarHeight# / 5)
BarMarkerColor = #BackgroundColor#
BarMarkerThickness = 0.75
BarColorSafe = 125,200,150
BarColorWarning = 220,210,0
BarColorAlert = 225,100,100

Padding = 10

BarSectionY = 0
BarSectionX = 0
BarTop = ( #BarSectionY# + #LabelHeight# + #Padding# * 1.5 )
BarSectionBottom = (#BarSectionY# + #SectionHeight#)
GraphHeight = 100

; styles

[TextLabel]
FontColor = #FontColor#
FontSize = ( #LabelHeight# / 1.5 )
StringEffect = Border
FontEffectColor = 0,0,0,125
FontWeight = 700

[TextFramerate]
StringEffect = Border
FontEffectColor = 0,0,0,255
FontSize = #FramerateCounterSize#
FontColor = #FontColor#
FontWeight = 400

[TextFramerateMini]
FontSize = (#FramerateCounterSize# / 4)
FontWeight = 600
FontColor = #FontColor#

[Bar]
BarColor=185,250,160,255
SolidColor=150,150,150,255
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