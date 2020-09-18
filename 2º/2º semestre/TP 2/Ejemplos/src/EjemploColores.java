import javax.swing.*;
import java.awt.event.*;
import java.awt.Color;

public class EjemploColores extends JFrame {

	public EjemploColores() {
		super("Ejemplo Colores Fondo");
		this.setSize(700,200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		JPanel panel = new JPanel();
	    JButton botonRojo = new JButton("Rojo"); 
        JButton botonAzul = new JButton("Azul"); 
	    GestorColor gestorRojo = new GestorColor(Color.RED);
        GestorColor gestorAzul = new GestorColor(Color.BLUE);
		botonRojo.addActionListener(gestorRojo);
        botonAzul.addActionListener(gestorAzul);
	    panel.add(botonRojo);
		panel.add(botonAzul);
		this.getContentPane().add(panel);
	}

    class GestorColor implements ActionListener {
        private Color colorFondo;
        public GestorColor(Color c) {
            colorFondo = c;
        } 			
        public void actionPerformed(ActionEvent e) {
			setBackground(colorFondo);
        }
    } // GestorColor

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploColores v = new EjemploColores();
				v.setVisible(true);
			}
		});
	}
}
