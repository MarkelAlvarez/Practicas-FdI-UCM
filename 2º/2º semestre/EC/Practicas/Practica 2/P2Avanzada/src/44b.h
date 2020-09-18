/*-------------------------------------------------------------------
**
**  Fichero:
**    44b.h  10/6/2014
**
**    (c) J.M. Mendias
**    Programaci�n de Sistemas y Dispositivos
**    Facultad de Inform�tica. Universidad Complutense de Madrid
**
**  Prop�sito:
**    Creaci�n de nemot�cnicos para los registros de los
**    controladores de dispositivos internos del chip S3C44BOX
**
**  Notas de dise�o:
**    Las direcciones usadas asumen un alineamiento little-endian
**
**-----------------------------------------------------------------*/

#ifndef __44B_H__
#define __44B_H__

#define _ISR_STARTADDRESS 	0xc7fff00

// DISPLAY
#define	LED8ADDR 	(*(volatile unsigned char *) 0x2140000)

/* Keyboard */
#define KEYBADDR    ((volatile unsigned char *)0x06000000)

/* System */
#define rSYSCFG		(*(volatile unsigned *)0x1c00000)

/* Cache */
#define rNCACHBE0	(*(volatile unsigned *)0x1c00004)
#define rNCACHBE1	(*(volatile unsigned *)0x1c00008)

/* Bus control */
#define rSBUSCON	(*(volatile unsigned *)0x1c40000)
    
/* Memory control */
#define rBWSCON		(*(volatile unsigned *)0x1c80000)
#define rBANKCON0	(*(volatile unsigned *)0x1c80004)
#define rBANKCON1	(*(volatile unsigned *)0x1c80008)
#define rBANKCON2	(*(volatile unsigned *)0x1c8000c)
#define rBANKCON3	(*(volatile unsigned *)0x1c80010)
#define rBANKCON4	(*(volatile unsigned *)0x1c80014)
#define rBANKCON5	(*(volatile unsigned *)0x1c80018)
#define rBANKCON6	(*(volatile unsigned *)0x1c8001c)
#define rBANKCON7	(*(volatile unsigned *)0x1c80020)
#define rREFRESH	(*(volatile unsigned *)0x1c80024)
#define rBANKSIZE	(*(volatile unsigned *)0x1c80028)
#define rMRSRB6		(*(volatile unsigned *)0x1c8002c)
#define rMRSRB7		(*(volatile unsigned *)0x1c80030)

/* UART */
#define rULCON0		(*(volatile unsigned *)0x1d00000)
#define rULCON1		(*(volatile unsigned *)0x1d04000)
#define rUCON0		(*(volatile unsigned *)0x1d00004)
#define rUCON1		(*(volatile unsigned *)0x1d04004)
#define rUFCON0		(*(volatile unsigned *)0x1d00008)
#define rUFCON1		(*(volatile unsigned *)0x1d04008)
#define rUMCON0		(*(volatile unsigned *)0x1d0000c)
#define rUMCON1		(*(volatile unsigned *)0x1d0400c)
#define rUTRSTAT0	(*(volatile unsigned *)0x1d00010)
#define rUTRSTAT1	(*(volatile unsigned *)0x1d04010)
#define rUERSTAT0	(*(volatile unsigned *)0x1d00014)
#define rUERSTAT1	(*(volatile unsigned *)0x1d04014)
#define rUFSTAT0	(*(volatile unsigned *)0x1d00018)
#define rUFSTAT1	(*(volatile unsigned *)0x1d04018)
#define rUMSTAT0	(*(volatile unsigned *)0x1d0001c)
#define rUMSTAT1	(*(volatile unsigned *)0x1d0401c)
#define rUBRDIV0	(*(volatile unsigned *)0x1d00028)
#define rUBRDIV1	(*(volatile unsigned *)0x1d04028)

#define rUTXH0		(*(volatile unsigned char *)0x1d00020)
#define rUTXH1		(*(volatile unsigned char *)0x1d04020)
#define rURXH0		(*(volatile unsigned char *)0x1d00024)
#define rURXH1		(*(volatile unsigned char *)0x1d04024)
#define WrUTXH0(ch)	(*(volatile unsigned char *)0x1d00020)=(unsigned char)(ch)
#define WrUTXH1(ch)	(*(volatile unsigned char *)0x1d04020)=(unsigned char)(ch)
#define RdURXH0()	(*(volatile unsigned char *)0x1d00024)
#define RdURXH1()	(*(volatile unsigned char *)0x1d04024)
#define UTXH0		(0x1d00020)    //byte_access address by BDMA
#define UTXH1		(0x1d04020)
#define URXH0		(0x1d00024)
#define URXH1		(0x1d04024)

/* SIO */
#define rSIOCON		(*(volatile unsigned *)0x1d14000)
#define rSIODAT		(*(volatile unsigned *)0x1d14004)
#define rSBRDR		(*(volatile unsigned *)0x1d14008)
#define rIVTCNT		(*(volatile unsigned *)0x1d1400c)
#define rDCNTZ		(*(volatile unsigned *)0x1d14010)

/* IIS */
#define rIISCON		(*(volatile unsigned *)0x1d18000)
#define rIISMOD		(*(volatile unsigned *)0x1d18004)
#define rIISPSR		(*(volatile unsigned *)0x1d18008)
#define rIISFCON	(*(volatile unsigned *)0x1d1800c)
#define IISFIF		((volatile unsigned short *)0x1d18010)

/* I/O PORT */
#define rPCONA		(*(volatile unsigned *)0x1d20000)
#define rPDATA		(*(volatile unsigned *)0x1d20004)

#define rPCONB		(*(volatile unsigned *)0x1d20008)
#define rPDATB		(*(volatile unsigned *)0x1d2000c)

#define rPCONC		(*(volatile unsigned *)0x1d20010)
#define rPDATC		(*(volatile unsigned *)0x1d20014)
#define rPUPC		(*(volatile unsigned *)0x1d20018)

#define rPCOND		(*(volatile unsigned *)0x1d2001c)
#define rPDATD		(*(volatile unsigned *)0x1d20020)
#define rPUPD		(*(volatile unsigned *)0x1d20024)

#define rPCONE		(*(volatile unsigned *)0x1d20028)
#define rPDATE		(*(volatile unsigned *)0x1d2002c)
#define rPUPE		(*(volatile unsigned *)0x1d20030)

#define rPCONF		(*(volatile unsigned *)0x1d20034)
#define rPDATF		(*(volatile unsigned *)0x1d20038)
#define rPUPF		(*(volatile unsigned *)0x1d2003c)

#define rPCONG		(*(volatile unsigned *)0x1d20040)
#define rPDATG		(*(volatile unsigned *)0x1d20044)
#define rPUPG		(*(volatile unsigned *)0x1d20048)

#define rSPUCR		(*(volatile unsigned *)0x1d2004c)
#define rEXTINT		(*(volatile unsigned *)0x1d20050)
#define rEXTINTPND	(*(volatile unsigned *)0x1d20054)

/* WATCHDOG */
#define rWTCON		(*(volatile unsigned *)0x1d30000)
#define rWTDAT		(*(volatile unsigned *)0x1d30004)
#define rWTCNT		(*(volatile unsigned *)0x1d30008)

/* ADC */
#define rADCCON		(*(volatile unsigned *)0x1d40000)
#define rADCPSR		(*(volatile unsigned *)0x1d40004)
#define rADCDAT		(*(volatile unsigned *)0x1d40008)

/* Timer */
#define rTCFG0		(*(volatile unsigned *)0x1d50000)
#define rTCFG1		(*(volatile unsigned *)0x1d50004)
#define rTCON		(*(volatile unsigned *)0x1d50008)

#define rTCNTB0		(*(volatile unsigned *)0x1d5000c)
#define rTCMPB0		(*(volatile unsigned *)0x1d50010)
#define rTCNTO0		(*(volatile unsigned *)0x1d50014)

#define rTCNTB1		(*(volatile unsigned *)0x1d50018)
#define rTCMPB1		(*(volatile unsigned *)0x1d5001c)
#define rTCNTO1		(*(volatile unsigned *)0x1d50020)

#define rTCNTB2		(*(volatile unsigned *)0x1d50024)
#define rTCMPB2		(*(volatile unsigned *)0x1d50028)
#define rTCNTO2		(*(volatile unsigned *)0x1d5002c)

#define rTCNTB3		(*(volatile unsigned *)0x1d50030)
#define rTCMPB3		(*(volatile unsigned *)0x1d50034)
#define rTCNTO3		(*(volatile unsigned *)0x1d50038)

#define rTCNTB4		(*(volatile unsigned *)0x1d5003c)
#define rTCMPB4		(*(volatile unsigned *)0x1d50040)
#define rTCNTO4		(*(volatile unsigned *)0x1d50044)

#define rTCNTB5		(*(volatile unsigned *)0x1d50048)
#define rTCNTO5		(*(volatile unsigned *)0x1d5004c)

/* SIO */
#define rSIOCON		(*(volatile unsigned *)0x1d14000)
#define rSIODAT		(*(volatile unsigned *)0x1d14004)
#define rSBRDR		(*(volatile unsigned *)0x1d14008)
#define rIVTCNT		(*(volatile unsigned *)0x1d1400c)
#define rDCNTZ		(*(volatile unsigned *)0x1d14010)

/* IIS */
#define rIISCON		(*(volatile unsigned *)0x1d18000)
#define rIISMOD		(*(volatile unsigned *)0x1d18004)
#define rIISPSR		(*(volatile unsigned *)0x1d18008)
#define rIISFCON	(*(volatile unsigned *)0x1d1800c)
#define rIISFIF		((volatile unsigned short *)0x1d18010)

/* IIC */
#define rIICCON     (*(volatile unsigned *)0x1d60000)
#define rIICSTAT    (*(volatile unsigned *)0x1d60004)
#define rIICADD     (*(volatile unsigned *)0x1d60008)
#define rIICDS      (*(volatile unsigned *)0x1d6000c)

/* RTC */
#define rRTCCON     (*(volatile unsigned char *)0x1d70040)
#define rRTCALM     (*(volatile unsigned char *)0x1d70050)
#define rALMSEC     (*(volatile unsigned char *)0x1d70054)
#define rALMMIN     (*(volatile unsigned char *)0x1d70058)
#define rALMHOUR    (*(volatile unsigned char *)0x1d7005c)
#define rALMDAY     (*(volatile unsigned char *)0x1d70060)
#define rALMMON     (*(volatile unsigned char *)0x1d70064)
#define rALMYEAR    (*(volatile unsigned char *)0x1d70068)
#define rRTCRST     (*(volatile unsigned char *)0x1d7006c)
#define rBCDSEC     (*(volatile unsigned char *)0x1d70070)
#define rBCDMIN     (*(volatile unsigned char *)0x1d70074)
#define rBCDHOUR    (*(volatile unsigned char *)0x1d70078)
#define rBCDDAY     (*(volatile unsigned char *)0x1d7007c)
#define rBCDDATE    (*(volatile unsigned char *)0x1d70080)
#define rBCDMON     (*(volatile unsigned char *)0x1d70084)
#define rBCDYEAR    (*(volatile unsigned char *)0x1d70088)
#define rTICINT     (*(volatile unsigned char *)0x1d7008c)

/* Clock & Power management */
#define rPLLCON		(*(volatile unsigned *)0x1d80000)
#define rCLKCON		(*(volatile unsigned *)0x1d80004)
#define rCLKSLOW	(*(volatile unsigned *)0x1d80008)
#define rLOCKTIME	(*(volatile unsigned *)0x1d8000c)

/* INTERRUPT */
#define rINTCON		(*(volatile unsigned *)0x1e00000)
#define rINTPND		(*(volatile unsigned *)0x1e00004)
#define rINTMOD		(*(volatile unsigned *)0x1e00008)
#define rINTMSK		(*(volatile unsigned *)0x1e0000c)

#define rI_PSLV		(*(volatile unsigned *)0x1e00010)
#define rI_PMST		(*(volatile unsigned *)0x1e00014)
#define rI_CSLV		(*(volatile unsigned *)0x1e00018)
#define rI_CMST		(*(volatile unsigned *)0x1e0001c)
#define rI_ISPR		(*(volatile unsigned *)0x1e00020)
#define rI_ISPC		(*(volatile unsigned *)0x1e00024)

#define rF_ISPR		(*(volatile unsigned *)0x1e00038)
#define rF_ISPC		(*(volatile unsigned *)0x1e0003c)

/* LCD */
#define rLCDCON1	(*(volatile unsigned *)0x1f00000)
#define rLCDCON2	(*(volatile unsigned *)0x1f00004)
#define rLCDCON3	(*(volatile unsigned *)0x1f00040)
#define rLCDSADDR1	(*(volatile unsigned *)0x1f00008)
#define rLCDSADDR2	(*(volatile unsigned *)0x1f0000c)
#define rLCDSADDR3	(*(volatile unsigned *)0x1f00010)
#define rREDLUT		(*(volatile unsigned *)0x1f00014)
#define rGREENLUT	(*(volatile unsigned *)0x1f00018)
#define rBLUELUT	(*(volatile unsigned *)0x1f0001c)
#define rDP1_2		(*(volatile unsigned *)0x1f00020)
#define rDP4_7		(*(volatile unsigned *)0x1f00024)
#define rDP3_5		(*(volatile unsigned *)0x1f00028)
#define rDP2_3		(*(volatile unsigned *)0x1f0002c)
#define rDP5_7		(*(volatile unsigned *)0x1f00030)
#define rDP3_4		(*(volatile unsigned *)0x1f00034)
#define rDP4_5		(*(volatile unsigned *)0x1f00038)
#define rDP6_7		(*(volatile unsigned *)0x1f0003c)
#define rDITHMODE	(*(volatile unsigned *)0x1f00044)

/* ZDMA0 */
#define rZDCON0		(*(volatile unsigned *)0x1e80000)
#define rZDISRC0	(*(volatile unsigned *)0x1e80004)
#define rZDIDES0	(*(volatile unsigned *)0x1e80008)
#define rZDICNT0	(*(volatile unsigned *)0x1e8000c)
#define rZDCSRC0	(*(volatile unsigned *)0x1e80010)
#define rZDCDES0	(*(volatile unsigned *)0x1e80014)
#define rZDCCNT0	(*(volatile unsigned *)0x1e80018)

/* ZDMA1 */
#define rZDCON1		(*(volatile unsigned *)0x1e80020)
#define rZDISRC1	(*(volatile unsigned *)0x1e80024)
#define rZDIDES1	(*(volatile unsigned *)0x1e80028)
#define rZDICNT1	(*(volatile unsigned *)0x1e8002c)
#define rZDCSRC1	(*(volatile unsigned *)0x1e80030)
#define rZDCDES1	(*(volatile unsigned *)0x1e80034)
#define rZDCCNT1	(*(volatile unsigned *)0x1e80038)

/* BDMA0 */
#define rBDCON0		(*(volatile unsigned *)0x1f80000)
#define rBDISRC0	(*(volatile unsigned *)0x1f80004)
#define rBDIDES0	(*(volatile unsigned *)0x1f80008)
#define rBDICNT0	(*(volatile unsigned *)0x1f8000c)
#define rBDCSRC0	(*(volatile unsigned *)0x1f80010)
#define rBDCDES0	(*(volatile unsigned *)0x1f80014)
#define rBDCCNT0	(*(volatile unsigned *)0x1f80018)

/* BDMA1 */
#define rBDCON1		(*(volatile unsigned *)0x1f80020)
#define rBDISRC1	(*(volatile unsigned *)0x1f80024)
#define rBDIDES1	(*(volatile unsigned *)0x1f80028)
#define rBDICNT1	(*(volatile unsigned *)0x1f8002c)
#define rBDCSRC1	(*(volatile unsigned *)0x1f80030)
#define rBDCDES1	(*(volatile unsigned *)0x1f80034)
#define rBDCCNT1	(*(volatile unsigned *)0x1f80038)

/* ISR */
#define pISR_RESET	(*(unsigned *)(_ISR_STARTADDRESS+0x0))
#define pISR_UNDEF	(*(unsigned *)(_ISR_STARTADDRESS+0x4))
#define pISR_SWI	(*(unsigned *)(_ISR_STARTADDRESS+0x8))
#define pISR_PABORT	(*(unsigned *)(_ISR_STARTADDRESS+0xc))
#define pISR_DABORT	(*(unsigned *)(_ISR_STARTADDRESS+0x10))
#define pISR_RESERVED	(*(unsigned *)(_ISR_STARTADDRESS+0x14))
#define pISR_IRQ	(*(unsigned *)(_ISR_STARTADDRESS+0x18))
#define pISR_FIQ	(*(unsigned *)(_ISR_STARTADDRESS+0x1c))
#define pISR_ADC	(*(unsigned *)(_ISR_STARTADDRESS+0x20))
#define pISR_RTC	(*(unsigned *)(_ISR_STARTADDRESS+0x24))
#define pISR_UTXD1	(*(unsigned *)(_ISR_STARTADDRESS+0x28))
#define pISR_UTXD0	(*(unsigned *)(_ISR_STARTADDRESS+0x2c))
#define pISR_SIO	(*(unsigned *)(_ISR_STARTADDRESS+0x30))
#define pISR_IIC	(*(unsigned *)(_ISR_STARTADDRESS+0x34))
#define pISR_URXD1	(*(unsigned *)(_ISR_STARTADDRESS+0x38))
#define pISR_URXD0	(*(unsigned *)(_ISR_STARTADDRESS+0x3c))
#define pISR_TIMER5	(*(unsigned *)(_ISR_STARTADDRESS+0x40))
#define pISR_TIMER4	(*(unsigned *)(_ISR_STARTADDRESS+0x44))
#define pISR_TIMER3	(*(unsigned *)(_ISR_STARTADDRESS+0x48))
#define pISR_TIMER2	(*(unsigned *)(_ISR_STARTADDRESS+0x4c))
#define pISR_TIMER1	(*(unsigned *)(_ISR_STARTADDRESS+0x50))
#define pISR_TIMER0	(*(unsigned *)(_ISR_STARTADDRESS+0x54))
#define pISR_UERR01	(*(unsigned *)(_ISR_STARTADDRESS+0x58))
#define pISR_WDT	(*(unsigned *)(_ISR_STARTADDRESS+0x5c))
#define pISR_BDMA1	(*(unsigned *)(_ISR_STARTADDRESS+0x60))
#define pISR_BDMA0	(*(unsigned *)(_ISR_STARTADDRESS+0x64))
#define pISR_ZDMA1	(*(unsigned *)(_ISR_STARTADDRESS+0x68))
#define pISR_ZDMA0	(*(unsigned *)(_ISR_STARTADDRESS+0x6c))
#define pISR_TICK	(*(unsigned *)(_ISR_STARTADDRESS+0x70))
#define pISR_EINT4567	(*(unsigned *)(_ISR_STARTADDRESS+0x74))
#define pISR_EINT3	(*(unsigned *)(_ISR_STARTADDRESS+0x78))
#define pISR_EINT2	(*(unsigned *)(_ISR_STARTADDRESS+0x7c))
#define pISR_EINT1	(*(unsigned *)(_ISR_STARTADDRESS+0x80))
#define pISR_EINT0	(*(unsigned *)(_ISR_STARTADDRESS+0x84))

enum enable {
	DISABLE = 0,
	ENABLE = 1
};


#endif /* __44B_H__ */

