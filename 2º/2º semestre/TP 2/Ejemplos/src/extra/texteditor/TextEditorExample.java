package extra.texteditor;

import javax.swing.*;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("serial")
public class TextEditorExample extends JFrame implements ActionListener {

	private final String LOAD = "load";
	private final String SAVE = "save";
	private final String CLEAR = "clear";
	private final String QUIT = "quit";

	private JFileChooser fc;
	private JTextArea textArea;

	public TextEditorExample() {
		super("[=] Text Editor [=]");
		initGUI();
	}

	private void initGUI() {

		JPanel mainPanel = new JPanel(new BorderLayout());
		this.setContentPane(mainPanel);

		// text area
		textArea = new JTextArea("");
		textArea.setEditable(true);
		textArea.setLineWrap(true);
		textArea.setWrapStyleWord(true);
		JScrollPane area = new JScrollPane(textArea);
		area.setPreferredSize(new Dimension(500, 500));
		mainPanel.add(area);

		// tool bar
		mainPanel.add(createJTolBar(), BorderLayout.PAGE_START);

		// menu bar
		this.setJMenuBar(createMenuBar());

		// we create the file chooser only once
		fc = new JFileChooser();

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);

	}

	public JMenuBar createMenuBar() {
		JMenuItem load, save, clear, quit;

		JMenuBar menuBar = new JMenuBar();

		JMenu file = new JMenu("File");
		menuBar.add(file);
		file.setMnemonic(KeyEvent.VK_F);

		load = new JMenuItem("Load");
		load.setActionCommand(LOAD);
		load.addActionListener(this);
		load.setMnemonic(KeyEvent.VK_L);
		load.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_L,
				ActionEvent.ALT_MASK));

		save = new JMenuItem("Save");
		save.setActionCommand(SAVE);
		save.addActionListener(this);
		save.setMnemonic(KeyEvent.VK_S);
		save.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,
				ActionEvent.ALT_MASK));

		clear = new JMenuItem("Clear");
		clear.setActionCommand(CLEAR);
		clear.addActionListener(this);
		clear.setMnemonic(KeyEvent.VK_C);
		clear.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_C,
				ActionEvent.ALT_MASK));

		quit = new JMenuItem("Quit");
		quit.setActionCommand(QUIT);
		quit.addActionListener(this);
		quit.setMnemonic(KeyEvent.VK_Q);
		quit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_Q,
				ActionEvent.ALT_MASK));

		file.add(load);
		file.add(save);
		file.addSeparator();
		file.add(clear);
		file.addSeparator();
		file.add(quit);

		return menuBar;
	}

	public JToolBar createJTolBar() {
		JToolBar toolBar = new JToolBar();

		JButton load = new JButton();
		load.setActionCommand(LOAD);
		load.setToolTipText("Load a file");
		load.addActionListener(this);
		load.setIcon(new ImageIcon(loadImage("resources/icons/open.png")));
		toolBar.add(load);

		JButton save = new JButton();
		save.setActionCommand(SAVE);
		save.setToolTipText("Save a file");
		save.addActionListener(this);
		save.setIcon(new ImageIcon(loadImage("resources/icons/save.png")));
		toolBar.add(save);

		JButton clear = new JButton();
		clear.setActionCommand(CLEAR);
		clear.setToolTipText("Clear Text");
		clear.addActionListener(this);
		clear.setIcon(new ImageIcon(loadImage("resources/icons/clear.png")));
		toolBar.add(clear);

		return toolBar;
	}

	public void actionPerformed(ActionEvent e) {
		if (LOAD.equals(e.getActionCommand()))
			loadFile();
		else if (SAVE.equals(e.getActionCommand()))
			saveFile();
		else if (CLEAR.equals(e.getActionCommand()))
			textArea.setText("");
		else if (QUIT.equals(e.getActionCommand()))
			System.exit(0);
	}

	private void saveFile() {
		int returnVal = fc.showSaveDialog(null);
		if (returnVal == JFileChooser.APPROVE_OPTION) {
			File file = fc.getSelectedFile();
			writeFile(file, textArea.getText());
		}
	}

	private void loadFile() {
		int returnVal = fc.showOpenDialog(null);
		if (returnVal == JFileChooser.APPROVE_OPTION) {
			File file = fc.getSelectedFile();
			String s = readFile(file);
			textArea.setText(s);
		}
	}

	public static String readFile(File file) {
		String s = "";
		try {
			s = new Scanner(file).useDelimiter("\\A").next();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		return s;
	}

	public static void writeFile(File file, String content) {
		try {
			PrintWriter pw = new PrintWriter(file);
			pw.print(content);
			pw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static Image loadImage(String path) {
		return Toolkit.getDefaultToolkit().createImage(path);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new TextEditorExample();
			}
		});
	}

}
