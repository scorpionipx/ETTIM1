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
	int n;
	int  *V;
}Vector;

typedef struct
{
	int m;
	int n;
	int p;
	int mp;
	double **M;
}Matrix;

typedef struct
{
	int length;
	char *_array;
}Array;

void dynmic_allocation_vector(Vector *F);
void dealloc_vector(Vector *F);
void read_vector(Vector F);
void print_vector(Vector F);
long int vector_elements_sum(Vector F);
long int vector_elements_product(Vector F);
void max_element_of_vector(Vector F);
void min_element_of_vector(Vector F);
void ascending_sort(Vector F);
void descending_sort(Vector F);

void vectors_sum(Vector X,Vector Y);
void vectors_product(Vector X,Vector Y);
void scalar_product(Vector X,Vector Y);
void column_line_product(Vector X,Vector Y);


void dynmic_allocation_matrix(Matrix *F);
void dynmic_allocation_matrix_nxn(Matrix *F);
void dynmic_allocation_matrix_nxp(Matrix *F);
void dealloc_matrix(Matrix *F);
void dealloc_matrix_nxn(Matrix *F);
void dealloc_matrix_nxp(Matrix *F);
void read_matrix(Matrix F);
void print_matrix(Matrix F);
void read_matrix_nxn(Matrix F);
void print_matrix_nxn(Matrix F);
void read_matrix_nxp(Matrix F);
void print_matrix_nxp(Matrix F);
double matrix_elements_sum(Matrix F);
double matrix_elements_product(Matrix F);
void max_element_of_matrix(Matrix F);
void min_element_of_matrix(Matrix F);
void negatives_nulls_positives(Matrix F);
double primary_diagonal_elements_sum(Matrix F);
void sum_of_two_matrix(Matrix A,Matrix B);
void product_of_two_matrix(Matrix A,Matrix B);

#endif
