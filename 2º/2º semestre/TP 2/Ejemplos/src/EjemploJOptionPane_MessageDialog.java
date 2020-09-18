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

public class EjemploJOptionPane_MessageDialog extends JFrame {

	public EjemploJOptionPane_MessageDialog() {
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
			//anadimos los JRadioButton uno a uno, no se puede en grupo
			pnlMessageType.add(b);
		}
		

		JButton btnMessageDialog = new JButton("Mostrar Mensaje ");
		System.out.println(this.getClass().getResource(
				"OK-icon.png"));
		btnMessageDialog.setIcon(new ImageIcon(this.getClass().getResource(
				"OK-icon.png")));
		btnMessageDialog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				//recorro el array de JRadioButton y busca el seleccionado
				int messageType = obtenerValorTipo(rdoMessageType,
						valMessageType);
				JOptionPane.showMessageDialog(
						EjemploJOptionPane_MessageDialog.this,
						rdoMessageType[messageType].getText(),"Message Dialog",
						messageType);
				System.out.println("Ha cerrado la ventana.");
			}
		});

		this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add(pnlMessageType, BorderLayout.CENTER);
		JPanel pnlSouth = new JPanel();
		pnlSouth.add(btnMessageDialog);
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
				final EjemploJOptionPane_MessageDialog v = new EjemploJOptionPane_MessageDialog();
				v.setVisible(true);
			}
		});
	}
}
