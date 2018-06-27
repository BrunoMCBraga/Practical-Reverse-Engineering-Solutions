/*
I am using Windows 7 64 bits:
https://msdn.microsoft.com/en-us/library/ms235286.aspx
 Integer arguments are passed in registers RCX, RDX, R8, and R9.
 
 I am using ntoskrnl with md5 fca6a23add16bdca38b1b7813295334d from System32. 

*/

/*
ntdll!_DISPATCHER_HEADER

0:000> dt  ntdll!_DISPATCHER_HEADER
   +0x000 Type             : UChar
   +0x001 TimerControlFlags : UChar
   +0x001 Absolute         : Pos 0, 1 Bit
   +0x001 Coalescable      : Pos 1, 1 Bit
   +0x001 KeepShifting     : Pos 2, 1 Bit
   +0x001 EncodedTolerableDelay : Pos 3, 5 Bits
   +0x001 Abandoned        : UChar
   +0x001 Signalling       : UChar
   +0x002 ThreadControlFlags : UChar
   +0x002 CpuThrottled     : Pos 0, 1 Bit
   +0x002 CycleProfiling   : Pos 1, 1 Bit
   +0x002 CounterProfiling : Pos 2, 1 Bit
   +0x002 Reserved         : Pos 3, 5 Bits
   +0x002 Hand             : UChar
   +0x002 Size             : UChar
   +0x003 TimerMiscFlags   : UChar
   +0x003 Index            : Pos 0, 6 Bits
   +0x003 Inserted         : Pos 6, 1 Bit
   +0x003 Expired          : Pos 7, 1 Bit
   +0x003 DebugActive      : UChar
   +0x003 ActiveDR7        : Pos 0, 1 Bit
   +0x003 Instrumented     : Pos 1, 1 Bit
   +0x003 Reserved2        : Pos 2, 4 Bits
   +0x003 UmsScheduled     : Pos 6, 1 Bit
   +0x003 UmsPrimary       : Pos 7, 1 Bit
   +0x003 DpcActive        : UChar
   +0x000 Lock             : Int4B
   +0x004 SignalState      : Int4B
   +0x008 WaitListHead     : _LIST_ENTRY
*/

NTKERNELAPI VOID KeInitializeQueue(
  PRKQUEUE Queue,
  ULONG    Count
){

	Queue->_DISPATCHER_HEADER.Type = 0x4;
	Queue->_DISPATCHER_HEADER.ThreadControlFlags = 0x10;

	int zero = 0;//long???
	Queue->_DISPATCHER_HEADER.TimerControlFlags = (char) zero;
	Queue->_DISPATCHER_HEADER.SignalState = zero;	

	PVOID queueOffset = &(Queue->_DISPATCHER_HEADER.WaitListHead);
	queueOffset->Blink = queueOffset;
	queueOffset->Flink = queueOffset;

	PVOID queueOffset2 = &(Queue->EntryListHead);
	queueOffset2->Blink = queueOffset2;
	queueOffset2->Flink = queueOffset2;

	PVOID queueOffset3 = &(Queue->ThreadListHead);
	queueOffset3->Blink = queueOffset3;
	queueOffset3->Flink = queueOffset3;

	Queue->CurrentCount = zero;		

	if(Count == zero)
        Queue->MaximumCount = KeNumberProcessors_0;
	else
		Queue->MaximumCount = Count;
}
