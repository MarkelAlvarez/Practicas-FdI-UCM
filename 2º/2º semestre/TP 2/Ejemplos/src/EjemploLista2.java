import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class EjemploLista2 extends JFrame implements ActionListener {
	public static final String COMMAND_ANNADIR = "Aniadir";
	public static final String COMMAND_ELIMINAR = "Eliminar";
	public static final String COMMAND_LIMPIAR = "Limpiar lista";
	public static final String COMMAND_SALIR = "Salir";
	
	JTextField txtTexto;
	JList<String> lstLista;
	DefaultListModel<String> modelo;

	public EjemploLista2() {

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		txtTexto = new JTextField("");
		modelo = new DefaultListModel<String>();
		lstLista = new JList<String>(modelo);
		

		JButton btnAnadir = new JButton(COMMAND_ANNADIR);
		btnAnadir.addActionListener(this); // en ventanas sencillas
		JButton btnEliminar = new JButton(COMMAND_ELIMINAR);
		btnEliminar.addActionListener(this); // en ventanas sencillas
		JButton btnLimpiar = new JButton(COMMAND_LIMPIAR);
		btnLimpiar.addActionListener(this); // en ventanas sencillas
		JButton btnSalir = new JButton(COMMAND_SALIR);
		btnSalir.addActionListener(this);

		JPanel pnl = new JPanel();
		this.getContentPane().add(pnl);
		pnl.setLayout(new BorderLayout());

		pnl.add(new JLabel("Lista de la compra"), BorderLayout.NORTH);
		pnl.add(btnSalir, BorderLayout.SOUTH);

		JPanel pnlCentro = new JPanel();
		pnl.add(pnlCentro, BorderLayout.CENTER);
		pnlCentro.setLayout(new BorderLayout());
		
		JPanel pnlTexto = new JPanel();
		pnlTexto.setLayout(new GridLayout(1, 2, 5, 5));
		pnlTexto.add(txtTexto);
		pnlTexto.add(btnAnadir);
		pnlCentro.add(pnlTexto, BorderLayout.NORTH);
		pnlCentro.add(lstLista, BorderLayout.CENTER);
		
		JPanel pnlBotones = new JPanel();
		pnlBotones.setLayout(new GridLayout(1, 2, 5, 5));
		pnlBotones.add(btnEliminar);
		pnlBotones.add(btnLimpiar);
		pnlCentro.add(pnlBotones, BorderLayout.SOUTH);
		
		this.getRootPane().setDefaultButton(btnAnadir);
		this.setSize(400, 300);
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		//System.out.println("e.getActionCommand(): " + e.getActionCommand());
		switch (e.getActionCommand()) {
		case COMMAND_ANNADIR:
			modelo.addElement(txtTexto.getText());
			txtTexto.setText("");
			txtTexto.requestFocus();
			break;
		case COMMAND_ELIMINAR:
			modelo.removeElement(lstLista.getSelectedValue());
			txtTexto.setText("");
			break;
		case COMMAND_LIMPIAR:
			modelo.removeAllElements();
			txtTexto.setText("");
			break;
		case COMMAND_SALIR:
			this.dispose();
			break;
		}
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploLista2 ej = new EjemploLista2();
				ej.setVisible(true);
			}
		});
	}

}
