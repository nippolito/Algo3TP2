#include <iostream>
#include <vector>

using namespace std;

struct entry2{
	entry2(): v(false), d(-1){}
	bool v; //visitado
	int d ; // distancia
};

struct entry
{
	entry(): p(false), d(-1){}
	bool p;
	int d;
};

int minNoVisitados(int n, entry2 dist []){
	int res=0xFFFFFFF;
	int resD=0xFFFFFFF;
	for(int i = 0; i < n; i ++){
		if(dist[i].d != -1 && dist[i].v == false && dist[i].d < resD) {
			res= i;
			resD = dist[i].d;
		}
	}
	if(res == 0xFFFFFFF) {
		return -1; // no es conexo. 
	}
	return res;
}

int main(){

	std::vector<int> respuestas;

	while(true){

		int n ; cin >>n;
		int r ; cin >> r;
		if(n == -1 && r == -1) break; // si terminan las entradas.
		int o, d, k;
		cin >> o ; cin >> d; cin >> k ;
		o = o-1;
		d = d-1; // esto porque se numeran desde 1 en el ejercicio, y yo desde 0 

		entry m [n][n]; // mas uno asi no tengo que restar siempre 1 jeje
		for(int i = 0; i < r; i ++ ){
			int c1,c2,d;
			bool p;
			cin >> c1; cin >> c2; cin >> p ; cin >> d;

			m[c1-1][c2-1].p = p;
			m[c1-1][c2-1].d = d;

			m[c2-1][c1-1].p = p;
			m[c2-1][c1-1].d = d;           // lleno la matriz
		}

		int m2[(k+1)*n][(k+1)*n];
		for(int i= 0; i< n*(k+1); i ++){
			int nodo1 = i/(k+1);
			int cantP1 = i%(k+1);

			for(int j = 0; j < n*(k+1); j++){
				int nodo2 = j/(k+1);
				int cantP2 = j%(k+1);
				if(m[nodo1][nodo2].d != -1 ){ // si son vecinos
					if(cantP1 > cantP2) m2[i][j] = -1; // si vengo de usar mas rutas premium a qrer usar menos es imposible asi que calzo un -1;
					else{
						bool seConectanPorPremium = m[nodo1][nodo2].p;
						if(seConectanPorPremium && cantP2 == cantP1)
							m2[i][j] = -1; // si se conectan por premium y no quiero aumentar la cantidad d premium no se puede asi que -1;
						else{
							m2[i][j] = m [nodo1][nodo2].d;
						}
					}
				}
				else{ // si no son vecinos
					m2[i][j] = -1;
				}
			}
		}

		/////////////////////////////////////////////
		//ACA TERMIA LA PARTE QUE CREO EL GRAFO AUXILIAR, AHORA QUEDA HACER DIKSTRA Y VER LA DISTANCIA MINIMA HASTA EL ULTIMO NODO
		/////////////////////////////////////////////

		int min;
		entry2 dist [n*(k+1)];
		dist [o*(k+1)].d = 0;

		int y = 0;
		while(true){  // mientras recorro todos los nodos
			min = minNoVisitados(n*(k+1),dist); //selecciono el minimo de los no visitados
			
			if(min == -1) break; 
			else if(min == d*(k+1)+k) break; //si llegue a mi objetivo
			dist[min].v = true;   // lo marco como visitado
			
			for(int j = 0 ; j < n*(k+1); j ++){   //actualizo distancias.
				if(m2[min][j] != -1){
					if(dist[j].d == -1 || dist[j].d > dist[min].d + m2[min][j]){ // si encontre un camino menor lo actualizo
						dist[j].d =   dist[min].d + m2[min][j];
					}
				} 
			}
			/*cout << "LAS DIST SON " << y <<": \n";
			for(int i =0 ; i < n*(k+1) ; i ++) cout << "(" << dist[i].d <<", "<< dist[i].v << "), ";
			cout << "\n\n";
			 y++;*/
		}


		if(min == -1) respuestas.push_back(-1);
		else respuestas.push_back(dist[min].d );

	}

	int x  = respuestas.size();

	for(int i = 0; i < x; i ++){
		cout << respuestas[i] << endl;
	}

	return 0 ;
}