#pragma once

#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <malloc.h>
#include <ctype.h>

#ifndef stdafx_H_
#define stdafx_H_

typedef struct
{
	int length;
	char *_array;
}Array;


void dynamic_allocation_array(Array *arrayx);
void dealloc_array(Array *arrayx);
int length_array(Array arrayx);
int compare_arrays(Array array1, Array array2);
void copy_arrays(Array array2, Array array1);
void copy_arrays_with_limit(Array array2, Array array1, int n);
void concat_arrays(Array array1, Array array2);

#endif
