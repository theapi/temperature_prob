EESchema Schematic File Version 2
LIBS:probe-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:theapi_probe
LIBS:probe-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATTINY85-S IC?
U 1 1 57D6926A
P 3300 4650
F 0 "IC?" H 2150 5050 50  0000 C CNN
F 1 "ATTINY85-S" H 4300 4250 50  0000 C CNN
F 2 "SO8-200" H 4250 4650 50  0000 C CIN
F 3 "" H 3300 4650 50  0000 C CNN
	1    3300 4650
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 57D692C9
P 5000 1750
F 0 "#PWR?" H 5000 1600 50  0001 C CNN
F 1 "+5V" H 5000 1890 50  0000 C CNN
F 2 "" H 5000 1750 50  0000 C CNN
F 3 "" H 5000 1750 50  0000 C CNN
	1    5000 1750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57D69307
P 4650 4900
F 0 "#PWR?" H 4650 4650 50  0001 C CNN
F 1 "GND" H 4650 4750 50  0000 C CNN
F 2 "" H 4650 4900 50  0000 C CNN
F 3 "" H 4650 4900 50  0000 C CNN
	1    4650 4900
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 57D6931D
P 5350 2450
F 0 "C?" H 5375 2550 50  0000 L CNN
F 1 "C" H 5375 2350 50  0000 L CNN
F 2 "" H 5388 2300 50  0000 C CNN
F 3 "" H 5350 2450 50  0000 C CNN
	1    5350 2450
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 57D69375
P 5000 4550
F 0 "C?" H 5025 4650 50  0000 L CNN
F 1 "C" H 5025 4450 50  0000 L CNN
F 2 "" H 5038 4400 50  0000 C CNN
F 3 "" H 5000 4550 50  0000 C CNN
	1    5000 4550
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57D693E9
P 1700 5250
F 0 "R?" V 1780 5250 50  0000 C CNN
F 1 "R" V 1700 5250 50  0000 C CNN
F 2 "" V 1630 5250 50  0000 C CNN
F 3 "" H 1700 5250 50  0000 C CNN
	1    1700 5250
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky D?
U 1 1 57D694A0
P 5000 2000
F 0 "D?" H 5000 2100 50  0000 C CNN
F 1 "D_Schottky" H 5000 1900 50  0000 C CNN
F 2 "" H 5000 2000 50  0000 C CNN
F 3 "" H 5000 2000 50  0000 C CNN
	1    5000 2000
	0    -1   -1   0   
$EndComp
$Comp
L LED D?
U 1 1 57D69603
P 5700 3200
F 0 "D?" H 5700 3300 50  0000 C CNN
F 1 "LED" H 5700 3100 50  0000 C CNN
F 2 "" H 5700 3200 50  0000 C CNN
F 3 "" H 5700 3200 50  0000 C CNN
	1    5700 3200
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 57D696BE
P 5350 3000
F 0 "R?" V 5430 3000 50  0000 C CNN
F 1 "R" V 5350 3000 50  0000 C CNN
F 2 "" V 5280 3000 50  0000 C CNN
F 3 "" H 5350 3000 50  0000 C CNN
	1    5350 3000
	0    1    1    0   
$EndComp
$Comp
L THERMISTOR TH?
U 1 1 57D69809
P 1350 3100
F 0 "TH?" V 1450 3150 50  0000 C CNN
F 1 "THERMISTOR" V 1250 3100 50  0000 C BNN
F 2 "" H 1350 3100 50  0000 C CNN
F 3 "" H 1350 3100 50  0000 C CNN
	1    1350 3100
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 57D698E5
P 1350 3800
F 0 "R?" V 1430 3800 50  0000 C CNN
F 1 "R" V 1350 3800 50  0000 C CNN
F 2 "" V 1280 3800 50  0000 C CNN
F 3 "" H 1350 3800 50  0000 C CNN
	1    1350 3800
	1    0    0    -1  
$EndComp
$Comp
L MAX7219 IC?
U 1 1 57D6BE4D
P 7300 5800
F 0 "IC?" H 7300 5800 60  0000 C CNN
F 1 "MAX7219" H 7300 5800 60  0000 C CNN
F 2 "" H 7300 5800 60  0000 C CNN
F 3 "" H 7300 5800 60  0000 C CNN
	1    7300 5800
	1    0    0    -1  
$EndComp
$Comp
L CC56-12 AFF?
U 1 1 57D6C499
P 8750 2900
F 0 "AFF?" H 8750 3650 50  0000 C CNN
F 1 "CC56-12" H 8750 3550 50  0000 C CNN
F 2 "" H 8250 2900 50  0000 C CNN
F 3 "" H 8250 2900 50  0000 C CNN
	1    8750 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57D6CE10
P 5700 3400
F 0 "#PWR?" H 5700 3150 50  0001 C CNN
F 1 "GND" H 5700 3250 50  0000 C CNN
F 2 "" H 5700 3400 50  0000 C CNN
F 3 "" H 5700 3400 50  0000 C CNN
	1    5700 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57D6C3B2
P 5350 2600
F 0 "#PWR?" H 5350 2350 50  0001 C CNN
F 1 "GND" H 5350 2450 50  0000 C CNN
F 2 "" H 5350 2600 50  0000 C CNN
F 3 "" H 5350 2600 50  0000 C CNN
	1    5350 2600
	1    0    0    -1  
$EndComp
Text Label 5000 3750 0    60   ~ 0
VCC
$Comp
L GND #PWR?
U 1 1 57D6CC35
P 5000 4700
F 0 "#PWR?" H 5000 4450 50  0001 C CNN
F 1 "GND" H 5000 4550 50  0000 C CNN
F 2 "" H 5000 4700 50  0000 C CNN
F 3 "" H 5000 4700 50  0000 C CNN
	1    5000 4700
	1    0    0    -1  
$EndComp
NoConn ~ 7800 5300
NoConn ~ 7800 5400
NoConn ~ 7800 5500
NoConn ~ 7800 5600
$Comp
L GND #PWR?
U 1 1 57D6D2FA
P 6800 5800
F 0 "#PWR?" H 6800 5550 50  0001 C CNN
F 1 "GND" H 6800 5650 50  0000 C CNN
F 2 "" H 6800 5800 50  0000 C CNN
F 3 "" H 6800 5800 50  0000 C CNN
	1    6800 5800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57D6D5C2
P 1700 5400
F 0 "#PWR?" H 1700 5150 50  0001 C CNN
F 1 "GND" H 1700 5250 50  0000 C CNN
F 2 "" H 1700 5400 50  0000 C CNN
F 3 "" H 1700 5400 50  0000 C CNN
	1    1700 5400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 57D6D625
P 1350 3950
F 0 "#PWR?" H 1350 3700 50  0001 C CNN
F 1 "GND" H 1350 3800 50  0000 C CNN
F 2 "" H 1350 3950 50  0000 C CNN
F 3 "" H 1350 3950 50  0000 C CNN
	1    1350 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1750 5000 1850
Wire Wire Line
	5000 2150 5000 4400
Connection ~ 5000 2300
Wire Wire Line
	1350 2300 5350 2300
Wire Wire Line
	5000 3000 5200 3000
Wire Wire Line
	5500 3000 5700 3000
Wire Wire Line
	5000 4400 4650 4400
Connection ~ 5000 3000
Wire Wire Line
	6800 4100 5000 4100
Connection ~ 5000 4100
Wire Wire Line
	7800 4200 8450 4200
Wire Wire Line
	8450 4200 8450 3600
Wire Wire Line
	7800 4300 8550 4300
Wire Wire Line
	8550 4300 8550 3600
Wire Wire Line
	7800 4400 8650 4400
Wire Wire Line
	8650 4400 8650 3600
Wire Wire Line
	7800 4500 8750 4500
Wire Wire Line
	8750 4500 8750 3600
Wire Wire Line
	7800 4600 8850 4600
Wire Wire Line
	8850 4600 8850 3600
Wire Wire Line
	7800 4700 8950 4700
Wire Wire Line
	8950 4700 8950 3600
Wire Wire Line
	7800 4800 9050 4800
Wire Wire Line
	9050 4800 9050 3600
Wire Wire Line
	7800 4100 9150 4100
Wire Wire Line
	9150 4100 9150 3600
Wire Wire Line
	7800 4900 10000 4900
Wire Wire Line
	10000 4900 10000 1800
Wire Wire Line
	10000 1800 8050 1800
Wire Wire Line
	8050 1800 8050 2200
Wire Wire Line
	7800 5000 10100 5000
Wire Wire Line
	10100 5000 10100 1900
Wire Wire Line
	10100 1900 8550 1900
Wire Wire Line
	8550 1900 8550 2200
Wire Wire Line
	7800 5100 10200 5100
Wire Wire Line
	10200 5100 10200 2050
Wire Wire Line
	10200 2050 9050 2050
Wire Wire Line
	9050 2050 9050 2200
Wire Wire Line
	7800 5200 10300 5200
Wire Wire Line
	10300 5200 10300 2200
Wire Wire Line
	10300 2200 9550 2200
Wire Wire Line
	6800 5500 6800 5800
Connection ~ 6800 5600
Wire Wire Line
	1950 4900 1700 4900
Wire Wire Line
	1700 4900 1700 5100
Wire Wire Line
	1350 3350 1350 3650
Wire Wire Line
	1650 3500 1650 4800
Wire Wire Line
	1650 3500 1350 3500
Connection ~ 1350 3500
Wire Wire Line
	1350 2300 1350 2850
Wire Wire Line
	1650 4800 1950 4800
Text Label 1450 3500 0    60   ~ 0
ADC2
$EndSCHEMATC
