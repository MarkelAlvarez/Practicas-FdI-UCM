package simulator.model;

import org.json.JSONObject;
import java.util.*;

public class Vehicle extends SimulatedObject {

	private List<Junction> itinerario;
	private int velocMaxima;
	private int velocActual;
	private VehicleStatus estado;
	private Road carretera = null;
	private int localizacion = 0;
	private int gradoCont;
	private int contTotal;
	private int distTotRec = 0;
	private String id;
	private int ultimoCruce;
	private Junction srcJunction = null;
	private Junction desJunction = null;
	
	Vehicle(String id, int maxSpeed, int contClass, List<Junction> itinerary) {
		
		super(id);
		
		if(maxSpeed <= 0) throw new IllegalArgumentException("La velocidad maxima tiene que ser un numero positivo.");
		if(contClass < 0 || contClass > 10) throw new IllegalArgumentException("El grado de contaminacion tiene que tener un valor entre 0 y 10.");
		if(itinerary.size() < 2) throw new IllegalArgumentException("El itinerario tiene que tener al menos dos elementos.");
	
		this.id = id;
		velocMaxima = maxSpeed;
		gradoCont = contClass;
		itinerario = Collections.unmodifiableList(new ArrayList<>(itinerary));
		ultimoCruce = 0;
		estado = VehicleStatus.PENDING;
	}
	
	@Override
	void advance(int time) {
		
		int locNueva = 0, contProd = 0;
		
		if(estado == VehicleStatus.TRAVELING) 
		{	
			locNueva = localizacion + velocActual;
			
			if(locNueva > carretera.getLongitud())
			{
				locNueva = carretera.getLongitud();
			}
			
			contProd = gradoCont * (locNueva - localizacion);
			distTotRec += (locNueva - localizacion);
			contTotal += contProd;
			carretera.addContamination(contProd);
			localizacion = locNueva;
			
			if(localizacion == carretera.getLongitud())
			{
				carretera.getCruceDestino().enter(this);
				estado = VehicleStatus.WAITING;
				velocActual = 0;
				ultimoCruce++;
			}
		}
		else
		{
			velocActual = 0;
		}
	}

	/**
	 * Mueve el veh�culo a la siguiente carretera. Este proceso se hace 
	 * saliendo de la carretera actual y entrando a la siguiente carretera
	 * de su itinerario, en la localizaci�n 0.
	 */
	void moveToNextRoad() {
		
		if(estado != VehicleStatus.PENDING && estado != VehicleStatus.WAITING)
		{
			throw new IllegalArgumentException("Estado erroneo para moverse a otra carretera.");
		}
		
		if(carretera != null)
		{
			carretera.exit(this);
		}
	
		if(ultimoCruce == itinerario.size() - 1)
		{
			carretera = null;
			estado = VehicleStatus.ARRIVED;
			localizacion = 0;
		}
		else
		{
			srcJunction = itinerario.get(ultimoCruce);
			desJunction = itinerario.get(ultimoCruce + 1);
			localizacion = 0;
			Road sigCarretera = srcJunction.roadTo(desJunction);
			sigCarretera.enter(this);
			carretera = sigCarretera;
			estado = VehicleStatus.TRAVELING;		
		}
	}
	
	/**
	 * Devuelve el estado del veh�culo en formato JSON.
	 */
	@Override
	public JSONObject report() {

		JSONObject json = new JSONObject();
		
		json.put("id", id);
		json.put("speed", velocActual);
		json.put("distance", distTotRec);
		json.put("co2", contTotal);
		json.put("class", gradoCont);
		json.put("status", estado);
		
		if (estado != VehicleStatus.PENDING && estado != VehicleStatus.ARRIVED)
		{
			json.put("road", carretera);
			json.put("location", localizacion);
		}		
		
		return json;
	}
	
	/*GETS & SETS*/
	
	/**
	 * Pone la velocidad actual al valor m�nimo entre s y la velocidad
	 * m�xima del veh�culo. Lanza una excepci�n si s es negativo.
	 * 
	 * @param s
	 */
	void setSpeed(int s) {
		
		if (s < 0)
		{
			throw new IllegalArgumentException("La velocidad debe ser positiva.");
		}
		
		if (s <= velocMaxima)
		{
			velocActual = s;
		}
		else
		{
			velocActual = velocMaxima;
		}
	}
	
	/**
	 * Pone el valor de contaminaci�n del veh�culo a 'c'. Lanza una 
	 * excepci�n si 'c' no es un valor entre 0 y 10 (ambos incluidos).
	 * 
	 * @param c
	 */
	void setContaminationClass(int c) {
		
		if (gradoCont < 0 || gradoCont > 10)
		{
			throw new IllegalArgumentException("El valor de contaminaci�n debe se entre 0 y 10 (ambos inclusive).");
		}
		
		gradoCont = c;
	}

	public int getGradoCont() {
		
		return gradoCont;
	}

	public int getLocalizacion() {
		
		return localizacion;
	}

	public int getVelocActual() {
		
		return velocActual;
	}
	
	@Override
	public String getId() {
		
		return id;
	}

	public void setId(String id) {
		
		this.id = id;
	}
	
	public List<Junction> getItinerario() {
		return itinerario;
	}

	public void setItinerario(List<Junction> itinerario) {
		this.itinerario = itinerario;
	}

	public int getContTotal() {
		
		return contTotal;
	}

	public void setContTotal(int contTotal) {
		
		this.contTotal = contTotal;
	}
	
	public VehicleStatus getEstado() {
		return estado;
	}

	public void setEstado(VehicleStatus estado) {
		this.estado = estado;
	}

	public Road getCarretera() {
		return carretera;
	}

	public void setCarretera(Road carretera) {
		this.carretera = carretera;
	}

	public int getVelocMaxima() {
		return velocMaxima;
	}

	public int getDistTotRec() {
		return distTotRec;
	}

	public Junction getDesJunction() {
		return desJunction;
	}
}