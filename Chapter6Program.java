
/**
*	This program creates an n x n array and fills it with random 1s and 0s
*       
*       Date Last Modified: 09/15/19
*	@author Andrew Rein
*
*	CS1131, Fall 2019
*
*/
import java.util.Arrays;
import java.util.Scanner;

public class Chapter6Program {

	public static void main(String[] args) {

		System.out.println("Enter n : "); // Allows the user to enter n
		Scanner nScan = new Scanner(System.in);//

		int n = nScan.nextInt();

		printMatrix(n);
	}

	public static void printMatrix(int n) {

		int[][] arr = new int[n][n];

		for (int r = 0; r < arr.length; r++) { // creates and fills an n x n array with 1s and 0s

			for (int c = 0; c < arr[r].length; c++) {

				arr[r][c] = (int) (Math.random() + 0.5); // random 1 or 0
				System.out.print(arr[r][c] + " ");
			}

			System.out.println();
		}

	}

}
