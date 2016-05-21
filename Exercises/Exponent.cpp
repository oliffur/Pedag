// returns x^y
#include <iostream>

using namespace std;

// returns x^y
double pow(double x, int y){
	if (y==0) return 1;

	// find x to the power of y/2
	double half = pow(x, y/2);
	
	// y = (y/2) + (y/2) + (y%2)
	return half*half*((y%2)*x);
}
