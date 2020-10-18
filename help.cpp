#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
void checkCVArguments_rcpp(NumericVector x,int windowSize, int maxHorizon){
if (x.size() < windowSize + 2 * maxHorizon) stop("The time series must be longer than windowSize + 2 * maxHorizon.");
if (windowSize <= 0 || maxHorizon <= 0) stop("The arguments windowSize, and maxHorizon must be positive integers.");
if (int(windowSize) == false ||  int(maxHorizon) == false) stop("The arguments windowSize, and maxHorizon must be positive integers.");
}




