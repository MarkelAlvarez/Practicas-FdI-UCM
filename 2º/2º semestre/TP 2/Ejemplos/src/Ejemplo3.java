
import javax.swing.*;
import java.awt.event.*;

public class Ejemplo3 extends JFrame {

	public Ejemplo3() {
		super("Mi primera ventana - Ejemplo3");
		this.setSize(320, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JButton boton = new JButton("Pulsa para saludar");
		boton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				System.out.println("Hola Mundo!");
			}
		});
		this.getContentPane().add(boton);
	}
	
	public static void main(String[] args) {
		// ...
		final Ejemplo3 v = new Ejemplo3();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}

