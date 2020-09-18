import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class EjemploJTable3 extends JFrame implements ActionListener {
	private JTable tbl;
	private JTextField txt;
	private JButton btnModificar;
	private JButton btnLeer;

	private Object[][] data = {
			{ "Kathy", "Smith", "Snowboarding", new Integer(5),
					new Boolean(false) },
			{ "John", "Doe", "Rowing", new Integer(3), new Boolean(true) },
			{ "Sue", "Black", "Knitting", new Integer(2), new Boolean(false) },
			{ "Jane", "White", "Speed reading", new Integer(20),
					new Boolean(true) },
			{ "Joe", "Brown", "Pool", new Integer(10), new Boolean(false) } };
	private String[] columnNames = { "First Name", "Last Name", "Sport",
			"# of Years", "Vegetarian" };

	public EjemploJTable3() {
		super("Ejemplo de JTable con datos de un array");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setLayout(new BorderLayout());

		JPanel pnlControl = new JPanel();
		pnlControl.setLayout(new GridLayout(1, 3, 5, 5));
		txt = new JTextField("");
		btnModificar = new JButton("Modificar");
		btnModificar.addActionListener(this);
		btnLeer = new JButton("Leer");
		btnLeer.addActionListener(this);
		pnlControl.add(txt);
		pnlControl.add(btnModificar);
		pnlControl.add(btnLeer);
		this.getContentPane().add(pnlControl, BorderLayout.NORTH);

		tbl = new JTable(data, columnNames);

		JScrollPane scb = new JScrollPane(tbl);
		
		
		this.getContentPane().add(scb, BorderLayout.CENTER);
		this.pack();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		int fila = tbl.getSelectedRow();
		int col = tbl.getSelectedColumn();

		// Se puede comparar con == porque es *exactamente* el mismo objeto en
		// memoria.
		if (e.getSource() == btnModificar) {
			if (fila >= 0 && col >= 0) {
				tbl.setValueAt(txt.getText(), fila, col);
			}
		} else if (e.getSource() == btnLeer) {
			if (fila >= 0 && col >= 0) {
				Object s = tbl.getValueAt(fila, col);
				txt.setText((String) s);
			}
		}
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploJTable3 v = new EjemploJTable3();
				v.setVisible(true);
			}
		});
	}
}
