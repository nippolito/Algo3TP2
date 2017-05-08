#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

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
		int n = m.size();

		for(int i = 0; i < n; i ++){
			v.push_back(false);
		}
		m.push_back(v);
		for(int i = 0; i < n+1; i++){
			m[i].push_back(false);
		}
	}
	//////////////////////////////////////////////////////	
	void AgregarArista(int x, int y){
		m[x][y]= true;
	}
	//////////////////////////////////////////////////////
	bool SonVecinos(int x, int y ){
		return m[x][y];
	}
	//////////////////////////////////////////////////////
	void Vecinos(int x, std::vector< int >& res){
		int size = m.size();
		for(int i = 0 ; i < size; i ++){
			if(m[x][i]) res.push_back(i);
		}
	}
	//////////////////////////////////////////////////////
	void Mostrar(){
		int size = m.size();
		cout << "0[ " ;
			for(int j = 0 ; j < size-1; j ++){
				cout << j+1 << " ,  ";
			}
		cout << size <<" ]" <<endl;
		for(int i = 0; i< size; i ++){
			cout << i+1<<"[ ";
			for(int j = 0 ; j < size-1; j ++){
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