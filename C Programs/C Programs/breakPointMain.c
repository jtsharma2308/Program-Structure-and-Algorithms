	#include <stdio.h>
	#include<time.h>
	
	void traditionalMultiply(int n, int a[200][200], int b[200][200], int c[200][200])
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
	    display(n, c);
	}
	
	void display(int n, int c[200][200])
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
	
		        
	double breakPoint(){
		int a[200][200], b[200][200], c[200][200] = {0};
	    clock_t start;
		int n, i, j;
		double size = 1;
		double diff1 = 0;
		double diff2 = 0;         	        
	        
	        
	        while(diff1 <= diff2)
		{
	        n = (int)pow(2.0, size);
	        
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
	    
	     
	    start = clock();   
	    traditionalMultiply(n, a, b, c);
	    diff1=(clock()-start)/(double)CLOCKS_PER_SEC;
	    printf("diff1: ");
	    printf("\n%f",diff1); 
	    printf("\n");
	    
	    start = clock();
	    strassenMultiply(n, a, b, c);
	     diff2=(clock()-start)/(double)CLOCKS_PER_SEC;
	     printf("diff2: ");
	    printf("\n%f",diff2); 
	    printf("\n");
	    
	    printf("Size: ");
	    printf("\n%f",size); 
	    
	    size++;
	    
	}
	
	printf("\nbreakpoint: ");
	printf("%f",pow(2.0, size-1));
	return pow(2.0, size-1);
	}
	
	void strassenMultiply (int n, int a[200][200], int b[200][200], int c[200][200])
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
	    display(n, c);
	}
	
	 
	int main()
	{
	    
		clock_t start;
		
		int a[200][200], b[200][200], c[200][200] = {0};
	    double diff,breakPnt;
	    int n, i, j;
	    
	    breakPnt = breakPoint();
	    printf("\nEnter size of Matrix A and B: ");
	scanf("%d", &n);
	
		for (i = 0; i < n; i++)
	    for (j = 0; j < n; j++) 
	    {
	        a[i][j] = rand();
	    }
	    printf("\nMatrix A: ");
	    display(n, a);
	    for (i = 0; i < n; i++)
	    for (j = 0; j < n; j++)
	    {
	        b[i][j] = rand();
	    } 
	    printf("\nMatrix B: ");
	    display(n, b);
	    
	    start = clock();
	    
	if(n >= breakPnt){
		printf("Multiplying using strassen's algorithm ");
		strassenMultiply(n, a, b, c);
		
	}else {
			printf("Multiplyting using traditional algorithm ");
		traditionalMultiply(n, a, b, c);
	
	}
	
	    diff=(clock()-start)/(double)CLOCKS_PER_SEC;
	    printf("\nTime taken: ");
	    printf("\n%f",diff); 
	    printf("\n");
	    
	}
	
	

