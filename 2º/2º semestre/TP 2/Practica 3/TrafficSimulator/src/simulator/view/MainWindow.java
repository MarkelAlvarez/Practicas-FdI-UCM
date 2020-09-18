package simulator.view;

import java.awt.*;
import javax.swing.*;
import javax.swing.border.TitledBorder;

import simulator.control.Controller;

public class MainWindow extends JFrame {

	private Controller _ctrl ;
	
	public MainWindow(Controller ctrl ) {
		
		super("Traffic Simulator");
		_ctrl = ctrl ;
		initGUI();
	}
	
	private void initGUI() {
		
		JPanel mainPanel = new JPanel(new BorderLayout());
		this.setContentPane(mainPanel);

		mainPanel.add(new ControlPanel(_ctrl), BorderLayout.PAGE_START);
		mainPanel.add(new StatusBar(_ctrl), BorderLayout.PAGE_END);
		
		JPanel viewsPanel = new JPanel(new GridLayout(1, 2));
		mainPanel.add(viewsPanel, BorderLayout.CENTER);
		
		JPanel tablesPanel = new JPanel();
		tablesPanel.setLayout(new BoxLayout(tablesPanel, BoxLayout.Y_AXIS));
		viewsPanel.add(tablesPanel);
		
		JPanel mapsPanel = new JPanel();
		mapsPanel.setLayout(new BoxLayout(mapsPanel, BoxLayout.Y_AXIS));
		viewsPanel.add(mapsPanel);
		
		// tables
		JPanel eventsView = createViewPanel( new JTable(new EventsTableModel(_ctrl)), "Events");
		eventsView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(eventsView);
		
		JPanel vehiclesView = createViewPanel( new JTable(new VehiclesTableModel(_ctrl)), "Vehicles");
		vehiclesView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(vehiclesView);
		
		JPanel roadsView = createViewPanel( new JTable(new RoadsTableModel(_ctrl)), "Roads");
		roadsView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(roadsView);
		
		JPanel junctionView = createViewPanel( new JTable(new JunctionsTableModel(_ctrl)), "Junctions");
		junctionView.setPreferredSize(new Dimension(500, 200));
		tablesPanel.add(junctionView);
		
		// maps
		JPanel mapView = createViewPanel(new MapComponent(_ctrl), "Map");
		mapView.setPreferredSize(new Dimension(500, 400));
		mapsPanel.add(mapView);
		
		JPanel roadView = createViewPanel(new MapByRoadComponent(_ctrl), "Map by Road");
		roadView.setPreferredSize(new Dimension(500, 400));
		mapsPanel.add(roadView);
		
		this.setIconImage(Toolkit.getDefaultToolkit().getImage("./resources/icons/weather.png"));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
		this.setResizable(true);
		this.pack();
		this.setVisible(true);
	}
	
	private JPanel createViewPanel(JComponent c, String title) {
		
		JPanel p = new JPanel(new BorderLayout());
		if (title.equalsIgnoreCase("Events"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Events", TitledBorder.LEFT, TitledBorder.TOP));
		}
		else if (title.equalsIgnoreCase("Vehicles"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Vehicles", TitledBorder.LEFT, TitledBorder.TOP));
		}
		else if (title.equalsIgnoreCase("Roads"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Roads", TitledBorder.LEFT, TitledBorder.TOP));
		}
		else if (title.equalsIgnoreCase("Junctions"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Junctions", TitledBorder.LEFT, TitledBorder.TOP));
		}
		else if (title.equalsIgnoreCase("Map"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Map", TitledBorder.LEFT, TitledBorder.TOP));
		}
		else if (title.equalsIgnoreCase("Map by Road"))
		{
			p.setBorder(BorderFactory.createTitledBorder(BorderFactory.createLineBorder(Color.black, 2), "Map by Road", TitledBorder.LEFT, TitledBorder.TOP));
		}
		p.add(new JScrollPane(c));
		
		return p;
	}
}