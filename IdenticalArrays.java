
/*
 * This program takes user input to create two 3x3 arrays and tests them to see if they're strictly identical or just identical.
 * 
 * author @ Andrew Rein
 * 
 * Date Modified : 9/21/19
 * 
 */
import java.util.Arrays;
import java.util.Scanner;

public class IdenticalArrays {

	public static void main(String[] args) {

		int[][] arr1 = new int[3][3];
		int[][] arr2 = new int[3][3];

		// Creates the arrays based on user input

		System.out.println("Enter list1 : ");
		Scanner arr1Scan = new Scanner(System.in);

		System.out.println("Enter list2 : ");
		Scanner arr2Scan = new Scanner(System.in);

		for (int r = 0; r < arr1.length; r++) {

			for (int c = 0; c < arr1[r].length; c++) {

				arr1[r][c] = arr1Scan.nextInt();
			}

		}
		for (int r = 0; r < arr2.length; r++) {

			for (int c = 0; c < arr2[r].length; c++) {

				arr2[r][c] = arr2Scan.nextInt();
			}

		}

		strictlyEquals(arr1, arr2);
		equals(arr1, arr2);
	}

	public static boolean strictlyEquals(int[][] m1, int[][] m2) {

		if (Arrays.deepEquals(m1, m2) == true) { // Uses Array.deepEquals to see if the two arrays are strictly identical
			System.out.println("The arrays are strictly equal.");
			return true;
		}

		System.out.println("The two arrays are not strictly identical.");
		return false;
	}

	public static boolean equals(int[][] m1, int[][] m2) { // Compares each element of each array to see if they contain the same elements but in a different order

		int count = 0;
		for (int j = 0; j < 3; j++) {

			for (int l = 0; l < 3; l++) {
				for (int r = 0; r < 3; r++) {

					for (int c = 0; c < 3; c++) {

						if (m2[j][l] == m1[r][c]) {
							count++;
						}
					}
				}
			}
		}
		if (count == 9) {
			System.out.println("The arrays are identical.");
			return true;
		}
		System.out.println("The arrays are not identical.");
		return false;
	}

}
