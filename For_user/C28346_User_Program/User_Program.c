/*C:\TI\workspace_v5_3\Mini-TMS320C28346\For_user\C28346_User_Program\Debug\test.bat
 * "${CG_TOOL_HEX}"  "${BuildArtifactFileName}" -boot -spi8  -a
 * main.c
 * Программа проверки выводов модуля
 */
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

// Prototype statements for functions found within this file.

#pragma CODE_SECTION(cpu_timer0_isr,"xintffuncs");	// Обработчик прерывания таймера будет выполняться из внешней PSRAM памяти
interrupt void cpu_timer0_isr(void);
#pragma CODE_SECTION(UserProgram,"xintffuncs");// Главная программа будет выполняться из внешней PSRAM памяти
void UserProgram(void);

void scia_echoback_init(void);
void scia_fifo_init(void);
void scia_xmit(int a);
void scia_msg(char *msg);
char *msg;
Uint16 ReceivedChar;
Uint16 LoopCount;
Uint16 ErrorCount;


//SPI block =======================================
void spi_init(void);



void InitXintf(void);
void MemClear(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);
void PSRAMTest(void);


void I2CMemoryTest(void);




void PinsTest(void);
void InitPeripherial(void);

int main(void) {
	// Step 0. Variables:

	// Step 1. Initialize System Control:
	// PLL, WatchDog, enable Peripheral Clocks
	// This example function is found in the DSP2834x_SysCtrl.c file.
	   InitSysCtrl();

	// Step 2. Initalize GPIO:
	   InitGpio();

	// Step 3. Clear all interrupts and initialize PIE vector table:
	// Disable CPU interrupts
	   DINT;

	// Initialize PIE control registers to their default state.
	// The default state is all PIE interrupts disabled and flags
	// are cleared.
	// This function is found in the DSP2834x_PieCtrl.c file.
	   InitPieCtrl();

	// Disable CPU interrupts and clear all CPU interrupt flags:
	   IER = 0x0000;
	   IFR = 0x0000;

	// Initialize the PIE vector table with pointers to the shell Interrupt
	// Service Routines (ISR).
	// This will populate the entire table, even if the interrupt
	// is not used in this example.  This is useful for debug purposes.
	// The shell ISR routines are found in DSP2834x_DefaultIsr.c.
	// This function is found in DSP2834x_PieVect.c.
	   InitPieVectTable();
	// Step 4. Initialize all the Device Peripherals:
	   InitXintf(); // Инициализация интерфейса памяти PSRAM
	   InitPeripherial(); // Инициализация UART, Таймера, и отправка приветственного сообщения по UART
	//Step 5. User specific code:
	   MemCopy(&XintffuncsLoadStart, &XintffuncsLoadEnd, &XintffuncsRunStart);	// Копируем код обработчика прерывания таймера и функцию UserProgram() во внешнее ОЗУ
	   UserProgram();	// Запуск основной программы из внешней RAM

	   return 0;
}

void UserProgram(void){

	msg = "Hello! This is a test programm for Mini-TMS320C28346.\rNow Mini-TMS320C28346 is working in demo SCI-loop-back mode.\r\0";
	scia_msg(msg);

	//Прием символа и отправка его же обратно
	for(;;){
		msg = "\r\nEnter a character: \0";
		scia_msg(msg);

		// Wait for inc character
		while(SciaRegs.SCIFFRX.bit.RXFFST !=1) { } // wait for XRDY =1 for empty state

		// Get character
		ReceivedChar = SciaRegs.SCIRXBUF.all;

		// Echo character back
		msg = "  You sent: \0";
		scia_msg(msg);
		scia_xmit(ReceivedChar);

		LoopCount++;
	}
}
void InitPeripherial(void){
	   //==========	SCI	=========================
	InitSciaGpio();			// Initialize SCI Pins
	scia_fifo_init();	   	// Initialize the SCI FIFO
	scia_echoback_init();	// Initalize SCI for echoback

	   //========= Green Led Pin - output
	   EALLOW;
	   GpioCtrlRegs.GPADIR.bit.GPIO14 = 1; //LED1 pin - output
	   EDIS;
	   //==========	TIMER =========================
	   InitCpuTimers();
	   // Configure CPU-Timer 0 to interrupt every 500 milliseconds:
	   // 300MHz CPU Freq, 50 millisecond Period (in uSeconds)
	   ConfigCpuTimer(&CpuTimer0, 300, 500000);
	   // To ensure precise timing, use write-only instructions to write to the entire register. Therefore, if any
	   // of the configuration bits are changed in ConfigCpuTimer and InitCpuTimers (in DSP2834x_CpuTimers.h), the
	   // below settings must also be updated.
	   CpuTimer0Regs.TCR.all = 0x4001; // Use write-only instruction to set TSS bit = 0

	   // Interrupts that are used in this example are re-mapped to
	   // ISR functions found within this file.
	   EALLOW;  // This is needed to write to EALLOW protected registers
	   PieVectTable.TINT0 = &cpu_timer0_isr;
	   EDIS;    // This is needed to disable write to EALLOW protected registers

	   // Enable CPU INT1 which is connected to CPU-Timer 0:
	   IER |= M_INT1;

	   // Enable TINT0 in the PIE: Group 1 interrupt 7
	   PieCtrlRegs.PIEIER1.bit.INTx7 = 1;

	   // Enable global Interrupts and higher priority real-time debug events:
	   EINT;   // Enable Global interrupt INTM
	   ERTM;   // Enable Global realtime interrupt DBGM


	   msg = "\r\n\n\nTERRAELECTRONICA\rMini-TMS320C28346\r===========================\r\0";
	   scia_msg(msg);
}

interrupt void cpu_timer0_isr(void) // Процедура обработки прерывания таймера
{
   CpuTimer0.InterruptCount++;
   GpioDataRegs.GPATOGGLE.bit.GPIO14 = 1; // Toggle GPIO34 once per 500 milliseconds
   // Acknowledge this interrupt to receive more interrupts from group 1
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}
//===========================================================================
// No more.
//===========================================================================
