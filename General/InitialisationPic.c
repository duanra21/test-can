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
	PR1 = 45000;
	T1CON = 0b1000000000100000;

	//Interruption du timer
	IFS0bits.T1IF = 0;
	IPC0bits.T1IP = 2;
	IEC0bits.T1IE = 1;	

	while(attenteInitialisation<100);

}

