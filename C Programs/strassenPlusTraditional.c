#include <stdio.h>
#include<time.h>

void traditionalMultiply(int n, int a[10][10], int b[10][10], int c[10][10])
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

void strassenMultiply (int n, int a[10][10], int b[10][10], int c[10][10])
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
    int a[10][10], b[10][10], c[10][10] = {0};
    //double size = 1; 
	int n, i, j;
	float diff1 = 0.0F;
	float diff2 = 0.0F;
	clock_t t1, t2, t3, t4; 
	printf("Enter size of Matrix A and B: ");
    scanf("%d", &n);
	
		for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) 
        {
            a[i][j] = rand();
        }
        
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            b[i][j] = rand();
        } 
	
	if(n >= 4){
		strassenMultiply(n, a, b, c);
		printf("Multiplying using strassen's algorithm ");
	}else {
		traditionalMultiply(n, a, b, c);
		printf("Multiplyting using traditional algorithm ");
	}
	
//	while(diff1 <= diff2)
//	{
//        n = (int)pow(2.0, size);
//        
//		for (i = 0; i < n; i++)
//        for (j = 0; j < n; j++) 
//        {
//            a[i][j] = rand();
//        }
//        
//        for (i = 0; i < n; i++)
//        for (j = 0; j < n; j++)
//        {
//            b[i][j] = rand();
//        } 
//    
//     
//    t1 = clock();   
//    traditionalMultiply(n, a, b, c);
//    t2 = clock();   
//
//    diff1 = ((float)(t2 - t1) / 1000000.0F ) * 1000;   
//    printf("%f",diff1); 
//    printf("\n");
//    
//    t3 = clock();
//    strassenMultiply(n, a, b, c);
//    t4 = clock();
//    
//    diff2 = ((float)(t3 - t4) / 1000000.0F ) * 1000;   
//    printf("%f",diff2); 
//    printf("\n");
//    
//    size++;
//    
//}
//printf("%f",size); 
    return 0;
}

