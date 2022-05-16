#include<bits/stdc++.h>
using namespace std; 
class cell
{
public:
    double f;
    double g;
    double h;
    int parent_x;
    int parent_y;
    
    cell()
    {
        f = FLT_MAX;g=FLT_MAX;h=FLT_MAX;parent_x=-1;parent_y=-1;
    }
};
bool is_valid_cell(vector<vector<int>>& grid, int i, int j)// i,j should not be out of bound
{
    if((i<grid.size() && i>=0) && (j<grid[0].size() && j>=0))return true;
    return false;
}
bool can_go(vector<vector<int>>& grid, int i, int j) // to check whether path is blocked or not.
{
    if (grid[i][j]==1)return true;
    return false;
} 
double heuristic_of_cell(int i, int j , pair<int,int> dest) // simple distance formula 
{
    return (double)sqrt(((i-dest.first)*(i-dest.first))+((j-dest.second)*(j-dest.second)));
}

void tracePath(vector<vector<cell*>> cellDetails, pair<int,int> dest) // to print the path
{
    printf("\nThe Path is ");
    int row = dest.first;
    int col = dest.second;
    stack<pair<int,int>> Path;
    while (!(cellDetails[row][col]->parent_x == row && cellDetails[row][col]->parent_y == col)) 
    {
        Path.push(make_pair(row, col));
        int temp_row = cellDetails[row][col]->parent_x;
        int temp_col = cellDetails[row][col]->parent_y;
        row = temp_row;
        col = temp_col;
    }
    Path.push(make_pair(row, col));
    while (!Path.empty()) {
        pair<int, int> p = Path.top();
        Path.pop();
        printf("-> (%d,%d) ", p.first, p.second);
    }
    return;
}

int dfs(set<pair<double,pair<int,int>>>& open_list,vector<vector<cell*>> grid_property, vector<vector<int>>& visit, vector<vector<int>>& grid, int i, int j, pair<int,int>& dest,pair<int,int>& parent)
{
    double gNew, hNew, fNew;
    if(is_valid_cell(grid,i,j))
    {
        if(i==dest.first && j==dest.second)
        {
            grid_property[i][j]->parent_x = parent.first;
			grid_property[i][j]->parent_y = parent.second;
            tracePath(grid_property,dest);
            cout<<"Destination has found"<<endl;
            return 3;
        }
        if(visit[i][j]==false && can_go(grid,i,j))
        {
            gNew = grid_property[parent.first][parent.second]->g + 1.0;
            hNew = heuristic_of_cell(i, j, dest);
            fNew = gNew + hNew;
            if (grid_property[i][j]->f == FLT_MAX || grid_property[i][j]->f > fNew) 
            {
                open_list.insert(make_pair(fNew, make_pair(i,j)));
                // Update the details of this cell
                grid_property[i][j]->f = fNew;
                grid_property[i][j]->g = gNew;
                grid_property[i][j]->h = hNew;
                grid_property[i][j]->parent_x = parent.first;
                grid_property[i][j]->parent_y = parent.second;
			}
        }
    }
    return 2;
}
void ASTAR(vector<vector<int>>& grid, pair<int,int> source, pair<int,int> dest)
{
    int m = grid.size(),n=grid[0].size();
    vector<vector<cell*>> grid_property(m,vector<cell*>(n)); // matrix of objects of class 'cell'
    set<pair<double,pair<int,int>>> open_list; // 
    vector<vector<int>> visit(m,vector<int>(n,0));  // visit matrix stores the data of visited cell
    int i = source.first,j=source.second;
    for (int ii = 0; ii < m; ii++) {
		for (int jj = 0; jj < n; jj++) {
            grid_property[ii][jj] = new cell();
		}
	}
    //default constructor automatically gets called, so all the data members of class CELL will automatically get initilise
    //below is source node initilization
    grid_property[i][j]->f=0;
    grid_property[i][j]->g=0;
    grid_property[i][j]->h=0;
    grid_property[i][j]->parent_x=i;
    grid_property[i][j]->parent_y=j;

    open_list.insert({0.0,{i,j}}); // putting source node into our list you can use make_pair or {}

    while (!open_list.empty())
    {
        
        auto curr = *open_list.begin(); // .begin() returns pointer to  the first element so to convert it into actual value use *  
        i = curr.second.first;
        j = curr.second.second;
        open_list.erase(open_list.begin());
        visit[i][j] = 1;
        pair<int,int> parent = {i,j};

        // apply dfs for 8 neighbours
        int a=0;
        a = dfs(open_list,grid_property,visit,grid,i-1,j,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i+1,j,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i,j+1,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i,j-1,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i-1,j-1,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i-1,j+1,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i+1,j+1,dest,parent);
        if(a==3)return;
        a = dfs(open_list,grid_property,visit,grid,i+1,j-1,dest,parent);
        if(a==3)return;
    }
}
int main()
{
    //You can take custom inputs if you are free from life!
    vector<vector<int>> grid = {{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
                                { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
                                { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                                { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }};
	pair<int,int> src = make_pair(8, 0);
	pair<int,int> dest = make_pair(0,0);
	ASTAR(grid, src, dest);
}