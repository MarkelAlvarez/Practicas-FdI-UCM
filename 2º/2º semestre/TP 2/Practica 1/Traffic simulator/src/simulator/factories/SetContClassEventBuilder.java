package simulator.factories;

import java.util.ArrayList;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import simulator.misc.Pair;
import simulator.model.*;

public class SetContClassEventBuilder extends Builder<Event> {

	private int tiempo;
	private List<Pair<String, Integer>> lista;
	
	public SetContClassEventBuilder() {
	
		super("set_cont_class");
	}

	@Override
	protected Event createTheInstance(JSONObject data) {
	
		tiempo = data.getInt("time");
		JSONArray jArray = data.getJSONArray("info");
		lista = new ArrayList<Pair<String, Integer>>();
		
		for (int i = 0; i < jArray.length(); i++)
		{
			lista.add(new Pair<String, Integer>(jArray.getJSONObject(i).getString("vehicle"), jArray.getJSONObject(i).getInt("class")));
		}
		
		return new NewSetContClassEvent(tiempo, lista);
	}
}