package simulator.factories;

import org.json.JSONObject;
import simulator.model.*;

public class RoundRobinStrategyBuilder extends Builder<LightSwitchingStrategy> {

	public RoundRobinStrategyBuilder() {

		super("round_robin_lss");
	}

	@Override
	protected LightSwitchingStrategy createTheInstance(JSONObject data) {
		
		RoundRobinStrategy rrs;
		
		if (data.has("timeslot"))
		{
			rrs = new RoundRobinStrategy(data.getInt("timeslot"));
		}
		else
		{
			rrs = new RoundRobinStrategy(1);
		}
		
		return rrs;
	}
}