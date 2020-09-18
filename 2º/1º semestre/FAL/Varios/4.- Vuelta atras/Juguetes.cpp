void asigna
		(

			//DEscripcion
			int numNiños, int numJugetes,
			int minJuguetePorNinyo,
			int edad[],
			int pegi[]//edad minima del niño por jugete
			int beneficio[MAX_NIÑOS][MAX_J],


			//Solucion Parcial
			//int asignados[], //uno por jugete
			int k,
			int satisfaccionParcial,
			int numAsignados[]//Cuantos jugetes tiene asignado el niño i

			//Marcaje
			int faltanParaMinimo,
			//Mejor solucion
			int &maxSatisfaccion
			)
{
	//caso base
	if(k == numJugetes)
	{
		if(satisfaccionParcial > maxSatisfaccion)
			maxSatisfaccion = satisfaccionParcial;
		return;
	}

	//Asignamos el jugete k a cada niño posible
	for(int i = 0; i < numNiños; i++)
	{
		//asignar el jugete k al niño i
		//¿Es prometedora?
		if(pegi[k]>edad[i])
			continue; //Salta sig iteracion
		//Si le doy otro jugete
		//¿Podran el resto de niños llegar al minJugete?

		if((numAsignados[i] >= minJuguetePorNinyomi) && (faltanParaMinimo >  numJugetes - k +1))
			continue;

		//Solucion prometedora
		if(numAsignados[i] < minJuguetePorNinyomi)
			faltanParaMinimo--;
		numAsignados[i]++;

		//Llamamos
		asigna(numNiños, numJugetes, minJuguetePorNinyomi, edad, pegi, beneficio, k+1,satisfaccionParcial + beneficio[i][k], numAsignados, faltanParaMinimo,maxSatisfaccion);
		//Desacemos asignacion
		numAsignados[i]--;
		if(numAsignados[i] >= minJuguetePorNinyomi) //Pensar si < o >=
			faltanParaMinimo++;

		}

	return;
}