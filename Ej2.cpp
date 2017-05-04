#include <iostream>
#include <stdlib.h> 

using namespace std;


// Represento a un eje
struct Edge
{
    int src, dest, weight;
};
 

// Represento al grafo
struct Graph
{
    // n-> Number of vertices, m-> Number of edges
    int n, m;
 
    // graph is represented as an array of edges.
    struct Edge* edge;
};


// Creates a graph with V vertices and E edges
struct Graph* createGraph(int n, int m)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->n = n;
    graph->m = m;
 
    graph->edge = (struct Edge*) malloc( graph->m * sizeof( struct Edge ) );
 
    return graph;
}




// suma todos los ejes y le suma 1 para poder utilizar esto como el "infinito"
int sumaEjes(struct Graph* grafo){
	int res = 0;
	for(int i = 0; i < grafo->m; i++){
		res = res + grafo->edge[i].weight;
	}
	return res + 1;
}


int maxPeaje(struct Graph* grafo){
	int res = grafo->edge[0].weight;
	for(int i = 1; i < grafo->m; i++){
		if(res < grafo->edge[i].weight){
			res = grafo->edge[i].weight;
		}
	}
	return res;
}


bool fordCicloNegativo(struct Graph* grafo, int source){
	int n = grafo->n;
	int m = grafo->m;
	int dist[n];

	int sumEjes = sumaEjes(grafo);

	// inicializo distancias en "infinito"
	for(int i = 0; i < n; i++){
		dist[i] = sumEjes;		// la suma de todos los ejes + 1 va a tener que ser mayor que cualquier distancia
	}
	dist[source] = 0;

	// calculo los caminos mínimos de todos
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			int u = grafo->edge[j].src;
			int v = grafo->edge[j].dest;
			int weight = grafo->edge[j].weight;
			if(dist[u] != sumEjes && dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
			}
		}
	}

	// me fijo si hay ciclos negativos con una iteración más y viendo si alguno baja de valor
	bool b = false;
	for(int j = 0; j < m; j++){
		int u = grafo->edge[j].src;
		int v = grafo->edge[j].dest;
		int weight = grafo->edge[j].weight;
		if(dist[u] != sumEjes && dist[u] + weight < dist[v]){
			b = true;
		}
	}

	return b;
}


int Ej2(struct Graph* grafo){
	int c = maxPeaje(grafo);
	int arr[c];

	// inicializo el arreglo, qué fácil que sería en python esto!
	for(int i = 0; i < c; i++){
		arr[i] = i + 1;
	}
	int L = 0;
	int R = c - 1;
	int m = (L + R) / 2;			// falta que tome el piso o techo
	bool b;

	// búsqueda binaria + Ford
	while(L < R){
		b = fordCicloNegativo(grafo, m);
		if(b){
			R = m;
		}else{
			L = m;
		}
		m = (L + R) / 2;
	}
	return L;
}






int main(){
	return 0;
}