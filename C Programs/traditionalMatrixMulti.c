#include <stdio.h>
#include <time.h>

void multiply(int n, int a[10][10], int b[10][10], int c[10][10])
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
 
int main()
{
    int a[10][10], b[10][10], c[10][10] = {0};
    int n, i, j;
    
 
    printf("Enter size of Matrix A and B respectively: ");
    scanf("%d", &n);
    
        printf("Enter elements in Matrix A:\n");
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
        
        printf("\nEnter elements in Matrix B:\n");
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &b[i][j]);
        }
                
         printf("\nTime taken by Traditional algorithm is:\n");
        
        clock_t t1, t2;
        float diff1;
        t1 = clock();   
    multiply(n, a, b, c);
    t2 = clock();   

    diff1 = ((float)(t2 - t1) / 1000.0F ) * 1000;   
    printf("%f",diff1); 
    printf("\n");
 
    printf("Result matrix is \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
           printf("%d ", c[i][j]);
        printf("\n");
    }
 
    return 0;
}
