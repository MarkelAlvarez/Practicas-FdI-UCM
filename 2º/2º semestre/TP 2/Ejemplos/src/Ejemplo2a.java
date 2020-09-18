import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Ejemplo2a extends JFrame {
	
	public Ejemplo2a() {
		super("Mi primera ventana - Ejemplo 2");
		this.setSize(320, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		final Ejemplo2a v = new Ejemplo2a();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}
