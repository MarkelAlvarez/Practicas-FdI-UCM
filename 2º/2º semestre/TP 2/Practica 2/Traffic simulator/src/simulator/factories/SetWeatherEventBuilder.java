package simulator.factories;

import java.util.ArrayList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.misc.Pair;
import simulator.model.*;

public class SetWeatherEventBuilder extends Builder<Event> {

	private int tiempo;
	private List<Pair<String, Weather>> lista;
	
	public SetWeatherEventBuilder() {
	
		super("set_weather");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
	
		tiempo = data.getInt("time");
		JSONArray jArray = data.getJSONArray("info");
		lista = new ArrayList<Pair<String, Weather>>();
		
		for (int i = 0; i < jArray.length(); i++)
		{
			lista.add(new Pair<String, Weather>(jArray.getJSONObject(i).getString("road"), Weather.valueOf(jArray.getJSONObject(i).getString("weather"))));
		}
		
		return new SetWeatherEvent(tiempo, lista);
	}
}