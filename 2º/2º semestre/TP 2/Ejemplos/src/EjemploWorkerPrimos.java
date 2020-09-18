import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;
import java.util.concurrent.CancellationException;
import java.util.concurrent.ExecutionException;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JProgressBar;
import javax.swing.SwingUtilities;
import javax.swing.SwingWorker;

// Ejemplo de Swing Worker
public class EjemploWorkerPrimos extends JFrame implements ActionListener {
	public final static int NUM = 5000000;
	private JProgressBar pb1;
	private JProgressBar pb2;
	private JProgressBar pb3;
	JButton btnStart;
	HebraPrimosWorker hebra1;
	HebraPrimosWorker hebra2;
	HebraPrimosWorker hebra3;
	private volatile int hebrasPendientes;
	
	public EjemploWorkerPrimos() {
		super("Ejemplo de SwingWorker");
		this.getContentPane().setLayout(new GridLayout(4,1,5,5));
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		pb1 = new JProgressBar(0,100);
		pb1.setFont(new Font("Dialog",Font.PLAIN,28));
		pb1.setStringPainted(true);
		
		pb2 = new JProgressBar(0,100);
		pb2.setFont(new Font("Dialog",Font.PLAIN,28));
		pb2.setStringPainted(true);
		
		pb3 = new JProgressBar(0,100);
		pb3.setFont(new Font("Dialog",Font.PLAIN,28));
		pb3.setStringPainted(true);
		
		btnStart = new JButton("Empezar");
		btnStart.setFont(new Font("Dialog",Font.PLAIN,28));
		
		this.getContentPane().add(pb1);
		this.getContentPane().add(pb2);
		this.getContentPane().add(pb3);
		this.getContentPane().add(btnStart);
		this.setSize(500, 200);
		
		btnStart.addActionListener(this);
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		
		if (hebrasPendientes == 0)
		{
			hebrasPendientes = 3;
			hebra1 = new HebraPrimosWorker(pb1,1,NUM);
			hebra2 = new HebraPrimosWorker(pb2,NUM+1,2*NUM);
			hebra3 = new HebraPrimosWorker(pb3,2*NUM+1,3*NUM);
			hebra1.execute();
			hebra2.execute();
			hebra3.execute();
		}
		else
		{
			JOptionPane.showMessageDialog(this, "Todavía hay workers haciendo cosas", "¡Oops!", JOptionPane.INFORMATION_MESSAGE);
		}
	}

	public static void main(String[] args) throws InterruptedException {
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				EjemploWorkerPrimos v = new EjemploWorkerPrimos();
				v.setVisible(true);
			}
		});
	}
	
	
	
	public class HebraPrimosWorker extends SwingWorker<Integer,Integer> {
		private int desde;
		private int hasta;
		private JProgressBar pb;

	    public HebraPrimosWorker(JProgressBar pb, int desde, int hasta) {
			this.pb = pb;
			this.desde = desde;
			this.hasta = hasta;
		}

		@Override
		protected Integer doInBackground() throws Exception {
			int ultimo = 0;
			for (int i = desde; i < hasta; i++) {
			    if (esPrimo(i)) {
			    	//System.out.println("Primo: "+i);
			    	ultimo = i;
			    }
			    if ((i-desde) % (NUM/100) == 0)
			    	publish(100*(i-desde)/NUM + 1);
			}			
			return ultimo;
		}
		
		@Override
		protected void process(List<Integer> porcentajes) {
			int ultimo = porcentajes.get(porcentajes.size()-1);
			pb.setString(Integer.toString(ultimo)+ " %");
			pb.setValue(ultimo);
		}
		
		@Override
	    public void done() {
			try {
				Integer ultimo = get();
				pb.setString("El último primo es " + ultimo);
				EjemploWorkerPrimos.this.hebrasPendientes--;
			} catch (CancellationException | InterruptedException | ExecutionException e) {
				pb.setString("Error!");
			}
		}
		
		private boolean esPrimo(int n) {
			if (n <= 3) { 
				return true;
			} else {
				if (n % 2 == 0) {
					return false;
				} else {
					boolean primo = true;
					for (int i = 3; i*i < n && primo; i += 2)
						if (n % i == 0) primo = false;
					return primo;
				}
			}
		}

	}


}
