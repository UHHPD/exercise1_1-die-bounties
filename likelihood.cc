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

double prob(double mu, vector<int> data) {
	double L = 1;
	for (int k: data) {
		L *= poisson(mu, k);
	}
	return L;
}

int main(){
  vector<int> daten;
  vector<int> uncertainty;
  int value;
  ifstream inFile ("datensumme.txt");
  if (inFile.is_open())
  {
    while( !inFile.eof() )
    {
      inFile >> value;
      if (inFile.eof()) {break;}
      daten.push_back(value);
    }
  }
  inFile.close();

  ofstream outFile1;
  ofstream outFile2;
  ofstream outFile3;
  outFile1.open("likelihood.txt");
  outFile2.open("nll.txt");
  outFile3.open("deltanll.txt");
  for (double mean = 0; mean <= 6.0; mean += 0.1) {
  	outFile1 << mean << " " << prob(mean, daten) << "\n";
  	outFile2 << mean << " " << -2*log(prob(mean, daten)) << "\n";
  	outFile3 << mean << " " << -2*log(prob(mean, daten)) + 2*log(prob(3.11538, daten)) << "\n";
    if (-2*log(prob(mean, daten)/prob(3.11538, daten)) < 1.0) {uncertainty.push_back(mean);}
  }
  outFile1.close();
  outFile2.close();
  outFile3.close();

  cout << "likelihood: " << prob(3.11538, daten) << "\n";
}