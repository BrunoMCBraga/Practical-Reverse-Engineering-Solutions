/*

https://msdn.microsoft.com/en-us/library/ms235286.aspx
 Integer arguments are passed in registers RCX, RDX, R8, and R9.


lkd> uf KeReadyThread
nt!KeReadyThread:
fffff800`02872c90 4053            push    rbx
fffff800`02872c92 4883ec20        sub     rsp,20h
fffff800`02872c96 488b5170        mov     rdx,qword ptr [rcx+70h] 
fffff800`02872c9a 488bd9          mov     rbx,rcx
fffff800`02872c9d 8b82dc000000    mov     eax,dword ptr [rdx+0DCh]
fffff800`02872ca3 a807            test    al,7
fffff800`02872ca5 0f85951a0600    jne     nt! ?? ::FNODOBFM::`string'+0x173c0 (fffff800`028d4740)  Branch

nt!KeReadyThread+0x1b:
fffff800`02872cab 488bcb          mov     rcx,rbx
fffff800`02872cae e88dfeffff      call    nt!KiFastReadyThread (fffff800`02872b40)

nt!KeReadyThread+0x23:
fffff800`02872cb3 4883c420        add     rsp,20h
fffff800`02872cb7 5b              pop     rbx
fffff800`02872cb8 c3              ret

nt! ?? ::FNODOBFM::`string'+0x173c0:
fffff800`028d4740 e833ccfaff      call    nt!KiInSwapSingleProcess (fffff800`02881378)
fffff800`028d4745 84c0            test    al,al
fffff800`028d4747 0f8566e5f9ff    jne     nt!KeReadyThread+0x23 (fffff800`02872cb3)  Branch

nt! ?? ::FNODOBFM::`string'+0x173cd:
fffff800`028d474d e959e5f9ff      jmp     nt!KeReadyThread+0x1b (fffff800`02872cab)  Branch

lkd> dt ntkrnlmp!_KTHREAD
   +0x000 Header           : _DISPATCHER_HEADER
   +0x018 CycleTime        : Uint8B
   +0x020 QuantumTarget    : Uint8B
   +0x028 InitialStack     : Ptr64 Void
   +0x030 StackLimit       : Ptr64 Void
   +0x038 KernelStack      : Ptr64 Void
   +0x040 ThreadLock       : Uint8B
   +0x048 WaitRegister     : _KWAIT_STATUS_REGISTER
   +0x049 Running          : UChar
   +0x04a Alerted          : [2] UChar
   +0x04c KernelStackResident : Pos 0, 1 Bit
   +0x04c ReadyTransition  : Pos 1, 1 Bit
   +0x04c ProcessReadyQueue : Pos 2, 1 Bit
   +0x04c WaitNext         : Pos 3, 1 Bit
   +0x04c SystemAffinityActive : Pos 4, 1 Bit
   +0x04c Alertable        : Pos 5, 1 Bit
   +0x04c GdiFlushActive   : Pos 6, 1 Bit
   +0x04c UserStackWalkActive : Pos 7, 1 Bit
   +0x04c ApcInterruptRequest : Pos 8, 1 Bit
   +0x04c ForceDeferSchedule : Pos 9, 1 Bit
   +0x04c QuantumEndMigrate : Pos 10, 1 Bit
   +0x04c UmsDirectedSwitchEnable : Pos 11, 1 Bit
   +0x04c TimerActive      : Pos 12, 1 Bit
   +0x04c SystemThread     : Pos 13, 1 Bit
   +0x04c Reserved         : Pos 14, 18 Bits
   +0x04c MiscFlags        : Int4B
   +0x050 ApcState         : _KAPC_STATE
   +0x050 ApcStateFill     : [43] UChar <--This is the closest i get to the offset 70. Online solutions are different which indicate that the exercises were likely done on XP or Vista.
   +0x07b Priority         : Char
   +0x07c NextProcessor    : Uint4B
   +0x080 DeferredProcessor : Uint4B
   +0x088 ApcQueueLock     : Uint8B
   +0x090 WaitStatus       : Int8B
   +0x098 WaitBlockList    : Ptr64 _KWAIT_BLOCK
   +0x0a0 WaitListEntry    : _LIST_ENTRY
   +0x0a0 SwapListEntry    : _SINGLE_LIST_ENTRY
   +0x0b0 Queue            : Ptr64 _KQUEUE
   +0x0b8 Teb              : Ptr64 Void
   +0x0c0 Timer            : _KTIMER
   +0x100 AutoAlignment    : Pos 0, 1 Bit
   +0x100 DisableBoost     : Pos 1, 1 Bit
   +0x100 EtwStackTraceApc1Inserted : Pos 2, 1 Bit
   +0x100 EtwStackTraceApc2Inserted : Pos 3, 1 Bit
   +0x100 CalloutActive    : Pos 4, 1 Bit
   +0x100 ApcQueueable     : Pos 5, 1 Bit
   +0x100 EnableStackSwap  : Pos 6, 1 Bit
   +0x100 GuiThread        : Pos 7, 1 Bit
   +0x100 UmsPerformingSyscall : Pos 8, 1 Bit
   +0x100 VdmSafe          : Pos 9, 1 Bit
   +0x100 UmsDispatched    : Pos 10, 1 Bit
   +0x100 ReservedFlags    : Pos 11, 21 Bits
   +0x100 ThreadFlags      : Int4B
   +0x104 Spare0           : Uint4B
   +0x108 WaitBlock        : [4] _KWAIT_BLOCK
   +0x108 WaitBlockFill4   : [44] UChar
   +0x134 ContextSwitches  : Uint4B
   +0x108 WaitBlockFill5   : [92] UChar
   +0x164 State            : UChar
   +0x165 NpxState         : Char
   +0x166 WaitIrql         : UChar
   +0x167 WaitMode         : Char
   +0x108 WaitBlockFill6   : [140] UChar
   +0x194 WaitTime         : Uint4B
   +0x108 WaitBlockFill7   : [168] UChar
   +0x1b0 TebMappedLowVa   : Ptr64 Void
   +0x1b8 Ucb              : Ptr64 _UMS_CONTROL_BLOCK
   +0x108 WaitBlockFill8   : [188] UChar
   +0x1c4 KernelApcDisable : Int2B
   +0x1c6 SpecialApcDisable : Int2B
   +0x1c4 CombinedApcDisable : Uint4B
   +0x1c8 QueueListEntry   : _LIST_ENTRY
   +0x1d8 TrapFrame        : Ptr64 _KTRAP_FRAME
   +0x1e0 FirstArgument    : Ptr64 Void
   +0x1e8 CallbackStack    : Ptr64 Void
   +0x1e8 CallbackDepth    : Uint8B
   +0x1f0 ApcStateIndex    : UChar
   +0x1f1 BasePriority     : Char
   +0x1f2 PriorityDecrement : Char
   +0x1f2 ForegroundBoost  : Pos 0, 4 Bits
   +0x1f2 UnusualBoost     : Pos 4, 4 Bits
   +0x1f3 Preempted        : UChar
   +0x1f4 AdjustReason     : UChar
   +0x1f5 AdjustIncrement  : Char
   +0x1f6 PreviousMode     : Char
   +0x1f7 Saturation       : Char
   +0x1f8 SystemCallNumber : Uint4B
   +0x1fc FreezeCount      : Uint4B
   +0x200 UserAffinity     : _GROUP_AFFINITY
   +0x210 Process          : Ptr64 _KPROCESS
   +0x218 Affinity         : _GROUP_AFFINITY
   +0x228 IdealProcessor   : Uint4B
   +0x22c UserIdealProcessor : Uint4B
   +0x230 ApcStatePointer  : [2] Ptr64 _KAPC_STATE
   +0x240 SavedApcState    : _KAPC_STATE
   +0x240 SavedApcStateFill : [43] UChar
   +0x26b WaitReason       : UChar
   +0x26c SuspendCount     : Char
   +0x26d Spare1           : Char
   +0x26e CodePatchInProgress : UChar
   +0x270 Win32Thread      : Ptr64 Void
   +0x278 StackBase        : Ptr64 Void
   +0x280 SuspendApc       : _KAPC
   +0x280 SuspendApcFill0  : [1] UChar
   +0x281 ResourceIndex    : UChar
   +0x280 SuspendApcFill1  : [3] UChar
   +0x283 QuantumReset     : UChar
   +0x280 SuspendApcFill2  : [4] UChar
   +0x284 KernelTime       : Uint4B
   +0x280 SuspendApcFill3  : [64] UChar
   +0x2c0 WaitPrcb         : Ptr64 _KPRCB
   +0x280 SuspendApcFill4  : [72] UChar
   +0x2c8 LegoData         : Ptr64 Void
   +0x280 SuspendApcFill5  : [83] UChar
   +0x2d3 LargeStack       : UChar
   +0x2d4 UserTime         : Uint4B
   +0x2d8 SuspendSemaphore : _KSEMAPHORE
   +0x2d8 SuspendSemaphorefill : [28] UChar
   +0x2f4 SListFaultCount  : Uint4B
   +0x2f8 ThreadListEntry  : _LIST_ENTRY
   +0x308 MutantListHead   : _LIST_ENTRY
   +0x318 SListFaultAddress : Ptr64 Void
   +0x320 ReadOperationCount : Int8B
   +0x328 WriteOperationCount : Int8B
   +0x330 OtherOperationCount : Int8B
   +0x338 ReadTransferCount : Int8B
   +0x340 WriteTransferCount : Int8B
   +0x348 OtherTransferCount : Int8B
   +0x350 ThreadCounters   : Ptr64 _KTHREAD_COUNTERS
   +0x358 StateSaveArea    : Ptr64 _XSAVE_FORMAT
   +0x360 XStateSave       : Ptr64 _XSTATE_SAVE


*/


VOID NTAPI KeReadyThread(IN PKTHREAD Thread){

	PVOID apcStateFillOffset = Thread->ApcStateFill[0x20]; //Thread+0x70
	PKTHREAD pLocalThread = Thread;
	int someField = apcStateFillOffset[0xDC];
	if((unsigned char) someField != 0x7)
		return;

	unsigned char res = KiInSwapSingleProcess(Thread,apcStateFillOffset);

	if(res != 0)
		return;

	KiFastReadyThread(pLocalThread);

}