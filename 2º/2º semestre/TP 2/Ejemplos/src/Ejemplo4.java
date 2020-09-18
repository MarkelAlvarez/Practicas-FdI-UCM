import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Ejemplo4 extends JFrame {

	public Ejemplo4() {
		super("Mi primera ventana - Ejemplo 4");
		this.setSize(700, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JButton boton = new JButton("Pulsa para saludar");
		JButton otroBoton = new JButton("Ahora salimos!");
		
		//this.getContentPane().setLayout(new FlowLayout()); //SALE CENTRADO
		this.getContentPane().setLayout(new FlowLayout(FlowLayout.LEFT));
		//this.getContentPane().setLayout(new FlowLayout(FlowLayout.RIGHT));
		this.getContentPane().add(new JLabel("Ventana de saludo"));
		this.getContentPane().add(boton);
		this.getContentPane().add(new JLabel("otra etiqueta"));
		this.getContentPane().add(otroBoton);
		
		boton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				System.out.println("Hola Mundo!");
			}});
		otroBoton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				dispose(); // JFrame window is destroyed and cleaned up by the operating system
			}});
	}

	public static void main(String []args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final Ejemplo4 v = new Ejemplo4();
				v.setVisible(true);
			}});
	}
}

