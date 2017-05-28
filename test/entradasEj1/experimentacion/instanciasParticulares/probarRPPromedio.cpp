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
  system("touch MuchasRP.txt");
  fstream f ("MuchasRP.txt", ios::in | ios::out);
  int n;

  srand (time(NULL));

  /* generate secret number between 1 and 10: */
  int q ; cin >> q;

  for(int z = 0; z < q; z+=5){
    for(int index = 0 ; index < 5; index++){
    n = 100; //------------
    int aux = 100 ;
    int m =  1000; // ---------------

    int o = rand() % n;//---------
    int d = rand() % n;//------------
    if(d == o) o = d-1; // por si tengo la mala leche de que me salgan la misma ciudad.
    if(o == -1 ) o = 2;
    int cantPremiums = 0;//-------------------


    int ** matriz = (int**)malloc (sizeof(int*)*n);
    for(int i = 0; i< n; i ++){
      matriz[i] = (int*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i< n; i ++){
      for(int j = 0; j < n; j++){
        matriz[i][j]= -1;
      }
    }


    f << n <<" " << m <<" " << o+1 << " " << d+1 << " " << cantPremiums << endl;
    for(int i = 0; i < m  ; i ++){
      int c1 = rand() % n ;
      int c2 = rand() % n ;
      int p ;
      if(i < z) p = 1;
      else p = 0;
       int dist = rand() % 50 + 1;
      

      if(matriz [c1][c2] == -1 && c1 != c2){
        matriz[c1][c2] = 1;
        matriz[c2][c1] = 1;
        f << c1+1 << " " << c2+1 << " " << p << " " << dist << endl;
      }
      else{
        bool cambio = false;
        while(!cambio){
          for(int i = 0; i < n; i++){
            if(matriz[c1][i]== -1 && c1 != i){
              c2 = i;
              matriz[c1][c2] = 1;
              matriz[c2][c1] = 1;
              f << c1+1 << " " << c2+1 << " " << p << " " << dist << endl;
              cambio = true;
              break;
            }
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
  }

  f << "-1 -1" <<endl;


  f.close();

  return 0;
}