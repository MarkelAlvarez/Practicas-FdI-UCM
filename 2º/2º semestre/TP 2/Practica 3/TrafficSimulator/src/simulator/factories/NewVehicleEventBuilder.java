package simulator.factories;

import java.util.ArrayList;
import java.util.List;

import org.json.*;
import simulator.model.*;

public class NewVehicleEventBuilder extends Builder<Event> {

	private int time;
	private String id;
	private int gradoCont;
	private int velocMaxima;
	private List<String> itinerario;
	
	public NewVehicleEventBuilder() {
	
		super("new_vehicle");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
	
		time = data.getInt("time");
		id = data.getString("id");
		velocMaxima = data.getInt("maxspeed");
		gradoCont = data.getInt("class");
		itinerario = new ArrayList<String>();
		
		JSONArray jArray = data.getJSONArray("itinerary");
		for (int i = 0; i < jArray.length(); i++)
		{
			itinerario.add(jArray.getString(i));
		}
		
		return new NewVehicleEvent(time, id, velocMaxima, gradoCont, itinerario);
	}
}