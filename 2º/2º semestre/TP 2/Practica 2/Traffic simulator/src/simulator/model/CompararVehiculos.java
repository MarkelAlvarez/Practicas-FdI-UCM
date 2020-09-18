package simulator.model;

import java.util.Comparator;

public class CompararVehiculos implements Comparator<Vehicle>{

	public CompararVehiculos() {
	}

	@Override
	public int compare(Vehicle o1, Vehicle o2) {
		
		if(o1.getLocalizacion() < o2.getLocalizacion())
		{
			return 1;
		}
		else if(o1.getLocalizacion() > o2.getLocalizacion())
		{
			return -1;
		}
		
		return 0;
	}
}