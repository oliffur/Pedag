/* there is a circle of houses (represented by a vector), each with a certain
 * amount of money; a robber is trying to take as much money as possible, but
 * stealing from any two adjacent houses will cause the police to arrive
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// takes a vector of houses and returns the maximum loot
int rob(vector<int>& houses){
	// keeps track of the maximum loot obtained from the first i houses
    vector<int> dp(houses.size(),0);

	// an integer to keep track of the maximum
    int maximum;
    
    // case 1: the robber steals from the 1st house (and therefore not the 2nd)
    dp[0] = houses[0];
    dp[1] = houses[0];
    
    // no need to check last house since we can't rob it; loop over other houses
    for (int i = 2; i<houses.size()-1; i++){
        dp[i] = max(houses[i] + dp[i-2], dp[i-1]);
    }
    maximum = dp[houses.size()-2];
    
    // case 2: the robber does not steal from the first house
    dp[0] = 0;
    dp[1] = houses[1];
    
    // we may steal from the last house so we need to loop over all the houses
    for (int i = 2; i<houses.size(); i++){
        dp[i] = max(houses[i] + dp[i-2], dp[i-1]);
    }
    
    // compare to our saved variable maximum
    if (dp[houses.size()-1]>maximum) maximum = dp[houses.size()-1];
    
    return maximum;
}

int main(){
    vector<int> houses = {1,5,2,4,3,2,5,1,2,3,1,2,3,1,5};
    cout << rob(houses) << endl;
    
    return 0;
}
