/* given a 2D board containing Xs and Os, capture all regions surrounded by X;
 * and change the Os within those regions to Xs
 *
 */

#include <vector>
#include <iostream>

using namespace std;

// method that, from an 'o', merges its neighboring 'o's and marks the current
// node with an '#'
void bfsMerge(vector<vector<char>>& grid, int x, int y);

void flipSurrounded(vector<vector<char>> grid){
    
    if (grid.size() == 0) return;
    
    int colSize = grid.size();
    int rowSize = grid[0].size();
    
    // main idea: merge all elements on all 4 borders, then any remaining
	// element in the middle will be surrounded
    
    // run bfs along left and right border
    for (int i = 0; i < colSize; i++){
        bfsMerge(grid, 0, i);
        bfsMerge(grid, rowSize-1, i);
    }
    
    // run bfs along top and bottom border
    for (int i = 0; i < rowSize; i++){
        bfsMerge(grid, i, 0);
        bfsMerge(grid, i, colSize-1);
    }
    
    // scan through matrix for any 'o's remaining and flip them
	// find all 'm's and make them 'o's.
    for (int i = 0; i < colSize; i++){
        for (int j = 0; j < rowSize; j++){
            if (grid[i][j]=='o'){
                grid[i][j] = 'x';
            }
            else if (grid[i][j] == 'm'){
                grid[i][j] = 'o';
            }
            
        }
    }
    
    return;
}

void bfsMerge(vector<vector<char>>& grid, int x, int y){
    if (x<0 || x>=grid[0].size()) return;
    if (y<0 || y>grid.size()) return;
    
    bfsMerge(grid, x-1, y);
    bfsMerge(grid, x+1, y);
    bfsMerge(grid, x, y-1);
    bfsMerge(grid, x, y+1);
    
    grid[i][j] = 'm';
}
