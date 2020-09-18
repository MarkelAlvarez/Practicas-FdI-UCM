package extra.popupmenu;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;

public class PopUpMenuExample extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	
	private JPanel _mainPanel;
	private JTextArea _editor;

	public PopUpMenuExample() {
		super("Pop Up Menu Example");
		initGUI();
	}

	private void initGUI() {
		_mainPanel = new JPanel(new BorderLayout());
		this.setContentPane(_mainPanel);

		addEditor();

		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);
	}

	private void addEditor() {
		_mainPanel.add(new JLabel("Right click over the text-area to get the popup menu."),BorderLayout.PAGE_START);

		_editor = new JTextArea(20, 20);

		_mainPanel.add(new JScrollPane(_editor, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.CENTER);

		// create the events pop-up menu
		JPopupMenu _editorPopupMenu = new JPopupMenu();
		
		JMenuItem clearOption = new JMenuItem("Clear");
		clearOption.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				_editor.setText("");
			}
		});

		JMenuItem exitOption = new JMenuItem("Exit");
		exitOption.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});

		JMenu subMenu = new JMenu("Insert");

		String[] greetings = { "Hola!", "Hello!", "Ciao!" };
		for (String s : greetings) {
			JMenuItem menuItem = new JMenuItem(s);
			menuItem.addActionListener(new ActionListener() {

				@Override
				public void actionPerformed(ActionEvent e) {
					_editor.insert(s, _editor.getCaretPosition());
				}
			});
			subMenu.add(menuItem);
		}

		
		_editorPopupMenu.add(subMenu);
		_editorPopupMenu.addSeparator();
		_editorPopupMenu.add(clearOption);
		_editorPopupMenu.add(exitOption);

		// connect the popup menu to the text area _editor
		_editor.addMouseListener(new MouseListener() {

			@Override
			public void mousePressed(MouseEvent e) {
				showPopup(e);
			}

			@Override
			public void mouseReleased(MouseEvent e) {
				showPopup(e);
			}

			private void showPopup(MouseEvent e) {
				if (e.isPopupTrigger() && _editorPopupMenu.isEnabled()) {
					_editorPopupMenu.show(e.getComponent(), e.getX(), e.getY());
				}
			}

			@Override
			public void mouseExited(MouseEvent e) {
			}

			@Override
			public void mouseEntered(MouseEvent e) {
			}

			@Override
			public void mouseClicked(MouseEvent e) {
			}
		});

	}
	
	public static void main(String[] args) {
		SwingUtilities.invokeLater( new Runnable() {
			
			@Override
			public void run() {
				new PopUpMenuExample();
			}
		});
	}

}
