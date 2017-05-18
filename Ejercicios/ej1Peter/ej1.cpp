#include <iostream>
#include <vector>
#include <list>
#include <limits>
using namespace std;

struct Arista {
	Arista(int c, int f, int p, int esp) : _comienzo(c), _fin(f), _peso(p), _esPremium(esp) {}

	int _comienzo;
	int _fin;
	int _peso;
	bool _esPremium;
};

int MinDistancia(const vector<vector<int> >& dist, int origen, int destino, const vector<vector<int> >& predec, const vector<vector<Arista> >& listAdy){
	int min  = numeric_limits<int>::max();
	int kmin = -1;
	
	for (int i = 0; i < dist.size(); ++i)
	{
		if (min > dist[i][destino]) {
			min = dist[i][destino]; 
			kmin = i;
		}
	}
	if (min == numeric_limits<int>::max()) return -1;

	int pred = -1;
	cout << "Camino de vuelta es: " << destino << " ";
	while (pred != origen){
		pred = predec[kmin][destino];
		int i = 0;
		for (i; listAdy[pred][i]._fin != destino; i++){}
		if (listAdy[pred][i]._esPremium){
			kmin--;
		}
		destino = pred;
		cout << pred << " ";
	}
	cout << endl;

	return min;
}

int EncontrarMinimaRuta( const vector<int>& dist, const vector<bool>& visit, const vector<int>& pred){
	int min  = numeric_limits<int>::max();
	int vertice;
	for (int i = 0; i < dist.size(); ++i)
	{
		if (visit[i] == false && dist[i] < min) {
			min = dist[i];
			vertice = i;
		}
	}
	if(min == numeric_limits<int>::max() ) return -1;
	return vertice;
}

int DijkstraRutasPremium(int origen, int destino, int n, int k, vector<vector<Arista> > listAdy){
	int max = numeric_limits<int>::max();
	vector<vector<int> > Distancias (k + 1, vector<int> (n,max));
	vector<vector<bool> > Visitado (k + 1, vector<bool> (n,false));
	
	vector<vector<int> > Predecesor;
	for (int i = 0; i < k + 1; ++i)
	{
		Distancias[i][origen] = 0;
	
		vector<int> vi;
		for (int j = 0; j < n; ++j)
		{
			vi.push_back(j);
		}
		Predecesor.push_back(vi);

		if (i != 0) Visitado[i][origen] = true;
	}

	for (int nivel = 0; nivel < k+1; ++nivel)
	{
		
		for (int iter = 0; iter < n; ++iter)
		{
			int siguiente = EncontrarMinimaRuta(Distancias[nivel], Visitado[nivel], Predecesor[nivel]);
			if (siguiente == -1) break; //si siguiente devuelve infinito entonces no quedan mas caminos por recorrer con a lo sumo nivel ruteas premium
			Visitado[nivel][siguiente] = true; //Defino el vertice en el nivel indicado como visitado para no recorrerlo de vuelta
			for (int vecino = 0; vecino < listAdy[siguiente].size(); ++vecino) //itero sobre sus vecinos
			{
				Arista arista = listAdy[siguiente][vecino]; //obtengo su arista en la lista de adyacencias
				if (arista._fin != Predecesor[nivel][siguiente]){ //si el vecino que quiero actualizar es el predecesor del nivel anterior 
					//entonces no actualizamos la distancia, ya que es de donde viene el camino que pasa por nivel rutas premium actual
					if (arista._esPremium){
						//si la ruta adyacente es premium modifico el vector del nivel+1
						if ( nivel != k && Distancias[nivel+1][arista._fin] > Distancias[nivel][siguiente] + arista._peso )
						{
							//relaxeo la distancia
							Distancias[nivel+1][arista._fin] = Distancias[nivel][siguiente] + arista._peso;
							Predecesor[nivel+1][arista._fin] = siguiente;					
						}
					}
					else {
						//si no es premium modifico el vector del nivel actual
						if (Distancias[nivel][arista._fin] > Distancias[nivel][siguiente] + arista._peso )
						{
							//relaxeo la distancia
							Distancias[nivel][arista._fin] = Distancias[nivel][siguiente] + arista._peso;
							Predecesor[nivel][arista._fin] = siguiente;					
						}
					}
				}
			}
		}
	}

	
	return MinDistancia(Distancias, origen, destino, Predecesor, listAdy);
}

int main(){
	

	while(true){
		/*vector<vector<Arista> > grafo;
		vector<Arista> v0;
		v0.push_back(Arista(0,1,6,true));
		v0.push_back(Arista(0,2,3,true));
		v0.push_back(Arista(0,3,10,false));
		
		grafo.push_back(v0);
		vector<Arista> v1;
		v1.push_back(Arista(1,0,6,true));
		v1.push_back(Arista(1,5,1,false));
		grafo.push_back(v1);
		vector<Arista> v2;
		v2.push_back(Arista(2,0,3,true));
		v2.push_back(Arista(2,3,2,false));
		v2.push_back(Arista(2,4,7,false));
		v2.push_back(Arista(2,5,1,true));
		grafo.push_back(v2);
		vector<Arista> v3;
		v3.push_back(Arista(3,0,10,false));
		v3.push_back(Arista(3,2,2,false));
		v3.push_back(Arista(3,6,5,true));
		grafo.push_back(v3);
		vector<Arista> v4;
		v4.push_back(Arista(4,2,7,false));
		v4.push_back(Arista(4,5,1,true));
		grafo.push_back(v4);
		vector<Arista> v5;
		v5.push_back(Arista(5,1,1,false));
		v5.push_back(Arista(5,2,1,true));
		v5.push_back(Arista(5,6,4,true));
		grafo.push_back(v5);
		vector<Arista> v6;
		v6.push_back(Arista(6,3,5,true));
		v6.push_back(Arista(6,4,1,true));
		v6.push_back(Arista(6,5,4,true));
		grafo.push_back(v6);*/
		
		int n ; cin >>n;
		int r ; cin >> r;
		if(n == -1 && r == -1) break; // si terminan las entradas.
		vector<vector<Arista> > grafo (n, vector<Arista>());
		int o, d, k;
		cin >> o ; cin >> d; cin >> k ;
		o = o;
		d = d; // esto porque se numeran desde 1 en el ejercicio, y yo desde 0 

		for(int i = 0; i < r; i ++ ){
			int c1,c2,d;
			bool p;
			cin >> c1; cin >> c2; cin >> p ; cin >> d;
			grafo[c1].push_back(Arista(c1, c2, d, p));
			grafo[c2].push_back(Arista(c2, c1, d, p));
		}
		
		int res = DijkstraRutasPremium(o,d,n,k,grafo);
		cout << res << endl;
	}
	
	return 0;
}