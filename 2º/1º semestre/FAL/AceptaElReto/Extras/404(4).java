import java.util.Scanner;

public class ElTelefonoDeMeucci {

	static int total = 0;
	static String fraccion = "";
	static String[] set1 = {"I","II","III","IV","V","VI","VII","VIII","IX","X"};

	public static void main(String[] args) {
		
		Scanner t = new Scanner(System.in);

		while(t.hasNext())
		{
			total = 0;
			fraccion = t.next();

			if((!fraccion.contains("I")) && (!fraccion.contains("V")))
			{
				total++;
			}
			else
			{
				buscar(fraccion);
			}

			System.out.println(total);
		}
	}

	private static void buscar(String str) {

		for(int i = 1; (i < 5) && (i <= str.length()); i++)
		{
			boolean existe = false;

			for(int j = 0; j < 10; j++)
			{
				if(str.substring(0,i).equals(set1[j]))
				{
					existe = true;
				}
			}

			if(existe)
			{
				String resultado = str.substring(i, str.length());

				if(resultado.length() > 0)
				{
				   buscar(resultado);
				}
				else if(resultado.length() == 0)
				{
					total++;
					return;
				}
			}
		 }
	}
}