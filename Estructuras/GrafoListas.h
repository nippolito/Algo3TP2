#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <iostream>
#include <vector>

using namespace std;

class GrafoMatriz{
public:
	GrafoMatriz(){}
	//////////////////////////////////////////////////////	
	GrafoMatriz(vector <vector<bool> >& otro){
		m  = otro;
	}
	//////////////////////////////////////////////////////	
	~GrafoMatriz(){}
	//////////////////////////////////////////////////////
	void AgregarNodo(){
		std::vector<bool> v;
		m.push_back(v);
	}
	//////////////////////////////////////////////////////	
	void AgregarArista(int x, int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}
	//////////////////////////////////////////////////////
	bool SonVecinos(int x, int y ){
		int res = false;
		int n = m[x].size();
		for(int i = 0 ; i < n; i ++){
			if (m[x][i] == y) res = true;
		}
		return res;
	}
	//////////////////////////////////////////////////////
	void Vecinos(int x, std::vector< int >& res){
		res = m[x];
	}
	//////////////////////////////////////////////////////
	void Mostrar(){
		int size = m.size();
		for(int i = 0; i< size; i ++){
			cout << i+1<<"[ ";
			int n = m[i].size();
			for(int j = 0 ; j < n; j ++){
				cout << m[i][j] << " ,  ";
			}
			cout << m[i][size-1]<<" ]" <<endl;
		}
	}
	//////////////////////////////////////////////////////


private:
	std::vector< vector< bool > > m;


};



#endif