#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<vector<int>> row_errors(n); // error = i means i, doesn't match with i-1
        vector<vector<int>> col_errors(n); // error = i means i, matches with i-1
        vector<vector<int>> grid (n, vector<int> (n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                char x;
                cin >> x;
                grid[i][j] = (x == 'W') ? 1 : 0;
                if (j >= 1 && grid[i][j] != grid[i][j-1]) row_errors[i].push_back(j);
                if (i >= 1 && grid[i][j] == grid[i-1][j]) col_errors[j].push_back(i);
            }
        }
        for (int i = 0; i < n; i++) row_errors[i].push_back(n);
        for (int i = 0; i < n; i++) col_errors[i].push_back(n);

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int i_lim = *upper_bound(col_errors[j].begin(), col_errors[j].end(), i) - 1;
                int i_minl = -1;
                if (j > 0 && grid[i][j-1] == grid[i][j]) i_minl = *upper_bound(col_errors[j-1].begin(), col_errors[j-1].end(), i) - 1; // min req. height for maxi
                if (i_minl >= i_lim) continue; // maxi will always have left column
                int j_minl = -1;
                if (i > 0 && grid[i-1][j] != grid[i][j]) j_minl = *upper_bound(row_errors[i-1].begin(), row_errors[i-1].end(), j) - 1; // min req. width for maxi
                int j_lim = j; 
                
                while (j_lim + 1 < n && grid[i][j_lim + 1] == grid[i][j_lim]){ // can move to next column
                    int ni_lim = *upper_bound(col_errors[j_lim + 1].begin(), col_errors[j_lim + 1].end(), i) - 1; // new height
                    if (ni_lim < i_lim){ // will affect height
                        if (j_lim > j_minl) { // better than above 
                            maxi++;
                        }
                        i_lim = ni_lim;
                        if (i_lim <= i_minl) break;
                    } 
                    j_lim++;
                }
                if (j_lim > j_minl && i_lim > i_minl) maxi++;
            }
        }
        cout << maxi << endl;
    }
}