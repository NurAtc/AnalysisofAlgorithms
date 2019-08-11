#include <stdio.h>

int max(int a, int b) { return (a > b)? a : b; }

int main()
{
    int A[4][6];

    int weight[3] = {3, 2, 1};
    int value[3] = {5, 3, 4};
    int W=5;

    for(int a=0; a<3; a++)
        A[a][0] = 0;

    for(int i=0; i<4; i++)
    {
        for(int j=1; j<6; j++)
	{
	    if(i==0 || j==0)
            {
	       A[i][j] = 0;
	       //printf("%d\n", A[i][j]);
	    }

	    else if(weight[i-1] > j)
	    {
		A[i][j] = A[i-1][j];
	        //printf("%d\n", A[i][j]);
	    }

	    else
	    {
		A[i][j] = max(A[i-1][j], value[i-1] + A[i-1][j-weight[i-1]]);
	        //printf("%d\n", A[i][j]);
	    }
	}
    }

    for(int b=0; b<4; b++)
    {
	for(int c=1; c<6; c++)
	    printf("%d ", A[b][c]);
	printf("\n");	    
    }

    printf("\n\n");
 

    int temp[4][6] = {0};

    for(int d=0; d<3; d++)
    {
	for(int f=1; f<6; f++)
	{
	     if(A[d][f] != A[d+1][f])
		 temp[d+1][f] = 1;
	     else
		 temp[d+1][f] = 0;
	}
    }

    for(int g=0; g<4; g++)
    {
	for(int h=1; h<6; h++)
	    printf("%d ", temp[g][h]);
	printf("\n");	    
    }

    printf("\n");

    for(int s=3; s>=0; s--)
	if(temp[s][W] == 1)
	{
	    W -= weight[s-1];
	    printf("%d. esya alindi\n", s);
	    printf("W:%d\n", W);
	}

    //printf("\n%d\n", W);

    return 0;
}
