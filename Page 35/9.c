/*

This function looks for the last occurrence of charToSearch on string and returns a pointer
for it. It starts by looking for the \0 to compute the size of the string.  

Not great code since it assumes that the string ends with \0.

*/

char* sub_1000CEA0(char* string, char charToSearch){

	int index;
	char c;

	for(index=0;;index++){

		c = *(string+index);
		if (c == 0x0)
			break;
	}

	int stringLength = index;
	int index2;
	for(index2=stringLength - 1;;index2--){

		c = *(string+index2);
		if (c == charToSearch)
			break;
	}

	if(*(string+index2) == charToSearch)
		return (string+index2);
	else
		return NULL;


}