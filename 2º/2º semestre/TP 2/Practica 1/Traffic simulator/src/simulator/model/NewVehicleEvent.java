package simulator.model;

import java.util.ArrayList;
import java.util.List;

public class NewVehicleEvent extends Event {

	private int time;
	private String id;
	private int gradoCont;
	private int velocMaxima;
	private List<String> itinerario;
	
	public NewVehicleEvent(int time, String id, int maxSpeed, int contClass, List<String> itinerary) {

		super(time);
		
		if(time < 0) throw new IllegalArgumentException("El tiempo no puede ser negativo.");
		if(maxSpeed < 0) throw new IllegalArgumentException("La velocidad maxima tiene que ser un numero positivo.");
		if(contClass < 0 || contClass > 10) throw new IllegalArgumentException("El grado de contaminacion tiene que tener un valor entre 0 y 10.");
		//if(itinerary.size() < 2) throw new IllegalArgumentException("El itinerario tiene que tener al menos dos elementos.");
		
		this.time = time;
		this.id = id;
		velocMaxima = maxSpeed;
		gradoCont = contClass;
		itinerario = itinerary;
	}

	@Override
	void execute(RoadMap map) {
		
		List<Junction> lista_pocha = new ArrayList<Junction>();
		
		for (String string: itinerario)
		{
			lista_pocha.add(map.getJunction(string));
		}
		Vehicle v = new Vehicle(id, velocMaxima, gradoCont, lista_pocha);
		map.addVehicle(v);
		v.moveToNextRoad();
	}
}