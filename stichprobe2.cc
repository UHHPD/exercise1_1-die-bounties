#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

void print(list<double> const &list)
{
    std::copy(list.begin(),
            list.end(),
            ostream_iterator<double>(cout, "\n"));
}

int main () {
  double value;
  double sum = 0;
  int count = 0;
  double var = 0;
  double var_count = 0;
  double var_count_bessel = 0;
  double mean_val;
  list<double> store_mean;
  list<double> store_variance;
  list<double> store_variance_bessel;
  double store_arr[9] = {0,0,0,0,0,0,0,0,0};
  ifstream inFile ("datensumme.txt");
  ofstream outFileM;
  ofstream outFileV;
  outFileM.open ("mittelwerte.txt");
  outFileV.open ("varianzen.txt");
  if (inFile.is_open())
  {
/*    use one looop to compute mean value and variance by storing the input number in an array of length 9
    and refillling this array for the next sequence of numbers*/
    while( !inFile.eof() )
    {
      inFile >> value;
      if (inFile.eof()) {break;}
      store_arr[count] = value;
      count++;
      if (count==9){
        double store_sum = 0;
        for (int j=0; j<9; j++) {
          store_sum += store_arr[j];
        }
        mean_val = store_sum/9;
        outFileM << mean_val << "\n";
        store_mean.push_back(mean_val);
        var_count = 0.0;
        var_count_bessel = 0.0;
        for (int i=0; i<9; i++) {
          double diff = store_arr[i]-mean_val;
          double var = pow(diff, 2);
          var_count += var/9;
          var_count_bessel += var/8;
        }
        outFileV << var_count << "\n";
        store_variance.push_back(var_count);
        store_variance_bessel.push_back(var_count_bessel);
        count = 0;
      }
    }
  outFileM.close();
  outFileV.close();
  }
  inFile.close();

  // compute mean of the means and variances
  double mean_of_means = 0;
  for (list<double>::iterator it = store_mean.begin(); it != store_mean.end(); it++){
    mean_of_means += *it/26;
    }

  double mean_of_variances = 0;
  for (list<double>::iterator it = store_variance.begin(); it != store_variance.end(); it++){
    mean_of_variances += *it/26;
    }
  double mean_of_variances_bessel = 0;
  for (list<double>::iterator it = store_variance_bessel.begin(); it != store_variance_bessel.end(); it++){
    mean_of_variances_bessel += *it/26;
    }
  cout << mean_of_means << "\n";
  cout << mean_of_variances << "\n";
  cout << mean_of_variances_bessel << "\n";
}