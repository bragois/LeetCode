class Solution {
private:

public:    
    int minPathSum(vector<vector<int>>& grid) {
        unsigned short int row = 0;
        unsigned short int col = 0;
        for(row = 0; row < grid.size(); row++){
            for(col = 0; col < grid[row].size(); col++){
                if((grid[row][col] >= 0) && ( grid[row][col] <= 200)){
                    if(row == 0 && col == 0){
                        // First element is an exception-no action needed
                        grid[row][col] = grid[row][col];
                    }
                    else if(row == 0){
                        // First row is an exception, the current sum is based
                        // only on the left neighbour
                        grid[row][col] += grid[row][col-1];
                    }
                    else if(col == 0){
                        // First column is an exception, the current sum is based
                        // only on the upper neighbour
                        grid[row][col] += grid[row-1][col];
                    }
                    else{
                        grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
                    }
                }
            }
        }
        return grid[row - 1][col - 1];
    }
};