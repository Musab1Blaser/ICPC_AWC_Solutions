#include <bits/stdc++.h>
using namespace std;

vector<long long> conv(long long n, long long b){
    vector<long long> result;
    while (n > 0){
        result.push_back(n % b);
        n /= b;
    }
    reverse(result.begin(), result.end());
    result.push_back(b); // base
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    long long t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        if (n <= 20)
        {
            if (n == 6) cout << 5 << " " << 2 << "\n";
            else if (n == 7)  cout << 6 << " " << 2 << "\n";
            else if (n == 9)  cout << 3 << " " << 2 << "\n";
            else if (n == 10)  cout << 3 << " " << 2 << "\n";
            else if (n == 12)  cout << 3 << " " << 2 << "\n";
            else if (n == 13)  cout << 12 << " " << 3 << "\n";
            else if (n == 14)  cout << 13 << " " << 3 << "\n";
            else if (n == 15)  cout << 14 << " " << 2 << "\n";
            else if (n == 16)  cout << 4 << " " << 2 << "\n";
            else if (n == 17)  cout << 15 << " " << 3 << "\n";
            else if (n == 18)  cout << 9 << " " << 3 << "\n";
            else if (n == 20)  cout << 19 << " " << 4 << "\n";
            else cout << -1 << "\n";
        }
        else {
            long long l = 2; // smallest base
            long long r = sqrt(n); // largest base
            while (r > l){
                long long b = l + (r - l)/2 + (r - l)%2; // need to find smallest val satisfying
                if (b*b + b <= n) l = b;
                else r = b - 1;
            }
            vector<long long> rep = conv(n, r);
            long long ans = n - rep[1];
            cout << ans << " " << r << "\n";
        }
    }
    return 0;
}