#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

double poisson(double mu, int k) {
  double p = pow(mu, k)*exp(-mu)/tgamma(k+1);
  return p;
}

int main(){
  vector<int> zaehler;
  zaehler.assign(11, 0);
  int value;
  ifstream inFile ("datensumme.txt");
  if (inFile.is_open())
  {
    while( !inFile.eof() )
    {
      inFile >> value;
      if (inFile.eof()) {break;}
      zaehler[value]+=1;
    }
  }
  inFile.close();

  ofstream outFile1;
  ofstream outFile2;
  outFile1.open("hist.txt");
  outFile2.open("histpoi.txt");

  for (int i=0; i<11; i++) {
    outFile1 << i << " " << zaehler[i] << "\n";
    outFile2 << i << " " << zaehler[i] << " " << 234*poisson(3.11538, i) << "\n";
  }
  outFile1.close();
  outFile2.close();

  for ( unsigned int k = 0 ; k < zaehler.size () ; ++ k ) {
    cout << k << " : " << zaehler [k] << " : " << 234*poisson(3.11538, k) << endl ;
  }
 }
