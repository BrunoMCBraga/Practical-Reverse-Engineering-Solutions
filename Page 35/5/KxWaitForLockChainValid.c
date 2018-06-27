/*

0:000> dt ntdll!_KSPIN_LOCK_QUEUE
   +0x000 Next             : Ptr64 _KSPIN_LOCK_QUEUE
   +0x008 Lock             : Ptr64 Uint8B

*/

PKSPIN_LOCK_QUEUE KxWaitForLockChainValid(__inout PKSPIN_LOCK_QUEUE LockQueue){

	//mov [rsp+arg_0], rbx
	PKSPIN_LOCK_QUEUE pLocalLockQueue = LockQueue; //rdi
	int counter = 0;

	while(true){
		counter++;
		if (HvlLongSpinCountMask == counter){
			if(HvlEnlightenments == 0x40)
				//pause
			else
				HvlNotifyLongSpinWait(counter);
		}

		else{
			//pause
		}

		Ptr64 nextPtr = pLocalLockQueue->Next;
		if(nextPtr == 0){
			continue;
		}
		else
			break;
	}

	//mov rbx, [rsp+28h+arg_0]
}

