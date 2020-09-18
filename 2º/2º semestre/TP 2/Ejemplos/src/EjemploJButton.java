import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.event.*;

public class EjemploJButton extends JFrame {

	public EjemploJButton() {
		super("Ejemplo JButton");
		this.setSize(320, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton boton = new JButton("Pulsa para saludar");
		boton.addActionListener(new MiActionListener());
		boton.addChangeListener(new miChangeListener());
		this.getContentPane().add(boton);
	}

	public class MiActionListener implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			((JButton) event.getSource()).setText("pulsado");
		}
	}

	public class miChangeListener implements ChangeListener {
		public void stateChanged(ChangeEvent e) {
			System.out.println("Estais haciendo cambios en el estado!");
		}
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploJButton v = new EjemploJButton();
				v.setVisible(true);
			}
		});
	}
}
