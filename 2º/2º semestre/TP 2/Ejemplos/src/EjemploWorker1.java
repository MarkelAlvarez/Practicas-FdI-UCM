// Ejemplo sencillo de Swing Worker.

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;

public class EjemploWorker1 extends JFrame {
	public EjemploWorker1() {
		super("Ejemplo de SwingWorker");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setSize(200, 100);
		
		JButton btnStart = new JButton("Empezar a contar");
		this.getContentPane().add(btnStart, BorderLayout.CENTER);
		btnStart.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				new MiWorker().execute();
			}
		});
	}
	
	public static class MiWorker extends SwingWorker<Void,Void> {
		@Override
		protected Void doInBackground() throws Exception {
			for (int i = 1; i < 100; i++) {
				System.out.print(Integer.toString(i) + " ");
				Thread.sleep(500);
			}			
			return null;
		}
	}
	
	public static void main(String[] args) throws InterruptedException {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploWorker1 v = new EjemploWorker1();
				v.setVisible(true);
			}
		});
	}
}
