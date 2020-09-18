package extra.dialog;

import java.util.List;

import javax.swing.DefaultListModel;

class MyListModel<E> extends DefaultListModel<E> {

	private static final long serialVersionUID = 1L;
	List<E> _list;

	MyListModel() {
		_list = null;
	}

	public void setList(List<E> l) {
		_list = l;
		refresh();
	}

	public E get(int index) {
		return _list.get(index);
	}

	@Override
	public E getElementAt(int index) {
		return _list.get(index);
	}

	@Override
	public int getSize() {
		return _list == null ? 0 : _list.size();
	}

	public void refresh() {
		fireContentsChanged(this, 0, _list.size());
	}

}
