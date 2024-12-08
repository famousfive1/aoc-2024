#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_map<int, unordered_set<int>> rules;

int main(int argc, char* argv[]) {
    ifstream in(argv[1], ios_base::in);
    string line;
    int u, v;
    char c;
    // Rules
    while (getline(in, line)) {
        if (line.size() == 0)
            break;
        istringstream(line) >> u >> c >> v;
        rules[u].insert(v);
    }

    long long ans = 0;
    // Queries
    while(getline(in, line)) {
        vector<int> arr;
        istringstream iss(line);
        int u;
        while (iss >> u >> c) arr.push_back(u);
        arr.push_back(u);
        int n = arr.size();

        bool poss = true;
        for (int i = 0; poss && i < n; i++)
            for (int j = i+1; poss && j < n; j++)
                if (!rules.count(arr[i]) || !rules[arr[i]].count(arr[j]))
                    poss = false;
        if (poss)
            continue;

        unordered_map<int, int> cnts;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (rules[arr[i]].count(arr[j]))
                    cnts[arr[j]]++;
            }
        }
        queue<int> q;
        for (int u : arr)
            if (cnts[u] == 0)
                q.push(u);

        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : rules[u]) {
                if (cnts.count(v)) {
                    cnts[v]--;
                    if (cnts[v] == 0)
                        q.push(v);
                }
            }
        }
        
        ans += order[n / 2];
    }

    cout << ans << endl;
    return 0;
}
