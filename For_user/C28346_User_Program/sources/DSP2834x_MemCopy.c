// TI File $Revision: /main/1 $
// Checkin $Date: February 1, 2008   09:59:44 $
//###########################################################################
//
// FILE:	DSP2834x_MemCopy.c
//
// TITLE:	Memory Copy Utility
//
// ASSUMPTIONS:
//
//          
//
// DESCRIPTION:
//
//          This function will copy the specified memory contents from
//          one location to another. 
// 
//          Uint16 *SourceAddr        Pointer to the first word to be moved
//                                    SourceAddr < SourceEndAddr
//          Uint16* SourceEndAddr     Pointer to the last word to be moved
//          Uint16* DestAddr          Pointer to the first destination word
//
//          No checks are made for invalid memory locations or that the
//          end address is > then the first start address.
// 
//          
//###########################################################################
// $TI Release: 2834x Header Files V1.12 $
// $Release Date: March 2011 $
//###########################################################################

#include "DSP2834x_Device.h"

void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr)
{
	//Uint32 xintf_out_data;
    while(SourceAddr < SourceEndAddr)
    { 

    	*DestAddr++ = *SourceAddr++;
    	//xintf_out_data = *SourceAddr;
    	//*DestAddr = *SourceAddr;
       //
       //*DestAddr++;
       //SourceAddr++;
       //
    }
    return;
}
void MemClear(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr)
{
	//Uint32 xintf_out_data;
    while(SourceAddr < SourceEndAddr)
    {

    	*DestAddr++ = 0;
    	SourceAddr++;
    }
    return;
}

//===========================================================================
// End of file.
//===========================================================================
