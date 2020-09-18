package extra.dialog;

import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.List;

@SuppressWarnings("serial")
public class DialogWindowExample extends JFrame  {

	private DialogWindow _dialog;
	
	List<String> _names;
	List<Integer> _ages;
	
	public DialogWindowExample() {
		super("Dialog Example");
		initGUI();
	}

	private void initGUI() {

		// initialize lists;
		_names  = new ArrayList<>();
		_ages  = new ArrayList<>();
		for(int i=0;i<10; i++) {
			_names.add("Item "+i);
			_ages.add(i+30);			
		}
		
		JPanel mainPanel = new JPanel();
		mainPanel.add(new JLabel("If you click "));
		
		_dialog = new DialogWindow(this);
		_dialog.setData(_names, _ages);
		
		JButton here = new JButton("here");
		here.addActionListener( new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				int status = _dialog.open();
				if ( status == 0) {
					System.out.println("Canceled");
				} else {
					System.out.println("The following items where selected:");
					for(String s : _dialog.getSelectedItems()) {
						System.out.println(s);
					}
					System.out.println("The following numbers where selected:");
					for(Integer s : _dialog.getSelectedNums()) {
						System.out.println(s);
					}
				}
			}
		});
		mainPanel.add(here);
		mainPanel.add(new JLabel("a dialog window is opened and the main window blocks."));

		this.setContentPane(mainPanel);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.pack();
		this.setVisible(true);

	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new DialogWindowExample();
			}
		});
	}
}