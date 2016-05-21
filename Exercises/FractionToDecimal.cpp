/* converts fraction to recurring decimal, with recurring part in parentheses
 * 
 */

#include <iostream>
#include <string>

using namespace std;

string fractionToDecimal(int num, int denom){
	// edge cases
    if (num == 0) return "0";
    if (denom == 0) return "(9).";
    
	// string to hold the result
    string result = "";
    
    // take care of negative cases, after which we can deal with positive
	// numbers only
    if ((num<0)^(denom<0)) result += "-";
    num = abs(num);
    denom = abs(denom);
    
    // find quotient and remainder
    int quot = num/denom;
    int rmdr = num%denom;
    
	// from here we will loop dividing as we do by hand, keeping track of the
	// remainders we get and their positions in a map
    unordered_map<int, int> map;
    while (rmdr!=0){
		// if the map already contains this remainder, then we stop, go back
		// to the first occurrence of that remainder, and add parentheses
        if (map.count(rmdr)){
            int beg = map.get(rmdr);
            string nonRecur = result.substring(0,beg);
            string recur = result.substring(beg, result.size());
            result = nonRecur + "(" + recur + ")";
            return result;
        }
        map.put(rmdr, result.length());
		rmdr *= 10;
        quot = rmdr / denom;
        result += quot;
        rmdr = (rmdr % denom);
    }
    
    return result;
}
