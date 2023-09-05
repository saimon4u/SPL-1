#include<stdio.h>

#define f(x) (x)*(x) + 1

int n = 11;

void printArray(double *a);

int  main(void){
	
	double a = 0.0, b = 2.0, h;

	double x[n], y[n], quotient[n];
		
	h = ( b - a ) / ( n-1 );
		
	x[0] = a;
	
	for(int i = 1; i < n-1; ++i)	x[i] = x[i - 1] + h;	
	
	x[n - 1] = b;
	
	for(int i =0; i < n; ++i) y[i] = f(x[i]);
		

	//printArray(x);	
	//printArray(y);
	
	
	//Forward Quotient
	quotient[0] = (y[1] - y[0]) / (x[1] - x[0]) ;
	
	//printf("Forward quotient:%.2lf\n", quotient[0]);
	
	//Central Difference Quotient	
	
	//printf("Central Quotient:\n");
	//double centralDiff;	
	for(int i = 1; i < n-1; ++i){
		quotient[i] = (y[i+1] - y[i-1])/(x[i+1] - x[i-1]);
		//printf("%.2lf\n", quotient[i]);	
	}
		
	//Backward Difference Quotient
	
	quotient[n-1] = (y[n-1] - y[n-2]) / (x[n-1] - x[n-2]);
	
	//printf("Backward quotient:%.2lf\n", quotient[n-1]);
	
	printf("\"x\",\"f(x)\",\"f'(x)\"\n");
	for(int i = 0; i < n; ++i){
		printf("%.2lf,%.2lf,%.2lf\n",x[i], y[i], quotient[i]);
	}			
	
	return 0;
}


void printArray(double *a){
	for(int i = 0; i < n; ++i) printf("%.2lf  ", a[i]);
	printf("\n");
}