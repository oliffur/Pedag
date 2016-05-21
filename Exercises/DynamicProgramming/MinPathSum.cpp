#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int findMax(int x, int y, vector< vector<int> >& dpGrid, \
            vector< vector<int> >& grid);

int findMinSumPath(vector< vector<int> >& grid){
    if (grid.empty()) return 0;
    int numRows = grid.size();
    int numCols = grid[0].size();
    
    vector< vector<int> > dpGrid(numRows, vector<int>(numCols, -1));
    
    int tempSum = 0;
    
    for (int i = 0; i !=numRows; i++){
        tempSum += grid[i][0];
        dpGrid[i][0] = tempSum;
    }
    
    tempSum = 0;
    
    for (int i = 0; i !=numCols; i++){
        tempSum += grid[0][i];
        dpGrid[0][i] = tempSum;
    }
    
    return findMax(numRows-1, numCols-1, dpGrid, grid);
    
}

int findMax(int x, int y, vector< vector<int> >& dpGrid, \
            vector< vector<int> >& grid){
    int xPrev, yPrev;
    
    if (dpGrid[x-1][y]==-1){
        findMax(x-1, y, dpGrid, grid);
    }
    if (dpGrid[x][y-1]==-1){
        findMax(x, y-1, dpGrid, grid);
    }
    dpGrid[x][y] = max(dpGrid[x-1][y],dpGrid[x][y-1]) + grid[x][y];
    
    return dpGrid[x][y];
}

int main(){
    vector<vector<int>> grid(8,vector<int>(12,8));
    cout<< findMinSumPath(grid)<< endl;
    return 0;
}


