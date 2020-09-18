package extra.jtable;

import java.util.List;
import javax.swing.table.AbstractTableModel;

public class EventsTableModel extends AbstractTableModel {

	private static final long serialVersionUID = 1L;
	
	private List<EventEx> _events;
	private String[] _colNames = { "#", "Time", "Priority" };

	public EventsTableModel() {
		
		_events=null;
	}

	public void update() {
		// observar que si no refresco la tabla no se carga
		// La tabla es la represantación visual de una estructura de datos,
		// en este caso de un ArrayList, hay que notificar los cambios.
		// We need to notify changes, otherwise the table does not refresh.
		fireTableDataChanged();;		
	}
	
	public void setEventsList(List<EventEx> events) {
		
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
				s = rowIndex;
				break;
			case 1:
				s = _events.get(rowIndex).getTime();
				break;
			case 2:
				s = _events.get(rowIndex).getPriority();
				break;
		}
		
		return s;
	}
}