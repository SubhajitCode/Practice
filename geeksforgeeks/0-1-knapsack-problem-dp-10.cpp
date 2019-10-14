#include<stdio.h> 

// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 

// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	int K[n+1][W+1];  
} 

int main() 
{ 
	int val[] = {60, 100, 120}; 
	int wt[] = {10, 20, 30}; 
	int  W = 50; 
	int n = sizeof(val)/sizeof(val[0]); 
	printf("%d", knapSack(W, wt, val, n)); 
	return 0; 
} 
