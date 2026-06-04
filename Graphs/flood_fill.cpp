#include<bits/stdc++.h>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& image, int color, int old_color){
    int n=image.size();
    int m=image[0].size();

    image[sr][sc] = color;
    vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    for(auto dir: directions){
        int new_sr = sr + dir.first;
        int new_sc = sc + dir.second;

        if(new_sr >= 0 && new_sr < n && new_sc >= 0 && new_sc < m && image[new_sr][new_sc] == old_color){
            dfs(new_sr, new_sc, image, color, old_color);
        }
    }
}

vector<vector<int>> flood_fill(int sr,int sc,vector<vector<int>>& image, int color){
    int old_color = image[sr][sc];
    if(old_color == color) return image;
    dfs(sr,sc,image,color,old_color);
    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int newColor = 2;

    vector<vector<int>> ans =
        flood_fill(sr, sc, image, newColor);

    cout << "Flood Filled Image:\n";

    for(auto row : ans)
    {
        for(auto cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}