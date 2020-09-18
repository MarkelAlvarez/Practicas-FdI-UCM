package extra.graphlayout;

import java.util.ArrayList;
import java.util.List;

public class Graph {
	private List<Edge> _edges;
	private List<Node> _nodes;
	
	public Graph() {
		_edges = new ArrayList<>();
		_nodes = new ArrayList<>();
	}
	
	public void addEdge(Edge e) {
		_edges.add(e);
	}
	
	public void addNode(Node n) {
		_nodes.add(n);
	}
	
	public List<Edge> getEdges() {
		return _edges;
	}
	
	public List<Node> getNodes() {
		return _nodes;
	}
}
