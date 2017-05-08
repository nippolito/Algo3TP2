#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

// Represento a un eje
struct Edge 				
{
    int src, dest, weight;
};
 
// Represento al grafo
struct Graph 			    // n-> Number of vertices, m-> Number of edges
{
    int n, m;
    struct Edge* edge;		   // graph is represented as an array of edges.
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


// suma todos los ejes y le suma 1000 para poder utilizar esto como el "infinito"
int sumaEjes(struct Graph* grafo){
	int res = 0;
	for(int i = 0; i < grafo->m; i++){
		res = res + grafo->edge[i].weight;
	}
	return res + 1000;
}

// calcula el peaje máximo
int maxPeaje(struct Graph* grafo){
	int res = grafo->edge[0].weight;
	for(int i = 1; i < grafo->m; i++){
		if(res < grafo->edge[i].weight){
			res = grafo->edge[i].weight;
		}
	}
	return res;
}

void mostrarPesos(struct Graph* grafo){			// al pedo
	for(int i = 0; i < grafo->m; i++){
		cout << grafo->edge[i].weight << endl;
	}
}


bool fordCicloNegativo(struct Graph* grafo, int source, int c){
	int n = grafo->n;
	int m = grafo->m;
	vector<int> dist(n);

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
			int weight = grafo->edge[j].weight - c;
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
		int weight = grafo->edge[j].weight - c;
		if(dist[u] != sumEjes && dist[u] + weight < dist[v]){
			b = true;
		}
	}

	return b;
}


int Ej2(struct Graph* grafo){
	int c = maxPeaje(grafo);
	vector<int> arr(c);
	// inicializo el arreglo, qué fácil que sería en python esto!
	for(int i = 0; i < c; i++){
		arr[i] = i + 1;
	}

	int L = 0;
	int R = c - 1;
	int m = floor((L + R) / 2);
	bool b;

	// búsqueda binaria + Ford
	while(L+1 < R){
		b = fordCicloNegativo(grafo, 0, arr[m]);
		if(b){
			R = m;
		}else{
			L = m;
		}
		m = floor((L + R) / 2);
 	}
	bool h = fordCicloNegativo(grafo, 0, arr[R]);
	if(h){
		return arr[L];
	}else{
		return arr[R];
	}
}


void Test1(){			// debe dar 2
	int n = 4;
	int m = 4;
	struct Graph* grafo = createGraph(n, m);

	grafo->edge[0].src = 1;
	grafo->edge[0].dest = 0;
	grafo->edge[0].weight = 1;

	grafo->edge[1].src = 0;
	grafo->edge[1].dest = 3;
	grafo->edge[1].weight = 5;

	grafo->edge[2].src = 3;
	grafo->edge[2].dest = 2;
	grafo->edge[2].weight = 1;

	grafo->edge[3].src = 2;
	grafo->edge[3].dest = 1;
	grafo->edge[3].weight = 1;

	int h = Ej2(grafo);
	cout << "La respuesta es: " << h << endl;
}

void Test2(){			// debe dar 16
	int n = 6;
	int m = 7;
	struct Graph* grafo = createGraph(n, m);

	grafo->edge[0].src = 0;
	grafo->edge[0].dest = 1;
	grafo->edge[0].weight = 30;

	grafo->edge[1].src = 1;
	grafo->edge[1].dest = 2;
	grafo->edge[1].weight = 10;

	grafo->edge[2].src = 2;
	grafo->edge[2].dest = 0;
	grafo->edge[2].weight = 10;

	grafo->edge[3].src = 2;
	grafo->edge[3].dest = 3;
	grafo->edge[3].weight = 100;

	grafo->edge[4].src = 3;
	grafo->edge[4].dest = 5;
	grafo->edge[4].weight = 100;

	grafo->edge[5].src = 4;
	grafo->edge[5].dest = 3;
	grafo->edge[5].weight = 100;

	grafo->edge[6].src = 4;
	grafo->edge[6].dest = 5;
	grafo->edge[6].weight = 100;

	int h = Ej2(grafo);
	cout << "La respuesta es: " << h << endl;
}


int main(){
	Test1();
	Test2();

	return 0;
}