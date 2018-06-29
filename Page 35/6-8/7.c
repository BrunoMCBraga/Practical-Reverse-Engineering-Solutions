 //Returns pointer to section header based on rule specified by arg2.

 PVOID sub_10BB6 (PVOID imageBase, PVOID arg2){

	PVOID imageHeaderOffset = *(imageBase + 0x3C);	
	PVOID peHeader = imageBase + imageHeaderOffset;
	short sizeOfOptionalHeader = *(peHeader + 0x14);
	int counter = 0;
	short numberOfSections = *(peHeader + 0x6);

	if(numberOfSections <= counter)
	 return 0;

	PVOID  pointerToSectionHeader = *(sizeOfOptionalHeader + peHeader + 0x18);
	
	//The stopping point is based on the number of sections
	for(;counter < *(peHeader + 0x6) ;++counter){

		//Likely bool
		int ret = random_funct(pointerToSectionHeader, arg2);
		if(ret == 0)
			return pointerToSectionHeader;

		pointerToSectionHeader+=0x28;//next section header

	}

	return 0;

}