package cs2321;

import java.util.Comparator;

import net.datastructures.*;

/**
 * A Adaptable PriorityQueue based on an heap.
 * 
 * Course: CS2321 Section ALL Assignment: #3
 * 
 * @author Andrew Rein
 */

public class HeapPQ<K, V> implements AdaptablePriorityQueue<K, V> {

	protected ArrayList<Entry<K, V>> heap = new ArrayList<Entry<K, V>>();

	private Comparator<K> comp;

	/* use default comparator, see DefaultComparator.java */
	public HeapPQ() {
		this(new DefaultComparator<K>());
	}

	/* use specified comparator */
	public HeapPQ(Comparator<K> c) {
		comp = c;
	}

	
	protected int parent(int j) {
		return ((j - 1) / 2); // Returns the parent index
	}


	protected int left(int j) {
		return (2 * j + 1); // Returns the left index
	}

	
	protected int right(int j) {
		return (2 * j + 2); // Returns the right index
	}


	protected boolean hasLeft(int j) {
		return left(j) < heap.size(); // Returns true if has left
	}


	protected boolean hasRight(int j) {
		return right(j) < heap.size(); // Returns true if has right
	}

	/*
	 * Return the data array that is used to store entries This method is purely for
	 * testing purpose of auto-grader
	 */
	Object[] data() {
		return heap.data;
	}

	
	public Entry<K, V> getIndex(int i){
		return heap.get(i);
	}
	
	protected void swap(int i, int j) { // Swaps the indexes of two values
		Entry<K, V> temp = heap.get(i);
		heap.set(i, heap.get(j));
		heap.set(j, temp);
		((AdaptablePQEntry<K, V>) heap.get(i)).setIndex(i);
		((AdaptablePQEntry<K, V>) heap.get(j)).setIndex(j);

	}

	protected int compare(Entry<K, V> a, Entry<K, V> b) {
		return comp.compare(a.getKey(), b.getKey());
	}


	/**
	 * The entry should be bubbled up to its appropriate position
	 * 
	 * @param int move the entry at index j higher if necessary to restore the heap
	 *        property
	 */
	public void upheap(int j) {
		while (j > 0) {
			int p = parent(j);
			if (compare(heap.get(j), heap.get(p)) >= 0) {
				break;
			}
			swap(j, p);
			j = p;
		}
	}

	/**
	 * The entry should be bubbled down to its appropriate position
	 * 
	 * @param int move the entry at index j lower if necessary to restore the heap
	 *        property
	 */

	public void downheap(int j) {
		
		if (size() == 2 && compare(min(), heap.get(1)) > 0){
			K newKey = min().getKey();
			V newVal = min().getValue();
			replaceKey(min(), heap.get(1).getKey());
			replaceValue(min(), heap.get(1).getValue());
			replaceKey(heap.get(1), newKey);
			replaceValue(heap.get(1), newVal);
			
		}
		
		int i = 0;
		while (hasLeft(j)) {
			int leftIndex = left(j);
			int smallChildIndex = leftIndex;
			i++;
			if(i == size() + 1) break;
			if (hasRight(j)) {
				int rightIndex = right(j);
				if (compare(heap.get(leftIndex), heap.get(rightIndex)) > 0) {
					smallChildIndex = rightIndex;
				}
				if (compare(heap.get(smallChildIndex), heap.get(j)) >= 0)
					break;
				swap(j, smallChildIndex);
				j = smallChildIndex;

			}
		}
	}

	@Override
	public int size() {

		return heap.size(); // Returns the size of the arraylist
	}


	@Override
	public boolean isEmpty() {

		return heap.size() == 0; // Returns true if empty
	}

	
	@Override
	public Entry<K, V> insert(K key, V value) throws IllegalArgumentException { // Inserts a key value pair at a
																				// location
		// checkKey(key);
		Entry<K, V> n = new AdaptablePQEntry<>(key, value, heap.size());
		heap.addLast(n); // Adds n to the end of the list
		upheap(heap.size() - 1);
		return n;
	}

	@Override
	public Entry<K, V> min() {
		if (heap.isEmpty()) {
			return null;
		}
		return heap.get(0); // Gets the minimum element
	}


	@Override
	public Entry<K, V> removeMin() { // Removes the minimum element
		if (heap.isEmpty()) {
			return null;
		}
		Entry<K, V> answer = heap.get(0);
		swap(0, heap.size() - 1);
		heap.remove(heap.size() - 1);
		downheap(0);
		return answer;
	}

	protected static class AdaptablePQEntry<K, V> extends PQEntry<K, V> {
		private int index;

		public AdaptablePQEntry(K key, V value, int j) {
			super(key, value);
			index = j;
		}

		public int getIndex() {
			return index;
		}

		public void setIndex(int j) {
			this.index = j;
		}
	}

	protected AdaptablePQEntry<K, V> validate(Entry<K, V> entry) throws IllegalArgumentException {

		AdaptablePQEntry<K, V> locator = (AdaptablePQEntry<K, V>) entry;
		int j = locator.getIndex();
		if (j >= heap.size() || heap.get(j) != locator)
			throw new IllegalArgumentException("Invalid entry");
		return locator;

	}

	protected void bubble(int j) {
		if (j > 0 && compare(heap.get(j), heap.get(parent(j))) < 0) {
			upheap(j);
		} else {
			downheap(j);
		}

	}

	

	@Override
	public void remove(Entry<K, V> entry) throws IllegalArgumentException { // Removes an entry
		AdaptablePQEntry<K, V> locator = validate(entry);
		int j = locator.getIndex();
		if (j == heap.size() - 1)
			heap.remove(heap.size() - 1);
		else {
			swap(j, heap.size() - 1);
			heap.remove(heap.size() - 1);
			bubble(j);
		}

	}

	protected boolean checkKey(K key) throws IllegalArgumentException {
		try {
			return (comp.compare(key, key) == 0);

		} catch (ClassCastException e) {
			throw new IllegalArgumentException("Incompatible key");
		}
	}


	@Override
	public void replaceKey(Entry<K, V> entry, K key) throws IllegalArgumentException {
		AdaptablePQEntry<K, V> locator = validate(entry);
		checkKey(key);
		locator.setKey(key);
		bubble(locator.getIndex());

	}

	@Override
	public void replaceValue(Entry<K, V> entry, V value) throws IllegalArgumentException {
		AdaptablePQEntry<K, V> locator = validate(entry);
		locator.setValue(value);

	}


}
