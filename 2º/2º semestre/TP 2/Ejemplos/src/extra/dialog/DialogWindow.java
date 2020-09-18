package extra.dialog;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.border.Border;
import javax.swing.border.TitledBorder;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JList;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.List;

class DialogWindow extends JDialog {

	private static final long serialVersionUID = 1L;

	private MyListModel<String> _itemsListModel;
	private MyListModel<Integer> _numsListModel;

	private int _status;
	private JList<String> _itemsList;
	private JList<Integer> _numsList;

	static final private char _clearSelectionKey = 'c';
	private Border _defaultBorder = BorderFactory.createLineBorder(Color.black, 2);

	public DialogWindow(Frame parent) {
		super(parent, true);
		initGUI();
	}

	private void initGUI() {

		_status = 0;

		setTitle("Some Dialog");
		JPanel mainPanel = new JPanel(new BorderLayout());

		JPanel contentPanel = new JPanel();
		contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.X_AXIS));
		mainPanel.add(contentPanel, BorderLayout.CENTER);

		JPanel itemsPanel = new JPanel(new BorderLayout());
		JPanel numsPanel = new JPanel(new BorderLayout());

		contentPanel.add(itemsPanel);
		contentPanel.add(numsPanel);

		itemsPanel.setBorder(
				BorderFactory.createTitledBorder(_defaultBorder, "Items", TitledBorder.LEFT, TitledBorder.TOP));
		numsPanel.setBorder(
				BorderFactory.createTitledBorder(_defaultBorder, "Numbers", TitledBorder.LEFT, TitledBorder.TOP));

		itemsPanel.setMinimumSize(new Dimension(100, 100));
		numsPanel.setMinimumSize(new Dimension(100, 100));

		_itemsListModel = new MyListModel<>();
		_numsListModel = new MyListModel<>();

		_itemsList = new JList<>(_itemsListModel);
		_numsList = new JList<>(_numsListModel);

		addCleanSelectionListner(_itemsList);
		addCleanSelectionListner(_numsList);

		itemsPanel.add(new JScrollPane(_itemsList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.CENTER);

		numsPanel.add(new JScrollPane(_numsList, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED,
				JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED), BorderLayout.CENTER);


		JPanel buttonsPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
		mainPanel.add(buttonsPanel, BorderLayout.PAGE_END);

		JButton cancelButton = new JButton("Cancel");
		cancelButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 0;
				DialogWindow.this.setVisible(false);
			}
		});
		buttonsPanel.add(cancelButton);

		JButton okButton = new JButton("OK");
		okButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				_status = 1;
				DialogWindow.this.setVisible(false);
			}
		});
		buttonsPanel.add(okButton);

		mainPanel.add(buttonsPanel, BorderLayout.PAGE_END);

		JPanel infoPanel = new JPanel();
		infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
		mainPanel.add(infoPanel, BorderLayout.PAGE_START);

		infoPanel.add(new JLabel("Select items for which you want to process."));
		infoPanel.add(new JLabel("Use '" + _clearSelectionKey + "' to deselect all."));
		infoPanel.add(new JLabel("Use Ctrl+A to select all"));
		infoPanel.add(new JLabel(" "));

		setContentPane(mainPanel);
		setMinimumSize(new Dimension(100, 100));
		setVisible(false);
	}

	private void addCleanSelectionListner(JList<?> list) {
		list.addKeyListener(new KeyListener() {

			@Override
			public void keyTyped(KeyEvent e) {
				if (e.getKeyChar() == _clearSelectionKey) {
					list.clearSelection();
				}
			}

			@Override
			public void keyReleased(KeyEvent e) {
			}

			@Override
			public void keyPressed(KeyEvent e) {
			}
		});

	}

	public void setData(List<String> items, List<Integer> nums) {
		_itemsListModel.setList(items);
		_numsListModel.setList(nums);
	}

	public String[] getSelectedItems() {
		int[] indices = _itemsList.getSelectedIndices();
		String[] items = new String[indices.length];
		for(int i=0; i<items.length; i++) {
			items[i] = _itemsListModel.getElementAt(indices[i]);
		}
		return items;
	}

	public Integer[] getSelectedNums() {
		int[] indices = _numsList.getSelectedIndices();
		Integer[] nums = new Integer[indices.length];
		for(int i=0; i<nums.length; i++) {
			nums[i] = _numsListModel.getElementAt(indices[i]);
		}
		return nums;
	}


	public int open() {
		setLocation(getParent().getLocation().x + 50, getParent().getLocation().y + 50);
		pack();
		setVisible(true);
		return _status;
	}

}
