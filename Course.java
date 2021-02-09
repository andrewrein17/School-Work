package cs2321;

import net.datastructures.Edge;
import net.datastructures.Graph;
import net.datastructures.Vertex;

/**
 * @author Ruihong Zhang Reference: Text book: R14.17 on page 678
 *
 */
public class Course {

	AdjListGraph<String, String> graph = new AdjListGraph<>(true);
	HashMap<Vertex<String>, Boolean> known = new HashMap<>();
	ArrayList<String> list = new ArrayList<>();
	Travel T = new Travel(graph);
	int count = 0;
	boolean counted = false;

	/**
	 * @param courses: An array of course information. Each element in the array is
	 *        also array: starts with the course name, followed by a list (0 or
	 *        more) of prerequisite course names.
	 * 
	 */
	public Course(String courses[][]) {

		for (int i = 0; i < courses.length; i++) {

			Vertex<String> v = graph.insertVertex(courses[i][0]);

			for (int k = 1; k < courses[i].length; k++) {

				Vertex<String> v1 = graph.insertVertex(courses[i][k]);
				Edge<String> e = graph.insertEdge(v, v1, "1");

			}

		}

	}

	/**
	 * @param course
	 * @return find the earliest semester that the given course could be taken by a
	 *         students after taking all the prerequisites.
	 */
	public int whichSemester(String course) {

		Vertex<String> start = null;

		for (Vertex<String> v : graph.vertices) {
			if (v.getElement().equals(course)) {
				start = v;
			}
		}

		if (graph.outDegree(start) == 0)
			return 1;

		count++;

		for (Edge<String> e : graph.outgoingEdges(start)) {

			Vertex<String> v = graph.opposite(start, e);

			route(v, "LA15", "LA22", known);
		}

		return count;
	}

	public void route(Vertex<String> start, String end, String end2, HashMap<Vertex<String>, Boolean> known) {

		// Base case.
		if (start.getElement().equals(end) || start.getElement().equals(end2)) {
			if (!this.counted) { // Makes sure both of the base classes are counted only once
				count++;
				this.counted = true;
			}
			return;
		}

		for (Edge<String> e : graph.outgoingEdges(start)) {

			if (graph.opposite(start, e).getElement().equals(end)
					|| graph.opposite(start, e).getElement().equals(end2)) { //Checks if multiple classes can be taken
				if (counted) {
					count--;
				}
			}

		}

		count++;

		known.put(start, true);

		Vertex<String> current = null;

		for (Edge<String> e : graph.outgoingEdges(start)) {
			current = graph.opposite(start, e);

			if (known.get(current) == null) { // Checks if vertex has been visited.

				route(current, end, end2, known); // Recurses until path found.
				break;
			}

		}

		return;
	}

}
