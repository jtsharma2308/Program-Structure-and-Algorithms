package traditionalMethod;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Random;

/**
 ** Java Program to Implement Strassen Algorithm
 **/

import java.util.Scanner;

/** Class Strassen **/
public class Strassen {
	/** Function to multiply matrices **/
	public int[][] multiply(int[][] A, int[][] B) {
		int n = A.length;
		int[][] R = new int[n][n];
		/** base case **/
		if (n == 1)
			R[0][0] = A[0][0] * B[0][0];
		else {
			int[][] A11 = new int[n / 2][n / 2];
			int[][] A12 = new int[n / 2][n / 2];
			int[][] A21 = new int[n / 2][n / 2];
			int[][] A22 = new int[n / 2][n / 2];
			int[][] B11 = new int[n / 2][n / 2];
			int[][] B12 = new int[n / 2][n / 2];
			int[][] B21 = new int[n / 2][n / 2];
			int[][] B22 = new int[n / 2][n / 2];

			/** Dividing matrix A into 4 halves **/
			split(A, A11, 0, 0);
			split(A, A12, 0, n / 2);
			split(A, A21, n / 2, 0);
			split(A, A22, n / 2, n / 2);
			/** Dividing matrix B into 4 halves **/
			split(B, B11, 0, 0);
			split(B, B12, 0, n / 2);
			split(B, B21, n / 2, 0);
			split(B, B22, n / 2, n / 2);

			/**
			 * M1 = (A11 + A22)(B11 + B22) 
			 * M2 = (A21 + A22) B11 
			 * M3 = A11 (B12 - B22)
			 * M4 = A22 (B21 - B11) 
			 * M5 = (A11 + A12) B22 
			 * M6 = (A21 - A11)(B11 + B12) 
			 * M7 = (A12 - A22) (B21 + B22)
			 **/

			int[][] M1 = multiply(add(A11, A22), add(B11, B22));
			int[][] M2 = multiply(add(A21, A22), B11);
			int[][] M3 = multiply(A11, sub(B12, B22));
			int[][] M4 = multiply(A22, sub(B21, B11));
			int[][] M5 = multiply(add(A11, A12), B22);
			int[][] M6 = multiply(sub(A21, A11), add(B11, B12));
			int[][] M7 = multiply(sub(A12, A22), add(B21, B22));

			/**
			 * C11 = M1 + M4 - M5 + M7 
			 * C12 = M3 + M5 
			 * C21 = M2 + M4 
			 * C22 = M1 - M2 + M3 + M6
			 **/
			int[][] C11 = add(sub(add(M1, M4), M5), M7);
			int[][] C12 = add(M3, M5);
			int[][] C21 = add(M2, M4);
			int[][] C22 = add(sub(add(M1, M3), M2), M6);

			/** join 4 halves into one result matrix **/
			join(C11, R, 0, 0);
			join(C12, R, 0, n / 2);
			join(C21, R, n / 2, 0);
			join(C22, R, n / 2, n / 2);
		}
		/** return result **/
		return R;
	}

	/** Function to traditional matrix multiplication **/
	public static int[][] traditionalMultiply(int[][] a, int[][] b) {
		int n = a.length;
		int[][] c = new int[n][n];
		int i, j;

		for (i = 0; i < a.length; i++) {
			for (j = 0; j < a.length; j++) {
				c[i][j] = 0;
				for (int k = 0; k < a.length; k++) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return c;
	}

	/** Funtion to sub two matrices **/
	public int[][] sub(int[][] A, int[][] B) {
		int n = A.length;
		int[][] C = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = A[i][j] - B[i][j];
		return C;
	}

	/** Funtion to add two matrices **/
	public int[][] add(int[][] A, int[][] B) {
		int n = A.length;
		int[][] C = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = A[i][j] + B[i][j];
		return C;
	}

	/** Funtion to split parent matrix into child matrices **/
	public void split(int[][] P, int[][] C, int iB, int jB) {
		for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
			for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
				C[i1][j1] = P[i2][j2];
	}

	/** Funtion to join child matrices intp parent matrix **/
	public void join(int[][] C, int[][] P, int iB, int jB) {
		for (int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
			for (int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
				P[i2][j2] = C[i1][j1];
	}

	public static int[][] matrixCreation(double size) {
		int[][] a = new int[(int) size][(int) size];

		Random random = new Random();

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				a[i][j] = random.nextInt(20);
			}
		}

		return a;
	}

	/** Main function **/
	public static void main(String[] args) {
		
		algo1();
		algo2();
		
		Strassen s = new Strassen();

		int n = 1;
		long traditionalTime = 0;
		long strassenTime = 0;
		double breakPoint = 0;

// Finding breakpoint//
		
		while(traditionalTime <= strassenTime){
			//while(n > 0){
			int[][] a = matrixCreation(Math.pow(2,n));
			int[][] b = matrixCreation(Math.pow(2,n));

			// ******************************************************//

			System.out.println("strassen: A x B");
			traditionalTime = System.currentTimeMillis();
			s.multiply(a, b);		
			traditionalTime = System.currentTimeMillis() - traditionalTime;
			System.out.println("time1 = " + traditionalTime);


			System.out.println("normal: A x B");
			strassenTime = System.currentTimeMillis();
			traditionalMultiply(a, b);
			strassenTime = System.currentTimeMillis() - strassenTime;
			System.out.println("time2 = " + strassenTime);

			n++;

			// ******************************************************//
		}
		breakPoint = Math.pow(2,n-1);	

		System.out.println("size: " +breakPoint );
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter order n :"); 
		int N = scan.nextInt();

		System.out.println("Enter N order matrix 1\n");
		int[][] A = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				A[i][j] = scan.nextInt();

		System.out.println("Enter N order matrix 2\n");
		int[][] B = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				B[i][j] = scan.nextInt();

// ****************************************Algorithm 3***************************************************** //		
		int[][] C = new int[N][N];

		if(N > breakPoint){
			C = s.multiply(A, B);
			System.out.println("Calculating using Strassens's algorithm!");
		}else{
			C = traditionalMultiply(A,B);
			System.out.println("Calculating using Traditional algorithm!");
		}

		System.out.println("\nProduct of matrices A and B : ");
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				System.out.print(C[i][j] +" ");
			System.out.println();
		}


	}
	
// ****************************************Algorithm 1***************************************************** //
	public static void algo1(){
		System.out.println("Inside Algo1");		
		/*int N = 0;
		Scanner scanner;
		try {
			scanner = new Scanner(new File("D:/Sem 5/Program Structure and Algorithms/Assignment 3/MatrixInputExample.txt"));
			String line = scanner.nextLine();
			int iA = 1;
			int x = Integer.parseInt(line);
			N = x-1;
			int[] tall = new int[N];


			while(scanner.hasNextInt()){
				try {
					tall[iA++] = Integer.parseInt(line);
				}
				catch (NumberFormatException ex) {
					continue;
				}
			}				

			int[][] A = new int[N/2][N/2]; 
			int[][] B = new int[N/2][N/2];
			int indexA = 0;
			for (int i = 0; i < N/2; i++){ 
				for (int j = 0; j <	N/2; j++){ 
					A[i][j] = tall[indexA];
					indexA++;
				}
			}

			indexA = N - indexA;
			for (int i = 0; i < N/2; i++) {
				for (int j = 0; j <	N/2; j++){ 
					A[i][j] = tall[indexA];
					indexA++;
				}
			}*/
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter order n :"); 
		int N = scan.nextInt();

		System.out.println("Enter N order matrix 1\n");
		int[][] A = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				A[i][j] = scan.nextInt();

		System.out.println("Enter N order matrix 2\n");
		int[][] B = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				B[i][j] = scan.nextInt();
		

		long time1 = System.currentTimeMillis();
		traditionalMultiply(A,B);		
		time1 = System.currentTimeMillis() - time1;
		System.out.println("time for algo1: " + time1);
	}
	
// ****************************************Algorithm 2***************************************************** //	
	public static void algo2(){
		System.out.println("Inside Algo12");		
		
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter order n :"); 
		int N = scan.nextInt();

		System.out.println("Enter N order matrix 1\n");
		int[][] A = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				A[i][j] = scan.nextInt();

		System.out.println("Enter N order matrix 2\n");
		int[][] B = new int[N][N]; 
		for (int i = 0; i < N; i++) 
			for (int j = 0; j <	N; j++) 
				B[i][j] = scan.nextInt();
		

		long time2 = System.currentTimeMillis();
		Strassen s1 = new Strassen();
		s1.multiply(A,B);		
		time2 = System.currentTimeMillis() - time2;
		System.out.println("time for algo2: " + time2);
	}
}
