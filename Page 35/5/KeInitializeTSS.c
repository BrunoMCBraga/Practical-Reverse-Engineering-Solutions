/*

This function is not present on Windows 7. As such, i will use:

kd> uf KiInitializeTSS
nt!KiInitializeTSS:
81a16eea 8bff            mov     edi,edi
81a16eec 55              push    ebp
81a16eed 8bec            mov     ebp,esp
81a16eef 8b4508          mov     eax,dword ptr [ebp+8]
81a16ef2 6683606400      and     word ptr [eax+64h],0
81a16ef7 6683606000      and     word ptr [eax+60h],0
81a16efc 66c74066ac20    mov     word ptr [eax+66h],20ACh
81a16f02 66c740081000    mov     word ptr [eax+8],10h
81a16f08 5d              pop     ebp
81a16f09 c20400          ret     4

kd> dt _KTSS
ntdll!_KTSS
   +0x000 Backlink         : Uint2B
   +0x002 Reserved0        : Uint2B
   +0x004 Esp0             : Uint4B
   +0x008 Ss0              : Uint2B
   +0x00a Reserved1        : Uint2B
   +0x00c NotUsed1         : [4] Uint4B
   +0x01c CR3              : Uint4B
   +0x020 Eip              : Uint4B
   +0x024 EFlags           : Uint4B
   +0x028 Eax              : Uint4B
   +0x02c Ecx              : Uint4B
   +0x030 Edx              : Uint4B
   +0x034 Ebx              : Uint4B
   +0x038 Esp              : Uint4B
   +0x03c Ebp              : Uint4B
   +0x040 Esi              : Uint4B
   +0x044 Edi              : Uint4B
   +0x048 Es               : Uint2B
   +0x04a Reserved2        : Uint2B
   +0x04c Cs               : Uint2B
   +0x04e Reserved3        : Uint2B
   +0x050 Ss               : Uint2B
   +0x052 Reserved4        : Uint2B
   +0x054 Ds               : Uint2B
   +0x056 Reserved5        : Uint2B
   +0x058 Fs               : Uint2B
   +0x05a Reserved6        : Uint2B
   +0x05c Gs               : Uint2B
   +0x05e Reserved7        : Uint2B
   +0x060 LDT              : Uint2B
   +0x062 Reserved8        : Uint2B
   +0x064 Flags            : Uint2B
   +0x066 IoMapBase        : Uint2B
   +0x068 IoMaps           : [1] _KiIoAccessMap
   +0x208c IntDirectionMap  : [32] UChar

from: https://johannesbader.ch/2014/06/practical-reverse-engineering-solutions-page-35-part-vi/. As opposed to the other cases, this x86.
*/

VOID NTAPI KiInitializeTSS	(IN PKTSS Tss){

	PKTSS localTss = Tss;
	localTss->Flags &= 0x0;
	localTss->LDT &= 0x0;
	localTss->IoMapBase = 0x2AC;
	localTss->Ss0 = 0x10;

}