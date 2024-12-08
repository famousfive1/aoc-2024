#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::vector<int> a, b;
    int x, y;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }

    std::cout << ans << std::endl;
    
    return 0;
}
