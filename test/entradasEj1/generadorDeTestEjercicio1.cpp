#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <iostream>

using namespace std;
int matriz[40][40];

int main ()
{
	system("touch entradas.txt");
  fstream f ("entradas.txt", ios::in | ios::out);
  int n;

  srand (time(NULL));

  /* generate secret number between 1 and 10: */

  for(int z = 0; z < 3; z++){
    n = rand() %  30 + 10;
    int aux = n* (n-1) / 2  -1;
    int m =  rand() % aux + 1;

    int o = rand() % n + 1;
    int d = rand() % n + 1;
    if(d == o) o = d-1; // por si tengo la mala leche de que me salgan la misma ciudad.
    int k = rand() % 20 + 8 ;
    int cantPremiums = rand() % m/2;


    for(int i = 0 ; i < n; i ++){
      for(int j = 0 ; j < n; j ++) matriz[i][j]= -1;
    }

    f << n <<" " << m <<" " << o << " " << d << " " << k << endl;
    for(int i = 0; i < m  ; i ++){
      int c1 = rand() % n + 1;
      int c2 = rand() % n + 1;
      if(c1 == c2) c1 = c2-1;
      int p ;
      if(i < cantPremiums) p = 1;
      else p = 0;
      int dist = rand() % 20 + 1;
      

      if(matriz [c1][c2] == -1 && c1 != c2){
        matriz[c1][c2] = 1;
        matriz[c2][c1] = 1;
        f << c1 << " " << c2 << " " << p << " " << dist << endl;
      }
      else{
        i=i-1; //try again bro
      }
    }
    f << "\n\n\n\n\n\n";
  }

  f << "-1 -1" <<endl;


  f.close();

  return 0;
}