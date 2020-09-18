int mision1(int v[], int n, int k)
{
	int i, ret, sumaMaxima, sumaActual;

	while (i < n)
	{
		sumaActual += v[i];
		sumaActual += v[i-k];

		if (sumaActual > sumaMaxima)
		{
			ret = i - k +1;
			sumaMaxima = sumaActual;
		}
		i++;
	}

	return ;
}