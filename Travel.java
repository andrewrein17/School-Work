package cs2321;

import net.datastructures.*;
import net.datastructures.Vertex;

/**
 * @author Ruihong Zhang Reference textbook R14.16 P14.81
 *
 */
public class Travel {

	AdjListGraph<String, String> graph = new AdjListGraph<>(false);
	HashMap<Vertex<String>, Boolean> known = new HashMap<>();
	HashMap<Vertex<String>, Edge<String>> forest = new HashMap<>();
	QuickSort<String> sorter;
	ArrayList<String> visited = new ArrayList<>();
	CircularArrayQueue<Vertex<String>> queue = new CircularArrayQueue<>(16);

	/**
	 * @param routes: Array of routes between cities. routes[i][0] and routes[i][1]
	 *        represent the city names on both ends of the route. routes[i][2]
	 *        represents the cost in string type. Hint: In Java, use Integer.valueOf
	 *        to convert string to integer.
	 */
	public Travel(String[][] routes) {

		for (int i = 0; i < routes.length; i++) {

			Vertex<String> v = graph.insertVertex(routes[i][0]);
			Vertex<String> v2 = graph.insertVertex(routes[i][1]);
			Edge<String> e = graph.insertEdge(v, v2, routes[i][2]);

		}

	}
	
	public Travel(AdjListGraph<String, String> newGraph) {
		graph = newGraph;
	}

	/**
	 * @param departure: the departure city name
	 * @param destination: the destination city name
	 * @return Return the path from departure city to destination using Depth First
	 *         Search algorithm. The path should be represented as ArrayList or
	 *         DoublylinkedList of city names. The order of city names in the list
	 *         should match order of the city names in the path.
	 * 
	 * @IMPORTANT_NOTE: The outgoing edges should be traversed by the order of the
	 *                  city names stored in the opposite vertices. For example, if
	 *                  V has 3 outgoing edges as in the picture below, V / | \ / |
	 *                  \ B A F your algorithm below should visit the outgoing edges
	 *                  of V in the order of A,B,F. This means you will need to
	 *                  create a helper function to sort the outgoing edges by the
	 *                  opposite city names.
	 * 
	 *                  See the method sortedOutgoingEdges below.
	 */
	public Iterable<String> DFSRoute(String departure, String destination) {

		Vertex<String> start = null;
		Vertex<String> end = null;

		for (Vertex<String> v : graph.vertices) {

			if (v.getElement().equals(departure)) { // Gets the start vertex.
				start = v;
			} else if (v.getElement().equals(destination)) { // Gets the end vertex.
				end = v;
			}

		}

		visited.addLast(start.getElement()); // Adds first element.

		return DFSRoute(start, end, known); // Uses helper method to find route.
	}

	public Iterable<String> DFSRoute(Vertex<String> start, Vertex<String> end, HashMap<Vertex<String>, Boolean> known) {

		// Base case.
		if (start.getElement().equals(end.getElement())) {
			return visited;
		}

		known.put(start, true);

		Vertex<String> current = null;

		for (Edge<String> e : sortedOutgoingEdges(start)) {

			current = graph.opposite(start, e);
			if (known.get(current) == null) { // Checks if vertex has been visited.

				visited.addLast(current.getElement());
				DFSRoute(current, end, known); // Recurses until path found. 
				break;

			}

		}

		return visited;
	}

	/**
	 * @param departure: the departure city name
	 * @param destination: the destination city name
	 * @return Return the path from departure city to destination using Breadth
	 *         First Search algorithm. The path should be represented as ArrayList
	 *         or DoublylinkedList of city names. The order of city names in the
	 *         list should match order of the city names in the path.
	 * 
	 * @IMPORTANT_NOTE: The outgoing edges should be traversed by the order of the
	 *                  city names stored in the opposite vertices. For example, if
	 *                  V has 3 outgoing edges as in the picture below, V / | \ / |
	 *                  \ B A F your algorithm below should visit the outgoing edges
	 *                  of V in the order of A,B,F. This means you will need to
	 *                  create a helper function to sort the outgoing edges by the
	 *                  opposite city names.
	 * 
	 *                  See the method sortedOutgoingEdges below.
	 */

	public Iterable<String> BFSRoute(String departure, String destination) {

		Vertex<String> start = null;
		Vertex<String> end = null;

		for (Vertex<String> v : graph.vertices) {

			if (v.getElement().equals(departure)) { // Sets the start vertex.
				start = v;
			} else if (v.getElement().equals(destination)) { // Sets the end vertex.
				end = v;
			}

		}

		return BFSRoute(start, end, known, forest); // Uses helper method to find route.

	}

	public Iterable<String> BFSRoute(Vertex<String> start, Vertex<String> end, HashMap<Vertex<String>, Boolean> known,
			HashMap<Vertex<String>, Edge<String>> forest) {

		if (start.getElement().equals(end.getElement())) { // Checks if start == end
			return visited;
		}

		queue.enqueue(start);
		known.put(start, true);

		Vertex<String> current = null;
		Vertex<String> p = null;
		while (!queue.isEmpty()) {

			current = queue.dequeue();
			for (Edge<String> e : sortedOutgoingEdges(current)) {

				p = graph.opposite(current, e);

				if (known.get(p) == null) { // Checks that if vertex has been visited

					known.put(p, true);

					queue.enqueue(p);
					forest.put(p, e);

					if (p.getElement().equals(end.getElement())) { // Once the end is found, use the forest to get the
																	// path taken.

						while (!p.getElement().equals(start.getElement())) {

							visited.addFirst(p.getElement());
							p = graph.opposite(p, forest.get(p)); // Traverses the forest.

						}

						visited.addFirst(p.getElement());
						return visited;

					}
				}

			}

		}

		return visited;
	}

	/**
	 * @param departure: the departure city name
	 * @param destination: the destination city name
	 * @param itinerary: an empty DoublylinkedList object will be passed in to the
	 *        method. When a shorted path is found, the city names in the path
	 *        should be added to the list in the order.
	 * @return return the cost of the shortest path from departure to destination.
	 * 
	 * @IMPORTANT_NOTE: The outgoing edges should be traversed by the order of the
	 *                  city names stored in the opposite vertices. For example, if
	 *                  V has 3 outgoing edges as in the picture below, V / | \ / |
	 *                  \ B A F your algorithm below should visit the outgoing edges
	 *                  of V in the order of A,B,F. This means you will need to
	 *                  create a helper function to sort the outgoing edges by the
	 *                  opposite city names.
	 * 
	 *                  See the method sortedOutgoingEdges below.
	 */

	public int DijkstraRoute(String departure, String destination, DoublyLinkedList<String> itinerary) {

		// TODO: find the path based Breadth First Search, update itinerary and return
		// the cost

		return 0;

	}

	/**
	 * I strongly recommend you to implement this method to return sorted outgoing
	 * edges for vertex V You may use any sorting algorithms, such as insert sort,
	 * selection sort, etc.
	 * 
	 * @param v: vertex v
	 * @return a list of edges ordered by edge's name
	 */

	public Iterable<Edge<String>> sortedOutgoingEdges(Vertex<String> v) {

		ArrayList<Edge<String>> eList = new ArrayList<>();
		ArrayList<Vertex<String>> vList = new ArrayList<>();

		for (Edge<String> e : graph.outgoingEdges(v)) {
			vList.addLast(graph.opposite(v, e));
		}

//		for (Vertex<String> vertex : vList) {
//			 System.out.print(vertex.getElement());
//		 }
//		
//		System.out.println();

		int n = vList.size();
		Vertex<String> temp;

		for (int i = 0; i < n; i++) {
			for (int j = 1; j < (n - i); j++) {
				if (vList.get(j - 1).getElement().compareTo(vList.get(j).getElement()) > 0) {
					temp = vList.get(j - 1);
					vList.set(j - 1, vList.get(j));
					vList.set(j, temp);
				}

			}
		}

//		for (Vertex<String> vertex : vList) {
//			 System.out.print(vertex.getElement());
//		 }
//		System.out.println();

		for (Vertex<String> vertex : vList) {
			eList.addLast(graph.getEdge(vertex, v));
		}

		return eList;
	}

}
