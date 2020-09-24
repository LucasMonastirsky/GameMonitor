; --- CPU ---

[CpuLabel]
Meter = String
MeterStyle = TextLabel
Text = "CPU"
X = ( #Padding# + #BarWidth# + #Padding# / 2 )
Y = ( #BarSectionY# + #Padding# )
StringAlign = Center
DynamicVariables = 1
UpdateDivider = -1
FontColor = #CpuColor#

[CpuUsageBar]
Meter = Bar
MeterStyle = Bar
MeasureName = CpuUsage
X = #Padding#

[CpuUsageMini]
Meter = String
MeterStyle = TextMini
Group = Mini | CpuBars
MeasureName = CpuUsage
X = ( ([CpuUsageBar:X] + [CpuUsageBar:XW]) / 2 )

[CpuUsageMarks]
Meter = Shape
Shape = Line [CpuUsageBar:X],(#BarTop#+#BarMarkY#),[CpuUsageBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [CpuUsageBar:X],(#BarTop#+#BarMarkY#*2),[CpuUsageBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [CpuUsageBar:X],(#BarTop#+#BarMarkY#*3),[CpuUsageBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [CpuUsageBar:X],(#BarTop#+#BarMarkY#*4),[CpuUsageBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[CpuTempBar]
Meter = Bar
MeterStyle = Bar
MeasureName = CpuTemp
X = ([CpuUsageBar:XW] + #Padding#)

[CpuTempMini]
Meter = String
MeterStyle = TextMini
Group = Mini | CpuBars
MeasureName = CpuTemp
X = ( ([CpuTempBar:X] + [CpuTempBar:XW]) / 2 )

[CpuTempMarks]
Meter = Shape
Shape = Line [CpuTempBar:X],(#BarTop#+#BarMarkY#),[CpuTempBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [CpuTempBar:X],(#BarTop#+#BarMarkY#*2),[CpuTempBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [CpuTempBar:X],(#BarTop#+#BarMarkY#*3),[CpuTempBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [CpuTempBar:X],(#BarTop#+#BarMarkY#*4),[CpuTempBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[DivisorCpuGpu]
Meter = Shape
Shape = Line ([CpuTempBar:XW] + #Padding#),(#BarSectionY#+#Padding#),([CpuTempBar:XW] + #Padding#),[BarSectionBottom] | StrokeWidth #DivisorWidth# | Stroke Color #DivisorColor#
DynamicVariables = 1
UpdateDivider = -1

; --- GPU ---

[GpuLabel]
Meter = String
MeterStyle = TextLabel
Text = "GPU"
X = ( [GpuUsageBar:XW] + #Padding# / 2 )
Y = ( #BarSectionY# + #Padding# )
StringAlign = Center
FontColor = #GpuColor#
DynamicVariables = 1
UpdateDivider = -1

[GpuUsageBar]
Meter = Bar
MeterStyle = Bar
MeasureName = GpuUsage
X = ([CpuTempBar:XW] + #Padding# * 2 + #DivisorWidth#)

[GpuUsageMini]
Meter = String
MeterStyle = TextMini
Group = Mini | GpuBars
MeasureName = GpuUsage
X = ( ([GpuUsageBar:X] + [GpuUsageBar:XW]) / 2 )

[GpuUsageMarks]
Meter = Shape
Shape = Line [GpuUsageBar:X],(#BarTop#+#BarMarkY#),[GpuUsageBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [GpuUsageBar:X],(#BarTop#+#BarMarkY#*2),[GpuUsageBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [GpuUsageBar:X],(#BarTop#+#BarMarkY#*3),[GpuUsageBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [GpuUsageBar:X],(#BarTop#+#BarMarkY#*4),[GpuUsageBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[GpuTempBar]
Meter = Bar
MeterStyle = Bar
MeasureName = GpuTemp
X = ([GpuUsageBar:XW] + #Padding#)

[GpuTempMini]
Meter = String
MeterStyle = TextMini
Group = Mini | GpuBars
MeasureName = GpuTemp
X = ( ([GpuTempBar:X] + [GpuTempBar:XW]) / 2 )

[GpuTempMarks]
Meter = Shape
Shape = Line [GpuTempBar:X],(#BarTop#+#BarMarkY#),[GpuTempBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [GpuTempBar:X],(#BarTop#+#BarMarkY#*2),[GpuTempBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [GpuTempBar:X],(#BarTop#+#BarMarkY#*3),[GpuTempBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [GpuTempBar:X],(#BarTop#+#BarMarkY#*4),[GpuTempBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[DivisorGpuRamX]
Measure = Calc
Formula = ( [GpuTempBar:XW] + #Padding# )
DynamicVariables = 1
UpdateDivider = -1

[DivisorGpuRam]
Meter = Shape
Shape = Line [DivisorGpuRamX],(#BarSectionY# + #Padding#),[DivisorGpuRamX],[BarSectionBottom] | StrokeWidth #DivisorWidth# | Stroke Color #DivisorColor#
DynamicVariables = 1
UpdateDivider = -1

; --- RAM ---

[RamLabel]
Meter = String
MeterStyle = TextLabel
Text = "RAM"
X = ( [VRamBar:XW] + #Padding# / 2 )
Y = ( #BarSectionY# + #Padding# )
StringAlign = Center
FontColor = #RamColor#
DynamicVariables = 1
UpdateDivider = -1

[VRamBar]
Meter = Bar
MeterStyle = Bar
MeasureName = VRam
X = ([GpuTempBar:XW] + #Padding# * 2 + #DivisorWidth#)

[VRamMini]
Meter = String
MeterStyle = TextMini
Group = Mini | RamBars
MeasureName = VRam
X = ( ([VRamBar:X] + [VRamBar:XW]) / 2 )

[VRamMarks]
Meter = Shape
Shape = Line [VRamBar:X],(#BarTop#+#BarMarkY#),[VRamBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [VRamBar:X],(#BarTop#+#BarMarkY#*2),[VRamBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [VRamBar:X],(#BarTop#+#BarMarkY#*3),[VRamBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [VRamBar:X],(#BarTop#+#BarMarkY#*4),[VRamBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[RamBar]
Meter = Bar
MeterStyle = Bar
MeasureName = Ram
X = ([VRamBar:XW] + #Padding#)

[RamMini]
Meter = String
MeterStyle = TextMini
Group = Mini | RamBars
MeasureName = Ram
X = ( ([RamBar:X] + [RamBar:XW]) / 2 )

[RamMarks]
Meter = Shape
Shape = Line [RamBar:X],(#BarTop#+#BarMarkY#),[RamBar:XW],(#BarTop#+#BarMarkY#) | #BarMarkStyle1#
Shape2 = Line [RamBar:X],(#BarTop#+#BarMarkY#*2),[RamBar:XW],(#BarTop#+#BarMarkY#*2) | #BarMarkStyle2#
Shape3 = Line [RamBar:X],(#BarTop#+#BarMarkY#*3),[RamBar:XW],(#BarTop#+#BarMarkY#*3) | #BarMarkStyle3#
Shape4 = Line [RamBar:X],(#BarTop#+#BarMarkY#*4),[RamBar:XW],(#BarTop#+#BarMarkY#*4) | #BarMarkStyle4#
DynamicVariables = 1
UpdateDivider = -1

[BarSectionBottom]
Measure = Calc
Formula = [CpuUsageBar:YH]
DynamicVariables = 1
UpdateDivider = -1

[DivisorBarGraph]
Meter = Shape
Shape = Line (#BarSectionX# + #Padding#),([BarSectionBottom] + #Padding#),([CalcWidth] - #Padding#),([BarSectionBottom] + #Padding#) | StrokeWidth #DivisorWidth# | Stroke Color #DivisorColor#
DynamicVariables = 1
UpdateDivider = -1