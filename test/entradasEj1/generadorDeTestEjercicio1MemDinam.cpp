#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <iostream>
#include <stdlib.h> 

using namespace std;
int matriz[40][40];

int main ()
{
	system("touch entradas.txt");
  fstream f ("entradas.txt", ios::in | ios::out);
  int n;

  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  int q ; cin >> q;

  for(int z = 0; z < q; z++){
    n = rand() %  100 + 10;
    int aux = n* 3 ;
    int m =  rand() % aux + 1;

    int o = rand() % n + 1;
    int d = rand() % n + 1;
    if(d == o) o = d-1; // por si tengo la mala leche de que me salgan la misma ciudad.
    
    int cantPremiums = rand() % m;


    int ** matriz = (int**)malloc (sizeof(int*)*n);
    for(int i = 0; i< n; i ++){
      matriz[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i< n; i ++){
      for(int j = 0; j < n; j++){
        matriz[i][j]= -1;
      }
    }


    f << n <<" " << m <<" " << o << " " << d << " " << cantPremiums << endl;
    for(int i = 0; i < m  ; i ++){
      int c1 = rand() % n ;
      int c2 = rand() % n ;
      if(c1 == c2) c1 = c2-1;
      int p ;
      if(i < cantPremiums) p = 1;
      else p = 0;
      int dist = rand() % 50 + 1;
      

      if(matriz [c1][c2] == -1 && c1 != c2){
        matriz[c1][c2] = 1;
        matriz[c2][c1] = 1;
        f << c1+1 << " " << c2+1 << " " << p << " " << dist << endl;
      }
      else{
        bool cambio = false;
        while(cambio == false)
        for(int c2aux = 0; c2aux < n; c2aux++){
          if(matriz[c1][c2aux]== -1){
            c2 = c2aux;
            matriz[c1][c2] = 1;
            matriz[c2][c1] = 1;
            f << c1+1 << " " << c2+1 << " " << p << " " << dist << endl;
            cambio = true;
            break;
          }
          c1 = (c1+1) % n;
        }



      }
    }
    f << "\n\n\n\n\n\n";




    for(int i = 0; i < n; i ++){
      free(matriz[i]);
    }
    free(matriz);
  }

  f << "-1 -1" <<endl;


  f.close();

  return 0;
}