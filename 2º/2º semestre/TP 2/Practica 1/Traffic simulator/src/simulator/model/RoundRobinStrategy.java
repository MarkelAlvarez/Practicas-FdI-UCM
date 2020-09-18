package simulator.model;

import java.util.*;

public class RoundRobinStrategy implements LightSwitchingStrategy {
	
	private int ticksVerde;

	public RoundRobinStrategy(int timeSlot) {
		
		ticksVerde = timeSlot;
	}

	@Override
	public int chooseNextGreen(List<Road> roads, List<List<Vehicle>> qs, int currGreen, int lastSwitchingTime, int currTime) {
		
		if(roads.isEmpty())
		{
			return -1;
		}
		else if(currGreen == -1)
		{
			return 0;
		}
		else if(currTime - lastSwitchingTime < ticksVerde)
		{
			return currGreen;
		}
		
		return (currGreen+1)%roads.size();
	}
}