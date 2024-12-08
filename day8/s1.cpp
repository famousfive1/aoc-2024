#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool checkbounds(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int main() {
    string line;
    vector<vector<char>> map;
    while(getline(cin, line)) {
        map.push_back(vector<char>(line.begin(), line.end()));
    }
    int n = map.size();
    unordered_map<char, vector<pair<int, int>>> towers;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(map[i][j] != '.')
                towers[map[i][j]].push_back({i, j});

    vector<vector<bool>> antinodes(n, vector<bool>(n, false));
    for(auto freq : towers) {
        vector<pair<int, int>> locs = freq.second;
        int m = locs.size();
        for(int i = 0; i < m; i++) {
            for(int j = i+1; j < m; j++) {
                int dx = locs[i].first - locs[j].first;
                int dy = locs[i].second - locs[j].second;
                int anx = locs[i].first + dx;
                int any = locs[i].second + dy;
                if(checkbounds(anx, any, n))
                    antinodes[anx][any] = true;
                anx = locs[j].first - dx;
                any = locs[j].second - dy;
                if(checkbounds(anx, any, n))
                    antinodes[anx][any] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(antinodes[i][j])
                ans++;
    cout << ans << endl;
    return 0;
}
