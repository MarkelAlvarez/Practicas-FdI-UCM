package simulator.model;

import java.util.List;
import org.json.JSONObject;

import simulator.misc.SortedArrayList;

public class TrafficSimulator {

	private RoadMap mapaCarreteras;
	private List<Event> listaEventos;
	private int time;
	
	public TrafficSimulator() {

		listaEventos = new SortedArrayList<Event>();
		mapaCarreteras = new RoadMap();
		time = 0;
	}
	
	public void addEvent(Event e) {
		
		listaEventos.add(e);
	}
	
	public void advance() {
		
		time++;
		
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
	}
	
	public void reset() {
		
		mapaCarreteras.reset();
		listaEventos.clear();
		time = 0;
	}
	
	public JSONObject report() {
		
		JSONObject json = new JSONObject();
		
		json.put("time", time);
		json.put("state", mapaCarreteras.report());
		
		return json;
	}
}