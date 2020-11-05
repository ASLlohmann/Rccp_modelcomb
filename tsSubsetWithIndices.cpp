#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector tsSubsetWithIndices(NumericVector tsTrain, NumericVector trainIndices) {
  Function timer("time");
  NumericVector time=timer(tsTrain);
  double minv = min(trainIndices);
  double maxv = max(trainIndices);
  Function windowr("window");
  NumericVector wdw=windowr(tsTrain, Named("start")=time[minv], _["end"]=time[maxv]);
  return wdw;
}

