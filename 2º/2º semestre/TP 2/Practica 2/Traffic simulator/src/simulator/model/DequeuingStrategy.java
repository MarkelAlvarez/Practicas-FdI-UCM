package simulator.model;

import java.util.*;

public interface DequeuingStrategy {
	
	List<Vehicle> dequeue(List<Vehicle> q);
}