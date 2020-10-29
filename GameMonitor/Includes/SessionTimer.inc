[Variables]
SessionStarted = 0  
SUBSTITUTE_LEADING_ZERO = "^(\d{1})$":"0\1"

[SessionTimer]
Meter = String
Text = [SessionHour]:[SessionMinute]
MeterStyle = TextFramerateMini
Group = Framerate
Y = [TimeValue:YH]
X = [TimeValue:XW]
StringAlign = Right
DynamicVariables = 1

[StartSession]
Measure = Calc
IfCondition = (#SessionStarted# < 1) && ([Framerate] > 0)
IfTrueAction = [!SetVariable SessionStarted 1][!SetVariable StartTime "([&Hour] * 60 + [&Minute])"][!UpdateMeter SessionTimer][!Redraw]
IfCondition2 = (#SessionStarted# > 0) && ([Framerate] < 1) 
IfTrueAction2 = [!SetVariable SessionStarted 0][!SetVariable LastSessionTime "([&Hour] * 60 + [&Minute] - #StartTime#)"][!UpdateMeasure SessionTime][!UpdateMeter SessionTimer][!Redraw]
DynamicVariables = 1

[SessionTime]
Measure = Calc
Formula = #SessionStarted# > 0 ? ([Hour] * 60 + [Minute] - #StartTime#) : (#LastSessionTime#)
DynamicVariables = 1

[SessionHour]
Measure = Calc
Formula = Floor([SessionTime] / 60)
RegExpSubstitute=1
Substitute=#SUBSTITUTE_LEADING_ZERO#
DynamicVariables = 1

[SessionMinute]
Measure = Calc
Formula = [SessionTime] % 60
RegExpSubstitute=1
Substitute = #SUBSTITUTE_LEADING_ZERO#
DynamicVariables = 1
