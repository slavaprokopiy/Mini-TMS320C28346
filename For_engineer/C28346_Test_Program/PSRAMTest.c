/*
 * PSRAMTest.c
 * Всего модулем XINF может быть адресовано 2^19 ячеек памяти = 524288 адресов. При адресации 32 битных ячеек максимальный
 * объем внешней памяти может быть равен 16777216 бит = 2097152 Байт = 2048 кБайт = 2 МБайт Т.к. 4 линии XA12-XA15 заняты бутлоадером,
 * то можно адресовать только 2^15 ячеек = 32768, что при адресации 32 битных ячеек составит 32*32768 = 1048576 бит =
 * = 131072 Байт = 128 кБайт
 */

#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

#define PSRAMZoneSize 0x80000	// Размер памяти PSRAM, выраженный в количестве 32-битных слов
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
	//PSRAMClear - стирание PSRAM
	for(i=0;i < PSRAMDataSize;i++){
		PSRAM_Zone[i] = 0;
	}

//Write operations
	//ProgrammAreaWrite - запись 16 зон в PSRAM
	for(i=0;i < PSRAMDataSize;i++){
		PSRAM_Zone[i] = i;
	}

/*debug - Специально изменяем значения в памяти для проверки правильности работы алгоритма Verify operations
	PSRAM_Zone[800]		= !PSRAM_Zone[800];
	PSRAM_Zone[1800] 	= !PSRAM_Zone[1800];
	PSRAM_Zone[2800] 	= !PSRAM_Zone[2800];
	PSRAM_Zone[3800] 	= !PSRAM_Zone[3800];
*/

//Verify operations
	//DataAreaVerify - проверка данных в PSRAM
	PassCount = 0;	// Сбрасываем счетчик успешных чтений
	FailCount = 0;	// Сбрасываем счетчик ошибочных чтений

	// Проверка
	for(i=0;i < PSRAMDataSize;i++){
		VerifyData = PSRAM_Zone[i];

		if(VerifyData != i){
			FailCount++;
			ZoneError = 1;
		}
		else{PassCount++;
			//! Вывод адреса, по которому обнаружена ошибка
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
