package extra.jtable;

public class EventEx {

	private Integer _time; //tiempo en el que se produce el evento
	private Integer _priority; //respecto de otros eventos
	
	public EventEx(Integer time, Integer prioridad) {
		
		_time = time;
		_priority = prioridad;	
	}

	public int getTime() {
		
		return _time;
	}

	public int getPriority() {
		
		return _priority;
	}	
}