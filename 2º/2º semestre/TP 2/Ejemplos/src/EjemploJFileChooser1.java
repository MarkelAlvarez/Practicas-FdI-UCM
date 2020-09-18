import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.plaf.FileChooserUI;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;


public class EjemploJFileChooser1 extends JFrame implements ActionListener {
	JFileChooser fc;
	
	public EjemploJFileChooser1() {
		super("Ejemplo de cuadro de dialogo de seleccion de archivos");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		this.setSize(340, 200);
		this.getContentPane().setLayout(new FlowLayout());

		JButton btnOpenFile = new JButton("Abrir archivo");
		btnOpenFile.setActionCommand("abrir");
		btnOpenFile.setIcon(new ImageIcon(this.getClass().getResource("open.png")));
		btnOpenFile.addActionListener(this);
		this.getContentPane().add(btnOpenFile);

		JButton btnSaveFile = new JButton("Guardar archivo");
		btnSaveFile.setActionCommand("guardar");
		btnSaveFile.setIcon(new ImageIcon(this.getClass().getResource("save.png")));
		btnSaveFile.addActionListener(this);
		this.getContentPane().add(btnSaveFile);

		
		fc = new JFileChooser();
		fc.setCurrentDirectory(new File("/Temp/"));
		fc.setMultiSelectionEnabled(true);
		fc.setFileFilter(new FileNameExtensionFilter("Archivos de imagenes", "png", "jpg", "jpeg", "bmp"));
	}	

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("abrir")) {
			int ret = fc.showOpenDialog(this);
			if (ret == JFileChooser.APPROVE_OPTION) {
				JOptionPane.showMessageDialog(this, "Se ha seleccionado abrir el archivo: " + fc.getSelectedFile());
			} else {
				JOptionPane.showMessageDialog(this, "Se ha pulsado cancelar o ha ocurrido un error.");
			}
		} else if (e.getActionCommand().equals("guardar")) {
			int ret = fc.showSaveDialog(this);
			if (ret == JFileChooser.APPROVE_OPTION) {
				JOptionPane.showMessageDialog(this, "Se ha seleccionado guardar el archivo: " + fc.getSelectedFile());
			} else {
				JOptionPane.showMessageDialog(this, "Se ha pulsado cancelar o ha ocurrido un error.");
			}
		}
	}
	
	public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException, UnsupportedLookAndFeelException {
		final EjemploJFileChooser1 v = new EjemploJFileChooser1();
		UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		for (javax.swing.UIManager.LookAndFeelInfo info: javax.swing.UIManager.getInstalledLookAndFeels()) {
			System.out.println(info);
		}
		
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				v.setVisible(true);
			}});
	}
}
