package simulator.factories;

import org.json.JSONObject;
import simulator.model.*;

public class MostCrowdedStrategyBuilder extends Builder<LightSwitchingStrategy> {

	public MostCrowdedStrategyBuilder() {
	
		super("most_crowded_lss");
	}

	@Override
	protected LightSwitchingStrategy createTheInstance(JSONObject data) {

		MostCrowdedStrategy mcs;
		
		if (data.has("timeslot"))
		{
			mcs = new MostCrowdedStrategy(data.getInt("timeslot"));
		}
		else
		{
			mcs = new MostCrowdedStrategy(1);
		}
		
		return mcs;
	}
}