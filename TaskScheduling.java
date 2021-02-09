package cs2321;

import net.datastructures.Entry;

public class TaskScheduling {
	/**
	 * Goal: Perform all the tasks using a minimum number of machines.
	 * 
	 * 
	 * @param tasks tasks[i][0] is start time for task i tasks[i][1] is end time for
	 *              task i
	 * @return The minimum number or machines
	 */
	public static int NumOfMachines(int[][] tasks) {

		HeapPQ<Integer, Integer> taskPQ = new HeapPQ<>();
		HeapPQ<Integer, Integer> machinePQ = new HeapPQ<>();

		// Inserts all tasks into PQ
		for (int i = 0; i < tasks.length; i++) {
			taskPQ.insert(tasks[i][0], tasks[i][1]);
		}

		while (!taskPQ.isEmpty()) {

			Entry<Integer, Integer> task = taskPQ.removeMin();

			if (machinePQ.isEmpty()) { // Inserts the first element into the machinePQ

				machinePQ.insert(task.getValue(), 0);

			} else if (machinePQ.min().getKey() <= task.getKey()) { // Compares the times to see if another job can be
																	// put in the same machine

				machinePQ.replaceKey(machinePQ.min(), task.getValue());

			} else { // Makes a new machine if no space is available for a job.

				machinePQ.insert(task.getValue(), 0);

			}

		}

		return machinePQ.size();
	}
}
