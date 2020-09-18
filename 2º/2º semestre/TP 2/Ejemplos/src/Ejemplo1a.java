import javax.swing.*;

public class Ejemplo1a extends JFrame {

	private static final long serialVersionUID = 1L;

	public Ejemplo1a() {
		super("[=] Hello World [=]");
		initGUI();
	}

	private void initGUI() {
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(400, 100);
		this.setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new Ejemplo1a();
			}
		});
	}
}

