import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.AbstractButton;
import javax.swing.ButtonGroup;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.JSeparator;
import javax.swing.SwingUtilities;

public class EjemploJMenuBar2 extends JFrame {

	public EjemploJMenuBar2() {
		super("Ejemplo de barra de menu");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(300, 300);

		MiMenuListener menuLst = new MiMenuListener();
		JMenuBar menuBar = new JMenuBar();
		JMenu menuCheckBoxes = new JMenu("Check Boxes");
		JCheckBoxMenuItem menuItemContinuo = new JCheckBoxMenuItem(
				"Vista continua");
		JCheckBoxMenuItem menuItemPresentacion = new JCheckBoxMenuItem(
				"Modo presentacion");
		menuCheckBoxes.add(menuItemContinuo);
		menuCheckBoxes.add(menuItemPresentacion);
		menuItemContinuo.addActionListener(menuLst);
		menuItemPresentacion.addActionListener(menuLst);
		menuBar.add(menuCheckBoxes);

		JMenu menuRadioButtons = new JMenu("Radio Buttons");
		JRadioButtonMenuItem menuItemCortar = new JRadioButtonMenuItem("Cortar");
		JRadioButtonMenuItem menuItemCopiar = new JRadioButtonMenuItem("Copiar");
		JRadioButtonMenuItem menuItemPegar = new JRadioButtonMenuItem("Pegar");
		ButtonGroup bgEditar = new ButtonGroup();
		bgEditar.add(menuItemCortar);
		bgEditar.add(menuItemCopiar);
		bgEditar.add(menuItemPegar);

		JRadioButtonMenuItem menuItemAgrandar = new JRadioButtonMenuItem(
				"Agrandar");
		JRadioButtonMenuItem menuItemDisminuir = new JRadioButtonMenuItem(
				"Disminuir");
		JRadioButtonMenuItem menuItem100 = new JRadioButtonMenuItem("100%");
		JRadioButtonMenuItem menuItem75 = new JRadioButtonMenuItem("75%");
		JRadioButtonMenuItem menuItem50 = new JRadioButtonMenuItem("50%");
		JRadioButtonMenuItem menuItem25 = new JRadioButtonMenuItem("25%");
		ButtonGroup bgZoom = new ButtonGroup();
		bgZoom.add(menuItemAgrandar);
		bgZoom.add(menuItemDisminuir);
		bgZoom.add(menuItem100);
		bgZoom.add(menuItem75);
		bgZoom.add(menuItem50);
		bgZoom.add(menuItem25);

		menuRadioButtons.add(menuItemCortar);
		menuRadioButtons.add(menuItemCopiar);
		menuRadioButtons.add(menuItemPegar);
		menuRadioButtons.add(new JSeparator());
		menuRadioButtons.add(menuItemAgrandar);
		menuRadioButtons.add(menuItemDisminuir);
		menuRadioButtons.add(menuItem100);
		menuRadioButtons.add(menuItem75);
		menuRadioButtons.add(menuItem50);
		menuRadioButtons.add(menuItem25);
		menuItemCortar.addItemListener(menuLst);
		menuItemCopiar.addItemListener(menuLst);
		menuItemPegar.addItemListener(menuLst);
		menuItemAgrandar.addItemListener(menuLst);
		menuItemDisminuir.addItemListener(menuLst);
		menuItem100.addItemListener(menuLst);
		menuItem75.addItemListener(menuLst);
		menuItem50.addItemListener(menuLst);
		menuItem25.addItemListener(menuLst);

		menuBar.add(menuRadioButtons);
		this.setJMenuBar(menuBar);

	}

	private class MiMenuListener implements ActionListener, ItemListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			JOptionPane.showMessageDialog(
					EjemploJMenuBar2.this,
					"Se ha pulsado en la opcion de menu: "
							+ e.getActionCommand(), "Informacion del menu",
					JOptionPane.DEFAULT_OPTION);
		}

		@Override
		public void itemStateChanged(ItemEvent e) {
			AbstractButton b = (AbstractButton) e.getSource();
			if (b.isSelected()) {
				JOptionPane.showMessageDialog(EjemploJMenuBar2.this,
						"La opcion de menu: " + b.getActionCommand()
								+ " esta seleccionada.");
			}
		}
	}

	public static void main(String[] args) {
		final EjemploJMenuBar2 v = new EjemploJMenuBar2();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}
