package simulator.model;

import java.util.*;

public class MoveAllStrategy implements DequeuingStrategy {

	public MoveAllStrategy() {
	}

	@Override
	public List<Vehicle> dequeue(List<Vehicle> q) {
		
		List <Vehicle> aux = new ArrayList<Vehicle>();
		
		for (Vehicle vehicle : q)
		{
			aux.add(vehicle);
		}
	
		return aux;
	}
}