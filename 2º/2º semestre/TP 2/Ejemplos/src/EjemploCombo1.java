import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public class EjemploCombo1 extends JFrame {
	JLabel lblTexto;
	JComboBox<String> lstLista;

	public EjemploCombo1() {
		super("Mi primer JComboBox");
		this.setSize(500, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		String[] valores = { "tornillos", "arandelas", "tuercas", "copetes",
				"martillos" };
		lstLista = new JComboBox<String>(valores);
		lstLista.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				System.out.println("has seleccionado: " + (String) lstLista.getSelectedItem());
				lblTexto.setText((String) lstLista.getSelectedItem());
			}
		});
		
		JButton btnSalir = new JButton("Salir");
		btnSalir.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				EjemploCombo1.this.dispose();
			}
		});

		JPanel pnl = new JPanel();	
		pnl.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
		pnl.setLayout(new GridLayout(3, 2, 5, 5));
		pnl.add(new JLabel("Lista:"));
		pnl.add(lstLista);
		pnl.add(new JLabel("Elemento seleccionado:"));
		lblTexto = new JLabel("");
		pnl.add(lblTexto);
		pnl.add(new JLabel(""));
		pnl.add(btnSalir);
		this.getContentPane().add(pnl);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploCombo1 ej = new EjemploCombo1();
				ej.setVisible(true);
			}
		});
	}
}
