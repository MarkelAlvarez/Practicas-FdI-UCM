import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Ejemplo7 extends JFrame {
	private JLabel lsouth;

	public Ejemplo7() {
		super("Mi primera ventana - Ejemplo 7");
		this.setSize(450, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.getContentPane().setLayout(new BorderLayout());
		JLabel lnorth = new JLabel("Ejemplo de agrupamiento de componentes.");
		this.getContentPane().add(lnorth, BorderLayout.NORTH);

		lsouth = new JLabel("Lo que has tecleado es: ");
		lsouth.setBackground(Color.yellow);
		lsouth.setOpaque(true);
		this.getContentPane().add(lsouth, BorderLayout.SOUTH);

		JPanel pnlCentro = new JPanel();
		pnlCentro.setLayout(new GridLayout(4, 3, 4, 4));
		for (int i = 1; i < 10; i++) {
			JButton btnI = creaBotonI(i);
			pnlCentro.add(btnI);
		}
		pnlCentro.add(new JLabel(""));
		pnlCentro.add(creaBotonI(0));
		pnlCentro.add(new JLabel(""));
		this.getContentPane().add(pnlCentro, BorderLayout.CENTER);
	}

	private JButton creaBotonI(int i) {
		final String strI = Integer.toString(i);
		JButton btnI = new JButton(strI);
		btnI.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				lsouth.setText(lsouth.getText() + strI);
			}
		});
		return btnI;
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final Ejemplo7 v = new Ejemplo7();
				v.setVisible(true);
			}
		});
	}
}
