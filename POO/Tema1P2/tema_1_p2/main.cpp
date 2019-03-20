#include "stdafx.h"

int main(void)
{
	Array array_1, array_2, array_3;
	int n;

	dynamic_allocation_array(&array_1);
	dynamic_allocation_array(&array_2);
	dynamic_allocation_array(&array_3);

	// P2.a
	puts("Enter array 1!\n");
	gets(array_1._array);
	puts("Enter array 2!\n");
	gets(array_2._array);

	array_1.length = length_array(array_1);
	printf("Array 1 length: %d\n", array_1.length);
	array_2.length=length_array(array_2);
	printf("Array 2 length: %d\n", array_2.length);

	// P2.b
	printf("Array 1 and array2 comparison result:  %d\n", compare_arrays(array_1, array_2));

	if(compare_arrays(array_1, array_2) == 0)
	{
		puts("Arrays are equal!");
	}
	else if(compare_arrays(array_1, array_2) < 0)
	{
		puts("Array 1 is smaller than array 2.");
	}
	else if(compare_arrays(array_1, array_2)>0)
	{
		puts("Array 1 is bigger than array 2.");
	}

	// P2.c
	copy_arrays(array_3, array_1);
	puts("Array 3: ");
	puts(array_3._array);

	// P2.d
	printf("How many characters to copy from array 1 to array 3?\n");
	scanf("%d",&n);
	copy_arrays_with_limit(array_3, array_1, n);
	puts("Array 3 after copy with limit: ");
	puts(array_3._array);

	// P2.e
	concat_arrays(array_1, array_2);
	copy_arrays(array_3, array_1);

	puts("Array 3 after concat of array 1 and array 2:\n");
	puts(array_3._array);

	dealloc_array(&array_1);
	dealloc_array(&array_2);
	dealloc_array(&array_3);
	_getch();
}
