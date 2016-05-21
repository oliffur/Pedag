/* returns the number of primes less than some integer n
 * 
 * 
 */

#include <iostream>
#include <math>
#include <algorithm>

using namespace std;

int countPrimes(int n){
	// small cases
	if (n<2) return 0;
	
	// array to store whether a number is prime or not	
	// first set each entry to true, and then go back and amend
	vector<bool> primes = vector<bool>(n,true);
	
	// for each number, if it is a prime, delete all its multiples in the array
	for(int i = 2; i<= sqrt(n); i++){
		if(primes[i]){
			for (int j = 2*i; j<n; j+=i) primes[j] = false;
		}
	}
	
	// return the sum of the values in the primes array
	return accumulate(primes.begin(), primes.end(), 0);
}

