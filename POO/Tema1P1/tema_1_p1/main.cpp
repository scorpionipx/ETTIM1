#include "stdafx.h"


int main(void)
{
	Vector v,X,Y;

	// P1
	printf("Enter vector size: ");
	if(scanf("%d",&v.n) != 1 || v.n <= 0 || v.n >= 100)
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_vector(&v);
	printf("Enter vector elemets: \n");
	read_vector(v);
	printf("Vector created: \n");
	print_vector(v);

	// P1.a
	printf("Vectro's elements sum: %ld\n", vector_elements_sum(v));
	printf("Vectro's elements product: %ld\n", vector_elements_product(v));

	// P1.b
	max_element_of_vector(v);
	min_element_of_vector(v);

	// P1.c
	ascending_sort(v);
	descending_sort(v);

	dealloc_vector(&v);


	printf("Enter vector X size: ");
	if(scanf("%d", &X.n)!= 1 || X.n <= 0 || X.n >= 100)
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_vector(&X);
	printf("Enter vector X elemets: \n");
	read_vector(X);

	printf("Vector X created: \n");
	print_vector(X);

	printf("Enter vector Y size: ");
	if(scanf("%d", &Y.n) != 1 || Y.n <= 0 || Y.n >= 100)
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_vector(&Y);
	printf("Enter vector Y elemets: \n");
	read_vector(Y);

	printf("Vector Y created: \n");
	print_vector(Y);

	// P1.d
	vectors_sum(X, Y);
	vectors_product(X, Y);

	// P1.e
	scalar_product(X, Y);

	// P1.f
	column_line_product(X,Y);

	dealloc_vector(&X);
	dealloc_vector(&Y);

	_getch();

	Matrix M,A,B,C,D;

	printf("Enter matrix size (rows, columns) n:\n");
	if(scanf("%d %d", &M.m, &M.n) != 2)
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_matrix(&M);
	printf("Enter matrix elements:\n");
	read_matrix(M);
	printf("Matrix created: \n");
	print_matrix(M);

	// P1.a
	printf("Matrix elements sum: %g\n", matrix_elements_sum(M));
	printf("Matrix elements product :%g\n", matrix_elements_product(M));
	// P1.b

	max_element_of_matrix(M);
	min_element_of_matrix(M);

	// P1.c
	negatives_nulls_positives(M);
	dealloc_matrix(&M);


	printf("Enter nxn matrix size:\n");
	if(scanf("%d", &D.mp)!=1)
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_matrix_nxn(&D);
	printf("Enter matrix elements:\n");
	read_matrix_nxn(D);
	printf("Matrix is:\n");
	print_matrix_nxn(D);

	// P1.d
	printf("Primary diagonal's elements sum: %g\n", primary_diagonal_elements_sum(D));
	dealloc_matrix_nxn(&D);


	//e)
	printf("Enter nxp matrix size:\n");
	if(scanf("%d%d",&A.m,&A.n)!=2 )
	{
		printf("Input error!");
		exit(1);
	}

	dynmic_allocation_matrix(&A);
	B.m = A.m;
	B.n = A.n;
	dynmic_allocation_matrix(&B);

	printf("Enter matrix A elements:\n");
	read_matrix(A);
	printf("Matrix A created: \n");
	print_matrix(A);

	printf("Enter matrix B elements:\n");
	read_matrix(B);
	printf("Matrix B created: \n");
	print_matrix(B);

	// P1.e
	sum_of_two_matrix(A, B);
	dealloc_matrix(&A);
	dealloc_matrix(&B);

	// P1.f
	printf("Enter matrix A size:\n");
	if(scanf("%d %d", &A.m, &A.n)!=2)
	{
		printf("Input error!");
		exit(1);
	}
	dynmic_allocation_matrix(&A);
	printf("Enter matrix A elements:\n");
	read_matrix(A);
	printf("Matrix A created:\n");
	print_matrix(A);


	printf("Enter matrix B number of columns:\n");
	if(scanf("%d", &B.p)!=1 )
	{
		printf("Input error!");
		exit(1);
	}

	B.n = A.n;
	dynmic_allocation_matrix_nxp(&B);
	printf("Enter matrix B elements:\n");
	read_matrix_nxp(B);
	printf("Matrix B created:\n");
	print_matrix_nxp(B);

	product_of_two_matrix(A,B);

	dealloc_matrix(&A);
	dealloc_matrix_nxp(&B);
	_getch();

	return 0;
}
