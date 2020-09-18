import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import javax.swing.WindowConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.SwingUtilities;

public class EjemploJSpinner extends JFrame {

	private JTextField tf;

	private JSpinner spinner;
	int Time0 = 1000;

	public EjemploJSpinner() {
		super("ejemplo: Spinner");
		this.setSize(320, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		tf = new JTextField(20);
		spinner = new JSpinner(new SpinnerNumberModel(Time0, 0, 5000,
				500));
		spinner.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent e) {
				// Ponemos el valor del JSpinner en el JTextField
				tf.setText(spinner.getValue().toString());
				
			}
		});

		// Creacion de la ventana con los componentes

		getContentPane().setLayout(new FlowLayout());
		getContentPane().add(spinner);
		getContentPane().add(tf);
		pack();
		setVisible(true);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				final EjemploJSpinner v = new EjemploJSpinner();
				v.setVisible(true);
			}
		});

	}

}
