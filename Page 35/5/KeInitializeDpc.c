/*
While this is a stdcall, the arguments are passed on registers per x64 convention:
https://msdn.microsoft.com/en-us/library/ms235286.aspx
 Integer arguments are passed in registers RCX, RDX, R8, and R9.
*/
void __stdcall KeInitializeDpc(PRKDPC Dpc, PKDEFERRED_ROUTINE DeferredRoutine, PVOID DeferredContext){

	int longZero = 0x0;
	short shortZero = (short) longZero;

	Dpc->Type[0] = 0x13;
	Dpc->Type[1] = 0x1;
	Dpc->DeferredRoutine = DeferredRoutine;
	Dpc->DeferredContext = DeferredContext;
	Dpc->Number =  shortZero; //On the code, ax is used.
	Dpc->DpcData = longZero;

} 
