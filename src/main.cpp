#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s; cin >> s;
    int n; n = (int)(s.size());
    vector<vector<int>>ans(n , vector<int>(n , 0));
    auto isValid = [&s](int i , int j) -> int{
        if((s[i] == 'A' and s[j] == 'U') or (s[i] == 'U' and s[j] == 'A'))
            return true;
        if((s[i] == 'G' and s[j] == 'C') or (s[i] == 'C' and s[j] == 'G'))
            return true;
        return false;
    };
    for(int diff = 5; diff < n; diff++)
    {
        for(int i = 0 , j = i + diff; i < n && j < n; i++ , j++){
            int temp = max(ans[i][j - 1] , isValid(i , j) * (1 + ans[i + 1][j - 1]));
            for(int t = i + 1; t < j - 4; t++)
                temp = max(temp , isValid(t , j) * (1 + ans[i][t - 1] + ans[t + 1][j - 1]));
            ans[i][j] = temp;
        }
    }
    cout << ans[0][n - 1] << "\n";
    return 0;
}
