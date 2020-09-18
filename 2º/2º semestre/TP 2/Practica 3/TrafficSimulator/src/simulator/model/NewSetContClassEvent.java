package simulator.model;

import java.util.*;
import simulator.misc.Pair;

public class NewSetContClassEvent extends Event {

	private List<Pair<String,Integer>> cont;
	
	public NewSetContClassEvent(int time, List<Pair<String,Integer>> cs) {
		
		super(time);
		
		if(cs == null) throw new IllegalArgumentException("La lista no puede estar vacia.");
		
		cont = cs;
	}

	@Override
	void execute(RoadMap map) {
		
		for (Pair<String, Integer> c : cont)
		{
			if(map.getVehicle(c.getFirst()) == null)
			{
				throw new IllegalArgumentException("El vehiculo con id " + c.getFirst() + " no existe.");
			}
			map.getVehicle(c.getFirst()).setContaminationClass(c.getSecond());
		}
	}
	
	@Override
	public String toString() {
		
		return "Event added (Change CO2 Class [(" + cont.get(0).getFirst() + ", " + cont.get(0).getSecond() + ")])";
	}
}