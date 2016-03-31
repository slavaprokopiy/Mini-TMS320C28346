/*
 * PinsTest.c
 *
 *  Created on: 11.05.2013
 *      Author: prokopiy
 */
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

void PinsInitForTest(void);
void GpioTest(void);
void SocPinsTest(void);
void GPIOError(void);
void GPIOGood(void);


int PinError = 0;

void scia_msg(char *msg);
extern char *msg;

void PinsTest(void){
	PinsInitForTest();	// Инициализация тестируемых выводов
	GpioTest();			// Проверка выводов GPIO
	SocPinsTest();		// Проверка выводов EXTSOC и EXTADCCLK
}

void PinsInitForTest(void){

	   GpioCtrlRegs.GPADIR.all = 0xFFFF;      // GPIO0-GPIO31 are outputs
	   GpioCtrlRegs.GPBDIR.all = 0xFFFF;      // GPIO32-GPIO63 are outputs
	   GpioCtrlRegs.GPCDIR.all = 0xFFFF;      // GPI064-GPIO95 are outputs

	   //Odd side (1-49)
	   GpioCtrlRegs.GPAMUX1.bit.GPIO6	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO12	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO5	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO8	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO10	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO15	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO18	=	0;// GPIO functionality //SPICLKA
	   GpioCtrlRegs.GPAMUX2.bit.GPIO26	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO19	=	0;// GPIO functionality//SPISTEA
	   GpioCtrlRegs.GPAMUX2.bit.GPIO21	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO24	=	0;// GPIO functionality
	   GpioCtrlRegs.GPBMUX1.bit.GPIO33	=	0;// GPIO functionality//SCLA

	   GpioCtrlRegs.GPADIR.bit.GPIO6	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO12	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO5	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO8	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO10	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO15	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO18	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO26	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO19	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO21	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO24	= 0;// Input
	   GpioCtrlRegs.GPBDIR.bit.GPIO33	= 0;// Input

	   GpioCtrlRegs.GPAPUD.bit.GPIO6	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO12	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO5	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO8	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO10	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO15	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO18	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO26	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO19	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO21	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO24	= 0;// Pullup enabled
	   GpioCtrlRegs.GPBPUD.bit.GPIO33	= 0;// Pullup enabled

	   //Even side (2-50)
	   GpioCtrlRegs.GPAMUX1.bit.GPIO3	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO9	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO14	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO1	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO4	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO7	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO11	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX1.bit.GPIO13	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO16	=	0;// GPIO functionality//SPISIMOA
	   GpioCtrlRegs.GPAMUX2.bit.GPIO17	=	0;// GPIO functionality//SPISOMIA
	   GpioCtrlRegs.GPAMUX2.bit.GPIO23	=	0;// GPIO functionality
	   //EXTSOC1B
	   //EXTSOC1A
	   //EXTSOC2B
	   //EXTSOC2A
	   //EXTSOC3A
	   //EXTSOC3B
	   //EXTADCCLK
	   GpioCtrlRegs.GPAMUX2.bit.GPIO20	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO22	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO25	=	0;// GPIO functionality
	   GpioCtrlRegs.GPAMUX2.bit.GPIO27	=	0;// GPIO functionality
	   GpioCtrlRegs.GPBMUX1.bit.GPIO32	=	0;// GPIO functionality//SDA

	   GpioCtrlRegs.GPADIR.bit.GPIO3	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO9	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO14	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO1	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO4	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO7	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO11	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO13	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO16	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO17	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO23	= 0;// Input
	   //EXTSOC1B
	   //EXTSOC1A
	   //EXTSOC2B
	   //EXTSOC2A
	   //EXTSOC3A
	   //EXTSOC3B
	   //EXTADCCLK
	   GpioCtrlRegs.GPADIR.bit.GPIO20	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO22	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO25	= 0;// Input
	   GpioCtrlRegs.GPADIR.bit.GPIO27	= 0;// Input
	   GpioCtrlRegs.GPBDIR.bit.GPIO32	= 0;// Input

	   GpioCtrlRegs.GPAPUD.bit.GPIO3	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO9	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO14	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO1	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO4	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO7	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO11	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO13	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO16	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO17	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO23	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO20	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO22	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO25	= 0;// Pullup enabled
	   GpioCtrlRegs.GPAPUD.bit.GPIO27	= 0;// Pullup enabled
	   GpioCtrlRegs.GPBPUD.bit.GPIO32	= 0;// Pullup enabled
}

void GpioTest(void){
// Odd side
	msg = "GPIO Test. Connect specified pin to DGND:\r\0";
    scia_msg(msg);

    //GPIO6
    msg = "GPIO6(X6:3) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO6 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO6 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO12
    msg = "\GPIO12(X6:5) - \0";
            scia_msg(msg);
	if(GpioDataRegs.GPADAT.bit.GPIO12 == 0){
		GPIOError();
	}
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO12 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

	//GPIO5
	msg = "GPIO5(X6:9) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO5 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO5 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO8
    msg = "GPIO8(X6:11) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO8 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO8 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO10
    msg = "GPIO10(X6:15) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO10 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO10 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO15
    msg = "GPIO15(X6:17) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO15 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO15 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO18
    msg = "GPIO18/SPICLKA(X6:21) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO18 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO18 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO26
    msg = "GPIO26(X6:23) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO26 == 0){
    	GPIOError();
    	}
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO26 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO19
    msg = "GPIO19/SPISTEA(X6:39) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO19 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO19 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO21
    msg = "GPIO21(X6:41) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO21 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO21 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO24
    msg = "GPIO24(X6:45) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO12 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO24 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO33
    msg = "GPIO33/SCLA(X6:47) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPBDAT.bit.GPIO33 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPBDAT.bit.GPIO33 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    // Even side
    //GPIO3
    msg = "GPIO3(X6:4) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO3 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }
    //GPIO9
    msg = "GPIO9(X6:6) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO9 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO9 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO14
    DINT;
    GpioDataRegs.GPASET.bit.GPIO14 = 1;
    msg = "GPIO14(X6:8) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO12 == 0){
    	GPIOError();
   	}
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO14 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    	EINT;
    }

    //GPIO1
    msg = "GPIO1(X6:10) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO1 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO1 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO4
    msg = "GPIO4(X6:12) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO12 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO4 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO7
    msg = "GPIO7(X6:14) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO7 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO7 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO11
    msg = "GPIO11(X6:16) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO11 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO11 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO13
    msg = "GPIO13(X6:18) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO13 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO13 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO16
    msg = "GPIO16/SPISIMOA(X6:20) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO16 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO16 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO17
    msg = "GPIO17/SPISOMIA(X6:22) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO17 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO17 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO23
    msg = "GPIO23(X6:24) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO23 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO23 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO20
    msg = "GPIO20(X6:40) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO20 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO20 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO22
    msg = "GPIO22(X6:42) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO22 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO22 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO25
    msg = "GPIO25(X6:44) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO25 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO25 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO27
    msg = "GPIO27(X6:46) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPADAT.bit.GPIO27 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPADAT.bit.GPIO27 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }

    //GPIO32
    msg = "GPIO32/SDA(X6:48) - \0";
    scia_msg(msg);
    if(GpioDataRegs.GPBDAT.bit.GPIO32 == 0){
    	GPIOError();
    }
    else{
    	while(GpioDataRegs.GPBDAT.bit.GPIO32 == 1){;}	// Пока пин не равен единице - ждем
    	GPIOGood();
    }
    if(!PinError){
    	msg = "All GPIO's are OK!\r===========================\r\0";
    	scia_msg(msg);
    }
    else{
    	msg = "GPIO Test is finished with errors!\r===========================\r\0";
    	scia_msg(msg);
    }

}

void SocPinsTest(void){
	InitEPwm();		// Инициализируем модули ШИМ, которые формируют сигналы EXTSOCxxEN

	msg = "EXTSOC Pins Test. Connect specified pin to X6:4 :\r\0";
    scia_msg(msg);
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1BEN = 0x1;     // Enable extsoc1b
    EDIS;
    msg = "EXTSOC1B(X6:26) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1BEN = 0x0;     // Disable extsoc1b
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 != 1){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1AEN = 0x1;     // Enable extsoc1a
    EDIS;
    msg = "EXTSOC1A(X6:28) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC1AEN = 0x0;     // Disable extsoc1a
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2AEN = 0x1;     // Enable extsoc2a
    EDIS;
    msg = "EXTSOC2A(X6:30) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2AEN = 0x0;     // Disable extsoc2a
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2BEN = 0x1;     // Enable extsoc2b
    EDIS;
    msg = "EXTSOC2B(X6:32) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC2BEN = 0x0;     // Disable extsoc2b
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3AEN = 0x1;     // Enable extsoc3a
    EDIS;
    msg = "EXTSOC3A(X6:34) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3AEN = 0x0;     // Disable extsoc3a
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3BEN = 0x1;     // Enable extsoc3b
    EDIS;
    msg = "EXTSOC3B(X6:36) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    EALLOW;
    SysCtrlRegs.EXTSOCCFG.bit.EXTSOC3BEN = 0x0;     // Disable extsoc3b
    EDIS;
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    msg = "EXTADCCLK(X6:38) - \0";
    scia_msg(msg);
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 1){;}	// Пока пин не равен единице - ждем
    while(GpioDataRegs.GPADAT.bit.GPIO3 == 0){;}	// Пока пин не равен нулю - ждем
    msg = "OK;\r\0";
    scia_msg(msg);

    msg = "All EXTSOC Pins  are OK!\r===========================\r\0";
    scia_msg(msg);
}

void GPIOError(void){
	msg = "ERROR, pin is shorted to DGND without user actions;\r\0";
	scia_msg(msg);
	PinError = 1;
}
void GPIOGood(void){
	msg = "OK;\r\0";
	scia_msg(msg);
}
