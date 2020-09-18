package simulator.factories;

import org.json.JSONObject;
import simulator.model.*;

public class NewInterCityRoadEventBuilder extends Builder<Event> {

	private int time;
	private String id;
	private String srcJunction;
	private String destJunction;
	private int longitud;
	private int limiteCO2;
	private int velocMaxima;
	private Weather clima;

	public NewInterCityRoadEventBuilder() {
	
		super("new_inter_city_road");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
		
		time = data.getInt("time");
		id = data.getString("id");
		srcJunction = data.getString("src");
		destJunction = data.getString("dest");
		longitud = data.getInt("length");
		limiteCO2 = data.getInt("co2limit");
		velocMaxima = data.getInt("maxspeed");
		clima = Weather.valueOf(data.getString("weather"));
		
		return new NewInterCityRoadEvent(time, id, srcJunction, destJunction, longitud, limiteCO2, velocMaxima, clima);
	}
}