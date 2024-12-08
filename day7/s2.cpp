#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<long long>& vals, long long res, int nop, int i, long long run) {
    if(i == nop) return run == res;
    if(check(vals, res, nop, i+1, run + vals[i+1]))
        return true;
    else if(check(vals, res, nop, i+1, run * vals[i+1]))
        return true;
    else {
        int cpy = vals[i+1];
        while(cpy) {
            run *= 10;
            cpy /= 10;
        }
        return check(vals, res, nop, i+1, run + vals[i+1]);
    }
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
        if(check(vals, res, vals.size() - 1, 0, vals[0]))
            ans += res;
    }
    cout << ans << endl;
    return 0;
}
