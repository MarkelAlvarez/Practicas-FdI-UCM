import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Ejemplo6 extends JFrame {

	public Ejemplo6() {
		super("Mi primera ventana - Ejemplo 6");
		this.setSize(450, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		int filas = 3;
		int cols = 4;
		this.getContentPane().setLayout(new GridLayout(filas, cols, 15, 15));
		for (int i = 0; i < filas; i++) {
			for (int j = 0; j < cols; j++) {
				JLabel lbl = new JLabel("(" + Integer.toString(i) + ", "
						+ Integer.toString(j) + ")");
				lbl.setBackground(Color.yellow);
				lbl.setOpaque(true);
				this.getContentPane().add(lbl);
			}
		}
	}

	public static void main(String[] args) {
		// ...
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final Ejemplo6 v = new Ejemplo6();
				v.setVisible(true);
			}
		});
	}
}

