/**
*       
*   Date Last Modified: 01/30/20
*	@author Andrew Rein
*
*	CS2321, Spring 2020
*
*/
package cs2321;

import java.util.Iterator;

import net.datastructures.Position;
import net.datastructures.PositionalList;

public class DoublyLinkedList<E> implements PositionalList<E> {

	private static class Node<E> implements Position<E> {

		private E element;
		private Node<E> prev;
		private Node<E> next;

		public Node(E e, Node<E> p, Node<E> n) {
			element = e;
			prev = p;
			next = n;
		}

		@Override
		public E getElement() throws IllegalStateException {
			if (next == null) {
				throw new IllegalStateException("Position not valid");
			}
			return element;
		}

		//Returns the previous node 
		public Node<E> getPrev() {
			return prev;
		}
        //Returns the next node
		public Node<E> getNext() {
			return next;
		}
		
		public void setElement(E e) {
			element = e;
		}

		public void setPrev(Node<E> p) {
			prev = p;
		}

		public void setNext(Node<E> n) {
			next = n;
		}

	}

	private Node<E> header; //Keeps the head of the list
	private Node<E> trailer; //Keeps the tail of the list
	private int size = 0;

	//Constructs a new object 
	public DoublyLinkedList() { 
		header = new Node<>(null, null, null);
		trailer = new Node<>(null, header, null);
		header.setNext(trailer);
	}

	private Node<E> validate(Position<E> p) throws IllegalArgumentException {
		if (!(p instanceof Node))
			throw new IllegalArgumentException("Invalid");
		Node<E> node = (Node<E>) p;
		if (node.getNext() == null) {
			throw new IllegalArgumentException("p is not in the list");
		}
		return node;
	}

	@Override
	public int size() { //Returns the size of the list 

		return size;
	}

	@Override
	public boolean isEmpty() { //Returns true if the list in empty
		return size == 0;
	}

	private Position<E> position(Node<E> node) { //Gets the position of the node
		if (node == header || node == trailer) {
			return null;
		}
		return node;
	}

	@Override
	public Position<E> first() { //Returns the first node in the list

		return position(header.getNext());
	}

	@Override
	public Position<E> last() { //Returns the last node in the list

		return position(trailer.getPrev());
	}

	@Override
	public Position<E> before(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return position(node.getPrev());
	}

	@Override
	public Position<E> after(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return position(node.getNext());
	}

	private Position<E> addBetween(E e, Node<E> pred, Node<E> succ) { //Adds a node between any two nodes 
		Node<E> newest = new Node<>(e, pred, succ);
		pred.setNext(newest);
		succ.setPrev(newest);
		size++;
		return newest;
	}

	@Override
	public Position<E> addFirst(E e) { //Adds a node to the start of the list 

		return addBetween(e, header, header.getNext());
	}

	@Override
	public Position<E> addLast(E e) { //Adds a node to the end of the list 

		return addBetween(e, trailer.getPrev(), trailer);
	}

	@Override
	public Position<E> addBefore(Position<E> p, E e) throws IllegalArgumentException {
		Node<E> node = validate(p);

		return addBetween(e, node.getPrev(), node);
	}

	@Override
	public Position<E> addAfter(Position<E> p, E e) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return addBetween(e, node, node.getNext());
	}

	@Override
	public E set(Position<E> p, E e) throws IllegalArgumentException {
		Node<E> node = validate(p);
		E answer = node.getElement();
		node.setElement(e);
		return answer;
	}

	@Override
	public E remove(Position<E> p) throws IllegalArgumentException { //Removes a node at a position 

		Node<E> node = validate(p);
		Node<E> predecessor = node.getPrev();
		Node<E> successor = node.getNext();
		predecessor.setNext(null);
		successor.setPrev(null);
		size--;
		E answer = node.getElement();
		node.setElement(null);
		node.setNext(null);
		node.setPrev(null);
		return answer;
	}

	@Override
	public Iterator<E> iterator() {
		return null;
	}

	@Override
	public Iterable<Position<E>> positions() {
		return null;
	}

	public E removeFirst() throws IllegalArgumentException { //Removes the first node in the list 
		E temp = header.getElement();

		if (header.next == null) {
			header = null;
		} else {
			header.next.prev = null;
			header = header.next;
		}
		return temp;
	}

	public E removeLast() throws IllegalArgumentException { //Removes the last node in the list
		E temp = trailer.getElement();
		trailer.prev.next = null;
		trailer = trailer.prev;

		return temp;
	}

}
