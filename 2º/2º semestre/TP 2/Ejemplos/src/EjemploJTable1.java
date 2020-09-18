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

public class EjemploJTable1 extends JFrame implements ActionListener {
	private JTable tbl;
	private JTextField txt;
	private JButton btnModificar;
	private JButton btnLeer;

	public EjemploJTable1() {
		
		super("Ejemplo sencillo de JTable vacio");
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

		tbl = new JTable(30, 10);

		// Ajuste de scrollbars y del tamaño de las columnas.
		JScrollPane scb = new JScrollPane(tbl);
		//System.out.println(tbl.getColumnCount());
		
		//con esto permitimos la barra horizontal
		tbl.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		
		// Para modificar el tamanyo de las columnas
		for (int i = 0; i < tbl.getColumnCount(); i++) {
			TableColumn col = tbl.getColumnModel().getColumn(i);
			col.setPreferredWidth(50);
		}
        tbl.setCellSelectionEnabled(true);
		this.getContentPane().add(scb, BorderLayout.CENTER);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.out.println("fila seleccionada: " + tbl.getSelectedRow());
		System.out.println("columna seleccionada: " + tbl.getSelectedColumn());
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
				final EjemploJTable1 v = new EjemploJTable1();
				v.setVisible(true);
			}
		});
	}
}
