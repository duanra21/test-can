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
int __C30_UART = 2;

unsigned char DebugTXBuffer[256];
unsigned char DebugTXInPtr = 0;
unsigned char DebugTXOutPtr = 0;

unsigned char DebugRXBuffer[256];
unsigned char DebugRXInPtr = 0;
unsigned char DebugRXOutPtr = 0;

/************************************************
*				PROGRAMME PRINCIPAL				*
************************************************/
void main(void)
{
	InitialisationDuPic();		
	//printf("Bonjour");
	int attente = 0;
	while(1)
	{
        // AH AHHH CODE VIDE :p
        //debugUARTSendString('c');
        //attente = 0;
        //for(attente; attente<1000; attente++);
        //printf("hi");
        PutChar('c');
	}
}

/************************************************
*					INTERRUPTION				*
************************************************/
//Timer1 à XHz
void __attribute__((__interrupt__,__auto_psv__)) _T1Interrupt(void) 
{
	LED_VERTE = !LED_VERTE;
	IFS0bits.T1IF = 0;
}


int PutChar(int c)
{
	if(U2STAbits.TRMT)
	{
		U2TXREG = c;
	}		
	else
	{
		DebugTXBuffer[DebugTXInPtr++] = c;
	}
	return 0;
}	

void debugUARTSendString(char* str)
{
	while(*str)
	{
		putchar(*(str++));
	}	
}	

void debugUARTHandle(void)
{
	unsigned int c;
	
	while(DebugRXInPtr!=DebugRXOutPtr)
	{	
		c = DebugRXBuffer[DebugRXOutPtr++];
	}	
}

/************************************************
*					INTERRUPTIONS				*
************************************************/
//Envoi de caractère du buffer
void __attribute__((__interrupt__,__auto_psv__)) _U2TXInterrupt(void) 
{
	IFS1bits.U2TXIF = 0;
	if(DebugTXInPtr!=DebugTXOutPtr)
	{
		U2TXREG = DebugTXBuffer[DebugTXOutPtr++];
	}	
}

//Réception de caractère
void __attribute__((__interrupt__,__auto_psv__)) _U2RXInterrupt(void) 
{
	IFS1bits.U2RXIF = 0;
	DebugRXBuffer[DebugRXInPtr++] = U2RXREG;
}

