#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::unordered_set<int>> rules;
int main(int argc, char* argv[]) {
    std::ifstream in(argv[1], std::ios_base::in);
    std::string line;
    int u, v;
    char c;
    // Rules
    while (std::getline(in, line)) {
        if (line.size() == 0)
            break;
        std::istringstream(line) >> u >> c >> v;
        rules[u].insert(v);
    }

    long long ans = 0;
    // Queries
    while(std::getline(in, line)) {
        std::vector<int> arr;
        std::istringstream iss(line);
        int q;
        while (iss >> q >> c) arr.push_back(q);
        arr.push_back(q);
        int n = arr.size();
        bool poss = true;
        for (int i = 0; poss && i < n; i++)
            for (int j = i+1; poss && j < n; j++)
                if (!rules.count(arr[i]) || !rules[arr[i]].count(arr[j]))
                    poss = false;
        if (poss)
            ans += arr[n / 2];
    }

    std::cout << ans << std::endl;
    return 0;
}
