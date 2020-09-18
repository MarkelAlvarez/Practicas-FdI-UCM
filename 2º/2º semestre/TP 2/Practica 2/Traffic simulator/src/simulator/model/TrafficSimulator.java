package simulator.model;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JOptionPane;

import org.json.JSONObject;

import simulator.misc.SortedArrayList;

public class TrafficSimulator implements Observable<TrafficSimObserver> {

	private RoadMap mapaCarreteras;
	private List<Event> listaEventos;
	private int time;
	private List<TrafficSimObserver> observadores;
	
	public TrafficSimulator() {

		listaEventos = new SortedArrayList<Event>();
		observadores = new ArrayList<TrafficSimObserver>();
		mapaCarreteras = new RoadMap();
		time = 0;
	}
	
	public void addEvent(Event e) {
		
		listaEventos.add(e);
		
		for (TrafficSimObserver obs : observadores)
		{
			obs.onEventAdded(mapaCarreteras, listaEventos, e, time);
		}
	}
	
	public void advance() {
		
		time++;
		
		for (TrafficSimObserver obs : observadores)
		{
			obs.onAdvanceStart(mapaCarreteras, listaEventos, time);
		}
		
		try {
			while (listaEventos.size() > 0 && listaEventos.get(0).getTime() == time)
			{
		        listaEventos.remove(0).execute(mapaCarreteras);
		    }
			
			for (Junction junction : mapaCarreteras.getJunctions())
			{
				junction.advance(time);
			}
			for (Road road : mapaCarreteras.getRoads())
			{
				road.advance(time);
			}
		} catch (Exception e) {
			for (TrafficSimObserver obs : observadores)
			{
				obs.onError(e.getMessage());
			}
			JOptionPane.showMessageDialog(null, e.getMessage());
		}
		
		for (TrafficSimObserver obs : observadores)
		{
			obs.onAdvanceEnd(mapaCarreteras, listaEventos, time);
		}
	}
	
	public void reset() {
		
		mapaCarreteras.reset();
		listaEventos.clear();
		time = 0;
		
		for (TrafficSimObserver obs : observadores)
		{
			obs.onReset(mapaCarreteras, listaEventos, time);
		}
	}
	
	public JSONObject report() {
		
		JSONObject json = new JSONObject();
		
		json.put("time", time);
		json.put("state", mapaCarreteras.report());
		
		return json;
	}

	@Override
	public void addObserver(TrafficSimObserver o) {
		
		if (!observadores.contains(o))
		{
			observadores.add(o);
		}
		o.onRegister(mapaCarreteras, listaEventos, time);
	}

	@Override
	public void removeObserver(TrafficSimObserver o) {
		
		if (observadores.contains(o))
		{
			observadores.remove(o);
		}
	}
}