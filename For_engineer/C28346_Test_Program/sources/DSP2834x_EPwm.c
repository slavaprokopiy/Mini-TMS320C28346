// TI File $Revision: /main/3 $
// Checkin $Date: August 1, 2008   16:35:35 $
//###########################################################################
//
// FILE:   DSP2834x_EPwm.c
//
// TITLE:  DSP2834x ePWM Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2834x Header Files V1.12 $
// $Release Date: March 2011 $
//###########################################################################

#include "DSP2834x_Device.h"     // DSP2834x Headerfile Include File
#include "DSP2834x_Examples.h"   // DSP2834x Examples Include File

//---------------------------------------------------------------------------
// InitEPwm:
//---------------------------------------------------------------------------
// This function initializes the ePWM(s) to a known state.
//
void InitEPwm(void)
{
	// Initialize ePWM1/2/3/4/5/6
	// Sets up the ePWM module for triggering CONVST for ADC2
	EALLOW;

	// Setup ePWM 1
	EPwm1Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;		// Set Immediate load
	EPwm1Regs.TBPRD = 0x2000;	 					// PWM frequency = 1 / period.
	EPwm1Regs.TBPHS.half.TBPHS = 0;
	EPwm1Regs.CMPA.half.CMPA = 0;					// Set duty 0% initially
	EPwm1Regs.CMPB = 0;								// Set duty 0% initially
	EPwm1Regs.TBCTR = 0;
	EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm1Regs.ETSEL.bit.SOCAEN = 0x1;   			// Enable extsoc1a event
	EPwm1Regs.ETSEL.bit.SOCASEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm1Regs.ETPS.bit.SOCAPRD = 0x1;   			// Generate SoC on first event

	EPwm1Regs.ETSEL.bit.SOCBEN = 0x1;   			// Enable extsoc1b event
	EPwm1Regs.ETSEL.bit.SOCBSEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm1Regs.ETPS.bit.SOCBPRD = 0x1;   			// Generate SoC on first event

	// Enable extsoc1B set polarity
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1AEN = 0x0;     // Disable extsoc1a
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1APOLSEL= 0x0;  // Set normal polarity

	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1BEN = 0x0;     // Disable extsoc1b
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1BPOLSEL= 0x0;  // Set normal polarity

	// Setup SOCADCCLK to run at 25Mhz
	SysCtrlRegs.HISPCP.bit.HSPCLK = 0x3;			// HSPCLK=SYSCLKOUT/8 (25Mhz)

	// Setup ePWM 4
	EPwm4Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;		// Set Immediate load
	EPwm4Regs.TBPRD = 0x2000;	 					// PWM frequency = 1 / period.
	EPwm4Regs.TBPHS.half.TBPHS = 0;
	EPwm4Regs.CMPA.half.CMPA = 0;					// Set duty 0% initially
	EPwm4Regs.CMPB = 0;								// Set duty 0% initially
	EPwm4Regs.TBCTR = 0;
	EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm4Regs.ETSEL.bit.SOCAEN = 0x1;   			// Enable extsoc1a event
	EPwm4Regs.ETSEL.bit.SOCASEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm4Regs.ETPS.bit.SOCAPRD = 0x1;   			// Generate SoC on first event

	EPwm4Regs.ETSEL.bit.SOCBEN = 0x1;   			// Enable extsoc1b event
	EPwm4Regs.ETSEL.bit.SOCBSEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm4Regs.ETPS.bit.SOCBPRD = 0x1;   			// Generate SoC on first event

	// Enable extsoc1B set polarity
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2AEN = 0x0;     // Disable extsoc1a
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2APOLSEL= 0x0;  // Set normal polarity

	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2BEN = 0x0;     // Disable extsoc1b
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2BPOLSEL= 0x0;  // Set normal polarity

	// Setup ePWM 7
	EPwm7Regs.TBCTL.bit.PRDLD = TB_IMMEDIATE;		// Set Immediate load
	EPwm7Regs.TBPRD = 0x2000;	 					// PWM frequency = 1 / period.
	EPwm7Regs.TBPHS.half.TBPHS = 0;
	EPwm7Regs.CMPA.half.CMPA = 0;					// Set duty 0% initially
	EPwm7Regs.CMPB = 0;								// Set duty 0% initially
	EPwm7Regs.TBCTR = 0;
	EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
	EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;
	EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV1;

	EPwm7Regs.ETSEL.bit.SOCAEN = 0x1;   			// Enable extsoc1a event
	EPwm7Regs.ETSEL.bit.SOCASEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm7Regs.ETPS.bit.SOCAPRD = 0x1;   			// Generate SoC on first event

	EPwm7Regs.ETSEL.bit.SOCBEN = 0x1;   			// Enable extsoc1b event
	EPwm7Regs.ETSEL.bit.SOCBSEL = 0x2;  			// Set event to happen on TBCTR = TBPRD
	EPwm7Regs.ETPS.bit.SOCBPRD = 0x1;   			// Generate SoC on first event

	// Enable extsoc1B set polarity
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3AEN = 0x0;     // Disable extsoc1a
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3APOLSEL= 0x0;  // Set normal polarity

	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3BEN = 0x0;     // Disable extsoc1b
	SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3BPOLSEL= 0x0;  // Set normal polarity

	EDIS;
   //tbd...

}

//---------------------------------------------------------------------------
// Example: InitEPwmGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//

void InitEPwmGpio(void)
{
   InitEPwm1Gpio();
   InitEPwm2Gpio();
   InitEPwm3Gpio();
#if DSP28_EPWM4
   InitEPwm4Gpio();
#endif // endif DSP28_EPWM4
#if DSP28_EPWM5
   InitEPwm5Gpio();
#endif // endif DSP28_EPWM5
#if DSP28_EPWM6
   InitEPwm6Gpio();
#endif // endif DSP28_EPWM6
#if DSP28_EPWM7
   InitEPwm7Gpio();
#endif // endif DSP28_EPWM7
#if DSP28_EPWM8
   InitEPwm8Gpio();
#endif // endif DSP28_EPWM8
#if DSP28_EPWM9
   InitEPwm9Gpio();
#endif // endif DSP28_EPWM9
}

void InitEPwm1Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;    // Disable pull-up on GPIO0 (EPWM1A)
    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up on GPIO1 (EPWM1B)

/* Configure ePWM-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM1 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;   // Configure GPIO0 as EPWM1A
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;   // Configure GPIO1 as EPWM1B

    EDIS;
}

void InitEPwm2Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO2 = 1;    // Disable pull-up on GPIO2 (EPWM2A)
    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up on GPIO3 (EPWM3B)

/* Configure ePWM-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM2 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;   // Configure GPIO2 as EPWM2A
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;   // Configure GPIO3 as EPWM2B

    EDIS;
}

void InitEPwm3Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO4 = 1;    // Disable pull-up on GPIO4 (EPWM3A)
    GpioCtrlRegs.GPAPUD.bit.GPIO5 = 1;    // Disable pull-up on GPIO5 (EPWM3B)

/* Configure ePWM-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM3 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;   // Configure GPIO4 as EPWM3A
    GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;   // Configure GPIO5 as EPWM3B

    EDIS;
}


#if DSP28_EPWM4
void InitEPwm4Gpio(void)
{
   EALLOW;
/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;    // Disable pull-up on GPIO6 (EPWM4A)
    GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;    // Disable pull-up on GPIO7 (EPWM4B)

/* Configure ePWM-4 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM4 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;   // Configure GPIO6 as EPWM4A
    GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;   // Configure GPIO7 as EPWM4B

    EDIS;
}
#endif // endif DSP28_EPWM4


#if DSP28_EPWM5
void InitEPwm5Gpio(void)
{
   EALLOW;
/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;    // Disable pull-up on GPIO8 (EPWM5A)
    GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;    // Disable pull-up on GPIO9 (EPWM5B)

/* Configure ePWM-5 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM5 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;   // Configure GPIO8 as EPWM5A
    GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;   // Configure GPIO9 as EPWM5B

    EDIS;
}
#endif // endif DSP28_EPWM5


#if DSP28_EPWM6
void InitEPwm6Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // Disable pull-up on GPIO10 EPWM6A
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // Disable pull-up on GPIO11 EPWM6B

/* Configure ePWM-6 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;   // Configure GPIO10 as EPWM6A
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EPWM6B

    EDIS;
}
#endif // endif DSP28_EPWM6

#if DSP28_EPWM7
void InitEPwm7Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 1;    // Disable pull-up on GPIO58 EPWM7A
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 1;    // Disable pull-up on GPIO59 EPWM7B

/* Configure ePWM-7 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 3;   // Configure GPIO58 as EPWM7A
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3;   // Configure GPIO59 as EPWM7B

    EDIS;
}
#endif // endif DSP28_EPWM7

#if DSP28_EPWM8
void InitEPwm8Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBPUD.bit.GPIO60 = 1;    // Disable pull-up on GPIO60 EPWM8A
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 1;    // Disable pull-up on GPIO61 EPWM8B

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 3;   // Configure GPIO60 as EPWM8A
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 3;   // Configure GPIO61 as EPWM8B

    EDIS;
}
#endif // endif DSP28_EPWM8

#if DSP28_EPWM9
void InitEPwm9Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBPUD.bit.GPIO62 = 1;    // Disable pull-up on GPIO62 EPWM9A
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;    // Disable pull-up on GPIO63 EPWM9B

/* Configure ePWM-9 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be ePWM6 functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 3;   // Configure GPIO62 as EPWM9A
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 3;   // Configure GPIO63 as EPWM9B

    EDIS;
}
#endif // endif DSP28_EPWM9

//---------------------------------------------------------------------------
// Example: InitEPwmSyncGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ePWM Synch pins
//

void InitEPwmSyncGpio(void)
{

   EALLOW;

/* Configure EPWMSYNCI  */

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO6 = 0;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;   // Enable pull-up on GPIO32 (EPWMSYNCI)

/* Set qualification for selected pins to asynch only */
// This will select synch to SYSCLKOUT for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;   // Synch to SYSCLKOUT GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 0;  // Synch to SYSCLKOUT GPIO32 (EPWMSYNCI)

/* Configure EPwmSync pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be EPwmSync functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 2;    // Enable pull-up on GPIO6 (EPWMSYNCI)
// GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 2;   // Enable pull-up on GPIO32 (EPWMSYNCI)



/* Configure EPWMSYNC0  */

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

// GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;    // Disable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBPUD.bit.GPIO33 = 1;   // Disable pull-up on GPIO33 (EPWMSYNC0)

// GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 3;    // Enable pull-up on GPIO6 (EPWMSYNC0)
   GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 2;   // Enable pull-up on GPIO33 (EPWMSYNC0)

}



//---------------------------------------------------------------------------
// Example: InitTzGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as Trip Zone (TZ) pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//

void InitTzGpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;    // Enable pull-up on GPIO12 (TZ1)
   GpioCtrlRegs.GPAPUD.bit.GPIO13 = 0;    // Enable pull-up on GPIO13 (TZ2)
   GpioCtrlRegs.GPAPUD.bit.GPIO14 = 0;    // Enable pull-up on GPIO14 (TZ3)
   GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;    // Enable pull-up on GPIO15 (TZ4)

   GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;    // Enable pull-up on GPIO16 (TZ5)
// GpioCtrlRegs.GPAPUD.bit.GPIO28 = 0;    // Enable pull-up on GPIO28 (TZ5)

   GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;    // Enable pull-up on GPIO17 (TZ6)
// GpioCtrlRegs.GPAPUD.bit.GPIO29 = 0;    // Enable pull-up on GPIO29 (TZ6)

/* Set qualification for selected pins to asynch only */
// Inputs are synchronized to SYSCLKOUT by default.
// This will select asynch (no qualification) for the selected pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3;  // Asynch input GPIO12 (TZ1)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3;  // Asynch input GPIO13 (TZ2)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;  // Asynch input GPIO14 (TZ3)
   GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;  // Asynch input GPIO15 (TZ4)

   GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;  // Asynch input GPIO16 (TZ5)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 3;  // Asynch input GPIO28 (TZ5)

   GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;  // Asynch input GPIO17 (TZ6)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 3;  // Asynch input GPIO29 (TZ6)


/* Configure TZ pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be TZ functional pins.
// Comment out other unwanted lines.
   GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;  // Configure GPIO12 as TZ1
   GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;  // Configure GPIO13 as TZ2
   GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;  // Configure GPIO14 as TZ3
   GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;  // Configure GPIO15 as TZ4

   GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;  // Configure GPIO16 as TZ5
// GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 3;  // Configure GPIO28 as TZ5

   GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;  // Configure GPIO17 as TZ6
// GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 3;  // Configure GPIO29 as TZ6

   EDIS;
}



//===========================================================================
// End of file.
//===========================================================================
