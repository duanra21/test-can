/*******************************************************************************
 *******************************************************************************
 ******                                                                   ******
 ****                                                                       ****
 ****                             Fichier main.c                            ****
 ****                            Principal du PIC                           ****
 ****                                                                       ****
 ******                                                                   ******
 ****                                                                       ****
 **** Commentaire :                                                         ****
 ****   Code de la fonction principale.                                     ****
 ****                                                                       ****
 ******                  ******************************                   ******
 ****                                                                       ****
 **** Créateur :                                                            ****
 ****                                                     VOILLEQUIN Arnaud ****
 ****  Date de création :                                                   ****
 ****                                                            14/08/2014 ****
 ****                                                                       ****
 ******                  ******************************                   ******
 ****                                                                       ****
 **** Modificateur :                                                        ****
 ****                                                     VOILLEQUIN Arnaud ****
 ****                                                                       ****
 ****  Date de modification :                                               ****
 ****                                                            14/08/2014 ****
 ****                                                                       ****
 ******                  ******************************                   ******
 ****                                                                       ****
 **** Association :                                                         ****
 ****                                                                 RSATz ****
 ****                                                                       ****
 ******                                                                   ******
 *******************************************************************************
 ******************************************************************************/


/************************************************
			TEMPLATE dsPIC33
************************************************/
#include "Include.h"

#define LED_VERTE	LATAbits.LATA4

/************************************************
			VARIABLES
************************************************/
volatile unsigned int globalTime = 0;
volatile unsigned int ledTime = 0;


/************************************************
*				PROGRAMME PRINCIPAL				*
************************************************/
void main(void)
{
	for(globalTime=0;globalTime<10000;globalTime++);
	//Config de l'oscillateur avec PLL
	//Quartz 16MHz => 80MHz => 40 MIPS
	CLKDIV = 2;	//2 pour 16MHz
	PLLFBD = 38;
	OSCCON = 0b0000001100000001;
	while(!OSCCONbits.LOCK);

	//Init des IO
	TRISAbits.TRISA4 = 0;

	//Timer 1 à 50Hz pour globalTime
	TMR1 = 0;
	PR1 = 12500;
	T1CON = 0b1000000000100000;

	//Interruption du timer
	IFS0bits.T1IF = 0;
	IPC0bits.T1IP = 2;
	IEC0bits.T1IE = 1;	

	while(globalTime<100);
	
	globalTime = 0;
	

	while(1)
	{
		if((globalTime-ledTime)>1)
		{
			LED_VERTE = !LED_VERTE;
			ledTime = globalTime;
		}
	}
}

/************************************************
*					INTERRUPTION				*
************************************************/
//Timer1 à 50Hz
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void) 
{
	globalTime++;
	IFS0bits.T1IF = 0;
}
