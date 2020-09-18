import java.awt.Dimension;
import java.util.ArrayList;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JLabel;


	public class Reloj extends JComponent {
		private int numPlayers;
		ArrayList<JLabel> tiemposPlayers = new ArrayList<JLabel>();

		public Reloj(int numPlayers) {
			this.numPlayers = numPlayers;
			initGUI();
		}

		private void initGUI() {
			this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
			this.setPreferredSize(new Dimension(200, 200));
			this.setBorder(BorderFactory.createTitledBorder("thinking times"));
			int i;
			for (i = 0; i < numPlayers; i++) {
				this.add(new JLabel("Thinking time for player: " + i));
				tiemposPlayers.add(new JLabel(""));
				this.add(tiemposPlayers.get(i));
			}
		}
	}



