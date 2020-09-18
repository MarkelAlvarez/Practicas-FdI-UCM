import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JSeparator;
import javax.swing.SwingUtilities;

public class EjemploJMenuBar1 extends JFrame {

	public EjemploJMenuBar1() {
		super("Ejemplo de barra de menu");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(300, 300);

		MiMenuListener menuLst = new MiMenuListener();
		JMenuBar menuBar = new JMenuBar();
		JMenu menuArchivo = new JMenu("Archivo");
		JMenuItem menuItemAbrir = new JMenuItem("Abrir");
		JMenuItem menuItemCerrar = new JMenuItem("Cerrar");
		JMenuItem menuItemSalir = new JMenuItem("Salir");
		menuArchivo.add(menuItemAbrir);
		menuArchivo.add(menuItemCerrar);
		menuArchivo.add(new JSeparator());
		menuArchivo.add(menuItemSalir);
		menuItemAbrir.addActionListener(menuLst);
		menuItemCerrar.addActionListener(menuLst);
		menuItemSalir.addActionListener(menuLst);

		menuBar.add(menuArchivo);

		JMenu menuEditar = new JMenu("Editar");
		JMenuItem menuItemCortar = new JMenuItem("Cortar");
		JMenuItem menuItemCopiar = new JMenuItem("Copiar");
		JMenuItem menuItemPegar = new JMenuItem("Pegar");
		JMenu menuZoom = new JMenu("Zoom");
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
					EjemploJMenuBar1.this,
					"Se ha pulsado en la opcion de menu: "
							+ e.getActionCommand(), "Informacion del menu",
					JOptionPane.DEFAULT_OPTION);
		}
	}

	public static void main(String[] args) {
		final EjemploJMenuBar1 v = new EjemploJMenuBar1();
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}
		});
	}
}
