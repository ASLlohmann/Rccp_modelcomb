#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
bool ishybrid(List mod) {
is = mod.inherits("hybridModel");
  return is;
  }


