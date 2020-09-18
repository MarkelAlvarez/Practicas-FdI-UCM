package ejemploJTablePR5;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.ListSelectionModel;
import javax.swing.SwingUtilities;
import javax.swing.border.TitledBorder;
import javax.swing.border.Border;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class EjJTablePR5 extends JFrame implements ActionListener {
	private static final long serialVersionUID = 1L;
	private Border _defaultBorder = BorderFactory
			.createLineBorder(Color.red, 4);
	private EventsTableModel _modelo;
	private JTable _eventsTable;
	private JButton btnMostrar;
	private List<EventsPrueba> _events;

	public EjJTablePR5() {

		super("Ejemplo de Jtable con los datos en un ArrayList");
		this.getContentPane().setLayout(new FlowLayout());
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(700, 300);

		btnMostrar = new JButton("Mostrar eventos");
		btnMostrar.addActionListener(this);

		JPanel eventsPanel = new JPanel(new BorderLayout());
		eventsPanel.setBorder(BorderFactory.createTitledBorder(_defaultBorder,
				"Listado de Eventos", TitledBorder.LEFT, TitledBorder.TOP));

		_modelo = new EventsTableModel();
		_eventsTable = new JTable(_modelo);

		eventsPanel.add(new JScrollPane(_eventsTable,
				JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED));

		this.getContentPane().add(btnMostrar);
		this.getContentPane().add(eventsPanel);
		_events = new ArrayList();
		inicializaEvents();
		pack();
		setVisible(true);

	}

	public void actionPerformed(ActionEvent e) {
			_modelo.setEventsList(_events);
	}

	public void inicializaEvents() {
		// en nuestra práctica PR5 los eventos se reciben por las notificaciones
		EventsPrueba e1 = new EventsPrueba(0, 3);
		EventsPrueba e2 = new EventsPrueba(1, 5);
		EventsPrueba e3 = new EventsPrueba(1, 2);
		_events.add(e1);
		_events.add(e2);
		_events.add(e3);

	};

	public static void main(String[] args) {

		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new EjJTablePR5();
			}
		});
	}

}
