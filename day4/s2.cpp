#include <iostream>
#include <string>
#include <vector>
#include <array>

int n, m;
long ans;
std::array<std::string, 4> patterns { "MMSS", "SMMS", "SSMM", "MSSM" };

void check(std::vector<std::vector<char>>& mat, int i, int j) {
    std::string pat;
    pat.push_back(mat[i-1][j-1]);
    pat.push_back(mat[i-1][j+1]);
    pat.push_back(mat[i+1][j+1]);
    pat.push_back(mat[i+1][j-1]);
    for (std::string i : patterns) {
        int c = i.compare(pat);
        if (c == 0) {
            ans++;
            break;
        }
    }
}


int main() {
    std::cin >> n >> m;
    std::vector<std::vector<char>> mat(n);
    for (int i = 0; i < n; i++) {
        mat[i].resize(m);
        for (int j = 0; j < m; j++)
            std::cin >> mat[i][j];
    }

    ans = 0;
    for (int i = 1; i < n-1; i++)
        for (int j = 1; j < m-1; j++)
            if (mat[i][j] == 'A')
                check(mat, i, j);

    std::cout << ans << std::endl;

    return 0;
}
