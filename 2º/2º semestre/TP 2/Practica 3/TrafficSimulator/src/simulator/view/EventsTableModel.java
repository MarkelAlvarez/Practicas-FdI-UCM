package simulator.view;

import java.util.ArrayList;
import java.util.List;

import javax.swing.SwingUtilities;
import javax.swing.table.AbstractTableModel;

import simulator.control.Controller;
import simulator.model.*;

public class EventsTableModel extends AbstractTableModel implements TrafficSimObserver {

	private List<Event> _events;
	private String[] _colNames = { "Time", "Descripción" };
	private Controller ctrl;

	public EventsTableModel(Controller _ctrl) {
		
		ctrl = _ctrl;
		_events = new ArrayList<Event>();
		ctrl.addObserver(this);
	}

	public void update() {
		// observar que si no refresco la tabla no se carga
		// La tabla es la represantación visual de una estructura de datos,
		// en este caso de un ArrayList, hay que notificar los cambios.
		// We need to notify changes, otherwise the table does not refresh.
		fireTableDataChanged();	
	}
	
	public void setEventsList(List<Event> events) {
		
		_events = events;
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
		
		return _events == null ? 0 : _events.size();
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
				s = _events.get(rowIndex).getTime();
				break;
			case 1:
				s = _events.get(rowIndex).toString();
				break;
			default:
				break;
		}
		
		return s;
	}
	
	@Override
	public void onAdvanceStart(RoadMap map, List<Event> events, int time) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setEventsList(events);
			}
		});
	}

	@Override
	public void onAdvanceEnd(RoadMap map, List<Event> events, int time) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setEventsList(events);
			}
		});
	}

	@Override
	public void onEventAdded(RoadMap map, List<Event> events, Event e, int time) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setEventsList(events);
			}
		});
	}

	@Override
	public void onReset(RoadMap map, List<Event> events, int time) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setEventsList(events);
			}
		});
	}

	@Override
	public void onRegister(RoadMap map, List<Event> events, int time) {
		
		SwingUtilities.invokeLater(new Runnable() {
			@Override
			public void run() {
				setEventsList(events);
			}
		});
	}

	@Override
	public void onError(String err) {
	}
}