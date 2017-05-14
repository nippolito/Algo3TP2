/*
IDEA:

Generar dos heaps. Uno con las rutas construidas (edgesConstructed),
 y otro con las posibles rutas a construir (edgesNotConstructed).

Invertir (convertir en negativo)los valores del peso de las rutas construidas.
(Recordar que el "costo" de las aristas construidas es el costo de REMOVICION)
De tal manera que al aplicar Kruskal a la edgesConstructed generará un AG con las aristas que MAS CUESTA REMOVER

Guardar todos la suma del costo de las aristas no usadas de edgesConstructed (hay que removerlas) en mst_constructed2Remove;

Aplicar kruskal, ahora a edgesNotConstructed. 
Guardar todos la suma del costo de las aristas usadas de edgesNotConstructed (hay que removerlas) en mst_build;

A la par, ir sumando las aristas que voy agregando a cantAristas.

Devolver [cantAristas, mst_constructed2Remove+mst_build];




*/
#include<bits/stdc++.h>
using namespace std;

// Creating shortcut for an integer pair
typedef pair<int, int> iPair;

// Structure to represent a graph
struct Graph
{
	int V, E;
										// Edge = < <yaConstruido/NoConstruido, valor de construiccion/removicion>, 
										//			<nodo origen, nodo destino> >;

	vector< pair<iPair, iPair> > edgesConstructed; //Ejes ya construidos
	vector< pair<iPair, iPair> > edgesNotConstructed; //Posibles ejes a construir

	// Constructor
	Graph(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	// Utility function to add an edge
	void addEdge(int c, int u, int v, int w)
	{
		if (c == 1)
		{
			w = -w; //Invierto todos los valores. Asi 
			edgesConstructed.push_back({{c,w}, {u, v}});
		} 
		if (c == 0){
			edgesNotConstructed.push_back({{c,w}, {u, v}});
		}

		if(c < 0 || c > 1){ cout<< "Error! Mal pasaje de parametros!" << endl;}

	}

	// Function to find MST using Kruskal's
	// MST algorithm.
	//Devuelve el costo y tambien cuantas aristas tiene
	int[2] kruskalMST();
};


// Disjoint Sets va a representar las componentes conexas creadas.
//Aca hay algo de magia, pero leer con detenimiento que las complejidades cierran.
//+info: http://www.csl.mtu.edu/cs4321/www/Lectures/Lecture%2019%20-%20Kruskal%20Algorithm%20and%20Dis-joint%20Sets.htm

struct DisjointSets
{
	int *parent, *rnk;
	int n;

	// Constructor.
	DisjointSets(int n)
	{
		// Allocate memory
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i < n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u)
	{
		/* Make the parent of the nodes in the path
		from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		/* Make tree with smaller height
		a subtree of the other tree */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

/* Functions returns weight of the MST*/

int[2] Graph::kruskalMST()
{
	int mst_build = 0; // Contador del costo por CONSTRUIR
	int mst_constructed2Remove = 0; //Contador del costo por REMOVER
	int cantAristas = 0; //Aristas agregadas

	// Sort edges in increasing order on basis of cost. 
	//Hay que ver como esta implementado en C++. No supera el n2 asique esta bien
	sort(edgesConstructed.begin(), edgesConstructed.end());
	sort(edgesNotConstructed.begin(), edgesNotConstructed.end());



	// Create disjoint sets
	DisjointSets ds(V);
	
	// Dos iteradores. Uno para cada heap.
	vector< pair<iPair, iPair> >::iterator itConst;
	vector< pair<iPair, iPair> >::iterator itNotConst;

	//Los ejes estan ordenados de tal manera que empiezo a armar el AG con los vertices que sean MAS COSTOSOS removerlos.
	for (itConst = edgesConstructed.begin(); itConst!=edgesConstructed.end(); itConst++) 
	{
		int u = itConst->second.first;
		int v = itConst->second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v){
			// Current edge will be in the MST
			// so print it
			cantAristas++;
			cout << u << " - " << v << endl;

			//La arista no me crea ciclos y ya la tenia construida. Costo = 0; 

			// Merge two sets
			ds.merge(set_u, set_v);
		}else{
			// SI pertenecen al mismo set, entonces esta arista forma un ciclo.
			//Al ya estar construida, necesito pagar por removerla.
			//La añado al costo de removicion de rutas

			mst_constructed2Remove += (itConst->first.second)*(-1); 
			//Recordar que tenian peso negativo para que se adapte a la pila.
		}
		
	}

	//Ahora resta agregar los ejes no construidos previamente. Tomo los de menor valor de costo. Aplico kruskal.
	for (itNotConst=edgesNotConstructed.begin(); itNotConst!=edgesNotConstructed.end(); itNotConst++)
	{
		int u = itNotConst->second.first;
		int v = itNotConst->second.second;
		int set_u = ds.find(u);
		int set_v = ds.find(v);
		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v)
		{
			// Current edge will be in the MST
			// so print it
			cantAristas++;
			cout << u << " - " << v << endl;

			// Update Costo Construccion
			mst_build += itNotConst->first.second;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	int[2] res;
	res[0] = cantAristas;
	res[1] = mst_build + mst_constructed2Remove;
	return res;
}

// Driver program to test above functions
int main()
{
	/* Let us create above shown weighted
	and unidrected graph */
	int V = 9, E = 14;
	Graph g(V, E);

	// making above shown graph. el eje posee 4 parametros (construido/noconstruido; nodo origen; nodo destino; peso )
	g.addEdge(1, 0, 1, 4);
	g.addEdge(1, 0, 7, 8);
	g.addEdge(1, 1, 2, 8);
	g.addEdge(1, 1, 7, 11);
	g.addEdge(1, 2, 3, 7);
	g.addEdge(1, 2, 8, 2);
	g.addEdge(1, 2, 5, 4);
	g.addEdge(0, 3, 4, 9);
	g.addEdge(0, 3, 5, 14);
	g.addEdge(0, 4, 5, 10);
	g.addEdge(0, 5, 6, 2);
	g.addEdge(0, 6, 7, 1);
	g.addEdge(0, 6, 8, 6);
	g.addEdge(0, 7, 8, 7);

	cout << "Los ejes de las ciudades son \n";
	int[2] res = g.kruskalMST();
	cout << "\n El costo total es " << res[1];
	cout << "\n El numero de vertices es " << res[0];

	return 0;
}
