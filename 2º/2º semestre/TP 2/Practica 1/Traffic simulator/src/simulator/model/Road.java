package simulator.model;

import java.util.*;

import org.json.JSONArray;
import org.json.JSONObject;

public abstract class Road extends SimulatedObject {

	private Junction cruceOrigen = null;
	private Junction cruceDestino = null;
	private int longitud;
	protected int velocMaxima;
	protected int limiteActual;
	private int limiteCont;
	private Weather condMet = null;
	private int contTotal;
	private List<Vehicle> vehiculos;
	private String id;
	private CompararVehiculos cmp;

	Road(String id, Junction srcJunc, Junction destJunc, int maxSpeed, int contLimit, int length, Weather weather) {

		super(id);

		if(maxSpeed <= 0) throw new IllegalArgumentException("La velocidad maxima tiene que ser un numero positivo.");
		if(contLimit < 0) throw new IllegalArgumentException("El limite de contaminacion no puede ser negativo.");
		if(length <= 0) throw new IllegalArgumentException("La longitud tiene que ser un numero positivo.");
		if(srcJunc == null) throw new IllegalArgumentException("El cruce de origen no puede ser nulo.");
		if(destJunc == null) throw new IllegalArgumentException("El cruce de destino no puede ser nulo.");
		if(weather == null) throw new IllegalArgumentException("La condicion meteorologica no puede ser nula.");

		this.id = id;
		setCruceOrigen(srcJunc);
		setCruceDestino(destJunc);
		velocMaxima = maxSpeed;
		limiteCont = contLimit;
		longitud = length;
		condMet = weather;
		vehiculos = new ArrayList<Vehicle>();
		
		srcJunc.addOutGoingRoad(this);
		destJunc.addIncommingRoad(this);
	}

	/**
	 * Se utiliza por los vehÃ­culos para entrar a la carretera. Simplemente
	 * aÃ±ade el vehÃ­culo a la lista de vehÃ­culos de la carretera (al final).
	 * 
	 * @param v
	 */
	void enter(Vehicle v) {

		if(v.getLocalizacion() != 0) throw new IllegalArgumentException("La localizacion del vehiculo tiene que ser 0.");
		if(v.getVelocActual() != 0) throw new IllegalArgumentException("La velocidad del vehiculo tiene que ser 0.");

		vehiculos.add(v);
	}

	/**
	 * Lo utiliza un vehÃ­culo para abandonar la carretera. Simplemente
	 * elimina el vehÃ­culo de la lista de vehÃ­culos de la carretera.
	 * 
	 * @param v
	 * */
	void exit(Vehicle v) {

		vehiculos.remove(v);
	}

	/**
	 * aÃ±ade c unidades de CO2 al total de la contaminaciÃ³n de la carretera. Tiene
	 * que comprobar que c no es negativo y lanzar una excepciÃ³n en otro caso.
	 * 
	 * @param c
	 */
	void addContamination(int c) {

		if(c < 0) throw new IllegalArgumentException("La contaminacion no puede ser negativa.");

		contTotal += c;
	}

	/**
	 * Avanza el estado de la carretera de la siguiente forma:
	 * 
	 * (1) llama a reduceTotalContamination para reducir la 
	 * contaminación total, es decir, la disminución de CO2.
	 * 
	 * (2) llama a updateSpeedLimit para establecer el lÃ­mite de
	 * velocidad de la carretera en el paso de simulaciÃ³n actual.
	 * 
	 * (3) recorre la lista de vehÃ­culos (desde el primero al Ãºltimo) y,
	 * para cada vehÃ­culo:
	 *  	a) pone la velocidad del vehÃ­culo al valor devuelto por calculateVehicleSpeed. 
	 * 		b) llama al mÃ©todo advance del vehÃ­culo.
	 * 
	 * @param time
	 */
	@Override
	void advance(int time) {

		reduceTotalContamination();
		updateSpeedLimit();

		for (Vehicle vehiculo: vehiculos)
		{
			vehiculo.setSpeed(calculateVehicleSpeed(vehiculo));
			vehiculo.advance(time);
		}
		cmp = new CompararVehiculos();
		vehiculos.sort(cmp);
	}

	/**
	 * Devuelve el estado de la carretera en formato JSON
	 */
	@Override
	public JSONObject report() {

		JSONObject json = new JSONObject();
		
		json.put("id", id);
		json.put("speedlimit", limiteActual);
		json.put("weather", condMet);
		json.put("co2", contTotal);
		
		JSONArray jArray = new JSONArray();
		json.put("vehicles", jArray);
		for (Vehicle vehicle : vehiculos)
		{
			jArray.put(vehicle.getId());
		}
		
		return json;
	}

	/*GETS & SETS*/

	/**
	 * Pone las condiciones atmosfÃ©ericas de la carretera al valor w. Debe 
	 * comprobar que w no es null y lanzar una excepciÃ³n en caso contrario.
	 * 
	 * @param w
	 */
	void setWeather(Weather w) {

		if(w == null) throw new IllegalArgumentException("La condicion meteorologica no puede ser nula.");

		condMet = w;
	}

	public Weather getCondMet() {

		return condMet;
	}

	public int getLimiteCont() {
		
		return limiteCont;
	}

	public void setLimiteCont(int limiteCont) {
		
		this.limiteCont = limiteCont;
	}

	public int getLongitud() {

		return longitud;
	}

	public void setLimiteActual(int limiteActual) {
		
		this.limiteActual = limiteActual;
	}

	public int getVelocMaxima() {
		
		return velocMaxima;
	}

	public void setVelocMaxima(int velocMaxima) {
		
		this.velocMaxima = velocMaxima;
	}

	@Override
	public String getId() {
		
		return id;
	}

	public void setId(String id) {
		
		this.id = id;
	}

	public List<Vehicle> getVehiculos() {
		return vehiculos;
	}

	public void setVehiculos(List<Vehicle> vehiculos) {
		this.vehiculos = vehiculos;
	}

	public Junction getCruceDestino() {
		return cruceDestino;
	}

	public void setCruceDestino(Junction cruceDestino) {
		this.cruceDestino = cruceDestino;
	}

	public Junction getCruceOrigen() {
		return cruceOrigen;
	}

	public void setCruceOrigen(Junction cruceOrigen) {
		this.cruceOrigen = cruceOrigen;
	}

	public int getContTotal() {
		return contTotal;
	}

	public void setContTotal(int contTotal) {
		this.contTotal = contTotal;
	}

	/**
	 * MÃ©todo abstracto para reducir el total de la contaminaciÃ³n de la carretera.
	 * La implementaciÃ³n especÃ­fica la definirÃ¡n las subclases de Road.
	 */
	abstract void reduceTotalContamination();
	/**
	 * mÃ©todo abstracto para actualizar la velocidad lÃ­mite de la carretera.
	 * La implementaciÃ³n especÃ­fica la definirÃ¡n las subclases de Road.
	 */
	abstract void updateSpeedLimit();
	/**
	 * mÃ©todo abstracto para calcular la velocidad de un vehÃ­culo v.
	 * La implementaciÃ³n especÃ­fica la definirÃ¡n las subclases de Road.
	 * 
	 * @param v
	 */
	abstract int calculateVehicleSpeed(Vehicle v);
}
