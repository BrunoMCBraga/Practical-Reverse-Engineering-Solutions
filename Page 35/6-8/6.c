/*

arg1: 


struct arg1{
	23h: unsigned char
	60h: PVOID. PVOID - 0x24 + 0x14 = PVOID - 0x10 points to struct arg2 struct. The lower
	byte here represents and omdex fpr MajorFunction table.

}

arg2:

struct arg2{
	8h: PVOID points to structure or memory region. Let us assume a structure st. By checking PMA
	i see this is likely a pointer for nt!_DRIVER_OBJECT.
}

Likely nt!_DRIVER_OBJECT
struct st{
	38h: PVOID[] Table of pointers to functions. If the previous is the case, this is the start of the Major Function table.
}

*/

sub_13842(struct arg1* arg1, struct arg2* arg2){

	int var1 = *(arg1+0x60);
	int var2 = *(arg2+0x8);

	*(arg1+0x23)--;
	var1 -= 0x24;

	*(arg1+0x60) = var1;
	*(var1+0x14) = arg2;

	unsigned char var3 = *var1;
	return (var2 + var3*4 + 0x38)(arg2, arg1);//Calls major function using var3 as index.
} 
