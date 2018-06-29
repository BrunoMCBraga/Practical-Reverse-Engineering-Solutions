/*I do not think this is a standard call. One of the arguments is on eax. On online solutions, the order of arguments is:
eax, ecx, edx, stack. There is no calling convention starting with eax, ecx, edx so i assume it was a convention
Also, the stack argument is not the first pushed since it is esp+0x8. Therefore, there is another argument that is never used.

I will therefore use the following conventions:
eax: arg1
ecx: arg2
edx: arg3
stack_1: arg4
stack_2: swithChoice

struct arg1{
	BYTE[8] a 0x0
	int b 0x8 0x8
	BYTE[48]  0xC
	int d 0x3C



}

*/


struct* sub_1172E(struct* arg1, PVOID arg2, PVOID arg3, PVOID arg4, int switchChoice){

	int localswitchChoice = switchChoice;
	switch(localswitchChoice){
		case 1:
			localswitchChoice = *(arg1+0x3C) >> 1; //dividing by 2
			arg1+=0x40;
		break;
		case 2:
			localswitchChoice = *(arg1+0x3C) >> 1;
			arg1+=0x44;
		break;
		case 3:
			localswitchChoice -= 0x9 
			if(localswitchChoice != 0)
				return arg1;
			else{
				localswitchChoice = *(arg1+0x8) >> 1;
				arg1 += 0xC;
			}
		break;
		case 4:
			localswitchChoice = *(arg1+0x3C) >> 1;
			arg1+=0x5E;
		break;
	}

	*arg2 = localswitchChoice;
	*arg3 = arg1;

	return arg1;
}