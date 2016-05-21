/* given an array of prices, finds the best times to buy and sell stocks, given
 * that you may buy and sell (1) one time, (2) at most k times, and (3) as many
 * times as you want
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


int buySellOneTime(vector<int>& prices){
	// small case
	if (prices.size()<2) return -1;

	// keeps track of the best profit so far
	int bestSoFar = 0;

	// keeps track of the best profit so far that ends with a sale at the
	// current element
	int bestEndingHere = 0;
	for (int i = 1; i < prices.size(); i++){
		// the new bestEndingHere is either the extended previous version, or
		// a standalone if the previous version is negative
		bestEndingHere = max(0,bestEndingHere) + (prices[i]-prices[i-1]);

		// the new bestSoFar is the maximum of the previous version, or the
		// best includes the current element and is therefore bestEndingHere
		bestSoFar = max(bestSoFar, bestEndingHere);
	}

	return bestSoFar;
}

int buySellKTimes(int k, vector<int>& prices){
    int arrSize = prices.size();
	
    // small cases
    if (arrSize<=1 || k<0) return 0;
    
    // bestWRecent[i][j] represents the maximum profit up to index i using at
    // most j transactions, one of which ends at index i
    vector< vector<int> > bestWRecent = \
		new vector< vector<int> >(arrSize, vector<int>(k+1,0));
	
    // bestSoFar[i][j] represents the maximum profit up to index i using at 
	// most j transactions
    vector< vector<int> > bestSoFar = \
		new vector< vector<int> >(arrSize, vector<int>(k+1,0));
    
    for (int i = 1; i<arrSize, i++){
        // the price differential today
        int diff = prices[i] - prices[i-1];
        
        for (int j=1; j<=k; j++){
            // to get bestWRecent[i][j], you can either join the trade at diff 
			// with a trade that ended at i-1, which is the bestWRecent + diff
			// term, or you can have diff be an independent term, which is the 
			// bestSoFar + diff term
            bestWRecent[i][j] = \
				max(bestSoFar[i-1][j-1] + diff, bestWRecent[i-1][j] + diff);
            
            // the best trade so far either includes diff (bestWRecent) or does
			// not (bestSoFar)
            bestSoFar[i][j] = max(bestSoFar[i-1][j], bestWRecent[i][j]);
        }
    }
    return bestSoFar[arrSize-1][k];
}

// if we can do infinite transactions; this is the same problem as finding all
// ascending sequences
int buySellInfTimes(vector<int>& prices){
	// small cases
    if (prices.size() <= 1) return 0;
    
    int profit = 0;
    
    for (int i = 1; i < prices.size(); i++){
		// find the profit from making a single transaction and add it to the
		// sum if it is greater than 0
        int diff = prices[i] - prices[i-1];
        if (diff>0) profit += diff;
    }
    return profit;
}
    }
}
