[FramerateGrid]
Meter = Image
ImageName = Images\FramerateGrid.png
X = 0
Y = ([CpuUsageBar:YH] + #Padding#)
W = [CalcWidth]
H = #GraphHeight#
DynamicVariables = 1
UpdateDivider = -1

[FramerateGraph]
Meter = Line
MeasureName = FramerateCapped
MeasureName2 = CpuUsage
X = 0r
Y = 0r
W = [CalcWidth]
H = #GraphHeight#
LineCount = 2
LineColor = 255,255,255
LineColor2 = #CpuColor#
LineWidth = 1
DynamicVariables = 1

[FramerateValue]
Meter = String
MeterStyle = TextFramerate
MeasureName = Framerate
Text = "%1"
X = 0r
Y = 0R
NumOfDecimals = 0

[SpacerFramerate]
Meter = String
FontColor = 255,255,255,1
FontSize = #FramerateCounterSize#
Text = "240"
X = 0r
Y = 0r

[FramerateMinValue]
Meter = String
MeterStyle = TextFramerateMini
Text = min: #FramerateMin#
X = 0R
Y = #Padding#r
NumOfDecimals = 0
DynamicVariables = 1

[TimeValue]
Meter = String
MeterStyle = TextFramerateMini
MeasureName = Time
Text = "%1"
X = 0r
Y = 0R