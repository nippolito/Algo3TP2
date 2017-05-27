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
    vector<Edge> edge;		   // graph is represented as an array of edges.
};

// Creates a graph with V vertices and E edges
void createGraph(Graph* graph, int n, int m)
{
    graph->n = n;
    graph->m = m;
 
    vector<Edge> vec(m);

    graph->edge = vec;

}

void addEdge(struct Graph* grafo, int num, int src, int dest, int weight){			// agrega eje al grafo
	grafo->edge[num].src = src;
	grafo->edge[num].dest = dest;
	grafo->edge[num].weight = weight;
}

void crearGrafo(Graph* grafo, int cantCiud, int cantRut, vector<int>& c1, vector<int>& c2, vector<int>& p){
	createGraph(grafo, cantCiud, cantRut);
	for(int i = 0; i < grafo->m; i++){
		addEdge(grafo, i, c1[i], c2[i], p[i]);
	}
}

void addGhostNode(Graph* graphGhost, Graph* grafo){		// agrega el nodo fantasma explicado, copia el grafo y crea uno nuevo
	int nuevoN = grafo->n + 1;
	int nuevoM = grafo->m + grafo->n;
	createGraph(graphGhost, nuevoN, nuevoM);
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
int maxPeaje(Graph* grafo){
	int res = grafo->edge[0].weight;
	for(int i = 1; i < grafo->m; i++){
		if(res < grafo->edge[i].weight){
			res = grafo->edge[i].weight;
		}
	}
	return res;
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

	Graph graphGhost;
	addGhostNode(&graphGhost, grafo);				// agrego el nodo fantasma al grafo

	// búsqueda binaria + Ford
	while(L+1 < R){
		b = fordCicloNegativo(&graphGhost, grafo->n, arr[m]);
		if(b){
			R = m;
		}else{
			L = m;
		}
		m = floor((L + R) / 2);
 	}
	bool h = fordCicloNegativo(&graphGhost, grafo->n, arr[R]);


	if(h){
		return arr[L];
	}else{
		return arr[R];
	}
}

int main(){
	int cantCiud;
	int cantRut;
	cout << "Comience a tipear los datos como especifica el enunciado" << endl;
	cin >> cantCiud;
	cin >> cantRut;

	while(cantCiud != (-1) && cantRut != (-1)){

		vector<int> c1(cantRut);
		vector<int> c2(cantRut);
		vector<int> p(cantRut);
		int ciudSal;
		int ciudDest;
		int peso;
		int i = 0;

		while(i < cantRut){
			cin >> ciudSal;
			cin >> ciudDest;
			cin >> peso;
			c1[i] = ciudSal;
			c2[i] = ciudDest;
			p[i] = peso;
			i++;
		}

		Graph grafo;
		crearGrafo(&grafo, cantCiud, cantRut, c1, c2, p);

		int h1 = Ej2(&grafo);

		cout << "La entrada tiene salida: " << h1 << endl;

		cin >> cantCiud;
		cin >> cantRut;
	}
	return 0;
}