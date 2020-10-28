[Variables]
SessionStarted = 0

[SessionTimer]
Meter = String
MeterStyle = TextFramerateMini
Group = Framerate
Y = 0R
X = 0r
DynamicVariables = 1

[StartSession]
Measure = Calc
IfCondition = (#SessionStarted# < 1) && ([Framerate] > 1)
IfTrueAction = [!SetVariable SessionStarted 1][!SetVariable StartTime "([&Hour] * 60 + [&Minute])"]
DynamicVariables = 1

[CurrentTime]
Measure = Calc
Formula = [Hour] * 60 + [Minute]

[SessionHour]
Measure = Calc
Formula = [CurrentTime] - Found([StartTime] / 60)
DynamicVariables = 1

[SessionMinute]
Measure = Calc
Formula = [Minute]
