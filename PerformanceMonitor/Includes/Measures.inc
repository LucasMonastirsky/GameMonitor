[FramerateRaw]
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=Framerate
MinValue=0
MaxValue=#TargetFramerate#
IfCondition = (([Framerate] > 0) && (([Framerate] < #FramerateMin#) || (#FramerateMin# < 1)))
IfTrueAction = !SetVariable FramerateMin [Framerate:0]
DynamicVariables = 1

[Framerate]
Measure = Calc
Formula = ([FramerateRaw] < 999 ? [FramerateRaw] : 999)
MinValue=0
MaxValue=#TargetFramerate#
DynamicVariables = 1

[FramerateCapped]
Measure = Calc
Formula = ([Framerate] < #TargetFramerate# ? [Framerate] : #TargetFramerate#)
MinValue=0
MaxValue=#TargetFramerate#
DynamicVariables = 1

[CpuUsage]
Measure = CPU
MinValue = 0
MaxValue = 100
IfCondition = CpuUsage < #CpuUsageWarning#
IfTrueAction = [!SetOption CpuUsageBar BarColor #BarColorSafe#]
IfCondition2 = CpuUsage >= #CpuUsageWarning#
IfTrueAction2 = [!SetOption CpuUsageBar BarColor #BarColorWarning#]
IfCondition3 = CpuUsage >= #CpuUsageAlert#
IfTrueAction3 = [!SetOption CpuUsageBar BarColor #BarColorAlert#]

[CpuTemp]
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=CPU temperature
MinValue = 0
MaxValue = 100
IfCondition = CpuTemp < #CpuTempWarning#
IfTrueAction = [!SetOption CpuTempBar BarColor #BarColorSafe#]
IfCondition2 = CpuTemp >= #CpuTempWarning#
IfTrueAction2 = [!SetOption CpuTempBar BarColor #BarColorWarning#]
IfCondition3 = CpuTemp >= #CpuTempAlert#
IfTrueAction3 = [!SetOption CpuTempBar BarColor #BarColorAlert#]

[GpuUsage]
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=GPU usage
MinValue=0
MaxValue=100
IfCondition = GpuUsage < #GpuUsageWarning#
IfTrueAction = [!SetOption GpuUsageBar BarColor #BarColorSafe#]
IfCondition2 = GpuUsage >= #GpuUsageWarning#
IfTrueAction2 = [!SetOption GpuUsageBar BarColor #BarColorWarning#]
IfCondition3 = GpuUsage >= #GpuUsageAlert#
IfTrueAction3 = [!SetOption GpuUsageBar BarColor #BarColorAlert#]

[GpuTemp]
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=GPU temperature
MinValue = 0
MaxValue = 100
IfCondition = GpuTemp < #GpuTempWarning#
IfTrueAction = [!SetOption GpuTempBar BarColor #BarColorSafe#]
IfCondition2 = GpuTemp >= #GpuTempWarning#
IfTrueAction2 = [!SetOption GpuTempBar BarColor #BarColorWarning#]
IfCondition3 = GpuTemp >= #GpuTempAlert#
IfTrueAction3 = [!SetOption GpuTempBar BarColor #BarColorAlert#]

[VRam]
Measure=Plugin
Plugin=Plugins\MSIAfterburner.dll
DataSource=Memory usage
MinValue = 0
MaxValue = #VRamTotal#
OnUpdateAction = !SetVariable VRamPercentage (Round([VRam:]/#VRamTotal#*100))
IfCondition = #VRamPercentage# < #VRamWarning#
IfTrueAction = [!SetOption VRamBar BarColor #BarColorSafe#]
IfCondition2 = #VRamPercentage# >= #VRamWarning#
IfTrueAction2 = [!SetOption VRamBar BarColor #BarColorWarning#]
IfCondition3 = #VRamPercentage# >= #VRamAlert#
IfTrueAction3 = [!SetOption VRamBar BarColor #BarColorAlert#]
DynamicVariables = 1

[Ram]
Measure = PhysicalMemory
OnUpdateAction = !SetVariable RamPercentage (Round([Ram:]/[Ram:MaxValue]*100))
IfCondition = #RamPercentage# < #RamWarning#
IfTrueAction = [!SetOption RamBar BarColor #BarColorSafe#]
IfCondition2 = #RamPercentage# >= #RamWarning#
IfTrueAction2 = [!SetOption RamBar BarColor #BarColorWarning#]
IfCondition3 = #RamPercentage# >= #RamAlert#
IfTrueAction3 = [!SetOption RamBar BarColor #BarColorAlert#]
DynamicVariables = 1

[Time]
Measure = Time

[Hour]
Measure = Time
Format = %H

[Minute]
Measure = Time
Format = %M

[Second]
Measure = Time
Format = %S