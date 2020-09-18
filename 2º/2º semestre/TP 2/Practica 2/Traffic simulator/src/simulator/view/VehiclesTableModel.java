package simulator.view;

import java.util.ArrayList;
import java.util.List;
import javax.swing.table.AbstractTableModel;

import simulator.control.Controller;
import simulator.model.*;

public class VehiclesTableModel extends AbstractTableModel implements TrafficSimObserver {

	private List<Vehicle> _vehicle;
	private String[] _colNames = { "ID", "Estado", "Itinerario", "CO2 Class", "Max Speed", "Act. Speed", "Total CO2", "Distancia" };
	private Controller ctrl;

	public VehiclesTableModel(Controller _ctrl) {
		
		ctrl = _ctrl;
		_vehicle = new ArrayList<Vehicle>();
		ctrl.addObserver(this);
	}

	public void update() {
		// observar que si no refresco la tabla no se carga
		// La tabla es la represantación visual de una estructura de datos,
		// en este caso de un ArrayList, hay que notificar los cambios.
		// We need to notify changes, otherwise the table does not refresh.
		fireTableDataChanged();	
	}
	
	public void setVehicleList(List<Vehicle> vehicle) {
		
		_vehicle = vehicle;
		update();
	}

	@Override
	public boolean isCellEditable(int row, int column) {
		
		return false;
	}

	//si no pongo esto no coge el nombre de las columnas
	//this is for the column header
	@Override
	public String getColumnName(int col) {
		
		return _colNames[col];
	}

	@Override
	// método obligatorio, probad a quitarlo, no compila
	// this is for the number of columns
	public int getColumnCount() {
		
		return _colNames.length;
	}

	@Override
	// método obligatorio
	// the number of row, like those in the events list
	public int getRowCount() {
		
		return _vehicle == null ? 0 : _vehicle.size();
	}

	@Override
	// método obligatorio
	// así es como se va a cargar la tabla desde el ArrayList
	// el índice del arrayList es el número de fila pq en este ejemplo
	// quiero enumerarlos.
	// returns the value of a particular cell 
	public Object getValueAt(int rowIndex, int columnIndex) {
		
		Object s = null;

		switch (columnIndex)
		{
			case 0:
				s = _vehicle.get(rowIndex).getId();
				break;
			case 1:
				VehicleStatus estado = _vehicle.get(rowIndex).getEstado();
				StringBuilder texto = new StringBuilder();
				switch (estado)
				{
					case PENDING:
						texto.append("Pending");
						break;
					case WAITING:    
						texto.append("Waiting:"+ _vehicle.get(rowIndex).getDesJunction());
						break;
					case TRAVELING:  
						texto.append(_vehicle.get(rowIndex).getCarretera() + ": " + _vehicle.get(rowIndex).getLocalizacion());
						break;
					case ARRIVED:    
						texto.append("Arrived");
						break;
				}
				s = texto.toString();
				break;
			case 2:
				s = _vehicle.get(rowIndex).getItinerario();
				break;
			case 3:
				s = _vehicle.get(rowIndex).getGradoCont();
				break;
			case 4:
				s = _vehicle.get(rowIndex).getVelocMaxima();
				break;
			case 5:
				s = _vehicle.get(rowIndex).getVelocActual();
				break;
			case 6:
				s = _vehicle.get(rowIndex).getContTotal();
				break;
			case 7:
				s = _vehicle.get(rowIndex).getDistTotRec();
				break;
			default:
				break;
		}
		
		return s;
	}
	
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		
		setVehicleList(map.getVehicles());
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		
		setVehicleList(map.getVehicles());
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		
		setVehicleList(map.getVehicles());
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		
		setVehicleList(map.getVehicles());
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		
		setVehicleList(map.getVehicles());
	}

	@Override
	public void onError(String err) {
	}
}