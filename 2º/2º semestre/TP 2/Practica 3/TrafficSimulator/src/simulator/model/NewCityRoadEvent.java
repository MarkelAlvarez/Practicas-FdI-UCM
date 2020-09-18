package simulator.model;

public class NewCityRoadEvent extends Event {

	private String id;
	private String srcJunction;
	private String destJunction;
	private int longitud;
	private int limiteCO2;
	private int velocMaxima;
	private Weather clima;
	
	public NewCityRoadEvent(int time, String id, String srcJun, String destJunc, int length, int co2Limit, int maxSpeed, Weather weather) {
	
		super(time);
		
		if(time < 0) throw new IllegalArgumentException("El tiempo no puede ser negativo.");
		if(srcJun == null) throw new IllegalArgumentException("El cruce de origen no puede ser nulo.");
		if(destJunc == null) throw new IllegalArgumentException("El cruce de destino no puede ser nulo.");
		if(length < 0) throw new IllegalArgumentException("La longitud no puede ser negativa");
		if(co2Limit < 0) throw new IllegalArgumentException("El limite de contaminacion no puede ser negativo.");
		if(maxSpeed <= 0) throw new IllegalArgumentException("La velocidad maxima tiene que ser un numero positivo.");
		if(weather == null) throw new IllegalArgumentException("La condicion meteorologica no puede ser nula.");
		
		this.id = id;
		srcJunction = srcJun;
		destJunction = destJunc;
		longitud = length;
		limiteCO2 = co2Limit;
		velocMaxima = maxSpeed;
		clima = weather;
	}

	@Override
	void execute(RoadMap map) {
		
		Road r = new CityRoad(id, map.getJunction(srcJunction), map.getJunction(destJunction), velocMaxima, limiteCO2, longitud, clima);
		map.addRoad(r);
	}
	
	@Override
	public String toString() {
		
		return "New City Road '" + id + "'";
	}
}