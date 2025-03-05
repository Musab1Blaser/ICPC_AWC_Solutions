#include <bits/stdc++.h>
using namespace std;

bool eval(vector<int> A, vector<long long> mincost, int target, int k){
    long long cost = 0;
    for (int i = 0; i <= A.size()/2; i++){
        if (cost > k) break;
        if (A[i] <= target) continue;
        if (target == 0) cost += mincost[A[i]+1];
        else cost += mincost[A[i]/(target + 1) + 1];
    }
    return cost <= k;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<long long> mincost(m+2);
        for (int i = 1; i <= m; i++) cin >> mincost[i];

        if (m > 1) mincost[m+1] = 2*mincost[m];
        else mincost[m+1] = 1e9+5;
        mincost[1] = 0;

        for (int i = m; i >= 1; i--) {
            mincost[i] = min(mincost[i], mincost[i+1]);
        }

        for (int i = 2; i <= m; i++)
        {
            for (int j = 2; j*i <= m+1; j++){
                mincost[i*j] = min(mincost[i*j], mincost[i] + mincost[j]);
            }
            mincost[m+1] = min(mincost[m+1], mincost[i] + mincost[(m+i)/i]);
        }
        for (int i = m; i >= 1; i--) {
            mincost[i] = min(mincost[i], mincost[i+1]);
        }

        sort(A.begin(), A.end());
        int l = 0;
        int r = A[n/2];
        while (r > l){
            int mid = l + (r-l)/2;
            if (eval(A, mincost, mid, k)) r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
}