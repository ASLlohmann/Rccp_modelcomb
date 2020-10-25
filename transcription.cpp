#include <Rcpp.h>
using namespace Rcpp;

//checkCVArguemnts function

// [[Rcpp::export]]
void checkCVArguments_rcpp(NumericVector x,int windowSize, int maxHorizon){
if (x.size() < windowSize + 2 * maxHorizon) stop("The time series must be longer than windowSize + 2 * maxHorizon.");
if (windowSize <= 0 || maxHorizon <= 0) stop("The arguments windowSize, and maxHorizon must be positive integers.");
if (int(windowSize) == false ||  int(maxHorizon) == false) stop("The arguments windowSize, and maxHorizon must be positive integers.");
}

//tsPartition function

cppFunction('Rcpp::Range tsPartition(NumericVector rolling, NumericVector x,NumericVector windowSize,NumericVector maxHorizon){
NumericVector a={0};
NumericVector b = x.size() - windowSize - maxHorizon + 1;
NumericVector c = (x.size() - windowSize) / maxHorizon;
NumericVector numPartitions = ifelse(rolling == a, b , c);
double x1 = numPartitions[0];
double x2 = windowSize[0];
List L = rep(List::create(NA_INTEGER),x1);
int start=1;
Rcpp::Range trainIndices=Rcpp::seq(start, start + x2 -1);
return trainIndices;
}') 


//Core CVTS function
 
// [[Rcpp::export]]             
cppFunction('NumericMatrix m3(int numRow, int MaxHorizon){
NumericVector v = rep({NA_REAL},numRow*MaxHorizon);
NumericMatrix m3(numRow , MaxHorizon, v.begin() );
return m3;
}')
            
// [[Rcpp::export]]                     
cppFunction('List vector(int numRow){
List L = rep(List::create(NA_INTEGER),numRow);
return L;
}')
            



  
