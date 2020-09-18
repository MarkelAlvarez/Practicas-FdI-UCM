import javax.swing.*;
import java.awt.event.*;

public class Ejemplo3a extends JFrame {

	public Ejemplo3a() {
		super("Mi primera ventana - Ejemplo3");
		this.setSize(320, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton boton = new JButton("Pulsa para saludar");
		boton.addActionListener(new MiActionListener());
		this.getContentPane().add(boton);
	}

	public class MiActionListener implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			System.out.println("Hola Mundo!");
		}
	}

	public static void main(String[] args) {
		// ...	
		SwingUtilities.invokeLater(new Runnable() {		
			public void run() {
				final Ejemplo3a v = new Ejemplo3a();
				v.setVisible(true);
			}
		});
	}
}
