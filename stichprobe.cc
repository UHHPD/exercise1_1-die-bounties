#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main () {
  // part a: compute mean
  double value;
  double sum = 0;
  double count = 0;
  double mean;
  ifstream inFile ("datensumme.txt");
  if (inFile.is_open())
  {
    //first loop to compute the mean
    while( !inFile.eof() )
    {
      inFile >> value;
      if (inFile.eof()) {break;}
      sum += value;
      count ++;
    }
  }
  mean = sum/count;
  cout << "mean:" << mean << "\n";
  inFile.close();

  //part b and c: compute variance and stadard deviation
  double variance = 0;
  inFile.open("datensumme.txt");
  if (inFile.is_open())
  {
    //write the first line to the terminal
    while( !inFile.eof() )
    {
      inFile >> value;
      if (inFile.eof()) {break;}
      double diff_square = pow(value-mean, 2);
      variance += diff_square/count;
    }
  }
    // print variance and stadard diviation
    cout << "variance:" << variance << "\n";
    double sigma = sqrt(variance);
    cout << "standard diviation:" << sigma << "\n";
    inFile.close();
  return 0;
}