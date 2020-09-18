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
import javax.swing.table.TableColumn;
import javax.swing.SwingUtilities;

public class EjemploJTable2 extends JFrame implements ActionListener {
	private JTable tbl;
	private JTextField txt;
	private JButton btnModificar;
	private JButton btnLeer;

	public EjemploJTable2() {
		super("Ejemplo de selección de elementos de JTable");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(300, 300);
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

		tbl = new JTable(10, 10);

		// Ajuste de scrollbars y del tamaño de las columnas.
		JScrollPane scb = new JScrollPane(tbl);
		tbl.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		for (int i = 0; i < tbl.getColumnCount(); i++) {
			TableColumn col = tbl.getColumnModel().getColumn(i);
			col.setPreferredWidth(50);
		}
		// Muestra Selección VISUAL de filas o columnas.
		tbl.setRowSelectionAllowed(true);
		tbl.setColumnSelectionAllowed(true);
		
		this.getContentPane().add(scb, BorderLayout.CENTER);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		int fila = tbl.getSelectedRow();
		int col = tbl.getSelectedColumn();

		// Se puede comparar con == porque es *exactamente* el mismo objeto en
		// memoria.
		if (e.getSource() == btnModificar) {
			if (fila >= 0 && col >= 0) {
				// Cambio de una sola celda.
				tbl.setValueAt(txt.getText(), fila, col);

			}
		} else if (e.getSource() == btnLeer) {
			if (fila >= 0 && col >= 0) {
				Object s = tbl.getValueAt(fila, col);
				txt.setText((String) s);
			}
			System.out.println(this);
		}

	}

	public String toString() {
		System.out.println("comienzo to string");
		StringBuffer s = new StringBuffer();
		for (int f = 0; f < tbl.getRowCount(); f++) {
			for (int c = 0; c < tbl.getColumnCount(); c++) {
				s.append(" \t" + tbl.getValueAt(f, c));
			}
			s.append(System.getProperty("line.separator"));
		}

		return s.toString();
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploJTable2 v = new EjemploJTable2();
				v.setVisible(true);

			}
		});

	}
}
