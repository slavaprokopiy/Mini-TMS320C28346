#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

// ��������� �������
// interrupt void ISRTimer2(void);
void delay_loop_time(long);
void spi_init(void);
void error(void);

// ������� �������
void BufferWrite(void);
void BufferToMemorySend(void);
void FlashWrite(void);
void FlashRead(void);
void FlashBlockErase(void);
unsigned char spi_rx_byte(void);
void spi_tx_byte(unsigned char);

// ������� ����������, ����������� � ����� Program_to_Load.c
extern unsigned char flash_data[];
extern unsigned char read_data[];
extern int DataSize;
extern int DataSizeToTransmit;

// ������� ����������
const int BufferSize = 528; // ������ ������ Flash-������
int count = 0;	// ���������� ����� ����� ���������, ������������ �� Flash-������
int page = 0;	// ����� ������������ �������� Flash-������
int i = 0;		// ����������, ������������ � ������

void main(void)
{

// Step 1. Initialize System Control:
// PLL, WatchDog, enable Peripheral Clocks
// This example function is found in the DSP2834x_SysCtrl.c file.
   InitSysCtrl();

// Step 2. Initalize GPIO:
// This example function is found in the DSP2834x_Gpio.c file and
// illustrates how to set the GPIO to it's default state.
   InitGpio();
// Setup only the GP I/O only for SPI-A functionality
// This function is found in DSP2834x_Spi.c
   InitSpiaGpio();

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
	spi_init();		  // init SPI

// Step 5. Main Program:
	FlashWrite();		// ����� ������ �� ������� Flash-������
	//FlashBlockErase();// ��� ������������� ����� ������� ����
	FlashRead();
	//!debug - ���������� �������� ������ ��� �������� ������ ��� ������
	//flash_data[50] = !flash_data[50];

	// ���� �������� ���������� ������
	for(i=0;i<DataSize;i++){				// ��������� ���� ����� ������
		if(flash_data[i] != read_data[i]){	// ���� ��������� ������ �� ����� ������, ������� ������������ �� ������,
			asm ("      ESTOP0");			// ��������� ��������
			while(1){;} 					// ������ ��� ������ ���������� ������
        }
	}
	GpioDataRegs.GPASET.bit.GPIO14 = 1;		// ���� �� �������� � ������� �����, �������� ������� ���������,
	while(1){;} 							// ������ ������ �� ����.
}


// Step 6. Insert all local Interrupt Service Routines (ISRs) and functions here:

void delay_loop_time(long time)
{
    long      i;
    for (i = 0; i < time; i++) {}
}

void error(void)
{
    asm("     ESTOP0");						// Test failed!! Stop!
    for (;;);
}

void spi_init(void)
{
	SpiaRegs.SPICCR.bit.SPISWRESET = 0; // clear this bit before the changes

	SpiaRegs.SPIFFTX.bit.TXFIFO = 0;
	SpiaRegs.SPIRXBUF = 0;
	SpiaRegs.SPITXBUF = 0;

	//SpiaRegs.SPICCR.all
	SpiaRegs.SPICCR.bit.SPICHAR = 0x7; //Character lenght - 8 bits
	SpiaRegs.SPICCR.bit.SPILBK = 0;
	SpiaRegs.SPICCR.bit.CLKPOLARITY = 0;

	//SpiaRegs.SPICTL.all
	SpiaRegs.SPICTL.bit.SPIINTENA = 0;
	SpiaRegs.SPICTL.bit.TALK = 1;
	SpiaRegs.SPICTL.bit.MASTER_SLAVE = 1;
	SpiaRegs.SPICTL.bit.CLK_PHASE = 1;
	SpiaRegs.SPICTL.bit.OVERRUNINTENA = 0;

	SpiaRegs.SPIBRR =0x007F;
    //SpiaRegs.SPICCR.all =0x009F;			// Relinquish SPI from Reset
	SpiaRegs.SPICCR.bit.SPISWRESET = 1;		// set this bit before resuming operation

    SpiaRegs.SPIPRI.bit.FREE = 2;			 // Set so breakpoints don't disturb xmission
    //SpiaRegs.SPIPRI.bit.SOFT = 2;
    EALLOW;
   	//	 GpioCtrlRegs.GPAPUD.all &= 0xFFF0FFFF;
   		// GpioCtrlRegs.GPAMUX2.all |= 0x00000015;
   		 //GpioCtrlRegs.GPAQSEL2.all |= 0x0000003F;
   	    // IOPORT as output pin instead of SPISTE
   	    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
   	    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
   	    GpioDataRegs.GPASET.bit.GPIO19 = 1;
   	EDIS;

}

void FlashWrite(void){
	//�������� ������� ������ � ����� 1
	while(DataSizeToTransmit>0){	// ���� �� �������� ��� ������
		BufferWrite();				// ��������� �����
		delay_loop_time(1010);		// ����������� ����� ������ � �����
		BufferToMemorySend();		// �������� ������ � ������� ������ ������
	}
}

void BufferWrite(void){
	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1; // ��������� ������� SPISTEA#
	//�������� ������� 0x84000000 - "������ � �����1"
	spi_tx_byte(0x84);
	spi_tx_byte(0x00);
	spi_tx_byte(0x00);
	spi_tx_byte(0x00);

	// �������� ������
	if(DataSizeToTransmit > BufferSize){	// ���� ������ ��� �������� ������, ��� ������ ������
		for( i = 0; i < BufferSize; i++){	// ���� ����� ������ �������� � �����
			spi_tx_byte(flash_data[count]);
			count++;
		}
	}
	else{											// ���� ������ ������, ��� ������ ������
		for(i = 0; i < DataSizeToTransmit; i++){	//������ � ����� ������� ����
			spi_tx_byte(flash_data[count]);
			count++;
		}
	}
	GpioDataRegs.GPASET.bit.GPIO19 = 1;	// ����� ������� SPISTEA#
	DataSizeToTransmit -= i;  			//��������� ������ ������, ������� ���������� ��������
}

void BufferToMemorySend(void){
	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;	// ��������� ������� SPISTEA#
	//������ �� ������1 � ������
	spi_tx_byte(0x83);						// ������� "������ �� ������1 � ������� ������"
	spi_tx_byte(0x00);						// 1 ������ + 7 MSB ������ ��������
	spi_tx_byte(0x00|(page<<2));			// 6 LSB ������ �������� + 2 ������
	spi_tx_byte(0x00);						// 8 ������
	GpioDataRegs.GPASET.bit.GPIO19 = 1;		// ����� ������� SPISTEA#
	page++; // ��������� ������ ��������
	delay_loop_time(500000);				// ��������� ����� �� ����� ��� ����� 40 �� ����� �������� ������� �������� �� ������ � ������� ������ ������
}

void FlashRead(void){
	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;	// ��������� ������� SPISTEA#
	spi_tx_byte(0x03);						// "Read" command
	spi_tx_byte(0x00);						// 1 ������ + 7 MSB ������ ��������
	spi_tx_byte(0x00);						// 6 LSB ������ �������� + 2 MSB ������ ������������ �����
	spi_tx_byte(0x00);						// 8 LSB ������ ���������� �����

	int i = 0;
	for(i = 0; i < DataSize; i++){			// ������ ������ ���� ����� ������
		read_data[i] = spi_rx_byte();
	}
	GpioDataRegs.GPASET.bit.GPIO19 = 1;		// ����� ������� SPISTEA#
}

unsigned char spi_rx_byte(void){
	unsigned char byte;
	SpiaRegs.SPITXBUF = 0x0000;
	while( (SpiaRegs.SPISTS.bit.INT_FLAG) !=1){;}
	// Clear SPIINT flag and capture received byte
	byte = SpiaRegs.SPIRXBUF;
	return byte;
}

void spi_tx_byte(unsigned char byte){
	unsigned char temp;
	SpiaRegs.SPITXBUF = byte<<8;
	while( (SpiaRegs.SPISTS.bit.INT_FLAG) !=1);
	temp = SpiaRegs.SPIRXBUF;
}

void FlashErase(void){
	GpioDataRegs.GPACLEAR.bit.GPIO19 = 1;
	spi_tx_byte(0x50);
	spi_tx_byte(0x00);
	spi_tx_byte(0x00);
	spi_tx_byte(0x00);
	GpioDataRegs.GPASET.bit.GPIO19 = 1;
	delay_loop_time(1500000);//wait 100 ms

}

//===========================================================================
// No more.
//===========================================================================
