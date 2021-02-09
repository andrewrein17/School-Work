package cs2321;

public class QuickSort<E extends Comparable<? super E>> implements Sorter<E> {

	public void sort(E[] array) {

		quickSort(array, 0, array.length - 1);

	}

	@TimeComplexity("O(n lg n")
	private void quickSort(E[] array, int p, int q) {
		if (p < q) {
			int r = partition(array, p, q); // Sets the pivot.
			quickSort(array, p, r); // Left array.
			quickSort(array, r + 1, q); // Right array.
		}
	}

	private int partition(E[] array, int p, int q) {
		int pivotIndex = (p + q) / 2;
		E pivot = array[pivotIndex]; // Sets the pivot to the value at the pivotIndex.
		p--;
		q++;

		while (true) {
			do
				p++;
			while (array[p].compareTo(pivot) < 0); // Finds value greater than pivot.
			do
				q--;
			while (array[q].compareTo(pivot) > 0); // Finds value less than pivot.

			if (p >= q) {
				return q;
			}

			E tmp = array[p]; // Swaps the values of p and q.

			array[p] = array[q];
			array[q] = tmp;
		}
	}
}
