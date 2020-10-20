#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
void checkCVArguments_rcpp(NumericVector x,int windowSize, int maxHorizon){
if (x.size() < windowSize + 2 * maxHorizon) stop("The time series must be longer than windowSize + 2 * maxHorizon.");
if (windowSize <= 0 || maxHorizon <= 0) stop("The arguments windowSize, and maxHorizon must be positive integers.");
if (int(windowSize) == false ||  int(maxHorizon) == false) stop("The arguments windowSize, and maxHorizon must be positive integers.");
}


// [[Rcpp::export]]
cppFunction('Rcpp::Range tsPartition(NumericVector y, int windowSize, int maxHorizon){
int x= (y.size() - windowSize) / maxHorizon;
List L = rep(List::create(NA_INTEGER),x);
int start = 1;
Rcpp::Range s=Rcpp::seq(start, start + windowSize -1);
return s; 
 }')
 
