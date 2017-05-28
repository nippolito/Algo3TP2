#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include <vector>
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

void CrearGrafoConAgmConstruido(Graph& g){
	
	vector<int> agm = {0};
	vector<int> noAgm;
	for(int i = 1; i< g.V; i++)
		noAgm.push_back(i);

	int m[g.V][g.V];
	for (int i = 0; i < g.V; ++i)
	{
		for (int j = 0; j < g.V; ++j)
		{
			m[i][j] = 0;
		}
	}
	for(int i = 0; i < g.V - 1; i++)
	{
		int randPosG = rand()%(0,noAgm.size()); 
		int randPosA = rand()%(0,agm.size());
		agm.push_back(noAgm[randPosG]);
		g.addEdge(noAgm[randPosG],agm[randPosA], 1, rand() % 101);
		m[noAgm[randPosG]][agm[randPosA]] = 1;
		m[agm[randPosA]][noAgm[randPosG]] = 1;
		noAgm.erase(noAgm.begin() + randPosG);
		
	}

	for (int i = 0; i < g.V; ++i)
	{
		for (int j = i+1; j < (g.V -1); ++j)
		{
			if (m[i][j] == 0) g.addEdge(i,j, 0, rand() % 101);
		}		
	}
}

void TestMedicionesEj3(){

	auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    stringstream ss;
    ss <<  "Muestreo_Ej3" <<".csv";

	ofstream file( ss.str() );
    if ( !file )
	{
        cerr << "Error: failed to create file " << ss.str() << '\n';
 	}
    file << "cantNod,Tiempo,Tipo" << endl;
    int cantMuestras = 100;
	for (int i = 2; i < 300; ++i)
	{
		typedef std::chrono::duration<double, std::milli> Duracion;
		double promedioMili = 0;
		for (int j = 0; j < cantMuestras; ++j)
		{
			Graph g(i, i * (i-1) / 2);
			CrearGrafoCompleto(g);

			start = std::chrono::high_resolution_clock::now();
   			iPair res = g.ej3();
			finish = std::chrono::high_resolution_clock::now();
	   		Duracion tiempoEjec = finish - start;
		   	promedioMili += tiempoEjec.count();

		}
		promedioMili = promedioMili/cantMuestras;
		file << i << "," << promedioMili << ",Original\n";
		cout << "Voy por cantidad de nodos: " << i << ". El promedio fue: " << promedioMili << endl;
	}
	
}


void TestMedicionesEj3Op()
{
	auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    stringstream ss;
    ss <<  "Muestreo_Ej3Op" <<".csv";

	ofstream file( ss.str() );
    if ( !file )
	{
        cerr << "Error: failed to create file " << ss.str() << '\n';
 	}
 	file << "cantNod,Tiempo,Tipo" << endl;
    int cantMuestras = 100;
	for (int i = 2; i < 300; ++i)
	{
		typedef std::chrono::duration<double, std::milli> Duracion;
		double promedioMili = 0;
		for (int j = 0; j < cantMuestras; ++j)
		{
			Graph g(i, i * (i-1) / 2);
			CrearGrafoCompleto(g);

			start = std::chrono::high_resolution_clock::now();
   			iPair res = g.ej3OP();
			finish = std::chrono::high_resolution_clock::now();
	   		Duracion tiempoEjec = finish - start;
		   	promedioMili += tiempoEjec.count();

		}
		promedioMili = promedioMili/cantMuestras;
		file << i << "," << promedioMili << ",Optimizada\n";
		cout << "Voy por cantidad de nodos: " << i << ". El promedio fue: " << promedioMili << endl;
	}
}

void TestMedicionesAgmHecho()
{
	auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();

    stringstream ss1, ss2;
    ss1 <<  "Muestreo_Ej3_Agm" <<".csv";
    ss2 <<  "Muestreo_Ej3_AgmOp" <<".csv";

    ofstream fileOp( ss2.str()  );
    if ( !fileOp )
	{
        cerr << "Error: failed to create file " << ss2.str() << '\n';
 	}
	ofstream file( ss1.str() );
    if ( !file )
	{
        cerr << "Error: failed to create file " << ss1.str() << '\n';
 	}
 	file << "cantNod,Tiempo,Tipo" << endl;
 	fileOp << "cantNod,Tiempo,Tipo" << endl;

    int cantMuestras = 100;
	for (int i = 2; i < 300; ++i)
	{
		typedef std::chrono::duration<double, std::milli> Duracion;
		double promedioMili = 0;
		double promedioMiliOp = 0;
		for (int j = 0; j < cantMuestras; ++j)
		{
			Graph g(i, i * (i-1) / 2);
			CrearGrafoConAgmConstruido(g);

			start = std::chrono::high_resolution_clock::now();
   			iPair res = g.ej3();
			finish = std::chrono::high_resolution_clock::now();
			g.resetear();
			Duracion tiempoEjec = finish - start;
		   	promedioMili += tiempoEjec.count();

			start = std::chrono::high_resolution_clock::now();
   			res = g.ej3OP();
			finish = std::chrono::high_resolution_clock::now();
	   		tiempoEjec = finish - start;
		   	promedioMiliOp += tiempoEjec.count();

		}
		promedioMili = promedioMili/cantMuestras;
		file << i << "," << promedioMili << ",OriginalConAGM" <<"\n";
		promedioMiliOp = promedioMiliOp/cantMuestras;
		fileOp << i << "," << promedioMiliOp << ",OptimizadaConAGM" <<"\n";
		
		cout << "Voy por cantidad de nodos: " << i << ". Los promedios fueron: " << promedioMili << " y " << promedioMiliOp << endl;
	}
}

void funcionNcuboLogcien(int n){
	int temp = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int t = (int) (100 * log (n) + 0.5);
			int k = 0;
			while(k < t){
				temp++;
			}
		}
	}
}

void expFuncionComplej(){
	fstream s ("FuncionComplej.csv", ios::out);

	s << "cantNod,Tiempo,Tipo" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 2; i < 300; i++){		// ciclo para variar el c
		for(int j = 0; j < 40; j++){
			s << i;
			s << ",";

			start = std::chrono::system_clock::now();
			funcionNcuboLogcien(i);
			end = std::chrono::system_clock::now();

			std::chrono::duration<double, std::milli> elapsed_seconds = end-start;

			s << elapsed_seconds.count();
			s << ",";
			s << "FuncionComplej" << endl;
		}
	}
}


int main()
{
	TestMedicionesEj3();
	TestMedicionesEj3Op();
	TestMedicionesAgmHecho();
	expFuncionComplej();
	return 0;
}