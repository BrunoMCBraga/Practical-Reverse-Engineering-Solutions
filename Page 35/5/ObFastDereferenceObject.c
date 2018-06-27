/*
I am using Windows 7 64 bits:
https://msdn.microsoft.com/en-us/library/ms235286.aspx
 Integer arguments are passed in registers RCX, RDX, R8, and R9.
 
 I am using ntoskrnl with md5 fca6a23add16bdca38b1b7813295334d from System32. 

*/

NTKERNELAPI
VOID
FASTCALL
ObFastDereferenceObject (IN PEX_FAST_REF FastRef, IN PVOID Object){

	/*
	0:000> dt ntdll!_EX_FAST_REF
	   +0x000 Object           : Ptr64 Void
	   +0x000 RefCnt           : Pos 0, 4 Bits
	   +0x000 Value            : Uint8B
	
	Basically a union. EX_FAST_REF pointers are built around that fact that that data structures allocated from 
	the pool are always aligned on a 16 byte boundary on 64-bit systems and 8 byte boundary on 32-bit systems. As
	a result of this alignment, a few spare bits in the pointer are available to be used for reference counting 
	purposes. This mechanism is for internal use in the kernel and not exposed to driver developers. 
	*/
	EX_FAST_REF fastRefLocalCopy = *FastRef; //mov rax,[rcx] PEX_FAST_REF FastRef
	PVOID refXORedwithObject = (fastRefLocalCopy ^ Object); //Basically this is used to extract the RefCnt.

	if(refXORedwithObject >= 0xF){
		return ObfDereferenceObject(Object);
	}

	Ptr64 unionValue = fastRefLocalCopy; 
	PEX_FAST_REF pFastRefArgument = FastRef; //r9

	while(true){
		unionValue = fastRefLocalCopy + 1; ///increments RefCnt. r8

		_atomic(
			//Isn't this always true? It seems it is comparing the value of the local union with the one passed as argument. 
			//But this union has not been changed before so this should be true? Online solutions used other ntoskrnl which does not have this part.
			//This one makes no sense but it suffices for training.
			if(fastRefLocalCopy == *pFastRefArgument){
				*pFastRefArgument = unionValue;
				return fastRefLocalCopy;
			}
			else
				fastRefLocalCopy = *pFastRefArgument;
		)

		EX_FAST_REF fastRefLocalCopy2 =  fastRefLocalCopy;
		fastRefLocalCopy2 = (fastRefLocalCopy ^ Object);

		if(fastRefLocalCopy2 < 0xF)
			continue;
		else
			break;
	}

	return ObfDereferenceObject(Object);
}
