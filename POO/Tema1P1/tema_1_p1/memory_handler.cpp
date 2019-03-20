#include "stdafx.h"

void dynmic_allocation_vector(Vector *F)
{
	F->V=(int*)malloc(F->n*sizeof(int));
		if(F->V==NULL)
		{
			printf("Vector dynamic memory allocation error!\n");
			free(F->V);
			F->V=NULL;
			F->n=0;
		}
}

void dealloc_vector(Vector *F)
{
	free(F->V);
	F->V=NULL;
	F->n=0;
}

void dynmic_allocation_matrix(Matrix *F)
{
	int i;
	double **Mtemp;
	F->M = (double **)malloc(F->m*sizeof(double *));
	Mtemp = F->M;
	for(i = 0; i < F->m;(i++, Mtemp++))
		*Mtemp=(double *)malloc(F->n*sizeof(double));
		if(*Mtemp==NULL)
		{
			printf("Matrix dynamic memory allocation error!\n");
			F->m=i;
			free(F->M);
			F->M=NULL;
			F->m=0;
			F->n=0;
		}

}

void dynmic_allocation_matrix_nxn(Matrix *F)
{
	int i;
	double **Mtemp;
	F->M=(double **)malloc(F->mp*sizeof(double *));
	Mtemp = F->M;
	for(i = 0; i < F->mp;(i++,Mtemp++))
		*Mtemp=(double *)malloc(F->mp*sizeof(double));
		if(*Mtemp==NULL)
		{
			printf("Matrix nxn dynamic memory allocation error!\n");
			F->mp=i;
			free(F->M);
			F->M=NULL;
			F->mp=0;
		}

}

void dynmic_allocation_matrix_nxp(Matrix *F)
{
	int i;
	double **Mtemp;
	F->M = (double **)malloc(F->n*sizeof(double *));
	Mtemp = F->M;
	for(i = 0; i < F->n;(i++, Mtemp++))
		*Mtemp=(double *)malloc(F->p*sizeof(double));
		if(*Mtemp==NULL)
		{
			printf("Matrix nxp dynamic memory allocation error!\n");
			F->n=i;
			free(F->M);
			F->M=NULL;
			F->n=0;
			F->p=0;
		}

}
void dealloc_matrix(Matrix *F)
{
	int i;
	double **MatrixTemp = F->M;
	for(i = 0; i < F->m;(i++, MatrixTemp++))
	{
		if(*MatrixTemp==NULL)
		{
			printf("No memory allocated for this line %d!\n", i);
		}
		free(*MatrixTemp);
	}
	free(F->M);
	F->M=NULL;
	F->m=0;
	F->n=0;
}
void dealloc_matrix_nxn(Matrix *F)
{
	int i;
	double **MatrixTemp = F->M;
	for(i = 0; i < F->mp; (i++, MatrixTemp++))
	{
		if(*MatrixTemp==NULL)
		{
			printf("No memory allocated for this line %d!\n", i);
		}
		free(*MatrixTemp);
	}
	free(F->M);
	F->M=NULL;
	F->mp=0;
}

void dealloc_matrix_nxp(Matrix *F)
{
	int i;
	double **MatrixTemp = F->M;
	for(i=0;i<F->n;(i++, MatrixTemp++))
	{
		if(*MatrixTemp==NULL)
		{
			printf("No memory allocated for this line %d!\n", i);
		}
		free(*MatrixTemp);
	}
	free(F->M);
	F->M=NULL;
	F->n=0;
	F->p=0;
}
