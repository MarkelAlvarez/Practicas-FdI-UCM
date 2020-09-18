import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import javax.swing.SwingUtilities;

public class EjemploJOptionPane0 extends JFrame {
	
	public EjemploJOptionPane0() {
		super("Ejemplo de cuadro de dialogo muy sencillo");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		this.setSize(300, 120);
		this.getContentPane().setLayout(new FlowLayout());

		JButton btnConfirmDialog = new JButton("Mostrar Message Dialog");
		btnConfirmDialog.setIcon(new ImageIcon(this.getClass().getResource("OK-icon.png")));

		btnConfirmDialog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				JOptionPane.showMessageDialog(
						EjemploJOptionPane0.this, 
						"Esto es un Message Dialog");
			}
		});
		this.getContentPane().add(btnConfirmDialog);
	}	
	
	public static void main(String[] args) {
		final EjemploJOptionPane0 v = new EjemploJOptionPane0();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}});
	}
}
