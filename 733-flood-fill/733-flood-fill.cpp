class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int scolor, int color) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != scolor || image[sr][sc] == -1)
            return;
        image[sr][sc] = -1;
        dfs(image, sr + 1, sc, scolor, color);
        dfs(image, sr - 1, sc, scolor, color);
        dfs(image, sr, sc + 1, scolor, color);
        dfs(image, sr, sc - 1, scolor, color);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, image[sr][sc], color);
        for(auto &x : image)
            for(auto &y : x)
                if(-1 == y)
                    y = color;
        return image;
    }
};