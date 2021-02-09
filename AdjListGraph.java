/**
*	This program constructs a graph of vertices and edges
*       
*   Date Last Modified: 12/1/20
*	@author Andrew Rein
*
*	CS2321, Fall 2020
*
*/
package cs2321;

import net.datastructures.*;

/*
 * Implement Graph interface. A graph can be declared as either directed or undirected.
 * In the case of an undirected graph, methods outgoingEdges and incomingEdges return the same collection,
 * and outDegree and inDegree return the same value.
 * 
 * @author CS2321 Instructor
 */
public class AdjListGraph<V, E> implements Graph<V, E> {

	private class InnerVertex<V> implements Vertex<V> {
		private V element;
		private Position<Vertex<V>> pos;
		public Map<Vertex<V>, Edge<E>> outgoing, incoming;

		public InnerVertex(V elem, boolean graphIsDirected) {

			element = elem;
			outgoing = new HashMap<>();
			if (graphIsDirected) {
				incoming = new HashMap<>();
			} else {
				incoming = outgoing;
			}

		}

		@TimeComplexity("O(1)")
		public boolean validate(Graph<V, E> graph) {
			return (AdjListGraph.this == graph && pos != null);
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the element in the vertex
		public V getElement() {
			return element;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a setter method
		// Sets the position of the vertex in the graph
		public void setPosition(Position<Vertex<V>> p) {
			pos = p;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the position of the vertex
		public Position<Vertex<V>> getPosition() {
			return pos;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the number of outgoing edges
		public Map<Vertex<V>, Edge<E>> getOutgoing() {
			return outgoing;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the number of incoming edges
		public Map<Vertex<V>, Edge<E>> getIncoming() {
			return incoming;
		}

		@Override
		public int compareTo(V o) {
			// TODO Auto-generated method stub
			return 0;
		}

	}

	private class InnerEdge<E> implements Edge<E> {

		private E element;
		private Position<Edge<E>> pos;
		private Vertex<V>[] endpoints;

		@SuppressWarnings("unchecked")
		public InnerEdge(Vertex<V> u, Vertex<V> v, E elem) {
			element = elem;
			endpoints = (Vertex<V>[]) new Vertex[] { u, v };
		}

		@TimeComplexity("O(1)")
		// TCJ: Just returns a bool check
		public boolean validate(Graph<V, E> graph) {
			return AdjListGraph.this == graph && pos != null;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the element at the edge
		public E getElement() {
			return element;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Returns the end points of the edge
		public Vertex<V>[] getEndPoints() {
			return endpoints;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a setter method
		// Sets the edge's position in the graph
		public void setPosition(Position<Edge<E>> p) {
			pos = p;
		}

		@TimeComplexity("O(1)")
		// TCJ: Just a getter method
		// Gets the edge's position in the graph
		public Position<Edge<E>> getPosition() {
			return pos;
		}

	}

	private boolean isDirected;
	public PositionalList<Vertex<V>> vertices = new LinkedPositionalList<>();
	public PositionalList<Edge<E>> edges = new LinkedPositionalList<>();

	public AdjListGraph(boolean directed) {
		isDirected = directed;
	}

	public AdjListGraph() {
		isDirected = false;
	}

	@TimeComplexity("O(1)")
	// TCJ: Just a getter method
	// Returns the number of vertices in the graph
	public int numVertices() {
		return vertices.size();
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns an iterable
	public Iterable<Vertex<V>> vertices() {
		return vertices;
	}

	@TimeComplexity("O(1)")
	// TCJ: Just a getter method
	// Returns the number of edges in the list
	public int numEdges() {
		return edges.size();
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns an iterable
	public Iterable<Edge<E>> edges() {
		return edges;
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns the size of the out degree of a vertex
	// Returns the out degree of the vertex
	public int outDegree(Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> vert = validate(v);
		return vert.getOutgoing().size();
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns an iterable
	// Returns an iterable of the outgoing edges of a vertex
	public Iterable<Edge<E>> outgoingEdges(Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> vert = validate(v);
		return vert.getOutgoing().values();
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns the size of the in degree of a vertex
	// Returns the in degree of the vertex
	public int inDegree(Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> vert = validate(v);
		return vert.getIncoming().size();
	}

	@TimeComplexity("O(1)")
	// TCJ: Only returns an iterable
	// Returns the incoming edges
	public Iterable<Edge<E>> incomingEdges(Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> vert = validate(v);
		return vert.getIncoming().values(); // edges are the values in the adjacency map
	}

	@TimeComplexity("O(1)")
	// TCJ: While the method calls the getOutgoing method, the method itself is
	// constant time
	// Gets the edge between two vertices
	public Edge<E> getEdge(Vertex<V> u, Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> origin = validate(u);
		return origin.getOutgoing().get(v); // will be null if no edge from u to v
	}

	@TimeComplexity("O(1)")
	// TCJ: Just returns an array of vertices
	// Gets the vertices of an edge
	public Vertex<V>[] endVertices(Edge<E> e) throws IllegalArgumentException {
		InnerEdge<E> edge = validate(e);
		return edge.getEndPoints();
	}

	@TimeComplexity("O(n)")
	// TCJ: Depends of if v is incident to the edge
	// Returns the vertex that is opposite to V
	public Vertex<V> opposite(Vertex<V> v, Edge<E> e) throws IllegalArgumentException {
		InnerEdge<E> edge = validate(e);
		Vertex<V>[] endpoints = edge.getEndPoints();
		if (endpoints[0] == v)
			return endpoints[1];
		else if (endpoints[1] == v)
			return endpoints[0];
		else
			throw new IllegalArgumentException("v is not incident to this edge");
	}

	@TimeComplexity("O(1)")
	// TCJ: Uses other methods, but the method itself is constant
	// Inserts a new vertices
	public Vertex<V> insertVertex(V element) {
		InnerVertex<V> v = new InnerVertex<>(element, isDirected);

		for (Vertex<V> vertex : vertices) {

			if (v.getElement().equals(vertex.getElement())) {
				return vertex;
			}

		}

		v.setPosition(vertices.addLast(v));
		return v;
	}

	@TimeComplexity("O(n)")
	// TCJ: Depends of if the edge exists
	// Inserts an edge between two vertices
	public Edge<E> insertEdge(Vertex<V> u, Vertex<V> v, E element) throws IllegalArgumentException {
		 if (getEdge(u, v) == null) {
		InnerEdge<E> e = new InnerEdge<>(u, v, element);
		e.setPosition(edges.addLast(e));
		InnerVertex<V> origin = validate(u);
		InnerVertex<V> dest = validate(v);
		origin.getOutgoing().put(v, e);
		dest.getIncoming().put(u, e);
		return e;
		 } else
		 throw new IllegalArgumentException("Edge from u to v exists");
	}

	@TimeComplexity("O(n)")
	// TCJ: Must loop through out going edges
	// Removes a vertex from the graph
	public void removeVertex(Vertex<V> v) throws IllegalArgumentException {
		InnerVertex<V> vert = validate(v);
		for (Edge<E> e : vert.getOutgoing().values())
			removeEdge(e);
		for (Edge<E> e : vert.getIncoming().values())
			removeEdge(e);
		vertices.remove(vert.getPosition());
		// vert.setPosition(null);
	}

	@TimeComplexity("O(1)")
	// TCJ: While it does use the remove method, the method itself is constant time
	// Removes an edge in the graph
	@SuppressWarnings({ "unchecked" })
	public void removeEdge(Edge<E> e) throws IllegalArgumentException {
		InnerEdge<E> edge = validate(e);
		InnerVertex<V>[] verts = (InnerVertex<V>[]) edge.getEndPoints();
		verts[0].getOutgoing().remove(verts[1]);
		verts[1].getIncoming().remove(verts[0]);
		edges.remove(edge.getPosition());
		edge.setPosition(null);
	}

	@TimeComplexity("O(1)")
	// TCJ: Just checks instances
	@SuppressWarnings({ "unchecked" })
	private InnerVertex<V> validate(Vertex<V> v) {
		if (!(v instanceof InnerVertex))
			throw new IllegalArgumentException("Invalid vertex");
		InnerVertex<V> vert = (InnerVertex<V>) v; // safe cast
		if (!vert.validate(this))
			throw new IllegalArgumentException("Invalid vertex");
		return vert;
	}

	@TimeComplexity("O(1)")
	// TCJ: Just checks instances
	private InnerEdge<E> validate(Edge<E> e) {
		if (!(e instanceof InnerEdge))
			throw new IllegalArgumentException("Invalid edge");
		InnerEdge<E> edge = (InnerEdge<E>) e; // safe cast
		if (!edge.validate(this))
			throw new IllegalArgumentException("Invalid edge");
		return edge;
	}

}
