
class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>& image, int newcolor) {

        int oldcolor=image[r][c];
        image[r][c] = newcolor;     // visit
        queue<pair<int,int>> q;
        q.push({r,c});              // source initialization

        while(!q.empty()){
            pair<int,int> src=q.front();
            q.pop();
            int r=src.first;
            int c=src.second;

            if (r - 1 >= 0 && image[r - 1][c] == oldcolor) {
                image[r-1][c]=newcolor;
                q.push({r-1,c});
            }
            if (r + 1<image.size() && image[r + 1][c] == oldcolor) {
                image[r+1][c]=newcolor;
                q.push({r+1,c});
            }
            if (c - 1 >= 0 && image[r][c-1] == oldcolor) {
                image[r][c-1]=newcolor;
                q.push({r,c-1});
            }
            if (c<image[0].size() && image[r][c+1] == oldcolor) {
                image[r][c+1]=newcolor;
                q.push({r,c+1});
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int oldcolor = image[sr][sc];

        if (oldcolor == color) {
            return image;
        }
        bfs(sr, sc, image, color);
        return image;
    }
};
