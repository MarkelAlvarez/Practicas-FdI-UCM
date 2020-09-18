package simulator.factories;

import org.json.JSONObject;
import simulator.model.*;

public class MoveFirstStrategyBuilder extends Builder<DequeuingStrategy> {

	public MoveFirstStrategyBuilder() {
	
		super("move_first_dqs");
	}

	@Override
	protected DequeuingStrategy createTheInstance(JSONObject data) {
	
		return new MoveFirstStrategy();
	}
}