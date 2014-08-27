/*******************************************************************************
 *******************************************************************************
 ******                                                                   ******
 ****                                                                       ****
 ****                        Fichier Implementation.c                       ****
 ****                         Schémas d'implentation                        ****
 ****                              PIC : test                               ****
 ****                                                                       ****
 ******                                                                   ******
 ****                                                                       ****
 **** Commentaire :                                                         ****
 ****   Fichier d'implentations du PIC. Il sert a visualier les pins du PIC ****
 ****  libre, et faciliter la réalisation des schémas electrique.           ****
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



/*******************************************************************************
 **                                                                           **
 *                           ----------------------                            *
 *                           |                    |                            *
 *                    /MCLR +|  1              28 |+ AVdd (3.3V)               *
 *                          -|  2              27 |+ AVss (GND)                *
 *                          -|  3              26 |- PWM (a faire)             *
 *                          -|  4              25 |- PWM (a faire)             *
 *                          -|  5              24 |- PWM (a faire)             *
 *                  UART Rx -|  6              23 |- PWM (a faire)             *
 *                  UART Tx -|  7              22 |-                           *
 *                Vss (GND) +|  8              21 |-                           *
 *                 Quartz 1 +|  9              20 |+ VCap (Capa 10uF)          *
 *                 Quartz 2 +| 10              19 |+ Vss  (GND)                *
 *                          -| 11              18 |-                           *
 *                LED_VERTE -| 12              17 |-                           *
 *               Vdd (3.3V) +| 13              16 |-                           *
 *                          -| 14              15 |-                           *
 *                           |                    |                            *
 *                           ----------------------                            *
 *                                                                             *
 **                                                                           **
 ******************************************************************************/
 
 #include "../Include.h"
 
 void RemappablePinInitialisation()
 {
 	/* Configuration des Pins d'entrées. Cette définition ce fait fonction par
 	fonction. Pour chaque fonction, les définitions sont :
 		11111 = Input tied to VSS
		01111 = Input tied to RP15
		01110 = Input tied to RP14
		01101 = Input tied to RP13
		01100 = Input tied to RP12
		01011 = Input tied to RP11
		01010 = Input tied to RP10
		01001 = Input tied to RP9
		01000 = Input tied to RP8
		00111 = Input tied to RP7
		00110 = Input tied to RP6
		00101 = Input tied to RP5
		00100 = Input tied to RP4
		00011 = Input tied to RP3
		00010 = Input tied to RP2
		00001 = Input tied to RP1
		00000 = Input tied to RP0
	Par défaut, si vous n'utiliser pas la fonction, il faut mettre la valeur à
	11111 pour la mettre sur VSS */
	
	/* External Interrupt 1 */
    RPINR0bits.INT1R = 0b11111;
    
	/* External Interrupt 2 */
	RPINR1bits.INT2R = 0b11111;
	
    /* Timer 2 External Clock */
    RPINR3bits.T2CKR = 0b11111;
    
    /* Timer 3 External Clock */
    RPINR3bits.T3CKR = 0b11111;
    /* Timer 4 External Clock */
    RPINR4bits.T4CKR = 0b11111;
    
    /* Timer 5 External Clock */
    RPINR4bits.T5CKR = 0b11111;
    
    /* Input Capture 1 */
    RPINR7bits.IC1R = 0b11111;
    
    /* Input Capture 2 */
    RPINR7bits.IC2R = 0b11111;
    
    /* Input Capture 7 */
    RPINR10bits.IC7R = 0b11111;
    
    /* Input Capture 8 */
    RPINR10bits.IC8R = 0b11111;
    
    /* Output Compare Fault A */
    RPINR11bits.OCFAR = 0b11111;
    
    /* PWM1 Fault */
    RPINR12bits.FLTA1R = 0b11111;
    
    /* PWM2 Fault */
    RPINR13bits.FLTA2R = 0b11111;
    
    /* QEI1 Phase A */
    RPINR14bits.QEA1R = 0b11111;
    
    /* QEI1 Phase B */
    RPINR14bits.QEB1R = 0b11111;
    
    /* QEI1 Index */
    RPINR15bits.INDX1R = 0b11111;
    
    /* QEI2 Phase A */
    RPINR16bits.QEA2R = 0b11111;
    
    /* QEI2 Phase B */
    RPINR16bits.QEB2R = 0b11111;
    
    /* QEI2 Index */
    RPINR17bits.INDX2R = 0b11111;
    
    /* UART1 Receive */
    RPINR18bits.U1RXR = 0b11111;
    
    /* UART1 Clear To Send */
    RPINR18bits.U1CTSR = 0b11111;
    
    /* UART2 Receive */
    RPINR19bits.U2RXR = 0b00010;
    
    /* UART2 Clear To Send */
    RPINR19bits.U2CTSR = 0b11111;
    
    /* SPI1 Data Input */
    RPINR20bits.SDI1R = 0b11111;
    
    /* SPI1 Clock Input */
    RPINR20bits.SCK1R = 0b11111;
    
    /* SPI1 Slave Select Input */
    RPINR21bits.SS1R = 0b11111;
    
    /* SPI2 Data Input */
    RPINR22bits.SDI2R = 0b11111;
    
    /* SPI2 Clock Input */
    RPINR22bits.SCK2R = 0b11111;
    
    /* SPI2 Slave Select Input */
    RPINR23bits.SS2R = 0b11111;
    
    /* ECAN1 Receive */
    RPINR26bits.C1RXR = 0b11111;
 
 	
 	/* Configuration des Pins de sortie. Cette définition ce fait pin par pins.
 	On a les fonctions suivante :
 		11011 =  UPDN2 (QEI2 direction (UPDN) status)
 		11010 =  UPDN1 (QEI1 direction (UPDN) status)
 		10101 =  OC4   (Output Compare 4)
 		10100 =  OC3   (Output Compare 3)
 		10011 =  OC2   (Output Compare 2)
 		10010 =  OC1   (Output Compare 1)
 		10000 =  C1TX  (ECAN1 Transmit)
 		01100 = /SS2   (SPI2 Slave Select Output)
 		01011 =  SCK2  (SPI2 Clock Output)
 		01010 =  SDO2  (SPI2 Data Output)
 		01001 = /SS1   (SPI1 Slave Select Output)
 		01000 =  SCK1  (SPI1 Clock Output)
 		00111 =  SDO1  (SPI1 Data Output)
 		00110 = /U2RTS (UART2 Ready To Send)
 		00101 =  U2TX  (UART2 Transmit)
 		00100 = /U1RTS (UART1 Ready To Send)
 		00011 =  U1TX  (UART1 Transmit)
 		00010 =  C2OUT (Comparator 2 Output)
 		00001 =  C1OUT (Comparator 1 Output)
 		00000 =  NULL  (Default Port Pin)
	Par défaut, si vous n'utiliser pas la fonction, il faut mettre la valeur à
	11111 pour la mettre sur VSS */
	
	/* Pin reprogrammable 0 (pin 4)*/
    RPOR0bits.RP0R = 0b00000;
    
    /* Pin reprogrammable 1 (pin 5)*/
    RPOR0bits.RP1R = 0b00000;
    
    /* Pin reprogrammable 2 (pin 6)*/
    RPOR1bits.RP2R = 0b00000;
    
    /* Pin reprogrammable 3 (pin 7)*/
    RPOR1bits.RP3R = 0b00101;
    
    /* Pin reprogrammable 4 (pin 11)*/
    RPOR2bits.RP4R = 0b00000;
    
    /* Pin reprogrammable 5 (pin 14)*/
    RPOR2bits.RP5R = 0b00000;
    
    /* Pin reprogrammable 6 (pin 15)*/
    RPOR3bits.RP6R = 0b00000;
    
    /* Pin reprogrammable 7 (pin 16)*/
    RPOR3bits.RP7R = 0b00000;
    
    /* Pin reprogrammable 8 (pin 17)*/
    RPOR4bits.RP8R = 0b00000;
    
    /* Pin reprogrammable 9 (pin 18)*/
    RPOR4bits.RP9R = 0b00000;
    
    /* Pin reprogrammable 10 (pin 21)*/
    RPOR5bits.RP10R = 0b00000;
    
    /* Pin reprogrammable 11 (pin 22)*/
    RPOR5bits.RP11R = 0b00000;
    
    /* Pin reprogrammable 12 (pin 23)*/
    RPOR6bits.RP12R = 0b00000;
    
    /* Pin reprogrammable 13 (pin 24)*/
    RPOR6bits.RP13R = 0b00000;
    
    /* Pin reprogrammable 14 (pin 25)*/
    RPOR7bits.RP14R = 0b00000;
    
    /* Pin reprogrammable 15 (pin 26)*/
    RPOR7bits.RP15R = 0b00000;
 
 }
 
 void ConfigurationEntreeSortie()
 {
	 TRISAbits.TRISA0 = 0;
	 TRISAbits.TRISA1 = 0;
	 TRISAbits.TRISA2 = 0;
	 TRISAbits.TRISA3 = 0;
	 TRISAbits.TRISA4 = 0;
	 
	 TRISBbits.TRISB0 = 0;
	 TRISBbits.TRISB1 = 0;
	 TRISBbits.TRISB2 = 1;
	 TRISBbits.TRISB3 = 0;
	 TRISBbits.TRISB4 = 0;
	 TRISBbits.TRISB5 = 0;
	 TRISBbits.TRISB6 = 0;
	 TRISBbits.TRISB7 = 0;
	 TRISBbits.TRISB8 = 0;
	 TRISBbits.TRISB9 = 0;
	 TRISBbits.TRISB10 = 0;
	 TRISBbits.TRISB11 = 0;
	 TRISBbits.TRISB12 = 0;
	 TRISBbits.TRISB13 = 0;
	 TRISBbits.TRISB14 = 0;
	 TRISBbits.TRISB15 = 0;
	 
	 // Les entrées analogiques
	 AD1PCFGLbits.PCFG0 = 0;
	 AD1PCFGLbits.PCFG1 = 0;
	 AD1PCFGLbits.PCFG2 = 0;
	 AD1PCFGLbits.PCFG3 = 0;
	 AD1PCFGLbits.PCFG4 = 1;
	 AD1PCFGLbits.PCFG5 = 0;
	 
	
 }
