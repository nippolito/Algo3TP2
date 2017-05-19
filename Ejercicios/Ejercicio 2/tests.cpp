#include "Ej2.cpp"
#include <chrono>
#include <random>
#include <fstream>

void Test1(){			// debe dar 2
	int n = 4;
	int m = 4;
	// struct Graph* grafo = createGraph(n, m);

	// addEdge(grafo, 0, 1, 0, 1);
	// addEdge(grafo, 1, 0, 3, 5);
	// addEdge(grafo, 2, 3, 2, 1);
	// addEdge(grafo, 3, 2, 1, 1);

	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	agregaAristaVec(0, c1, c2, p, 1, 0, 1);
	agregaAristaVec(1, c1, c2, p, 0, 3, 5);
	agregaAristaVec(2, c1, c2, p, 3, 2, 1);
	agregaAristaVec(3, c1, c2, p, 2, 1, 1);

	// int h = Ej2(grafo);
	// cout << "La respuesta es: " << h << endl;

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	int h1 = Ej2Testeo(grafo);

	cout << "La respuesta es: " << h1 << endl;	
}

void Test2(){			// debe dar 16
	int n = 6;
	int m = 7;
	// struct Graph* grafo = createGraph(n, m);

	// addEdge(grafo, 0, 0, 1, 30);
	// addEdge(grafo, 1, 1, 2, 10);
	// addEdge(grafo, 2, 2, 0, 10);
	// addEdge(grafo, 3, 2, 3, 100);
	// addEdge(grafo, 4, 3, 5, 100);
	// addEdge(grafo, 5, 4, 3, 100);
	// addEdge(grafo, 6, 4, 5, 100);

	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	agregaAristaVec(0, c1, c2, p, 0, 1, 30);
	agregaAristaVec(1, c1, c2, p, 1, 2, 10);
	agregaAristaVec(2, c1, c2, p, 2, 0, 10);
	agregaAristaVec(3, c1, c2, p, 2, 3, 100);	
	agregaAristaVec(4, c1, c2, p, 3, 5, 100);
	agregaAristaVec(5, c1, c2, p, 4, 3, 100);
	agregaAristaVec(6, c1, c2, p, 4, 5, 100);	

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	int h1 = Ej2Testeo(grafo);

	cout << "La respuesta es: " << h1 << endl;	
}

void Test3(){		// debe dar 7
	int n = 5;
	int m = 3;
	// struct Graph* grafo = createGraph(n, m);

	// addEdge(grafo, 0, 2, 4, 5);
	// addEdge(grafo, 1, 4, 3, 6);
	// addEdge(grafo, 2, 3, 2, 10);

	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	agregaAristaVec(0, c1, c2, p, 2, 4, 5);
	agregaAristaVec(1, c1, c2, p, 4, 3, 6);
	agregaAristaVec(2, c1, c2, p, 3, 2, 10);

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	int h1 = Ej2Testeo(grafo);

	cout << "La respuesta es: " << h1 << endl;	
}

void Test4(){			// Debe dar 6
	int n = 12;
	int m = 10;
	// struct Graph* grafo = createGraph(n, m);

	// addEdge(grafo, 0, 0, 1, 90);
	// addEdge(grafo, 1, 1, 2, 1);
	// addEdge(grafo, 2, 3, 4, 1);
	// addEdge(grafo, 3, 5, 6, 5);
	// addEdge(grafo, 4, 6, 7, 5);
	// addEdge(grafo, 5, 7, 8, 5);
	// addEdge(grafo, 6, 8, 5, 9);
	// addEdge(grafo, 7, 9, 10, 5);
	// addEdge(grafo, 8, 10, 11, 6);
	// addEdge(grafo, 9, 11, 9, 10);

	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	agregaAristaVec(0, c1, c2, p, 0, 1, 90);
	agregaAristaVec(1, c1, c2, p, 1, 2, 1);
	agregaAristaVec(2, c1, c2, p, 3, 4, 1);
	agregaAristaVec(3, c1, c2, p, 5, 6, 5);	
	agregaAristaVec(4, c1, c2, p, 6, 7, 5);
	agregaAristaVec(5, c1, c2, p, 7, 8, 5);
	agregaAristaVec(6, c1, c2, p, 8, 5, 9);
	agregaAristaVec(7, c1, c2, p, 9, 10, 5);
	agregaAristaVec(8, c1, c2, p, 10, 11, 6);
	agregaAristaVec(9, c1, c2, p, 11, 9, 10);

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	int h1 = Ej2Testeo(grafo);

	cout << "La respuesta es: " << h1 << endl;	
}

void mostrarGrafo(int n, int m, vector<int>& c1, vector<int>& c2, vector<int>& p){
	cout << "Ciudades: " << n << " ---- Rutas: " << m << endl;
	for(int i = 0; i < m; i++){
		cout << "[" << c1[i] << ", " << c2[i] << ", " << p[i] << "]" << endl;
	}
}

void genGraphNigualM(int cantNodos){			// genera el grafo de n nodos con N y M garantizando un ciclo
	int n = cantNodos;
	int m = cantNodos;
	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	for(int i = 0; i < m; i++){		// crea las aristas obligatorias tq de toda ciudad se pueda viajar a otra
		c1[i] = i;
		int x1 = rand() % (m - 1);		// rango [0, m - 1]. Luego, de la ciudad i se puede viajar a una al azar
		c2[i] = x1;		
		int x2 = rand() % 100;		// el peso de esa arista está en el rango [0, 100]
		if(x2 == 0){
			x2++;
		}
		p[i] = x2;
		if(c2[i] == i){
			if(c2[i] == (n - 1)){
				c2[i] = i - 1;
			}else{
				c2[i] = i + 1;
			}
		}
	}

	mostrarGrafo(n, m, c1, c2, p);

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	int h1 = Ej2Testeo(grafo);
	cout << "La respuesta es: " << h1 << endl;
}

struct Graph* genGraphComp(int cantNodos){		// genera un digrafo completo de n nodos
	int n = cantNodos;
	int m = n * (n - 1);
	vector<int> c1(m);
	vector<int> c2(m);
	vector<int> p(m);

	int k = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(j != i){
				c1[k] = i;
				c2[k] = j;
				int x1 = rand() % 100;
				if(x1 == 0){
					x1++;
				}
				p[k] = x1;
				k++;
			}
		}
	}

	struct Graph* grafo = crearGrafo(n, m, c1, c2, p);

	// mostrarGrafo(n, m, c1, c2, p);

	// int h1 = Ej2Testeo(grafo);
	// cout << "La respuesta es: " << h1 << endl;
	return grafo;
}

void expGrafos(){			// con grafos completos, para ver qué onda
	fstream s ("Exp.csv", ios::out);

	s << "cantNod,Res" << endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;

	for(int i = 2; i < 10; i++){
		for(int j = 0; j < 5; j++){
			s << i;
			s << ",";
			struct Graph* grafo = genGraphComp(i);
			int h1 = Ej2Testeo(grafo);
			s << h1 << endl;
		}
	}
}

// void Test5(){			// debe dar Segmentation Fault pero no pasa nada porque no hay pesos que sean 0
// 	int n = 4;
// 	int m = 3;
// 	struct Graph* grafo = createGraph(n, m);

// 	grafo->edge[0].src = 1;
// 	grafo->edge[0].dest = 3;
// 	grafo->edge[0].weight = 0;

// 	grafo->edge[1].src = 3;
// 	grafo->edge[1].dest = 2;
// 	grafo->edge[1].weight = 0;

// 	grafo->edge[2].src = 2;
// 	grafo->edge[2].dest = 1;
// 	grafo->edge[2].weight = 0;	

// 	int h = Ej2(grafo);
// 	cout << "La respuesta es: " << h << endl;
// }


int main(){
	srand (time(NULL));
	Test1();
	Test2();
	Test3();
	Test4();
	// genGraphNigualM(10);
	// genGraphComp(4);
	// expGrafos();
	return 0;
}