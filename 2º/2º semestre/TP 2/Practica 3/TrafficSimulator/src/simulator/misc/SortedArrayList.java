package simulator.misc;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;

public class SortedArrayList<E> extends ArrayList<E> {

	private static final long serialVersionUID = 1L;
	private Comparator<E> _cmp;

	public SortedArrayList(Comparator<E> cmp) {

		super();
		_cmp = cmp;
	}

	public SortedArrayList() {

		_cmp = new Comparator<E>()
		{
			@SuppressWarnings("unchecked")
			@Override
			public int compare(E o1, E o2) {

				return ((Comparable<E>) o1).compareTo(o2);
			}
		};
	}

	@Override
	public boolean add(E e) {

		int j = size() - 1;

		/* Start from the end, and look for the first
		 * element that is smaller than or equal to e
		 */
		while (j >= 0 && _cmp.compare(get(j), e) > 0)
		{
			j--;
		}

		super.add(j + 1, e);

		return true;
	}

	@Override
	public boolean addAll(Collection<? extends E> c) {

		for (E e : c) 
		{
			add(e);
		}

		return true;
	}

	@Override
	public void add(int index, E element) {

		throw new UnsupportedOperationException("Cannot insert to a sorted list");
	}

	@Override
	public boolean addAll(int index, Collection<? extends E> c) {

		throw new UnsupportedOperationException("Cannot insert to a sorted list");
	}

	@Override
	public E set(int index, E element) {

		throw new UnsupportedOperationException("Cannot set an element in a sorted list");
	}
}