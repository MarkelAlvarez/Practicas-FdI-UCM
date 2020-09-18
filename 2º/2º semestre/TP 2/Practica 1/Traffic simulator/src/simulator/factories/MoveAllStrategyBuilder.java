package simulator.factories;

import org.json.JSONObject;
import simulator.model.*;

public class MoveAllStrategyBuilder extends Builder<DequeuingStrategy> {

	public MoveAllStrategyBuilder() {
	
		super("most_all_dqs");
	}

	@Override
	protected DequeuingStrategy createTheInstance(JSONObject data) {
	
		return new MoveAllStrategy();
	}
}