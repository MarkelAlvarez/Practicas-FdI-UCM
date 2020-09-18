import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;

public class Ejemplo2 extends JFrame {

	public Ejemplo2() {
		super("Ejemplo de multiples hilos de ejecucion");
		this.getContentPane().setLayout(new FlowLayout());
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);

		MiContador contador1 = new MiContador();
		this.getContentPane().add(contador1);
		MiContador contador2 = new MiContador();
		this.getContentPane().add(contador2);
		MiContador contador3 = new MiContador();
		this.getContentPane().add(contador3);

		this.pack();
	}

	private class MiContador extends JPanel implements Runnable {
		private JLabel lbl;
		private Thread hiloContador = null;

		public MiContador() {

			this.setBorder(BorderFactory.createTitledBorder("Contador"));
			this.setLayout(new BorderLayout());

			final JButton btnStart = new JButton("Iniciar");
			this.add(btnStart, BorderLayout.NORTH);

			lbl = new JLabel("0");
			this.add(lbl, BorderLayout.CENTER);

			final JButton btnStop = new JButton("Parar");
			this.add(btnStop, BorderLayout.SOUTH);

			btnStart.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if (hiloContador == null) {
						btnStart.setEnabled(false);
						hiloContador = new Thread(MiContador.this);
						hiloContador.start();
					}
				}
			});

			btnStop.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					if (hiloContador != null) {
						hiloContador.interrupt();
						hiloContador = null;
					}
					btnStart.setEnabled(true);
				}
			});
		}

		public void run() {
			int desde = 1;
			while (!Thread.currentThread().isInterrupted()) {
				final String strNum = Integer.toString(desde);
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						lbl.setText(strNum);
					}
				});
				try {
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					return;
				}
				desde++;
			}
		}
	}

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				final Ejemplo2 v = new Ejemplo2();
				v.setVisible(true);
			}
		});

	}
}
