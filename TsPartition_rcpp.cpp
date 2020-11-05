#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
cppFunction('List forecastm(List slices, Function f, NumericVector x, double h) {
   for(int i = 0; i < n; ++i) {
    Rcpp::Range trainIndices=Rcpp::seq(start, start + x2 -1);
    Rcpp::Range  testIndices=Rcpp::seq(start + x2, start + x2 + h - 1);
    slices[i] = List::create(Named("TrainIndices")=trainIndices,Named("TestIndices")=testIndices);
    start += 1;
  }
  Function forecast("forecast");
  return  forecast(f(x),Named("h")=2);
}')


// [[Rcpp::export]]
cppFunction('NumericVector tsSubsetWithIndices(NumericVector tsTrain, NumericVector trainIndices) {
Function timer("time");  
NumericVector time=timer(tsTrain);
double minv = min(trainIndices);
double maxv = max(trainIndices);
Function windowr("window");  
NumericVector wdw=windowr(tsTrain, Named("start")=time[minv], _["end"]=time[maxv]);
return wdw;
}')

// [[Rcpp::export]]
List  tsPartition(double rolling, NumericVector x,NumericVector windowSize,NumericVector maxHorizon){

  // Create number of partitions:

  NumericVector condition={0};
  NumericVector b = x.size() - windowSize - maxHorizon + 1;
  NumericVector c = (x.size() - windowSize) / maxHorizon;
  NumericVector numPartitions = ifelse(rolling == condition, b , c);

  // Set-up:

  double start=1;
  double x2 = windowSize[0];
  double n  = numPartitions[0];
  double h = maxHorizon[0];

  // Set-up:

  List slices = rep(List::create(List::create(Named("trainIndices")=0,Named("testIndices")=0)),n);

  for(int i = 0; i < n; ++i) {
    Rcpp::Range trainIndices=Rcpp::seq(start, start + x2 -1);
    Rcpp::Range  testIndices=Rcpp::seq(start + x2, start + x2 + h - 1);
    slices[i] = List::create(Named("TrainIndices")=trainIndices,Named("TestIndices")=testIndices);
    start += 1;
  }
  return slices;
  }


