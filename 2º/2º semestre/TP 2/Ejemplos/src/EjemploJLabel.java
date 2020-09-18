import java.awt.BorderLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class EjemploJLabel extends JFrame {
	private JPanel panelCampos = new JPanel();
    private JPanel panelBotones = new JPanel();
    private JLabel etiquetaValor = new JLabel("Valor", JLabel.CENTER);
    private JTextField campoValor = new JTextField(20);
    private JLabel etiquetaCopia = new JLabel("Copia", JLabel.CENTER);
    private JTextField campoCopia = new JTextField(20);
    private JButton botonCopiar = new JButton("Copiar");
    private JButton botonBorrar = new JButton("Borrar");

	public EjemploJLabel() {
		super("Mi primer JLabel");
		this.setSize(800, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		panelCampos.add(etiquetaValor);
        panelCampos.add(campoValor);
        panelCampos.add(etiquetaCopia);
        panelCampos.add(campoCopia);

        // panelBotones.setLayout(new FlowLayout()); // layout por defecto
        panelBotones.add(botonCopiar);
        panelBotones.add(botonBorrar);
        this.add(panelCampos, BorderLayout.NORTH);
        this.add(panelBotones, BorderLayout.CENTER);  
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploJLabel ej = new EjemploJLabel();
				ej.setVisible(true);
			}
		});
	}
}
