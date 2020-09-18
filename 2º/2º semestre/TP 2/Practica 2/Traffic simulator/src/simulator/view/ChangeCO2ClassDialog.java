package simulator.view;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;

import simulator.model.RoadMap;
import simulator.model.Vehicle;

public class ChangeCO2ClassDialog extends JDialog {

	private JPanel emergente;
	private JLabel texto;
	private JLabel textoVehicle;
	private JComboBox<Vehicle> vehicle;
	private JLabel textoCO2;
	private JComboBox<Integer> co2;
	private JLabel textoTicks;
	private JSpinner ticks;
	
	private JPanel botones;
	private JPanel opciones;
	private JButton ok;
	private JButton cancel;

	private int estado = 0;
	private DefaultComboBoxModel<Vehicle> vehicleModel;
	private DefaultComboBoxModel<Integer> co2Model;

	public ChangeCO2ClassDialog(Frame padre) {
		
		super(padre, true);
		initGUI();
	}

	private void initGUI() {
		
		setTitle("Change CO2 Class");
		
		emergente = new JPanel();
		emergente.setLayout(new BoxLayout(emergente, BoxLayout.Y_AXIS));
		setContentPane(emergente);
		
		texto = new JLabel("<html>Schedule an event to change the CO2 class of a vehicle after a given number of<br>simulation ticks form now.</html>");
		texto.setAlignmentX(CENTER_ALIGNMENT);
		emergente.add(texto);
		emergente.add(Box.createRigidArea(new Dimension(0, 20)));		
	
		botones = new JPanel();
		botones.setAlignmentX(CENTER_ALIGNMENT);
		emergente.add(botones);
		
		textoVehicle = new JLabel("Vehicle: ", JLabel.CENTER);
		vehicleModel = new DefaultComboBoxModel<Vehicle>();
		vehicle = new JComboBox<Vehicle>(vehicleModel);
		vehicle.setVisible(true);
		botones.add(textoVehicle);
		botones.add(vehicle);
		
		textoCO2 = new JLabel("CO2 Class: ", JLabel.CENTER);
		co2Model = new DefaultComboBoxModel<Integer>();
		co2 = new JComboBox<Integer>(co2Model);
		co2.setVisible(true);
		botones.add(textoCO2);
		botones.add(co2);
		
		ticks = new JSpinner();
		textoTicks = new JLabel("Ticks: ", JLabel.CENTER);
		ticks = new JSpinner(new SpinnerNumberModel(10, 1, 99999, 1));
		ticks.setMinimumSize(new Dimension(80, 30));
		ticks.setMaximumSize(new Dimension(200, 30));
		ticks.setPreferredSize(new Dimension(80, 30));
		
		botones.add(textoTicks);
		botones.add(ticks);
		
		opciones = new JPanel();
		opciones.setAlignmentX(CENTER_ALIGNMENT);
		emergente.add(opciones);
		
		cancel = new JButton("Cancel");
		cancel.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				estado = 0;
				ChangeCO2ClassDialog.this.setVisible(false);
			}
		});
		opciones.add(cancel);

		ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				if ((vehicleModel.getSelectedItem() != null) && (co2Model.getSelectedItem() != null))
				{
					estado = 1;
					ChangeCO2ClassDialog.this.setVisible(false);
				}
			}
		});
		opciones.add(ok);

		setPreferredSize(new Dimension(500, 200));
		pack();
		setResizable(false);
		setVisible(false);
	}
	
	public int open(RoadMap mapa) {
		
		for (Vehicle v : mapa.getVehicles())
		{
			vehicleModel.addElement(v);
		}
		for (int i = 0; i < 11; i++)
		{
			co2Model.addElement(i);
		}
		
		setLocation(getParent().getLocation().x + 10, getParent().getLocation().y + 10);
		setVisible(true);
		
		return estado;
	}

	public Integer getTicks() {
		
		return (Integer) ticks.getValue();
	}

	public Integer getCO2Class() {
		
		return (Integer) co2Model.getSelectedItem();
	}
	
	public Vehicle getVehicle() {
		
		return (Vehicle) vehicleModel.getSelectedItem();
	}
}