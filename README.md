# mcOptionPricer


The package implements a Monte Carlo simulation to calculate the price of a path dependent up-and-in put option. 
The option has a barrier between the moment of pricing and the option expiry and is active only if the stock price is above the barrier.

The Monte Carlo simulation generates random samples of the stock price at the option expiry and calculates the payoff of the option if it is active. The average of all the payoffs is then discounted back to the present value using the risk-free rate.

The ```monte_carlo_up_and_in_put()``` function takes the current stock price (S), strike price (K), option expiry time (t), risk-free rate (r), volatility (sigma), barrier (H), and number of simulations (N) as inputs and returns the price of the up-and-in put option.

This implementation is written in Rcpp and can be easily integrated with R for use in financial applications. The code uses the standard normal distribution to generate random samples of the stock price and the C++ standard library for random number generation.

Overall, the implementation is efficient and accurate, making it a useful tool for pricing path dependent options in financial applications.



## Install the package from Github
```{r}
#devtools::install_github("https://github.com/Macosso/mcOptionPricer")

```

## Load the library
```{r}
library(mcOptionPricer)
```


## Computation
Compute the European theoretical Option price for a up-and-in put option for the following parameters
```{r}
S0 <- 95 #price of the underyling at the moment of option pricing
K <- 100 #strike price
sigma <- 0.24 #annualized volatility rate
r <- 0.07 #annualized risk-free rate r
t <- 0.75 #time to maturity
N = 1000 # number of simulations
b = 80 # barrier

#Ct --> Option Price
Ct = mcOptionPricer::monte_carlo_up_and_in_put(S0, K, t, r, sigma, b, N)
Ct
[1] 3.607434
```


# Main Assumptions
This implementation of Monte Carlo simulation of the up-and-in put option makes the following assumptions:

1. The stock price follows a geometric Brownian motion: This means that the stock price evolves over time according to a random walk with a drift and volatility.

2. The drift and volatility are constant over the life of the option: The simulation assumes that the drift and volatility are constant over the life of the option, which may not always be the case in reality.

3. The option is European: The option can only be exercised at the option expiry, which is a common assumption for European options.

4. The risk-free rate is constant: The simulation assumes that the risk-free rate remains constant over the life of the option, which may not always be the case in reality.

5. The option is path dependent: The option depends on the stock price at the option expiry, and not just the final stock price. The option is active only if the stock price is above the barrier between the moment of pricing and the option expiry.

6. The option is priced using Monte Carlo simulation: The simulation uses random samples of the stock price to estimate the price of the option. This means that the results may vary with different random seeds or number of simulations.
