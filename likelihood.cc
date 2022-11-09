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
  vector<double> uncertainty;
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
  }
  for (double mean = 3.0; mean <=3.3; mean += 0.01) {
    if (-2*log(prob(mean, daten)/prob(3.11538, daten)) < 1.0) {uncertainty.push_back(mean); cout << "test " << mean << "\n";}
  }
  outFile1.close();
  outFile2.close();
  outFile3.close();

  double sigma_file = 1.65365;
  double normalize_donominator = 1.0;
  for (int i=0; i<daten.size(); i++) {normalize_donominator *= poisson(daten[i], daten[i]);}
  double normalized_likelihood = -2*log(prob(3.11538, daten)/normalize_donominator);
  cout << "normalized: " << -2*log(prob(3.11538, daten)/normalize_donominator) << "\n";
  cout << "likelihood: " << prob(3.11538, daten) << "\n";
  cout << "uncertainty on sample mean approx.: " << sigma_file/sqrt(234) << "\n";
  cout << "uncertainty on estimator: " << (uncertainty[uncertainty.size()-1]-uncertainty[0])/2 << "\n";

  //compute z
  double z = (normalized_likelihood-233)/sqrt(2*233);
  cout << "relative deviation likelihood ratio from mean: " << z << "\n";
}