package extra.graphlayout;

public class Dot {
	private String _id;
	private int _location;
	
	public Dot(String id, int location) {
		_id = id;
		_location = location;
	}
	
	public String getId() {
		return _id;
	}
	
	public int getLocation() {
		return _location;
	}
	
}
