#include <bits/stdc++.h>
using namespace std;

struct status {
    int x;
    int y;
    int stamina;
    vector<pair<int, int>> food_eaten;
};

int main() {
    int n, m, h, w;
    cin >> n >> m >> h >> w;
    cin.get();

    char maze[n][m];
    int begin_x, begin_y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            maze[i][j] = cin.get();
            if (maze[i][j] == 'P') {
                begin_x = i;
                begin_y = j;
            }
        }
        cin.get();
    }

    // BFS
    queue<status> bfs_queue;
    int maze_max_sta[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            maze_max_sta[i][j] = 0;
        }
    }
    bfs_queue.push(status{begin_x, begin_y, h, {}});
    maze_max_sta[begin_x][begin_y] = h;

    while (bfs_queue.size() > 0) {
        size_t opcount = bfs_queue.size();
        for (int i=0; i<opcount; i++) {
            status st = bfs_queue.front();
            bfs_queue.pop();
            
            vector<pair<int, int>> &food_list = st.food_eaten;

            int stamina = st.stamina-1;
            if (stamina < 0) continue;
            const int offset_x[4] = {-1, 0, 1, 0};
            const int offset_y[4] = {0, -1, 0, 1};
            for (int direction=0; direction<4; direction++) {
                int x2 = st.x+offset_x[direction];
                int y2 = st.y+offset_y[direction];
                if (0<=x2 && x2<n && 0<=y2 && y2<m && maze[x2][y2]!='#') {
                    if (maze[x2][y2] == 'E') {
                        cout << "Yes" << endl;
                        return 0;
                    } else if (maze[x2][y2] == 'F') {
                        if (find(food_list.begin(), food_list.end(), pair<int, int>{x2, y2}) == food_list.end()) {
                            stamina += w;
                            food_list.push_back(pair<int, int>{x2, y2});
                        }
                    }

                    if (stamina > maze_max_sta[x2][y2]) {
                        bfs_queue.push(status{x2, y2, stamina, food_list});
                        maze_max_sta[x2][y2] = stamina;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}