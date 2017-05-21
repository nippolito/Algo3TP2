#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include "ej3.cpp"

using namespace std;

void CrearGrafoCompleto(Graph& g){
	
	for (int i = 0; i < g.V; ++i)
	{
		for (int j = i+1; j < (g.V -1); ++j)
		{
			g.addEdge(i,j, rand() % 2, rand() % 101);
		}		
	}
}

void TestMediciones(){

	auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    stringstream ss;
    ss <<  "Muestreo_Ej3" <<".txt";

	ofstream file( ss.str() );
    if ( !file )
	{
        cerr << "Error: failed to create file " << ss.str() << '\n';
 	}

    int cantMuestras = 100;
	for (int i = 2; i < 200; ++i)
	{
		typedef std::chrono::duration<double, std::milli> Duracion;
		double promedioMili = 0;
		for (int j = 0; j < cantMuestras; ++j)
		{
			Graph g(i, i * (i-1) / 2);
			CrearGrafoCompleto(g);

			start = std::chrono::high_resolution_clock::now();
   			iPair res = g.kruskalMST();
			finish = std::chrono::high_resolution_clock::now();
	   		Duracion tiempoEjec = finish - start;
		   	promedioMili += tiempoEjec.count();

		}
		promedioMili = promedioMili/cantMuestras;
		file << i << " " << promedioMili << "\n";
		cout << "Voy por cantidad de nodos: " << i << ". El promedio fue: " << promedioMili << endl;
	}
		
	
	
}



int main()
{
	TestMediciones();	
	return 0;
}