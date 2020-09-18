import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class EjemploListaScroll extends JFrame implements ActionListener {
	public static final String COMMAND_ANNADIR = "Aniadir";
	public static final String COMMAND_ELIMINAR = "Eliminar";
	public static final String COMMAND_LIMPIAR = "Limpiar lista";
	public static final String COMMAND_SALIR = "Salir";
	
	JTextField txtTexto;
	JList<String> lstLista;
	DefaultListModel<String> modelo;

	public EjemploListaScroll() {
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		txtTexto = new JTextField("");
		modelo = new DefaultListModel<String>();
		lstLista = new JList<String>(modelo);
		
		JScrollPane sclLista = new JScrollPane(lstLista);
		//sclLista.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		//sclLista.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		//sclLista.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		//sclLista.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);

		JButton btnAnadir = new JButton(COMMAND_ANNADIR);
		btnAnadir.setActionCommand(COMMAND_ANNADIR);
		btnAnadir.addActionListener(this); 
		JButton btnEliminar = new JButton(COMMAND_ELIMINAR);
		btnEliminar.setActionCommand(COMMAND_ELIMINAR);
		btnEliminar.addActionListener(this); 
		JButton btnLimpiar = new JButton(COMMAND_LIMPIAR);
		btnLimpiar.setActionCommand(COMMAND_LIMPIAR);
		btnLimpiar.addActionListener(this); 
		JButton btnSalir = new JButton(COMMAND_SALIR);
		btnSalir.setActionCommand(COMMAND_SALIR);
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
		pnlCentro.add(sclLista, BorderLayout.CENTER);
		
		JPanel pnlBotones = new JPanel();
		pnlBotones.setLayout(new GridLayout(1, 2, 5, 5));
		pnlBotones.add(btnEliminar);
		pnlBotones.add(btnLimpiar);
		pnlCentro.add(pnlBotones, BorderLayout.SOUTH);

		this.getRootPane().setDefaultButton(btnAnadir);
		// Display the window.
		this.setSize(300, 200);
		this.setVisible(true);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		switch (e.getActionCommand()) {
		case COMMAND_ANNADIR:
			if (!txtTexto.getText().trim().equals(""))
				aniadirItem(txtTexto.getText());
			txtTexto.setText("");
			txtTexto.requestFocus();
			break;
		case COMMAND_ELIMINAR:
			eliminarItems();
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

	private void aniadirItem(String s) {
		if (modelo.contains(s)) {
			JOptionPane.showMessageDialog(this, "Ya está en el modelo.");
		} else
			modelo.addElement(s);
	}

	private void eliminarItems() {
		List<String> seleccion = lstLista.getSelectedValuesList();
		for (String elem : seleccion)
			modelo.removeElement(elem);
	}

	public static void main(String[] args) {		
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploListaScroll ej = new EjemploListaScroll();
				ej.setVisible(true);
			}
		});
	}

}
