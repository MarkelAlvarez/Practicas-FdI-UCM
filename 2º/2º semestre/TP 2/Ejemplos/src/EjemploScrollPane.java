import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Component;

@SuppressWarnings("serial")
public class EjemploScrollPane extends JFrame {

	public EjemploScrollPane() {
		super(" ScrollPane with JPanel");
		initGUI();
	}

	private void initGUI() {
		JPanel mainPanel = new JPanel(new BorderLayout());
		JPanel p = new JPanel();
		p.setLayout(new BoxLayout(p, BoxLayout.Y_AXIS));
		addButton("Holaa", p);
		addButton("Holaaa", p);
		addButton("Holaaaa", p);
		addButton("Holaaaaa", p);
		addButton("Holaaaaaaaa", p);
		addButton("Holaaaaaaaaaaaaaaaaa", p);
		addButton("Holaaaaaaaaaaaaaaaaaaaaa", p);
		JScrollPane area = new JScrollPane(p);
		area.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		mainPanel.add(area);
		mainPanel.setOpaque(true);
		this.setContentPane(mainPanel);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	 
		this.pack();
		this.setVisible(true);
	}

	private void addButton(String text, JPanel container) {
		JButton button = new JButton(text);
		// try LEFT or RIGHT instead of CENTER
		button.setAlignmentX(Component.CENTER_ALIGNMENT);
		container.add(button);
	}

	public static void main(String[] args) {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				new EjemploScrollPane();
			}
		});
	}
}

