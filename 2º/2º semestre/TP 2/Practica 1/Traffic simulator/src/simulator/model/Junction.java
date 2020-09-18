package simulator.model;

import java.util.*;

import org.json.JSONArray;
import org.json.JSONObject;

public class Junction extends SimulatedObject {

	private List<Road> listaEntrantes;
	private Map<Junction,Road> mapaSalientes;
	private List<List<Vehicle >> listaColas;
	private Map<Road,List<Vehicle>> carretera_cola;
	private int indiceVerde;
	private int pasoSemaforo = 1;
	private LightSwitchingStrategy estratSem;
	private DequeuingStrategy estratCola;
	private int x;
	private int y;
	private String id;
	
	protected Junction(String id, LightSwitchingStrategy lsStrategy, DequeuingStrategy dqStrategy, int xCoor, int yCoor) {
		
		super(id);
		
		if(lsStrategy == null && dqStrategy == null) throw new IllegalArgumentException("Ninguna de las estrategias no pueden ser null.");
		if((xCoor < 0) || (yCoor < 0)) throw new IllegalArgumentException("Las coordenadas deben tener un valor positivo mayor que 0.");
		
		this.id = id;
		estratSem = lsStrategy;
		estratCola = dqStrategy;
		x = xCoor;
		y = yCoor;
		
		mapaSalientes = new HashMap<Junction, Road>();
		listaEntrantes = new ArrayList<Road>();
		listaColas = new ArrayList<List<Vehicle>>();
		carretera_cola = new HashMap<Road, List<Vehicle>>();
	}

	void addIncommingRoad(Road r) {
		
		if(!this.equals(r.getCruceDestino()))
		{
			throw new IllegalArgumentException("No existe el cruce.");
		}
		
		listaEntrantes.add(r);
		List<Vehicle> aux_r = new LinkedList<Vehicle>();
		listaColas.add(aux_r);
		carretera_cola.put(r, aux_r);
	}
	
	void addOutGoingRoad(Road r) {
		
		if(!this.equals(r.getCruceOrigen()))
		{
			throw new IllegalArgumentException("No existe el cruce.");
		}
		if(mapaSalientes.get(r.getCruceDestino()) != null)
		{
			throw new IllegalArgumentException("Hay m�s de un cruce.");
		}
		
		mapaSalientes.put(r.getCruceDestino(), r);
	}
	
	void enter(Vehicle v) {
		
		Road r = v.getCarretera();
		List<Vehicle> q = carretera_cola.get(r);
		q.add(v);
	}
	
	Road roadTo(Junction j) {
		
		return mapaSalientes.get(j);
	}
	
	@Override
	void advance(int time) {
		
		int next;
		
		if (indiceVerde != -1 && !listaColas.isEmpty())
		{	
			List<Vehicle> q = listaColas.get(indiceVerde);
			List<Vehicle> pasan = estratCola.dequeue(q);
		
			for (Vehicle v : pasan)
			{
				v.moveToNextRoad();
				q.remove(v);
			}
		}
		
		next = estratSem.chooseNextGreen(listaEntrantes, listaColas, indiceVerde, pasoSemaforo, time);
		if (next != indiceVerde)
		{
			indiceVerde = next;
			pasoSemaforo = time;
		}
	}

	@Override
	public JSONObject report() {

		JSONObject json = new JSONObject();
		
		json.put("id", id);
		
		if (indiceVerde == -1)
		{
			json.put("green", "none");
		}
		else
		{
			json.put("green", listaEntrantes.get(indiceVerde).getId());
		}
		
		JSONArray jArray = new JSONArray();
		json.put("queues", jArray);
		/* Estos son los de dentro de "queues" */
		for (Road roads : listaEntrantes)
		{
			JSONObject jsonCarreteras = new JSONObject();
			jArray.put(jsonCarreteras);
			jsonCarreteras.put("road", roads.getId());
			
			JSONArray jArray2 = new JSONArray();
			jsonCarreteras.put("vehicles", jArray2);
			for (Vehicle v : carretera_cola.get(roads))
			{
				jArray2.put(v.getId());
			}
		}
		
		return json;
	}
	
	/*GETS Y SETS*/
	
	@Override
	public String getId() {
		
		return id;
	}

	public void setId(String id) {
		
		this.id = id;
	}
}