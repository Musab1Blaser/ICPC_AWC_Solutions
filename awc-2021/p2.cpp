#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int, int>> math_tol_int (n);
    for (int i = 0; i < n; i++) cin >> math_tol_int[i].second;
    for (int i = 0; i < n; i++) cin >> math_tol_int[i].first;
    sort(math_tol_int.begin(), math_tol_int.end(), std::greater<pair<int, int>>());
    
    int m; cin >> m;
    vector<pair<int, int>> phy_int_tol (m);
    for (int i = 0; i < m; i++) cin >> phy_int_tol[i].first;
    for (int i = 0; i < m; i++) cin >> phy_int_tol[i].second;
    sort(phy_int_tol.begin(), phy_int_tol.end(), std::greater<pair<int, int>>()); // sort by desc intelligence

    vector<vector<long long>> phy_tol_intpref(101, vector<long long> (1, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= 100; j++)
            if (phy_int_tol[i].second >= j) // if can tolerate
                phy_tol_intpref[j].push_back(phy_tol_intpref[j].back() + phy_int_tol[i].first); // add this guys intelligence
    }

    long long ans = phy_tol_intpref[0].back();
    vector<int> math_int = {};
    for (int i = 0; i < n; i++){
        int tol = math_tol_int[i].first;
        math_int.push_back(math_tol_int[i].second);
        sort(math_int.begin(), math_int.end(), std::greater<int>());
        long long cur_int = 0;
        for (int j = 0; j <= i; j++){
            cur_int += (long long) math_int[j];
            if (tol > phy_tol_intpref[j+1].size())
                ans = max(ans, cur_int + phy_tol_intpref[j+1].back());
            else
                ans = max(ans, cur_int + phy_tol_intpref[j+1][tol]);
        }
    }
    cout << ans << endl;
}