#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <list>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

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

  ofstream outFile;
  outFile.open("hist.txt");
  for (int i=0; i<11; i++) {
    outFile << i << " " << zaehler[i] << "\n";
  }
  outFile.close();

  for ( unsigned int k = 0 ; k < zaehler.size () ; ++ k ) {
    cout << k << " : " << zaehler [k] << endl ;
  }
 }
