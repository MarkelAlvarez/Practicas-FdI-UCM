package extra.graphlayout;

import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.event.*;
import java.util.Random;

@SuppressWarnings("serial")
public class GraphLayoutExample extends JFrame  {
	
	private GraphComponent _graphComp;
    Random _rand;
    
	public GraphLayoutExample() {
		super("Dialog Example");
		initGUI();
	}

	private void initGUI() {
		_rand = new Random(System.currentTimeMillis());

		JPanel mainPanel = new JPanel(new BorderLayout() );
		
		_graphComp = new GraphComponent();
		mainPanel.add(_graphComp, BorderLayout.CENTER);

		JButton newGraph = new JButton("New Graph");
		newGraph.addActionListener( new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				generateGraph();
			}
		});
		
		mainPanel.add(newGraph,BorderLayout.PAGE_START);
		
		this.setContentPane(mainPanel);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);

	}

	protected void generateGraph() {

		Graph g = new Graph();
		int numNodes = _rand.nextInt(20)+5;
		int numEdges = _rand.nextInt(2*numNodes);		
		
		for (int i=0; i<numNodes; i++) {
			g.addNode(new Node("n"+i));
		}
		
		for (int i=0; i<numEdges; i++) {
			int s = _rand.nextInt(numNodes);
			int t = _rand.nextInt(numNodes);
			if ( s == t ) {
				t = (t + 1) % numNodes;
			}
			int l = _rand.nextInt(30)+20;
			Edge e = new Edge("e"+i, g.getNodes().get(s), g.getNodes().get(t), l);
			
			int numDots = _rand.nextInt(5);
			for(int j=0; j<numDots; j++) {
				l = Math.max(0, _rand.nextBoolean() ? l/2 : l);
				e.addDot( new Dot("d"+j, l));
			}
			
			g.addEdge(e);
		}
		
		_graphComp.setGraph(g);

	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new GraphLayoutExample();
			}
		});
	}
}