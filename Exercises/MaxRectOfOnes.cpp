/* given a 2D grid filled with 0's and 1's, find the largest rectangle
 * containing all 1's and return its area
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

int findLargestRect(vector<int>& vec);

int maxRectangle(vector<vector<int>>& grid){
    int xLen = grid.size();
    int yLen = xLen==0 ? 0 : grid[0].size();
    
    vector<vector<int>> heights(yLen, vector<int>(xLen, 0));
    
    int maxArea = 0;
    for (int i = yLen-1; i>=0; i--){
        for (int j = 0; j<xLen; j++){
            if (i == xLen-1){
                heights[i][j] = 0;
            }
            else{
                heights[i][j] = grid[i][j]==0 ? 0 : heights[i+1][j]+1;
            }
        }
    }
    
    for (int i = 0; i < yLen; i++){
        int temp = maxHistogram(heights[i]);
        if (maxArea<temp) maxArea = temp;
    }
    return maxArea;
}

