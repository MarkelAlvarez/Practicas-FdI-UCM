import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.AbstractButton;
import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.SwingUtilities;

public class EjemploJOptionPane_OptionDialog extends JFrame {
	
	public EjemploJOptionPane_OptionDialog() {
		
		super("Ejemplos de cuadros de dialogo sencillos");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		final int[] valMessageType = { JOptionPane.ERROR_MESSAGE,
				JOptionPane.INFORMATION_MESSAGE, JOptionPane.WARNING_MESSAGE,
				JOptionPane.QUESTION_MESSAGE, JOptionPane.PLAIN_MESSAGE };
		final JRadioButton[] rdoMessageType = {
				new JRadioButton("ERROR_MESSAGE"),
				new JRadioButton("INFORMATION_MESSAGE"),
				new JRadioButton("WARNING_MESSAGE"),
				new JRadioButton("QUESTION_MESSAGE"),
				new JRadioButton("PLAIN_MESSAGE") };
		rdoMessageType[0].setSelected(true);
		ButtonGroup grpMessageType = new ButtonGroup();
		JPanel pnlMessageType = new JPanel();
		pnlMessageType.setBorder(BorderFactory
				.createTitledBorder("Message Type"));
		for (AbstractButton b : rdoMessageType) {
			grpMessageType.add(b);
			pnlMessageType.add(b);
		}

		JButton btnCustomDialog = new JButton("Mostrar Option Dialog");
		btnCustomDialog.setIcon(new ImageIcon(this.getClass().getResource(
				"OK-icon.png")));
		btnCustomDialog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				int optionType = JOptionPane.DEFAULT_OPTION;
				int messageType = obtenerValorTipo(rdoMessageType,
						valMessageType);
				String[] textoBotones = { "Que si!", "Que no!", "Que no se",
						"Puedo salir de aqui ya?" };
				int res = JOptionPane.showOptionDialog(
						EjemploJOptionPane_OptionDialog.this,
						"Esto es un Option Dialog con botones a medida",
						"Confirm Dialog", optionType, messageType, null,
						textoBotones, textoBotones[0]);
				
				System.out.println("res = " + res);
			}
		});

		this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add(pnlMessageType, BorderLayout.CENTER);
		JPanel pnlSouth = new JPanel();
		pnlSouth.add(btnCustomDialog);
		this.getContentPane().add(pnlSouth, BorderLayout.SOUTH);
		this.pack();

	}

	private int obtenerValorTipo(AbstractButton[] btns, int[] vals) {
		int i;
		for (i = 0; i < btns.length && !btns[i].isSelected(); i++) {
		}
		return (i < btns.length ? vals[i] : vals[0]); // si no esta seleccionado devuelve el primero.
	}

	public static void main(String[] args) {		
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploJOptionPane_OptionDialog v = new EjemploJOptionPane_OptionDialog();
				v.setVisible(true);
			}
		});
	}
}
