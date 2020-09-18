import java.awt.BorderLayout;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JSeparator;
import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class EjemploJMenu extends JFrame {
    private JMenuBar barraMenu = new JMenuBar();
    private JMenu menu1 = new JMenu("Menu");
    private JMenuItem itemCopiar = new JMenuItem("Copiar");
    private JMenuItem itemBorrar = new JMenuItem("Borrar");
    private JMenu menu2 = new JMenu("Otro Menu");
    private JMenuItem itemArchivar = new JMenuItem("Archivar");
    private JMenuItem itemCargar = new JMenuItem("Cargar");

	public EjemploJMenu() {
		super("Mi primer JMenu");
		this.setSize(800, 200);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		menu1.add(itemCopiar);
        menu1.add(new JSeparator());
        menu1.add(itemBorrar);
        menu2.add(itemArchivar);
        menu2.add(itemCargar);
        barraMenu.add(menu1);
        barraMenu.add(menu2);
        setJMenuBar(barraMenu);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploJMenu ej = new EjemploJMenu();
				ej.setVisible(true);
			}
		});
	}
}
