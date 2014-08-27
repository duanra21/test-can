/*******************************************************************************
 *******************************************************************************
 ******                                                                   ******
 ****                                                                       ****
 ****                      Fichier InitialisationPic.c                      ****
 ****                    Fonction d'initialisation du PIC                   ****
 ****                                                                       ****
 ******                                                                   ******
 ****                                                                       ****
 **** Commentaire :                                                         ****
 ****   Fichier pour l'initialisation du PIC. Mettre toutes les fonction    ****
 **** pour l'initialisation du PIC                                          ****
 ****                                                                       ****
 ******                  ******************************                   ******
 ****                                                                       ****
 **** Créateur :                                                            ****
 ****                                                     VOILLEQUIN Arnaud ****
 ****  Date de création :                                                   ****
 ****                                                            17/08/2014 ****
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

#include "../Include.h"

// Variables utilisés dans ces fonctions

volatile unsigned int attenteInitialisation = 0;


void InitialisationDuPic()
{
	// Attente pour commencer l'initialisation
	for(attenteInitialisation=0;attenteInitialisation<10000;attenteInitialisation++);

	// Configuration de l'oscillateur
	ConfigurationOscillateurPic();

	// Configuration des IO
	ConfigurationEntreeSortie();
	
	
	//Timer 1 à xHz pour globalTime (pas envie de faire un gros calcul)
	TMR1 = 0;
	PR1 = 50000;
	T1CON = 0b1000000000100000;

	//Interruption du timer
	IFS0bits.T1IF = 0;
	IPC0bits.T1IP = 7;
	IEC0bits.T1IE = 1;	

	while(attenteInitialisation<100);
	
	U2BRG = 86;		//115200 pour le module bluetooth

	U2STA = 0b0010000000000000;
	U2MODE = 0b0000000000001000;
	U2MODEbits.UARTEN = 1;
	U2STAbits.UTXEN = 1;
	
	IFS1bits.U2TXIF = 0;
	IPC7bits.U2TXIP = 3;
	IEC1bits.U2TXIE = 1;

	IFS1bits.U2RXIF = 0;
	IPC7bits.U2RXIP = 6;
	IEC1bits.U2RXIE = 1;

}

