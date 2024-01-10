package cs2321;

import java.util.Iterator;
import java.util.NoSuchElementException;

import net.datastructures.*;

public class LinkedPositionalList<E> implements PositionalList<E> {
	private Node<E> header;
	private Node<E> trailer;
	private int size = 0;

	public LinkedPositionalList() {
		header = new Node<>(null, null, null);
		trailer = new Node<>(null, header, null);
		header.setNext(trailer);
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
	public Position<E> first() {
		return position(header.getNext());
	}

	@Override
	public Position<E> last() {
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

	@Override
	public Position<E> addFirst(E e) {
		return addBetween(e, header, header.getNext());
	}

	@Override
	public Position<E> addLast(E e) {
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
	public E remove(Position<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		Node<E> prev = node.getPrev();
		Node<E> successor = node.getNext();
		prev.setNext(successor);
		successor.setPrev(prev);
		size--;
		E anw = node.element;
		node.setElement(null);
		node.setPrev(null);
		node.setNext(null);
		return anw;
	}

	private Node<E> validate(Position<E> p) throws IllegalArgumentException {
		if (!(p instanceof Node))
			throw new IllegalArgumentException("Invalid Position");
		Node<E> node = (Node<E>) p;
		if (node.getNext() == null) {
			throw new IllegalArgumentException("p is no longer in list!");
		}
		return node;
	}

	private Position<E> position(Node<E> node) {
		if (node == header || node == trailer)
			return null;
		return node;
	}

	private Position<E> addBetween(E e, Node<E> pred, Node<E> succ) {
		Node<E> newest = new Node<>(e, pred, succ);
		pred.setNext(newest);
		succ.setPrev(newest);
		size++;
		return newest;
	}

	private static class Node<E> implements Position<E> {
		private E element;
		private Node<E> next;
		private Node<E> prev;

		public Node(E e, Node<E> p, Node<E> n) {
			element = e;
			next = n;
			prev = p;
		}

		@Override
		public E getElement() throws IllegalStateException {
			if (next == null) {
				throw new IllegalStateException("Node not valid no more1");
			}
			return element;
		}

		public void setElement(E element) {
			this.element = element;
		}

		public Node<E> getNext() {
			return next;
		}

		public void setNext(Node<E> next) {
			this.next = next;
		}

		public Node<E> getPrev() {
			return prev;
		}

		public void setPrev(Node<E> prev) {
			this.prev = prev;
		}

	}

	private class PositionIterator implements Iterator<Position<E>> {
		private Position<E> cursor = first();
		private Position<E> recent = null;

		@Override
		public boolean hasNext() {
			return (cursor != null);
		}

		@Override
		public Position<E> next() throws NoSuchElementException {
			if (cursor == null) {
				throw new NoSuchElementException("Nothing Left");
			}
			recent = cursor;
			cursor = after(cursor);
			return recent;
		}

		@Override
		public void remove() throws IllegalStateException {
			if (recent == null) {
				throw new IllegalStateException("Nothing to remove");
			}
			LinkedPositionalList.this.remove(recent);
			recent = null;
		}
	}

	private class PositionIterable implements Iterable<Position<E>> {
		@Override
		public Iterator<Position<E>> iterator() {
			return new PositionIterator();
		}
	}

	public Iterable<Position<E>> positions() {
		return new PositionIterable();
	}

	private class ElementIterator implements Iterator<E> {
		Iterator<Position<E>> iter = new PositionIterator();

		@Override
		public boolean hasNext() {
			return iter.hasNext();
		}

		@Override
		public E next() {
			return iter.next().getElement();
		}

		@Override
		public void remove() {
			iter.remove();
		}
	}

	public Iterator<E> iterator() {
		return new ElementIterator();
	}
}
