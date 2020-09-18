package simulator.model;

import java.util.*;

import simulator.misc.Pair;

public class SetWeatherEvent extends Event {
	
	private List<Pair<String,Weather>> tiempo;

	public SetWeatherEvent(int time, List<Pair<String,Weather>> ws) {
	
		super(time);
		
		if(ws == null) throw new IllegalArgumentException("La lista no puede estar vacia.");
		
		tiempo = ws;
	}

	@Override
	void execute(RoadMap map) {

		for (Pair<String, Weather> w : tiempo)
		{
			if (map.getRoad(w.getFirst()) == null)
			{
				throw new IllegalArgumentException("La carretera no existe en el mapa de carreteras.");
			}
			map.getRoad(w.getFirst()).setWeather(w.getSecond());
		}
	}
	
	@Override
	public String toString() {
		
		return "Event added (Change Weather [(" + tiempo.get(0).getFirst() + ", " + tiempo.get(0).getSecond() + ")])";
	}
}