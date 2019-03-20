#include "stdafx.h"

int length_array(Array arrayx)
{
	arrayx.length=0;

	while(arrayx._array[arrayx.length] != '\0')
	{
		arrayx.length++;
	}
	return arrayx.length;
}


int compare_arrays(Array array1, Array array2)
{
	int i = 0, j = 0, c;
	while(array1._array[i] != '\0')
	{
		i++;
	}
	while(array2._array[j] != '\0')
	{
		j++;
	}
	c = i - j;
	return c;
}

void copy_arrays(Array array3, Array array1)
{
	int  i = 0;
	while(array1._array[i] != '\0')
	{
		array3._array[i] = array1._array[i];
		i++;
	}
	array3._array[i] = '\0';
}

void copy_arrays_with_limit(Array array3, Array array1, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		array3._array[i] = array1._array[i];
	}
	array3._array[n] = '\0';
}

void concat_arrays(Array array1, Array array2)
{
	int i = 0, j = 0;

	while(array1._array[i]!='\0')
	{
		i++;
	}

	while(array2._array[j]!='\0')
	{
		array1._array[i] = array2._array[j];
		i++;
		j++;
	}
	array1._array[i] = '\0';
}
