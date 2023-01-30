#include <Rcpp.h>
using namespace Rcpp;
#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// [[Rcpp::export]]
double monte_carlo_up_and_in_put(double S0, double K, double t, double r, double sigma, double b, int N = 10000) {
  // Sum to store the total payoff
  double sum = 0.0;
  
  // Sum to store the total payoff
  default_random_engine generator;
  
  // Normal distribution with mean 0 and standard deviation 1
  normal_distribution<double> distribution(0.0,1.0);
  
  // Loop over number of simulations
  for (int i = 0; i < N; i++) {
    // Calculate stock price at the option expiry
    double S_T = S0 * exp((r - 0.5 * pow(sigma,2)) * t + sigma * sqrt(t) * distribution(generator));
    // Calculate stock price at the option expiry
    if (S_T > b) {
      // Add the payoff to the sum
      sum += max(K - S_T, 0.0);
    }
  }
  // Discount the average payoff back to the present value and return
  return (exp(-r * t) * sum / N);
}
