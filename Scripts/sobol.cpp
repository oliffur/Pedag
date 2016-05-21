#include <cstdlib>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// ----- SOBOL POINTS GENERATOR BASED ON GRAYCODE ORDER -----------------
// INPUT: 
//   N         number of points  (cannot be greater than 2^32)
//   D         dimension  (make sure that the data file contains enough data!!) 
//   dir_file  the input file containing direction numbers
//
// OUTPUT:
//   A 2-dimensional array POINTS, where
//     
//     POINTS[i][j] = the jth component of the ith point,
//   
//   with i indexed from 0 to N-1 and j indexed from 0 to D-1
//
// ----------------------------------------------------------------------

double **sobol_points(unsigned N, unsigned D)
{
    
    // C[i] = index from the left of the first zero bit of i
    // using 'unsigned' to increase possible values of L and N
    unsigned *grayCodes = new unsigned [N];
    // the index of the first zero bit of 0 is 1
    grayCodes[0] = 1;
    for (unsigned i=1;i<=N-1;i++) {
        // initialize C[i]
        grayCodes[i] = 1;
        unsigned curr = i;
        // determine whether the leftmost digit of curr is 1
        while (curr & 1) {
            // shift curr by 1 bit, and increment C[i]
            curr = curr>>1;
            grayCodes[i]++;
        }
    }
    // array of sobol points
    double* points = new double[N];
    points[0] = 0;

    // computing flip vector; flipBits[1]  = 1000...(31 zeroes)...000
    //                        flipBits[2]  = 0100...(30 zeroes)...000
    //                        ...
    //                        flipBits[32] = 0000.................001

	// instead of making all 32, we only make up to maxLen, since N will probably
	// not be large enough to warrant 32 flipbits
    unsigned maxLen = (unsigned)ceil(log((double)N)/log(2.0)); 
    unsigned *flipBits = new unsigned[maxLen+1]; 
    for (unsigned i=1;i<=maxLen;i++) flipBits[i] = 1 << (32-i); // all m's = 1

    unsigned *sobolBits = new unsigned [N];
    sobolBits[0] = 0;
    for (unsigned i=1; i<=N-1; i++){
        // next sobol bits value is equal to previous one with the previous gray
        // code position flipped
        // 
        // since gray codes follow 12131214121312151213..., first we will flip
		// the first bit, followed by flipping the second bit, followed by 
		// flipping the first bit again, then the third bit, etc.
        sobolBits[i] = sobolBits[i-1] ^ flipBits[grayCodes[i-1]];
        points[i] = (double)sobolBits[i]/pow(2.0,32); 
    }

    delete[] grayCodes;
    delete[] sobolBits;
    delete[] flipBits;
    
    return points;
}


int main()
{

  int N,D;
  cin >> N >> endl;
  cin >> D >> endl;
  double **P = sobol_points(N,D); 

   
    for (int i = 0; i < 10000; i++){
        cout << P[i][0];
    }
}
