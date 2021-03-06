# MPLAB IDE generated this makefile for use with GNU make.
# Project: Test-CAN.mcp
# Date: Sun Aug 17 16:06:15 2014

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

Test-CAN.hex : Test-CAN.cof
	$(HX) "Test-CAN.cof"

Test-CAN.cof : Implementation.o main.o ConfigurationPic.o ConfigurationOscillateur.o InitialisationPic.o
	$(CC) -mcpu=33FJ128MC802 "Implementation.o" "main.o" "ConfigurationPic.o" "ConfigurationOscillateur.o" "InitialisationPic.o" -o"Test-CAN.cof" -Wl,-Tp33FJ128MC802.gld,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--heap=256,-Map="Test-CAN.map",--report-mem

Implementation.o : General/Implementation.h General/ConfigurationOscillateur.h General/ConfigurationPic.h General/InitialisationPic.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libPIC30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ128MC802.h Include.h General/Implementation.c
	$(CC) -mcpu=33FJ128MC802 -x c -c "General\Implementation.c" -o"Implementation.o" -D__DEBUG -g -Wall -O3

main.o : General/Implementation.h General/ConfigurationOscillateur.h General/ConfigurationPic.h General/InitialisationPic.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libPIC30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ128MC802.h Include.h main.c
	$(CC) -mcpu=33FJ128MC802 -x c -c "main.c" -o"main.o" -D__DEBUG -g -Wall -O3

ConfigurationPic.o : General/Implementation.h General/ConfigurationOscillateur.h General/ConfigurationPic.h General/InitialisationPic.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libPIC30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ128MC802.h Include.h General/ConfigurationPic.c
	$(CC) -mcpu=33FJ128MC802 -x c -c "General\ConfigurationPic.c" -o"ConfigurationPic.o" -D__DEBUG -g -Wall -O3

ConfigurationOscillateur.o : General/Implementation.h General/ConfigurationOscillateur.h General/ConfigurationPic.h General/InitialisationPic.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libPIC30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ128MC802.h include.h General/ConfigurationOscillateur.c
	$(CC) -mcpu=33FJ128MC802 -x c -c "General\ConfigurationOscillateur.c" -o"ConfigurationOscillateur.o" -D__DEBUG -g -Wall -O3

InitialisationPic.o : General/Implementation.h General/ConfigurationOscillateur.h General/ConfigurationPic.h General/InitialisationPic.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/generic/h/libPIC30.h ../../../../program\ files\ (x86)/microchip/mplab\ c30/support/dsPIC33F/h/p33FJ128MC802.h Include.h General/InitialisationPic.c
	$(CC) -mcpu=33FJ128MC802 -x c -c "General\InitialisationPic.c" -o"InitialisationPic.o" -D__DEBUG -g -Wall -O3

clean : 
	$(RM) "Implementation.o" "main.o" "ConfigurationPic.o" "ConfigurationOscillateur.o" "InitialisationPic.o" "Test-CAN.cof" "Test-CAN.hex"

