import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

public class EjemploJOptionPane_InputDialog extends JFrame {
	
	public EjemploJOptionPane_InputDialog() {
		super("Ejemplos de cuadros de dialogo sencillos");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		final JButton btnInputDialog = new JButton("Mostrar Input Dialog");
		btnInputDialog.setIcon(new ImageIcon(this.getClass().getResource(
				"OK-icon.png")));
		btnInputDialog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				String res = JOptionPane.showInputDialog(
						EjemploJOptionPane_InputDialog.this,
						"Introduce un texto");
				System.out.println("res = " + res);
			}
		});

		JPanel pnlSouth = new JPanel();
		pnlSouth.add(btnInputDialog);
		this.getContentPane().add(pnlSouth);
		this.pack();

	}

	public static void main(String[] args) {
		final EjemploJOptionPane_InputDialog v = new EjemploJOptionPane_InputDialog();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}
