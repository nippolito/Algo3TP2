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

void addEdge(struct Graph* grafo, int num, int src, int dest, int weight){			// agrega eje al grafo
	grafo->edge[num].src = src;
	grafo->edge[num].dest = dest;
	grafo->edge[num].weight = weight;
}

void agregaAristaVec(int pos, vector<int>& c1, vector<int>& c2, vector<int>& p, int src, int dest, int weight){
	c1[pos] = src;
	c2[pos] = dest;
	p[pos] = weight;
}

struct Graph* addGhostNode(struct Graph* grafo){		// agrega el nodo fantasma explicado, copia el grafo y crea uno nuevo
	int nuevoN = grafo->n + 1;
	int nuevoM = grafo->m + grafo->n;
	struct Graph* graphGhost = createGraph(nuevoN, nuevoM);
	for(int i = 0; i < grafo->m; i++){
		graphGhost->edge[i].src = grafo->edge[i].src;
		graphGhost->edge[i].dest = grafo->edge[i].dest;
		graphGhost->edge[i].weight = grafo->edge[i].weight;	
	}
	int j = 0;
	for(int i = grafo->m; i < nuevoM; i++){
		graphGhost->edge[i].src = grafo->n;
		graphGhost->edge[i].dest = j;
		graphGhost->edge[i].weight = 0;
		j++;
	}
	return graphGhost;
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

void mostrarEjes(struct Graph* grafo){			// función de utilidad para mostrar los ejes
	for(int i = 0; i < grafo->m; i++){
		cout << "(" << grafo->edge[i].src << ", " << grafo->edge[i].dest << ")" << endl;
	}	
}

void mostrarPesos(struct Graph* grafo){			// al pedo
	for(int i = 0; i < grafo->m; i++){
		cout << grafo->edge[i].weight << endl;
	}
}



struct Graph* crearGrafo(int cantCiud, int cantRut, vector<int>& c1, vector<int>& c2, vector<int>& p){
	struct Graph* grafo = createGraph(cantCiud, cantRut);
	for(int i = 0; i < grafo->m; i++){
		addEdge(grafo, i, c1[i], c2[i], p[i]);
	}
	return grafo;
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

// int Ej2Ent(int cantCiud, int cantRut, vector<int>& c1, vector<int>& c2, vector<int>& p){
// 	struct Graph* grafo = crearGrafo(cantCiud, cantRut, c1, c2, p);
// 	int c = maxPeaje(grafo);
// 	vector<int> arr(c);
// 	// inicializo el arreglo, qué fácil que sería en python esto!
// 	for(int i = 0; i < c; i++){
// 		arr[i] = i + 1;
// 	}

// 	int L = 0;
// 	int R = c - 1;
// 	int m = floor((L + R) / 2);
// 	bool b;

// 	struct Graph* graphGhost = addGhostNode(grafo);				// agrego el nodo fantasma al grafo

// 	// búsqueda binaria + Ford
// 	while(L+1 < R){
// 		b = fordCicloNegativo(graphGhost, grafo->n, arr[m]);
// 		if(b){
// 			R = m;
// 		}else{
// 			L = m;
// 		}
// 		m = floor((L + R) / 2);
//  	}
// 	bool h = fordCicloNegativo(graphGhost, grafo->n, arr[R]);

// 	free(grafo);
// 	free(graphGhost);

// 	if(h){
// 		return arr[L];
// 	}else{
// 		return arr[R];
// 	}
// }

int Ej2Testeo(struct Graph* grafo){
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

	struct Graph* graphGhost = addGhostNode(grafo);				// agrego el nodo fantasma al grafo

	// búsqueda binaria + Ford
	while(L+1 < R){
		b = fordCicloNegativo(graphGhost, grafo->n, arr[m]);
		if(b){
			R = m;
		}else{
			L = m;
		}
		m = floor((L + R) / 2);
 	}
	bool h = fordCicloNegativo(graphGhost, grafo->n, arr[R]);

	free(grafo);
	free(graphGhost);

	if(h){
		return arr[L];
	}else{
		return arr[R];
	}
}