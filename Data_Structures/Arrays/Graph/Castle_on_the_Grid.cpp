#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class point
{
public:
    int x,y;
    point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) 
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> color(n,vector<char> (m,'w'));
    vector<vector<point*>> pred(n,vector<point*> (m));
    queue<point*> que;
    que.push(new point(startX, startY));
    pred[startX][startY] = new point(-1, -1);

    vector<vector<int>> dir= {{1,0},{0,1},{-1,0},{0,-1}};

    int turns = 0;
    while(!que.empty())
    {
        int r = que.front()->x;
        int c = que.front()->y;
        color[r][c] = 'r';
        que.pop();
        // cout<<r<<" "<<c<<endl;

        if(r == goalX && c == goalY)
        {
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=0;j<m;j++)
            //         if(pred[i][j])
            //             cout<<pred[i][j]->x<<", "<<pred[i][j]->y<<"  ";
            //         else
            //             cout<<" null ";
            //     cout<<endl;
            // }
            // cout<<r<<" "<<c<<" "<<turns<<endl;
            // cout<<pred[r][c]->x<<" "<<pred[r][c]->y<<endl;
            int i = r, j = c;
            while(r != -1 && c != -1)
            {
                r = pred[i][j]->x;
                c = pred[i][j]->y;
                i = r, j = c;
                turns++;
                // cout<<r<<" "<<c<<" "<<turns<<endl;
            }
            return turns-1;
        }

        for(int d=0;d<4;d++)
        {
            int i = r + dir[d][0];
            int j = c + dir[d][1];
            while(i >= 0 && j >= 0 && i < n && j < m && color[i][j] != 'r' && grid[i][j] == '.')
            {
                if(color[i][j] == 'g')
                {
                    i += dir[d][0];
                    j += dir[d][1];
                    continue;
                }
                color[i][j] = 'g';
                pred[i][j] = new point(r,c);
                que.push(new point(i,j));
                i += dir[d][0];
                j += dir[d][1];
            }
        }
    }

    return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string startXStartY_temp;
    getline(cin, startXStartY_temp);

    vector<string> startXStartY = split_string(startXStartY_temp);

    int startX = stoi(startXStartY[0]);

    int startY = stoi(startXStartY[1]);

    int goalX = stoi(startXStartY[2]);

    int goalY = stoi(startXStartY[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
