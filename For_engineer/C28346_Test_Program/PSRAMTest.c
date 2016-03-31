/*
 * PSRAMTest.c
 * ����� ������� XINF ����� ���� ���������� 2^19 ����� ������ = 524288 �������. ��� ��������� 32 ������ ����� ������������
 * ����� ������� ������ ����� ���� ����� 16777216 ��� = 2097152 ���� = 2048 ����� = 2 ����� �.�. 4 ����� XA12-XA15 ������ �����������,
 * �� ����� ���������� ������ 2^15 ����� = 32768, ��� ��� ��������� 32 ������ ����� �������� 32*32768 = 1048576 ��� =
 * = 131072 ���� = 128 �����
 */

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

#define PSRAMZoneSize 0x80000	// ������ ������ PSRAM, ���������� � ���������� 32-������ ����
#pragma DATA_SECTION(PSRAM_Zone,"xintffuncs");
Uint32	PSRAM_Zone[];

Uint32 PassCount;
Uint32 FailCount;
Uint32 VerifyData;

void PSRAMDataFail(void);
void PSRAMDataPass(void);
int ZoneError = 0;
int PSRAMError = 0;


void scia_msg(char *msg);
extern char *msg;

void PSRAMTest(void){
	Uint32 PSRAMDataSize = PSRAMZoneSize;
	Uint32 i;

	msg = "\PSRAM Test:\r\0";
	scia_msg(msg);
//Clear operation
	//PSRAMClear - �������� PSRAM
	for(i=0;i < PSRAMDataSize;i++){
		PSRAM_Zone[i] = 0;
	}

//Write operations
	//ProgrammAreaWrite - ������ 16 ��� � PSRAM
	for(i=0;i < PSRAMDataSize;i++){
		PSRAM_Zone[i] = i;
	}

/*debug - ���������� �������� �������� � ������ ��� �������� ������������ ������ ��������� Verify operations
	PSRAM_Zone[800]		= !PSRAM_Zone[800];
	PSRAM_Zone[1800] 	= !PSRAM_Zone[1800];
	PSRAM_Zone[2800] 	= !PSRAM_Zone[2800];
	PSRAM_Zone[3800] 	= !PSRAM_Zone[3800];
*/

//Verify operations
	//DataAreaVerify - �������� ������ � PSRAM
	PassCount = 0;	// ���������� ������� �������� ������
	FailCount = 0;	// ���������� ������� ��������� ������

	// ��������
	for(i=0;i < PSRAMDataSize;i++){
		VerifyData = PSRAM_Zone[i];

		if(VerifyData != i){
			FailCount++;
			ZoneError = 1;
		}
		else{PassCount++;
			//! ����� ������, �� �������� ���������� ������
		}
	}

	if(PassCount == PSRAMDataSize){
		PSRAMDataPass();
	}
	else{
		PSRAMDataFail();
	}
	if(PSRAMError == 1){
		msg = "PSRAM Test is finished with errors!\r\0";
		scia_msg(msg);
		msg = "===========================\r\0";
		scia_msg(msg);

	}
	else{
		msg = "PSRAM is OK!\r===========================\r\0";
		scia_msg(msg);
	}
}

void PSRAMDataFail(void){
	msg = "ERROR: PSRAM test failed!\r\0";
	scia_msg(msg);
	PSRAMError = 1;
}
void PSRAMDataPass(void){
	msg = "PSRAM Data Area is OK!\r\0";
	scia_msg(msg);
}
