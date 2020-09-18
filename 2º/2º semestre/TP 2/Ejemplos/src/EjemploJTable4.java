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
import javax.swing.table.AbstractTableModel;
import javax.swing.table.TableColumn;
import javax.swing.SwingUtilities;

public class EjemploJTable4 extends JFrame implements ActionListener {
	private JTable tbl;
	private JTextField txt;
	private JButton btnModificar;
	private JButton btnAniadirFila;
	private MiModeloDeTabla modelo;

	public EjemploJTable4() {
		super("Ejemplo de JTable con un modelo de tabla");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(200, 200);
		this.getContentPane().setLayout(new BorderLayout());

		JPanel pnlControl = new JPanel();
		pnlControl.setLayout(new GridLayout(1, 3, 5, 5));
		txt = new JTextField("");
		btnModificar = new JButton("Modificar");
		btnModificar.addActionListener(this);
		btnAniadirFila = new JButton("Aniadir fila");
		btnAniadirFila.addActionListener(this);
		pnlControl.add(txt);
		pnlControl.add(btnModificar);
		pnlControl.add(btnAniadirFila);
		this.getContentPane().add(pnlControl, BorderLayout.NORTH);

		modelo = new MiModeloDeTabla(3, 3);
		tbl = new JTable(modelo);

		JScrollPane scb = new JScrollPane(tbl);
		 tbl.setCellSelectionEnabled(true);
		tbl.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
		for (int i = 0; i < tbl.getColumnCount(); i++) {
			TableColumn col = tbl.getColumnModel().getColumn(i);
			col.setPreferredWidth(70);
		}
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
				modelo.setValueAt(txt.getText(), fila, col);
			}
		} else if (e.getSource() == btnAniadirFila) {
			modelo.aniadirFilaVacia();
		}
	}

	private class MiModeloDeTabla extends AbstractTableModel {
		private int filas = 0;
		private int cols = 0;
		private Object[][] data;
		private final String[] columnNames = { "columna1", "columna2",
				"columna3" };

		public MiModeloDeTabla(int f, int c) {
			filas = f;
			cols = c;
			data = new Object[filas][cols];
		}

		@Override
		public String getColumnName(int col) {
			return columnNames[col].toString();
		}

		@Override
		public int getRowCount() {
			return data.length;
		}

		@Override
		public int getColumnCount() {
			return columnNames.length;
		}

		@Override
		public Object getValueAt(int row, int col) {
			return data[row][col];
		}

		@Override
		public boolean isCellEditable(int row, int col) {
			return true;
		}

		@Override
		public void setValueAt(Object value, int row, int col) {
			data[row][col] = value;
			fireTableCellUpdated(row, col);
		}

		public void aniadirFilaVacia() {
			filas++;
			Object[][] nuevoData = new Object[filas][cols];
			for (int i = 0; i < filas - 1; i++) {
				for (int j = 0; j < cols; j++) {
					nuevoData[i][j] = data[i][j];
				}
			}
			data = nuevoData;
			for (int j = 0; j < cols; j++)
				data[filas - 1][j] = new Integer(33);
			fireTableRowsInserted(filas - 1, filas - 1);
		}
	}

	public static void main(String[] args) {
		final EjemploJTable4 v = new EjemploJTable4();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}

}
