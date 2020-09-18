import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Ejemplo8 extends JFrame {
	
	public Ejemplo8() {
		super("Mi ventana");
		this.setSize(600,200);
		JPanel mainPanel = new JPanel();
		mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
		this.getContentPane().add(mainPanel);
		JButton boton1 = new JButton("hola");
		JButton boton2 = new JButton("holaaa");
		JButton boton3 = new JButton("holaaaaa");
		mainPanel.add(boton1);
		mainPanel.add(boton2);
		mainPanel.add(boton3);
		Reloj reloj = new Reloj(2);
		mainPanel.add(reloj);
		this.pack();
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final Ejemplo8 v = new Ejemplo8();
				v.setVisible(true);
			}
		});
	}

}