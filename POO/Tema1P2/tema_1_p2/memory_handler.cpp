#include "stdafx.h"

void dynamic_allocation_array(Array *arrayx)
{
	int length=100;
	arrayx->_array=(char*)malloc(length*sizeof(char));
    if(arrayx->_array==NULL)
    {
        printf("Memory allocation error!\n");
        free(arrayx->_array);
        arrayx->_array=NULL;
    }
}
void dealloc_array(Array *arrayx)
{
	free(arrayx->_array);
	arrayx->_array=NULL;
	arrayx->length=0;
}
