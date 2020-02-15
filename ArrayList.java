/**
*   Date Last Modified: 01/30/20
*	@author Andrew Rein
*
*	CS2321, Spring 2020
*
*/
package cs2321;

import java.util.Iterator;

import net.datastructures.List;

public class ArrayList<E> implements List<E> {

	public static final int CAPACITY = 16;
	private E[] data;
	private int size = 0;

	public ArrayList() {
		this(CAPACITY);
	}

	@SuppressWarnings("unchecked")
	public ArrayList(int capacity) {
		data = (E[]) new Object[capacity];
	}

	protected void checkIndex(int i, int n) throws IndexOutOfBoundsException, IllegalStateException {
		if (i < 0 || i >= n)
			throw new IndexOutOfBoundsException("Illega index");
	}

	@Override
	public int size() { //Returns the size of the list

		return size;
	}

	@Override
	public boolean isEmpty() { //Returns true if the list is empty 
		return size == 0;
	}

	@Override
	public E get(int i) throws IndexOutOfBoundsException { //Returns an element at a given index
		checkIndex(i, size);

		return data[i];
	}

	@Override
	public E set(int i, E e) throws IndexOutOfBoundsException { //Sets an element at the given index
		checkIndex(i, size);
		E temp = data[i];
		data[i] = e;
		return temp;
	}

	@Override
	public void add(int i, E e) throws IndexOutOfBoundsException { //Adds an element at a given index

		checkIndex(i, size + 1);
		if (size == data.length) {
			resize(2 * data.length);
		}

		for (int k = size - 1; k >= i; k--) {
			data[k + 1] = data[k];
		}
		data[i] = e;
		size++;
	}

	@Override
	public E remove(int i) throws IndexOutOfBoundsException { //Removes an element at a given index 
		checkIndex(i, size);
		E temp = data[i];
		for (int k = i; k < size - 1; k++) {
			data[k] = data[k + 1];
		}
		data[size - 1] = null;
		size--;

		return temp;
	}

	@Override
	public Iterator<E> iterator() {
		return null;
	}

	public void addFirst(E e) {
		data[size + 1] = e;
	}

	public void addLast(E e) {
	}

	public E removeFirst() throws IndexOutOfBoundsException {
		return null;
	}

	public E removeLast() throws IndexOutOfBoundsException {
		return null;
	}

	public void resize(int capacity) { //Allows the array to be resized of the capacity is reached
		@SuppressWarnings("unchecked")
		E[] temp = (E[]) new Object[capacity];
		for (int k = 0; k < size; k++) {
			temp[k] = data[k];
		}
		data = temp;
	}

	// Return the capacity of array, not the number of elements.
	// Notes: The initial capacity is 16. When the array is full, the array should
	// be doubled.
	public int capacity() {
		return data.length;
	}

}
