[Variables]
FramerateMin = 0
FramerateMax = 0

BarMarkY = ( #BarHeight# / #BarDivisor# )
BarMarkStyle1 = StrokeColor #BarMarkerColor# | StrokeWidth ( #BarDivisor# > 1 ? #BarMarkerThickness# : 0)
BarMarkStyle2 = StrokeColor #BarMarkerColor# | StrokeWidth ( #BarDivisor# > 2 ? #BarMarkerThickness# : 0)
BarMarkStyle3 = StrokeColor #BarMarkerColor# | StrokeWidth ( #BarDivisor# > 3 ? #BarMarkerThickness# : 0)
BarMarkStyle4 = StrokeColor #BarMarkerColor# | StrokeWidth ( #BarDivisor# > 4 ? #BarMarkerThickness# : 0)

t = 0

[CalcWidth]
Measure = Calc
Formula = (#BarWidth# * 6 + #Padding# * 9)

[CalcHeight]
Measure = Calc
Formula = ( #LabelHeight# + #BarHeight# + #Padding# * 1.5 + #GraphHeight# + [FramerateValue:H])
DynamicVariables = 1
UpdateDivider = -1

[UtilHideMini]
Measure = Calc
IfCondition = #ShowValuesInBars# < 1
IfTrueAction = !HideMeterGroup Mini
UpdateDivider = -1

[UtilHideOnDesktop]
Measure = Calc
IfCondition = ((#HideOnDesktop# > 0) && ([Framerate] < 1))
IfTrueAction = !HideFade
IfCondition2 = ((#HideOnDesktop# > 0) && ([Framerate] > 0))
IfTrueAction2 = !ShowFade
DynamicVariables = 1