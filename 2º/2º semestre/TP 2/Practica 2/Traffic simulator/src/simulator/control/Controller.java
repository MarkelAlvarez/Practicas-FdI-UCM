package simulator.control;

import java.io.*;
import org.json.*;
import simulator.factories.*;
import simulator.model.*;

public class Controller implements Observable<TrafficSimObserver> {

	private TrafficSimulator sim;
	private Factory<Event> eventosFact;
	
	public Controller(TrafficSimulator sim, Factory<Event> eventsFactory) {
		
		if (sim == null) {throw new IllegalArgumentException("El valor \"traffic simulator\" no pueden ser null.");}
		if (eventsFactory == null) {throw new IllegalArgumentException("El valor \"events factory\" no pueden ser null.");}
		
		this.sim = sim;
		this.eventosFact = eventsFactory;
	}
	
	public void loadEvents(InputStream in) {
		
		JSONObject jo = new JSONObject(new JSONTokener(in));
		JSONArray array = jo.getJSONArray("events");
		
		if (!jo.has("events"))
		{
			throw new IllegalArgumentException("JSONObject tag in Controller.java loadEvents should be \"events\".");
		}
		
		for (int i = 0; i < array.length(); i++)
		{
			sim.addEvent(eventosFact.createInstance(array.getJSONObject(i)));
		}
	}
	
	public void run(int n, OutputStream out) throws InterruptedException {
		
		if(out != null)
		{
			JSONObject salida = new JSONObject();
			JSONArray array = new JSONArray();
			
			for (int i = 0; i < n; i++) 
			{
				sim.advance();
				array.put(sim.report());
			}
			salida.put("states", array);
			
			PrintStream p = new PrintStream(out);
			p.println(salida.toString());
		}
		else
		{
			for (int i = 0; i < n; i++) 
			{
				sim.advance();
				Thread.sleep(30);
			}
		}
	}
	
	/*public void run(int n, OutputStream out) {
		
		PrintStream salida = new PrintStream(out);
		salida.println("{");
		salida.println("\"states\" : [");
		
		for (int i = 0; i < n; i++)
		{
			sim.advance();
			salida.print(sim.report().toString());
			if (i < n)
			{
				salida.println(",");
			}
		}
		
		salida.println("]");
		salida.println("}");
	}*/
	
	public void reset() {

		sim.reset();
	}

	public void addEvent(Event e) {
		
		sim.addEvent(e);
	}
	
	@Override
	public void addObserver(TrafficSimObserver o) {
		
		sim.addObserver(o);
	}

	@Override
	public void removeObserver(TrafficSimObserver o) {
	
		sim.removeObserver(o);	
	}
}