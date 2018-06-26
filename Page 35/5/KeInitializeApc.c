NTKERNELAPI __stdcall VOID KeInitializeApc(
    PKAPC Apc, //0
    PKTHREAD Thread, //4
    KAPC_ENVIRONMENT Environment, //8
    PKKERNEL_ROUTINE KernelRoutine, //C
    PKRUNDOWN_ROUTINE RundownRoutine, //10
    PKNORMAL_ROUTINE NormalRoutine,//14
    KPROCESSOR_MODE ProcessorMode,//18
    PVOID NormalContext //1C
){

	PKAPC localApc= Apc; //eax
	KAPC_ENVIRONMENT localEnvironment = Environment; //edx
	PKTHREAD localThread = Thread; //ecx
	
	localApc->Type = 0x12;
	localApc->Size = 0x30

	if(localEnvironment == 2){
		char var = Thread->ApcStateIndex;
	}

	localApc->Thread = localThread;
	PKKERNEL_ROUTINE localKernelRoutine = KernelRoutine;
	localApc->KernelRoutine = localKernelRoutine;
	PKRUNDOWN_ROUTINE localRundownRoutine = RundownRoutine;
	localApc->ApcStateIndex = var;
	localApc->RundownRoutine = localRundownRoutine;
	PKNORMAL_ROUTINE localNormalRoutine = NormalRoutine;
	int zero = 0x0;
	localApc->NormalRoutine = localNormalRoutine;

	if(localNormalRoutine == 0){
		localApc->ApcMode = (char) zero;
		localApc->NormalContext = zero;
	}

	else{
		KPROCESSOR_MODE localProcessorMode = ProcessorMode;
		localApc->ApcMode = localProcessorMode;
		PVOID localNormalContext = NormalContext;
		localApc->NormalContext = localNormalContext;

	}

		localApc->Inserted = (unsigned char) zero;
}
