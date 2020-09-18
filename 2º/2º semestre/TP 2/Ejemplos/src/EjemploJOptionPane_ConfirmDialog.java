import java.awt.BorderLayout;
import java.awt.GridLayout;
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

public class EjemploJOptionPane_ConfirmDialog extends JFrame {
	public EjemploJOptionPane_ConfirmDialog() {
		super("Ejemplos de cuadros de dialogo sencillos");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	

		// Arrays con valores y radio buttons para seleccionar 
		// el tipo de opcion y el tipo de mensaje.
		final int[] valOptionType = {
				JOptionPane.YES_NO_OPTION,
				JOptionPane.YES_NO_CANCEL_OPTION,
				JOptionPane.OK_CANCEL_OPTION};
		final JRadioButton[] rdoOptionType = {
				new JRadioButton("YES_NO_OPTION"),
				new JRadioButton("YES_NO_CANCEL_OPTION"),
				new JRadioButton("OK_CANCEL_OPTION")};
		final int[] valMessageType = {
				JOptionPane.ERROR_MESSAGE,
				JOptionPane.INFORMATION_MESSAGE,
				JOptionPane.WARNING_MESSAGE,
				JOptionPane.QUESTION_MESSAGE,
				JOptionPane.PLAIN_MESSAGE
		};
		final JRadioButton[] rdoMessageType = {
				new JRadioButton("ERROR_MESSAGE"),
				new JRadioButton("INFORMATION_MESSAGE"),
				new JRadioButton("WARNING_MESSAGE"),
				new JRadioButton("QUESTION_MESSAGE"),
				new JRadioButton("PLAIN_MESSAGE")
		};

		rdoOptionType[0].setSelected(true);
		ButtonGroup grpOptionType = new ButtonGroup();
		JPanel pnlOptionType = new JPanel();
		pnlOptionType.setBorder(BorderFactory.createTitledBorder("Option Type"));
		for (AbstractButton b : rdoOptionType) {
			grpOptionType.add(b);
			pnlOptionType.add(b);
		}
		
		rdoMessageType[0].setSelected(true);
		ButtonGroup grpMessageType = new ButtonGroup();
		JPanel pnlMessageType = new JPanel();
		pnlMessageType.setBorder(BorderFactory.createTitledBorder("Message Type"));
		for (AbstractButton b : rdoMessageType) {
			grpMessageType.add(b);
			pnlMessageType.add(b);
		}
				
		JButton btnConfirmDialog = new JButton("Mostrar Confirm Dialog");
		btnConfirmDialog.setIcon(new ImageIcon(this.getClass().getResource("OK-icon.png")));
		btnConfirmDialog.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				int optionType = obtenerValorTipo(rdoOptionType,valOptionType);
				int messageType = obtenerValorTipo(rdoMessageType,valMessageType);
				int res = JOptionPane.showConfirmDialog(
						EjemploJOptionPane_ConfirmDialog.this, 
						"Esto es un Confirm Dialog", 
						"Confirm Dialog",  
						optionType, 
						messageType);
				System.out.println("res = " + res);
			}
		});
		
		this.getContentPane().setLayout(new BorderLayout());
		JPanel pnlCenter = new JPanel();
		pnlCenter.setLayout(new GridLayout(2,1,10,10));
		pnlCenter.add(pnlOptionType);
		pnlCenter.add(pnlMessageType);
		this.getContentPane().add(pnlCenter,BorderLayout.CENTER);
		JPanel pnlSouth = new JPanel();
		//pnlSouth.setLayout(new BorderLayout());
		pnlSouth.add(btnConfirmDialog);
		//pnlSouth.add(btnCustomDialog,BorderLayout.EAST);
		this.getContentPane().add(pnlSouth,BorderLayout.SOUTH);
		this.pack();
		
	}
	
	private int obtenerValorTipo(AbstractButton[] btns, int[] vals) {
		int i;
		for (i = 0; i < btns.length && !btns[i].isSelected(); i++)
			;
		return vals[i];
	}	
	
	public static void main(String[] args) {
		final EjemploJOptionPane_ConfirmDialog v = new EjemploJOptionPane_ConfirmDialog();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}});
	}
}
