/*
 * C Program to Perform Matrix Multiplication using Recursion
 */
#include <stdio.h>
#include<time.h> 
 
void multiply(int, int [][10], int [][10], int [][10]);
void display(int, int[][10]);
 
int main()
{
    int a[10][10], b[10][10], c[10][10] = {0};
    int n, i, j, k;
    
 
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
        
        printf("\nTime taken by Strassen's algorithmis:\n");
        
        clock_t t1, t2;
        float diff1;
        t1 = clock();   
    multiply(n, a, b, c);
    t2 = clock();   

    diff1 = ((float)(t2 - t1) / 1000.0F ) * 1000;   
    printf("%f",diff1); 
    printf("\n");
        
    printf("On matrix multiplication of A and B the result is:\n");
    display(n, c);
}
 
void multiply (int n, int a[10][10], int b[10][10], int c[10][10])
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
                multiply(n, a, b, c);
            }
            k = 0;
            j++;
            multiply(n, a, b, c);
        }
        j = 0;
        i++;
        multiply(n, a, b, c);
    }
}
 
void display(int n, int c[10][10])
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
