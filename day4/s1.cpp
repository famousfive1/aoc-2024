#include <iostream>
#include <vector>

int n, m;
long ans;
int dir[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
char letters[4] = "MAS";

void check(std::vector<std::vector<char>>& mat, int i, int j) {
    for (int d = 0; d < 8; d++) {
        int a = i, b = j;
        bool fnd = true;
        for (int p = 0; p < 3; p++) {
            a += dir[d][0];
            b += dir[d][1];
            if (a < 0 || b < 0 || a >= n || b >= m) {
                fnd = false;
                break;
            }
            if (mat[a][b] != letters[p]) {
                fnd = false;
                break;
            }
        }
        if (fnd)
            ans++;
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] == 'X')
                check(mat, i, j);

    std::cout << ans << std::endl;

    return 0;
}
