#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int sx, sy;
vector<vector<char>> map;
vector<array<int, 2>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool simulate() {
    int nsteps = 0;
    int d = 0;
    int x = sx, y = sy;
    int nx = x + dir[d][0];
    int ny = y + dir[d][1];
    while(nx >= 0 && ny >= 0 && nx < n && ny < m) {
        if(map[nx][ny] == '#') {
            d = (d + 1) % 4;
        }
        else {
            nsteps++;
            if(nsteps > n*m)
                return true;
            x = nx, y = ny;
        }
        nx = x + dir[d][0];
        ny = y + dir[d][1];
    }
    return false;
}

int main() {
    cin >> n >> m;
    map.resize(n);
    for(int i = 0; i < n; i++) {
        map[i].resize(m);
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] == '^')
                sx = i, sy = j;
        }
    }


    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == '.') {
                map[i][j] = '#';
                if(simulate())
                    ans++;
                map[i][j] = '.';
            }
        }
    }
    cout << ans << endl;
}
