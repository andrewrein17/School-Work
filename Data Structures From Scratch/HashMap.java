/**
*	HashMap using an array that handles collisions using separate chaining 
*       
*   Date Last Modified: 11/16/20
*	@author Andrew Rein
*
*	CS2321, Fall 2020
*
*/
package cs2321;

import net.datastructures.*;

public class HashMap<K, V> extends AbstractMap<K, V> implements Map<K, V> {

	/*
	 * Use Array of UnorderedMap<K,V> for the Underlying storage for the map of
	 * entries.
	 * 
	 */
	private UnorderedMap<K, V>[] table;
	int size; // number of mappings(entries)
	int capacity; // The size of the hash table.
	int DefaultCapacity = 17; // The default hash table size

	/*
	 * Maintain the load factor <= 0.75. If the load factor is greater than 0.75,
	 * then double the table, rehash the entries, and put then into new places.
	 */
	double loadfactor = 0.75;

	/**
	 * Constructor that takes a hash size
	 * 
	 * @param hashtable size: the number of buckets to initialize
	 */
	@SuppressWarnings("unchecked")
	public HashMap(int hashtablesize) {

		table = (UnorderedMap<K, V>[]) new UnorderedMap[hashtablesize];
		capacity = hashtablesize;
		for (int i = 0; i < capacity; i++) {

			table[i] = new UnorderedMap<K, V>();

		}

	}

	/**
	 * Constructor that takes no argument Initialize the hash table with default
	 * hash table size: 17
	 */
	public HashMap() {
		this(17);

	}

	/*
	 * This method should be called by map an integer to the index range of the hash
	 * table
	 */
	private int hashValue(K key) {
		return Math.abs(key.hashCode()) % capacity;
	}

	/*
	 * The purpose of this method is for testing if the table was doubled when
	 * rehashing is needed. Return the the size of the hash table. It should be 17
	 * initially, after the load factor is more than 0.75, it should be doubled.
	 */
	public int tableSize() {
		return capacity;
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
	@TimeComplexity("O(n)")
	public V get(K key) {

		return bucketGet(hashValue(key), key);
	}

	/*
	 * Puts a key value pair into the table
	 */
	@TimeComplexity("O(n)")
	@Override
	public V put(K key, V value) {

		V answer = bucketPut(hashValue(key), key, value);

		if (size > capacity / 2) {
			resize(2 * capacity - 1);
		}

		return answer;

	}
	

	/*
	 * Resizes the table if needed
	 */
	private void resize(int newCap) {

		ArrayList<Entry<K, V>> buffer = new ArrayList<>(size);

		for (Entry<K, V> e : entrySet()) {
			buffer.addLast(e);
		}
		capacity = newCap;
		createTable();
		size = 0;
		for (Entry<K, V> e : buffer) {
			put(e.getKey(), e.getValue());
		}

	}

	@SuppressWarnings("unchecked")
	protected void createTable() {

		table = (UnorderedMap<K, V>[]) new UnorderedMap[capacity];

	}

	@TimeComplexity("O(n^2)")
	@Override
	public V remove(K key) {
		return bucketRemove(hashValue(key), key);
	}

	@Override
	public Iterable<Entry<K, V>> entrySet() {
		ArrayList<Entry<K, V>> buffer = new ArrayList<>();
		for (int i = 0; i < capacity; i++) {
			if (table[i] != null) {
				for (Entry<K, V> entry : table[i].entrySet()) {
					buffer.addLast(entry);
				}
			}
		}
		return buffer;
	}

	/*
	 * Gets the value with the K k or returns null if not found
	 */
	@TimeComplexity("O(n)")
	private V bucketGet(int h, K k) {
		UnorderedMap<K, V> bucket = table[h];
		if (bucket == null)
			return null;
		return bucket.get(k);
	}

	/*
	 * Puts key value pair into table and returns old value
	 */
	@TimeComplexity("O(n)")
	private V bucketPut(int h, K k, V v) {
		UnorderedMap<K, V> bucket = table[h];
		if (bucket == null) {
			bucket = table[h] = new UnorderedMap<>();
		}
		V val = bucketGet(h, k); //Holds the old value
		int oldSize = bucket.size();
		V answer = bucket.put(k, v);
		

		size += (bucket.size() - oldSize); //Updates size

		return val;
	}

	protected V bucketRemove(int h, K k) {
		UnorderedMap<K, V> bucket = table[h];
		if (bucket == null)
			return null;
		int oldSize = bucket.size();
		V answer = bucket.remove(k);

		size -= (oldSize - bucket.size());
		return answer;
	}

}
