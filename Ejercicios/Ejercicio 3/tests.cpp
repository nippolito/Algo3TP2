#include <assert.h>
#include <fstream>
#include <chrono>
#include <random>
#include "ej3.cpp"

using namespace std;

void Test1(){
	int V = 5, E = 20;
	Graph g(V, E);
	
	// making above shown graph. el eje posee 4 parametros (construido/noconstruido; nodo origen; nodo destino; peso )
	g.addEdge(0, 1, 0, 4);
	g.addEdge(0, 2, 1, 8);
	g.addEdge(0, 3, 1, 8);
	g.addEdge(0, 4, 1, 11);

	g.addEdge(1, 2, 0, 2);
	g.addEdge(1, 3, 0, 4);
	g.addEdge(1, 4, 0, 9);
	
	g.addEdge(2, 3, 0, 14);
	g.addEdge(2, 4, 0, 10);
	
	g.addEdge(3, 4, 1, 2);
	
	cout << "Los ejes de las ciudades son \n";
	iPair res = g.kruskalMST();
	vector<iPair> sol = g.dameSolucion();
	
	vector<iPair>::iterator itConst;
	for (itConst = sol.begin(); itConst!=sol.end(); itConst++) 	{
		int u = itConst->first;
		int v = itConst->second;
		cout <<u <<" "<< v <<" ";
	}
	
	cout << endl;
	cout << "\n El costo total es " << res.second;
	cout << "\n El numero de vertices es " << res.first << endl;

}



int main()
{
	Test1();	
	return 0;
}