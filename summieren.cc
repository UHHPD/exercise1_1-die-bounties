#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main () {
  int value1, value2;
  int sum;
  string line;
  ifstream inFile ("daten.txt");

  ofstream outFile;
  outFile.open ("summieren.txt");

  if (inFile.is_open())
  {
    //write the first line to the terminal
    while( !inFile.eof() )
    {
      inFile >> value1 >> value2;
      if (inFile.eof()) {break;}
      sum = value1+value2;
      cout << sum << "\n";
      outFile << sum << "\n";
    }
    inFile.close();
    outFile.close();
  }

  else cout << "Unable to open file";

  return 0;
}
