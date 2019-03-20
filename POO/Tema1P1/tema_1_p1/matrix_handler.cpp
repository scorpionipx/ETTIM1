#include "stdafx.h"

void read_matrix(Matrix F)
{
	int i, j;
	for(i = 0; i < F.m; i++)
	{
		for(j=0; j < F.n; j++)
		{
			printf("element[%d][%d]: ", i, j);
			if(scanf("%lf", &F.M[i][j]) != 1)
			{
				printf("Input error!");
				exit(1);
			}
		}
	}
}

void print_matrix(Matrix F)
{
	int i,j;
	for (i=0; i < F.m; i++)
	{
		for(j = 0; j < F.n; j++)
		{
			printf("%5g", F.M[i][j]);
		}
		printf("\n");
	}
}
void read_matrix_nxn(Matrix F)
{
	int i, j;
	for(i = 0; i < F.mp; i++)
	{
		for(j=0; j < F.mp; j++)
		{
			printf("element[%d][%d]: ", i, j);
			if(scanf("%lf",&F.M[i][j])!=1)
			{
				printf("Input error!");
				exit(1);
			}
		}
	}
}

void print_matrix_nxn(Matrix F)
{
	int i, j;
	for (i=0; i<F.mp; i++)
	{
		for(j = 0; j < F.mp; j++)
		{
			printf("%5g", F.M[i][j]);
		}
		printf("\n");
	}

}
void read_matrix_nxp(Matrix F)
{
	int i, j;
	for(i=0; i<F.n; i++)
	{
		for(j=0; j<F.p; j++)
		{
			printf("element[%d][%d]: ",i,j);
			if(scanf("%lf",&F.M[i][j])!=1)
			{
				printf("Input error!");
				exit(1);
			}
		}
	}
}

void print_matrix_nxp(Matrix F)
{
	int i, j;
	for (i = 0; i < F.n; i++)
	{
		for(j = 0; j < F.p; j++)
		{
			printf("%5g", F.M[i][j]);
		}
		printf("\n");
	}

}
double matrix_elements_sum(Matrix F)
{
	int i, j;
	double sum = 0;
	 for(i = 0; i < F.m; i++)
	 {
		 for(j=0; j<F.n; j++)
		 {
			sum += F.M[i][j];
		 }
	 }
	return sum;
}

double matrix_elements_product(Matrix F)
{
	int i, j;
	double prod = 1;

	 for(i = 0; i < F.m; i++)
	 {
		for(j = 0; j < F.n; j++)
		{
			prod *= F.M[i][j];
		}
	 }
	return prod;
}

void max_element_of_matrix(Matrix F)
{
	int i, j, position_row = 0, position_column = 0;
	double elem_max = F.M[0][0];
	for(i = 0; i < F.m; i++)
	{
		 for(j = 0; j < F.n; j++)
		 {
			 if(F.M[i][j] > elem_max)
			{
				elem_max = F.M[i][j];
				position_row = i;
				position_column = j;
			 }
		 }
	}
	printf("Maximum element is: %g, at position: [%d, %d].\n", elem_max, position_row, position_column);
}

void min_element_of_matrix(Matrix F)
{
	int i, j, position_row = 0, position_column = 0;
	double elem_min = F.M[0][0];
	for(i = 0; i < F.m; i++)
	{
		 for(j = 0; j < F.n; j++)
		 {
			 if(F.M[i][j] < elem_min)
			 {
				  elem_min = F.M[i][j];
				  position_row = i;
				  position_column = j;
			 }
		 }
	}
	printf("Minimum element is: %g, at position: [%d, %d].\n", elem_min, position_row, position_column);
}


void negatives_nulls_positives(Matrix F)
{
	int i, j, neg = 0, null = 0, pos = 0;
	for(i = 0; i < F.m; i++)
	{
		for(j = 0; j < F.n; j++)
		{
			if(F.M[i][j] < 0)
			{
				neg++;
			}
			if(F.M[i][j]==0)
			{
				null++;
			}
			if(F.M[i][j]>0)
			{
				pos++;
			}
		}
	}
	printf("Matrix statistics:\nnegatives: %d\nnulls: %d\npositives: %d\n", neg, null, pos);
}


double primary_diagonal_elements_sum(Matrix F)
{
	int i;
	double sum = 0;
	for(i = 0; i < F.mp; i++)
	{
		 sum += F.M[i][i];
	}
	return sum;
}

void sum_of_two_matrix(Matrix A,Matrix B)
{

	int i, j;
	double C[100][100];
	for(i = 0; i < A.m; i++)
	{
		for(j = 0; j < A.n; j++)
		{
			C[i][j] = A.M[i][j] + B.M[i][j];
		}
	}
	printf("Sum matrix:\n\n");
	for (i = 0; i < A.m; i++)
	{
		for(j = 0; j < A.n; j++)
		{
			printf("%5g", C[i][j]);
		}
		printf("\n");
	}
}

void product_of_two_matrix(Matrix A,Matrix B)
{
	int i, j, k;
	double C[100][100];
	for(i = 0; i < A.m; i++)
	{
		for(j = 0;j < B.p; j++)
		{
			C[i][j]=0;
		}
	}

	for(i = 0; i < A.m; i++)
	{
		for(j = 0; j < B.p; j++)
		{
			for(k = 0; k < A.n; k++)
			{
				C[i][j] += A.M[i][k] * B.M[k][j];
			}
		}
	}
	printf("Product matrix:\n\n");
	for(i = 0; i < A.m; i++)
	{
		for(j = 0; j < B.p; j++)
		{
			printf("%5g\t", C[i][j]);
		}
		printf("\n");
	}
}


