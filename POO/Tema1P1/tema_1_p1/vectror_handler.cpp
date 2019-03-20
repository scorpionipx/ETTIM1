#include "stdafx.h"

void read_vector(Vector F)
{
	int i;
	for(i = 0; i < F.n; i++)
	{
		printf("element[%d]: ", i);
		if (scanf("%d", &F.V[i]) != 1)
		{
			printf("Input error! ");
			exit(1);
		}
	}
}

void print_vector(Vector F)
{
	int i;
	for(i = 0; i < F.n; i++)
	{
		printf("%d\t", F.V[i]);
		if((i+1) %5 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
}

long int vector_elements_sum(Vector F)
{
	int i;
	long int sum = 0;
	for(i = 0;i < F.n; i++)
	{
		sum += F.V[i];
	}
	return sum;
}

long int vector_elements_product(Vector F)
{
	long int prod = 1;
	int i;
	for(i = 0; i < F.n; i++)
	{
		prod *= F.V[i];
	}
	return prod;
}

void max_element_of_vector(Vector F)
{
	int i, elem_max = F.V[0], position = 0;
	for(i = 0; i < F.n; i++)
	{
		if(F.V[i] > elem_max)
		{
			 elem_max = F.V[i];
			 position = i;
		}
	}
	printf("Maximium element is: %d, at position: %d.\n", elem_max, position);
}

void min_element_of_vector(Vector F)
{
	int i, elem_min = F.V[0], position=0;
	for(i = 0; i < F.n; i++)
	{
		if(F.V[i] < elem_min)
		{
			elem_min = F.V[i];
			position = i;
		}
	}
	printf("Minimum element is: %d, at position: %d.\n", elem_min, position);
}

void ascending_sort(Vector F)
{
	int aux, i, j;

	for(i = 0; i < F.n; i++)
	{
		for(j = i+1; j < F.n; j++)
		{
			if(F.V[i] > F.V[j])
			{
				aux = F.V[i];
				F.V[i] = F.V[j];
				F.V[j] = aux;
			}
		}
	}
	printf("Ascending ordered vector:\n");
	print_vector(F);
}

void descending_sort(Vector F)
{
	int aux,i,j;

	for(i = 0; i < F.n; i++)
	{
		for(j = i+1; j < F.n; j++)
		{
			if(F.V[i] < F.V[j])
			{
				aux = F.V[i];
				F.V[i] = F.V[j];
				F.V[j] = aux;
			}
		}
	}
	printf("Descending ordered vector:\n");
	print_vector(F);
}

void vectors_sum(Vector X, Vector Y)
{
	int i;
	int S[100];
	for(i = 0; i < X.n; i++)
	{
		S[i] = X.V[i] + Y.V[i];
	}

	printf("Sum vector:\n");
	for(i = 0; i < X.n; i++)
	{
		printf("%d\t", S[i]);
	}
	printf("\n");
}

void vectors_product(Vector X, Vector Y)
{
	int i;
	int P[100];
	for(i = 0; i < X.n; i++)
	{
		P[i] = X.V[i] * Y.V[i];
	}
	printf("Product vector:\n");
	for(i = 0; i < X.n; i++)
	{
		printf("%d\t", P[i]);
	}
	printf("\n");
}

void scalar_product(Vector X, Vector Y)
{
	int i, ps = 0;

	for(i = 0; i < X.n; i++)
	{
		ps += X.V[i] * Y.V[i];
	}
	printf("Scalar product: %d\n", ps);
}

void column_line_product(Vector X, Vector Y)
{
	int i,j;
	int XY[100][100];
	for (i = 0; i < X.n; i++)
	{
		for (j = 0; j < X.n; j++)
		{
			XY[i][j] = X.V[i] * Y.V[j];
		}
	}
	printf("Column line product:\n");
	for (i = 0; i < X.n; i++)
	{
		for(j = 0; j < X.n; j++)
		{
			printf("%d\t ", XY[i][j]);
		}
		printf("\n");
	}
}
