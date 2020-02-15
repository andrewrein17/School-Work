/**
*       
*       Date Last Modified: 01/30/20
*	@author Andrew Rein
*
*	CS2321, Spring 2020
*
*/
package cs2321;

import net.datastructures.Queue;

/**
 * @author ruihong-adm
 * @param <E>
 *
 */

public class CircularArrayQueue<E> implements Queue<E> {

	private int CAPACITY = 16;
	private int head;
	private int tail;
	private int size;
	private E[] queue;

	@SuppressWarnings("unchecked")
	public CircularArrayQueue(int queueSize) {
		head = 0;
		tail = 0;
		size = 0;
		queue = ((E[]) (new Object[queueSize]));
	}

	@Override
	public int size() {
		return size;
	}

	@Override
	public boolean isEmpty() {
		return size == 0;
	}

	@Override
	public void enqueue(E e) { //Queues an element at the end of the queue

		if (queue.length == size) {
			CAPACITY = CAPACITY * 2;
		}
		queue[tail] = e;
		tail = (tail + 1);

		size++;

	}

	@Override
	public E first() { //Returns the first element in the queue

		return queue[head];
	}

	@Override
	public E dequeue() { //Dequeues the first element in the queue  

		E temp = queue[head];
		queue[head] = null;
		head = (head + 1);

		size--;

		return temp;
	}

}
