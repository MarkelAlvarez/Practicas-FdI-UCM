
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Dimension;

@SuppressWarnings("serial")
public class EjemploJTable0 extends JFrame {

	EjemploJTable0() {
		super(" Ejemplo JTable");
		initGUI();
	}

	private void initGUI() {

		String[] columnNames = { "First Name", "Last Name", "Sport",
				"# of Years", "Vegetarian" };

		Object[][] data = {
				{ "Kathy", "Smith", "Snowboarding", new Integer(5),
						new Boolean(false) },
				{ "John", "Doe", "Rowing", new Integer(3), new Boolean(true) },
				{ "Sue", "Black", "Knitting", new Integer(2),
						new Boolean(false) },
				{ "Jane", "White", "Speed reading", new Integer(20),
						new Boolean(true) },
				{ "Joe", "Brown", "Pool", new Integer(10), new Boolean(false) } };

		JPanel mainPanel = new JPanel(new BorderLayout(5, 5));

		JTable table = new JTable(data, columnNames);
		
		JScrollPane area = new JScrollPane(table,
				JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

		// We then set the preferred size of the scrollpane.
		area.setPreferredSize(new Dimension(200, 100));

		mainPanel.add(area);
		this.setContentPane(mainPanel);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setSize(300,100);
		this.setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new EjemploJTable0();
			}
		});
	}
}