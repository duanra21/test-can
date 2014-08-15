/*******************************************************************************
 *******************************************************************************
 ******                                                                   ******
 ****                                                                       ****
 ****                       Fichier ConfigurationPic.c                      ****
 ****                          Configuration du pic                         ****
 ****                                                                       ****
 ******                                                                   ******
 ****                                                                       ****
 **** Commentaire :                                                         ****
 ****   Fichier de configuration du pic                                     ****
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
 
 /* Inclusion générale des fichiers */
 #include "../Include.h"

/*******************************************************************************
 ****                         BITS DE CONFIGURATION                         ****
 ******************************************************************************/
	_FBS(RBS_NO_RAM&BSS_NO_BOOT_CODE&BWRP_WRPROTECT_OFF)
	_FSS(RSS_NO_RAM&SSS_NO_FLASH&SWRP_WRPROTECT_OFF)
	_FGS(GSS_OFF&GCP_OFF&GWRP_OFF)
	_FOSCSEL(FNOSC_PRIPLL&IESO_ON)
	_FOSC(FCKSM_CSECME&IOL1WAY_OFF&OSCIOFNC_OFF&POSCMD_HS)
	_FWDT(FWDTEN_OFF&WINDIS_OFF&WDTPRE_PR32&WDTPOST_PS1)
	_FPOR(PWMPIN_ON&HPOL_ON&LPOL_ON&ALTI2C_OFF&FPWRT_PWR128)
	
