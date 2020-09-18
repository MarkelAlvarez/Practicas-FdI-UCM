package ejemploJTablePR5;

import java.util.List;

import javax.swing.table.AbstractTableModel;

public class EventsTableModel extends AbstractTableModel {
	private static final long serialVersionUID = 1L;

	private List<EventsPrueba> _events;
	private String[] _colNames = { "número", "tiempo", "prioridad" };

	public void setEventsList(List<EventsPrueba> events) {
		_events = events;
		// observar que si no refresco la tabla no se carga
		fireTableStructureChanged();
	}

	@Override
	public boolean isCellEditable(int row, int column) {
		return false;
	}

	@Override
	public String getColumnName(int col) {
		return _colNames[col];
	}

	@Override
	public int getColumnCount() {
		return _colNames.length;
	}

	@Override
	public int getRowCount() {
		return _events == null ? 0 : _events.size();
	}

	// asi es como se va a cargar la tabla desde el ArrayList
	@Override
	public Object getValueAt(int rowIndex, int columnIndex) {
		Object s = null;
		switch (columnIndex) {
		case 0:
			s = rowIndex;
			break;
		case 1:
			s = _events.get(rowIndex).getTime();
			break;
		case 2:
			s = _events.get(rowIndex).getPrioridad();
			break;
		}

		return s;
	}

	public void refresh() {
		fireTableDataChanged();
	}

}
