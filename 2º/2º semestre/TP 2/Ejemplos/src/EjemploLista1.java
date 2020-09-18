import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.SwingUtilities;

public class EjemploLista1 extends JFrame {
	JLabel lblTexto;
	JList<String> lstLista;

	// Ejemplo de lista basada en array de elementos.
	// Crea un modelo no modificable de los elementos del array.
	public EjemploLista1() {
		super("Mi toolbox");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		// String[] valores = { "tornillos", "arandelas", "tuercas", "copetes",
		// "martillos" };
		String[] valores = { "tornillos", "arandelas", "tuercas", "copetes",
				"martillos", "dfgfgdf", "gddfghfd", "fsrtsrtfgsr" };
		lblTexto = new JLabel("");
		lstLista = new JList<String>(valores);
		JScrollPane scb = new JScrollPane(lstLista);
		lstLista.setVisibleRowCount(4);

		lstLista.addListSelectionListener(new ListSelectionListener() {
			@Override
			public void valueChanged(ListSelectionEvent e) {
				lblTexto.setText(lstLista.getSelectedValue());

			}
		});
		JButton btnSalir = new JButton("Salir");
		btnSalir.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				EjemploLista1.this.dispose();
			}
		});

		JPanel pnl = new JPanel();
		pnl.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		pnl.setLayout(new GridLayout(3, 2, 5, 5));
		pnl.add(new JLabel("Lista:"));

		pnl.add(scb);

		pnl.add(new JLabel("Elemento seleccionado:"));
		pnl.add(lblTexto);

		pnl.add(new JLabel(""));
		pnl.add(btnSalir);
		this.getContentPane().add(pnl);

		this.setSize(400, 300);
		this.pack();

	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {

				final EjemploLista1 ej = new EjemploLista1();
				ej.setVisible(true);
			}
		});
	}

}
