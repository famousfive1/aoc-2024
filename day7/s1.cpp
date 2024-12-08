#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<long long>& vals, long long res) {
    int nop = vals.size() - 1;
    int mask = (1 << nop) - 1;

    while(mask >= 0) {
        long long run = vals[0];
        for(int i = 0; i < nop; i++) {
            if(mask & (1 << i)) {
                run += vals[i+1];
            }
            else {
                run *= vals[i+1];
            }
        }
        if(res == run)
            return true;
        mask--;
    }
    return false;
}

int main() {
    string line;
    char c;
    long long ans = 0;
    while(getline(cin, line)) {
        istringstream stream(line);
        long long res;
        stream >> res >> c;
        vector<long long> vals;
        long long x;
        while(stream >> x)
            vals.push_back(x);
        if(check(vals, res))
            ans += res;
    }
    cout << ans << endl;
    return 0;
}
