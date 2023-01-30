#include <Rcpp.h>
using namespace Rcpp;
#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// [[Rcpp::export]]
double monte_carlo_up_and_in_put(double S0, double K, double t, double r, double sigma, double b, int N = 10000) {
  double sum = 0.0;
  default_random_engine generator;
  normal_distribution<double> distribution(0.0,1.0);
  
  for (int i = 0; i < N; i++) {
    double S_T = S0 * exp((r - 0.5 * pow(sigma,2)) * t + sigma * sqrt(t) * distribution(generator));
    if (S_T > b) {
      sum += max(K - S_T, 0.0);
    }
  }
  return (exp(-r * t) * sum / N);
}
