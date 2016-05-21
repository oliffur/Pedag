#include <iostream>

using namespace std;

int main(){
	
	int i1 = 7.2; // i1 becomes 7
	int i2 {7.2}; // error; expecting int
	int i3 = {7.2}; // same as i2 example; error

	double d1 = 7;
	double d2 {7};
	double d3 = {7};
	
	cout << i1 << i2 << i3 << d1 << d2 << d3;

	return 0;
}
