package simulator.view;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import simulator.model.*;

public class ChangeWeatherDialog extends JDialog {
	
	private JPanel emergente;
	private JLabel texto;
	private JLabel textoRoad;
	private JComboBox<Road> road;
	private JLabel textoWeather;
	private JComboBox<Weather> weather;
	private JLabel textoTicks;
	private JSpinner ticks;
		
	private JPanel botones;
	private JPanel opciones;
	private JButton ok;
	private JButton cancel;

	private int estado = 0;
	private DefaultComboBoxModel<Road> roadModel;
	private DefaultComboBoxModel<Weather> weatherModel;

	public ChangeWeatherDialog(Frame padre) {
		
		super(padre, true);
		initGUI();
	}

	private void initGUI() {
	
		setTitle("Change Road Weather");
			
		emergente = new JPanel();
		emergente.setLayout(new BoxLayout(emergente, BoxLayout.Y_AXIS));
		setContentPane(emergente);
			
		texto = new JLabel("<html>Schedule an event to change the weather class of a road after a given number of<br>simulation ticks form now.</html>");
		texto.setAlignmentX(CENTER_ALIGNMENT);
		emergente.add(texto);
		emergente.add(Box.createRigidArea(new Dimension(0, 20)));		
		
		botones = new JPanel();
		botones.setAlignmentX(CENTER_ALIGNMENT);
		emergente.add(botones);
			
		textoRoad = new JLabel("Road: ", JLabel.CENTER);
		roadModel = new DefaultComboBoxModel<Road>();
		road = new JComboBox<Road>(roadModel);
		road.setVisible(true);
		botones.add(textoRoad);
		botones.add(road);
			
		textoWeather = new JLabel("CO2 Class: ", JLabel.CENTER);
		weatherModel = new DefaultComboBoxModel<Weather>();
		weather = new JComboBox<Weather>(weatherModel);
		weather.setVisible(true);
		botones.add(textoWeather);
		botones.add(weather);
			
		ticks = new JSpinner();
		textoTicks = new JLabel("Ticks: ", JLabel.CENTER);
		ticks = new JSpinner(new SpinnerNumberModel(10, 1, 300, 1));
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
				ChangeWeatherDialog.this.setVisible(false);	
			}
		});
		opciones.add(cancel);

		ok = new JButton("OK");
		ok.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				if ((weatherModel.getSelectedItem() != null) && (roadModel.getSelectedItem() != null))
				{
					estado = 1;
					ChangeWeatherDialog.this.setVisible(false);
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
		
		for (Road r : mapa.getRoads())
		{
			roadModel.addElement(r);
		}
		for (Weather w : Weather.values())
		{
			weatherModel.addElement(w);
		}
		setLocation(getParent().getLocation().x + 10, getParent().getLocation().y + 10);
		setVisible(true);
			
		return estado;
	}

	public Integer getTicks() {
		
		return (Integer) ticks.getValue();
	}

	public Weather getWeather() {
			
		return (Weather) weatherModel.getSelectedItem();
	}
		
	public Road getRoad() {
		
		return (Road) roadModel.getSelectedItem();
	}
}