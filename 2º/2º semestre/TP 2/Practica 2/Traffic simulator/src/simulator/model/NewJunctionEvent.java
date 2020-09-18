package simulator.model;

public class NewJunctionEvent extends Event {

	private LightSwitchingStrategy estratSem;
	private DequeuingStrategy estratCola;
	private int x;
	private int y;
	private String id;
	
	public NewJunctionEvent(int time, String id, LightSwitchingStrategy lsStrategy, DequeuingStrategy dqStrategy, int xCoor, int yCoor) {
	
		super(time);
		
		if(lsStrategy == null && dqStrategy == null) throw new IllegalArgumentException("Ninguna de las estrategias no pueden ser null.");
		if((xCoor < 0) || (yCoor < 0)) throw new IllegalArgumentException("Las coordenadas deben tener un valor positivo mayor que 0.");
		
		this.id = id;
		estratSem = lsStrategy;
		estratCola = dqStrategy;
		x = xCoor;
		y = yCoor;
	}

	@Override
	void execute(RoadMap map) {

		Junction j = new Junction(id, estratSem, estratCola, x, y);
		map.addJunction(j);
	}
	
	@Override
	public String toString() {
		
		return "New Junction '" + id + "'";
	}
}