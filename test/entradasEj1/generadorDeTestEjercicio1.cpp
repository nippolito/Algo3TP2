#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <iostream>

using namespace std;

int main ()
{
	system("touch entradas.txt");
  fstream f ("entradas.txt", ios::in | ios::out);
  int n;

  srand (time(NULL));

  /* generate secret number between 1 and 10: */

  for(int z = 0; z < 50; z++){
    n = rand() %  30 + 10;
    int aux = n* (n-1) / 2  -1;
    int m =  rand() % aux + 1;

    int o = rand() % n;
    int d = rand() % n;
    if(d == o) o = d-1; // por si tengo la mala leche de que me salgan la misma ciudad.
    int k = rand() % 20 + 8 ;
    int cantPremiums = rand() % m/2;

    f << n <<" " << m <<" " << o << " " << d << " " << k << endl;
    for(int i = 0; i < m  ; i ++){
      int c1 = rand() % n;
      int c2 = rand() % n;
      if(c1 == c2) c1 = c2-1;
      int p ;
      if(i < cantPremiums) p = 1;
      else p = 0;
      int dist = rand() % 20 + 1;
      f << c1 << " " << c2 << " " << p << " " << dist << endl;
    }
    f << "\n\n\n\n\n\n";
  }

  f << "-1 -1" <<endl;


  f.close();

  return 0;
}