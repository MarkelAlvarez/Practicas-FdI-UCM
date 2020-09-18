import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;
import javax.swing.KeyStroke;
import javax.swing.SwingUtilities;

public class EjemploJMenuBar3 extends JFrame {

	public EjemploJMenuBar3() {
		super("Ejemplo de barra de menu");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(300, 300);

		MiMenuListener menuLst = new MiMenuListener();
		JMenuBar menuBar = new JMenuBar();
		JMenu menuArchivo = new JMenu("Archivo");
		menuArchivo.setMnemonic(KeyEvent.VK_A);
		JMenuItem menuItemAbrir = new JMenuItem("Abrir", KeyEvent.VK_A);
		JMenuItem menuItemCerrar = new JMenuItem("Cerrar", KeyEvent.VK_C);
		JMenuItem menuItemSalir = new JMenuItem("Salir", KeyEvent.VK_S);
		menuArchivo.add(menuItemAbrir);
		menuArchivo.add(menuItemCerrar);
		menuArchivo.add(new JSeparator());
		menuArchivo.add(menuItemSalir);
		menuItemAbrir.addActionListener(menuLst);
		menuItemCerrar.addActionListener(menuLst);
		menuItemSalir.addActionListener(menuLst);

		menuBar.add(menuArchivo);

		JMenu menuEditar = new JMenu("Editar");
		menuEditar.setMnemonic(KeyEvent.VK_E);
		JMenuItem menuItemCortar = new JMenuItem("Cortar", KeyEvent.VK_O);
		menuItemCortar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X,
				ActionEvent.CTRL_MASK));
		JMenuItem menuItemCopiar = new JMenuItem("Copiar", KeyEvent.VK_P);
		menuItemCopiar.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C,
				ActionEvent.CTRL_MASK + ActionEvent.ALT_MASK));
		JMenuItem menuItemPegar = new JMenuItem("Pegar", KeyEvent.VK_G);
		JMenu menuZoom = new JMenu("Zoom");
		menuZoom.setMnemonic(KeyEvent.VK_Z);
		JMenuItem menuItemAgrandar = new JMenuItem("+");
		JMenuItem menuItemDisminuir = new JMenuItem("-");

		menuEditar.add(menuItemCortar);
		menuEditar.add(menuItemCopiar);
		menuEditar.add(menuItemPegar);
		menuEditar.add(menuZoom);
		menuZoom.add(menuItemAgrandar);
		menuZoom.add(menuItemDisminuir);
		menuItemCortar.addActionListener(menuLst);
		menuItemCopiar.addActionListener(menuLst);
		menuItemPegar.addActionListener(menuLst);
		menuItemAgrandar.addActionListener(menuLst);
		menuItemDisminuir.addActionListener(menuLst);
		menuBar.add(menuEditar);
		this.setJMenuBar(menuBar);

	}

	private class MiMenuListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			JOptionPane.showMessageDialog(
					EjemploJMenuBar3.this,
					"Se ha pulsado en la opción de menú: "
							+ e.getActionCommand(), "Información del menú",
					JOptionPane.DEFAULT_OPTION);
		}
	}

	public static void main(String[] args) {
		final EjemploJMenuBar3 v = new EjemploJMenuBar3();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}
