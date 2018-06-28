/*

https://msdn.microsoft.com/en-us/library/ms235286.aspx
 Integer arguments are passed in registers RCX, RDX, R8, and R9.

 */

NTSTATUS RtlValidateUnicodeString(IN ULONG Flags, IN PCUNICODE_STRING UnicodeString){

	if(Flags == 0){
		return some_func(UnicodeString, 0x7FFF, 0x100);
	}

	else
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

}


/*

lkd> dt ntkrnlmp!_UNICODE_STRING
   +0x000 Length           : Uint2B
   +0x002 MaximumLength    : Uint2B
   +0x008 Buffer           : Ptr64 Uint2B

*/

NTSTATUS some_func(IN PCUNICODE_STRING UnicodeString, int something1, int something2){

	int status = STATUS_SUCCESS;
	if(UnicodeString == 0)
		return status;

	
	//Unicode strings have even number of bytes. It is checking if it is odd. 
	if((((unsigned char)UnicodeString->Length) & 1) != 0)
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

	short maximumLength = UnicodeString->MaximumLength;
	if((((unsigned char)maximumLength) & 0x1) == !=0) 
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

	if(UnicodeString->Length > maximumLength)
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

	if(something1 > 0xFFFE)
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

	if(UnicodeString->Buffer == (short) status) //checks if buffer is zero
		return 0C000000Dh; //STATUS_INVALID_PARAMETER

	if(((short) something2) == (short) status)
		return status;

	return 0C000000Dh; //STATUS_INVALID_PARAMETER

}	