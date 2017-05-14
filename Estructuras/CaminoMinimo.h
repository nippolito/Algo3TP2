#ifndef CAMINO_MINIMO_H
#define CAMINO_MINIMO_H

#include <iostream>
#include <vector>
#include "GrafoMatriz.h"
#include <queue>

using namespace std;

struct entry{
	bool v; //visitado
	int d ; // distancia
};

int minVisitados(int n, entry dist []){
	int res=100;
	int resD=100;
	for(int i = 0; i < n; i ++){
		if(dist[i].d != -1 && dist[i].v == false && dist[i].d < resD) {
			res= i;
			resD = dist[i].d;
		}
	}
	if(res == 100) cout << "NO ES CONEXO"<<endl;
	return res;
}

void dijkstra(int n, GrafoMatriz& g, int nodo, int res[]){
	entry dist [n];
	for(int i = 0; i< n; i++){
		dist[i].d=-1; 
		dist[i].v= false; 
	}
	dist[nodo].d = 0;
	for(int i = 0; i < n; i ++){ // mientras recorro todos los nodos
		int min = minVisitados(n,dist); //selecciono el minimo de los no visitados
		dist[min].v = true;   // lo marco como visitado
		
		for(int j = 0 ; j < n; j ++){   //actualizo distancias.
			if(g.SonVecinos(min,j)){
				if(dist[j].d == -1 || dist[j].d > dist[min].d + g.PesoDe(min, j)){ // si encontre un camino menor lo actualizo
					dist[j].d =   dist[min].d + g.PesoDe(min, j);
				}
			} 
		}

	}

	for(int i = 0 ; i < n; i ++){
		res[i] = dist[i].d;
	}

}




#endif