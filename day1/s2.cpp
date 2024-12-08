#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::vector<int> a;
    std::map<int, int> b;
    int x, y;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> x >> y;
        a.push_back(x);
        b[y]++;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if (b.count(a[i])) {
            ans += a[i] * b[a[i]];
        }
    }

    std::cout << ans << std::endl;
    
    return 0;
}
