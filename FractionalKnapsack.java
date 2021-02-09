package cs2321;

import net.datastructures.Entry;
import java.util.Comparator;

/**
 * @author: Andrew Rein
 *
 */
public class FractionalKnapsack {

	/**
	 * Goal: Choose items with maximum total benefit but with weight at most W. You
	 * are allowed to take fractional amounts from items.
	 * 
	 * @param items          items[i][0] is weight for item i items[i][1] is benefit
	 *                       for item i
	 * @param knapsackWeight
	 * @return The maximum total benefit. Please use double type operation. For
	 *         example 5/2 = 2.5
	 * 
	 */
	public static double MaximumValue(int[][] items, int knapsackWeight) {

		double totalValue = 0;
		double W = (double) knapsackWeight;

		NewComparator c = new NewComparator();
		HeapPQ<Double, Double> PQ = new HeapPQ<>(c);

		//Inserts all the elements based on value
		for (int i = 0; i < items.length; i++) {
			PQ.insert((double) ((double) items[i][1] / (double) items[i][0]), (double) items[i][0]); 
		}

		//Puts the items with the most value into the knapsack
		while (!PQ.isEmpty()) {

			Entry<Double, Double> item = PQ.removeMin();

			if (W - item.getValue() < 0) { //Checks if the weight would go over

				totalValue += item.getKey() * W; //Puts a fraction of the item in to fill the knapsack
				break;
				
			} else {
				
				totalValue += item.getKey() * item.getValue(); //Adds the item to the knapsack
				W -= item.getValue();
			}

		}

		return totalValue;
	}

	/*
	 * Comparator for a max PQ
	 */
	public static class NewComparator extends DefaultComparator<Double> {

		@Override
		public int compare(Double a, Double b) throws ClassCastException {
			return super.compare(a, b) * -1;
		}

	}
}
