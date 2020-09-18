
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EjemploConversorMoneda extends JFrame {
	JButton btnCalcular;
	JButton btnSalir;
	JTextField txtImporte;
	JTextField txtTipoCambio;
	JLabel lblResultado;
	JRadioButton radioPtsEuros;
	JRadioButton radioEurosPts;
	JRadioButton radioOtros;
	private final static String PTS_EUROS = "Pesetas a euros";
	private final static String EUROS_PTS = "Euros a pesetas";
	private final static String OTROS = "Otros";
	private final static double PTS_POR_EURO = 166.386;
	private final static double EUROS_POR_PTS = (Math
			.round(1.0 / 166.386 * 10000000.0)) / 10000000.0;

	public EjemploConversorMoneda() {
		super("Conversor viejuno");
		this.setLocation(50, 50);
		this.setSize(700, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		btnCalcular = new JButton("Calcular");
		btnCalcular.addActionListener(new AccionCalcular());

		btnSalir = new JButton("Salir");
		btnSalir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent event) {
				EjemploConversorMoneda.this.dispose(); // para cerrar la ventana
			}
		});

		txtImporte = new JTextField();
		txtImporte.setPreferredSize(new Dimension(70, 25));
		txtTipoCambio = new JTextField();
		txtTipoCambio.setPreferredSize(new Dimension(70, 25));

		AccionRadios actRadios = new AccionRadios();
		
		radioPtsEuros = new JRadioButton(PTS_EUROS);
		radioPtsEuros.addActionListener(actRadios);
		radioPtsEuros.setActionCommand(PTS_EUROS);
		
		radioEurosPts = new JRadioButton(EUROS_PTS);
		radioEurosPts.addActionListener(actRadios);
		radioEurosPts.setActionCommand(EUROS_PTS);
		
		radioOtros = new JRadioButton(OTROS);
		radioOtros.addActionListener(actRadios);
		radioOtros.setActionCommand(OTROS);
		radioOtros.setSelected(true);
		
		lblResultado = new JLabel("");
		//ButtonGroup radioGroup = new ButtonGroup();
		//radioGroup.add(radioPtsEuros);
		//radioGroup.add(radioEurosPts);
		//radioGroup.add(radioOtros);
		
		JPanel pnlPrincipal = new JPanel();
		pnlPrincipal.setLayout(new GridLayout(4, 3, 10, 10));
		pnlPrincipal.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
		pnlPrincipal.add(new JLabel("Importe:"));
		pnlPrincipal.add(txtImporte);
		pnlPrincipal.add(radioPtsEuros);

		pnlPrincipal.add(new JLabel("Tipo de cambio:"));
		pnlPrincipal.add(txtTipoCambio);
		pnlPrincipal.add(radioEurosPts);

		pnlPrincipal.add(new JLabel("Importe resultante:"));
		pnlPrincipal.add(lblResultado);
		pnlPrincipal.add(radioOtros);

		pnlPrincipal.add(new JLabel(""));
		pnlPrincipal.add(new JLabel(""));

		JPanel pnlBotones = new JPanel();
		pnlBotones.setLayout(new GridLayout(1, 2, 5, 5));
		pnlBotones.add(btnCalcular);
		pnlBotones.add(btnSalir);
		
		pnlPrincipal.add(pnlBotones);
		this.getContentPane().add(pnlPrincipal);
	}

	private class AccionCalcular implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			int importe = 0;
			double tipoCambio = 0.0;
			try {
				importe = Integer.parseInt(txtImporte.getText());
			} catch (NumberFormatException e) {
				JOptionPane.showMessageDialog(EjemploConversorMoneda.this,
						"El importe es incorrecto.");
				txtImporte.requestFocus();
				return;
			}
			try {
				tipoCambio = Double.parseDouble(txtTipoCambio.getText());
			} catch (NumberFormatException e) {
				JOptionPane.showMessageDialog(EjemploConversorMoneda.this,
						"El tipo de cambio es incorrecto.");
				txtTipoCambio.requestFocus();
				return;
			}
			double result = importe * tipoCambio;
			result = (Math.round(result * 100.0)) / 100.0;
			lblResultado.setText((new Double(result)).toString());
		}
	}

	private class AccionRadios implements ActionListener {
		public void actionPerformed(ActionEvent event) {
			if (event.getActionCommand().equals(PTS_EUROS)) {
				txtTipoCambio.setText(Double.toString(EUROS_POR_PTS));
				txtTipoCambio.setEditable(false);
			} else if (event.getActionCommand().equals(EUROS_PTS)) {
				txtTipoCambio.setText(Double.toString(PTS_POR_EURO));
				txtTipoCambio.setEditable(false);
			} else if (event.getActionCommand().equals(OTROS)) {
				txtTipoCambio.setText("");
				txtTipoCambio.setEditable(true);
			}
		}
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploConversorMoneda v = new EjemploConversorMoneda();
				v.setVisible(true);
			}
		});
	}

}
