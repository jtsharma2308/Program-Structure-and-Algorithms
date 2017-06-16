#include <stdio.h>
#include<time.h>

void traditionalMultiply(int n, int a[100][100], int b[100][100], int c[100][100])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += a[i][k]*b[k][j];
        }
    }
}

void display(int n, int c[100][100])
{
    int i, j;
 
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", c[i][j]);
        }
        printf("\n");
    }
}

void strassenMultiply (int n, int a[100][100], int b[100][100], int c[100][100])
{
    static int i = 0, j = 0, k = 0;
 
    if (i >= n)
    {
        return;
    }
    else if (i < n)
    {
        if (j < n)
        {
            if (k < n)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
                strassenMultiply(n, a, b, c);
            }
            k = 0;
            j++;
            strassenMultiply(n, a, b, c);
        }
        j = 0;
        i++;
        strassenMultiply(n, a, b, c);
    }
}

 
int main()
{
    int a[100][100], b[100][100], c[100][100] = {0};
    clock_t start;
	int n, i, j;
	double diff1, diff2 = 0.0F;
	clock_t t1, t2, t3, t4; 
	printf("Enter size of Matrix A and B: ");
    scanf("%d", &n);
	
		for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
        {
            a[i][j] = rand();
        }
        display(n, a);
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            b[i][j] = rand();
        } 
        display(n, b);
	
	start=clock();
	if(n >= 4){
		strassenMultiply(n, a, b, c);
		printf("Multiplying using strassen's algorithm ");
	}else {
		traditionalMultiply(n, a, b, c);
		printf("Multiplyting using traditional algorithm ");
	}
	diff1=(clock()-start)/(double)CLOCKS_PER_SEC;
    printf("\n%f",diff1);
	 
    return 0;
}


