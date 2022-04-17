#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


#ifdef DBG
    #include "debug.h"
#else
    #define dbg(...)
#endif

string s;
int** dp;
int** path;
pair<int,int>* pairs;
int n;
int pos;

int isValid(int i , int j){
    if((s[i] == 'A' and s[j] == 'U') or (s[i] == 'U' and s[j] == 'A'))
            return true;
    if((s[i] == 'G' and s[j] == 'C') or (s[i] == 'C' and s[j] == 'G'))
        return true;
    return false;
}

void initialize(int*** a , int n){
    *a = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        (*a)[i] = (int*)calloc(n , sizeof(int));
}

void findOptimalPairing(){

    for(int diff = 5; diff < n; diff++)
    {
        for(int i = 0 , j = i + diff; i < n && j < n; i++ , j++){
            dp[i][j] = dp[i][j - 1];
            path[i][j] = -1;
            if((isValid(i , j) * (1 + dp[i + 1][j - 1])) > dp[i][j]){
                dp[i][j] = isValid(i , j) * (1 + dp[i + 1][j - 1]);
                path[i][j] = i;
            }
            for(int t = i + 1; t < j - 4; t++){
                if((isValid(t , j) * (1 + dp[i][t - 1] + dp[t + 1][j - 1])) > dp[i][j]){
                    dp[i][j] = isValid(t , j) * (1 + dp[i][t - 1] + dp[t + 1][j - 1]);
                    path[i][j] = t;
                }
            }
        }
    }
}

void getPairs(int i, int j){

    if(dp[i][j] == 0)
        return;

    if(path[i][j] == -1){
        getPairs(i , j - 1);
        return;
    }
    
    pairs[pos] = {path[i][j] , j};
    pos++;
    if(i != path[i][j])
        getPairs(i , path[i][j] - 1);
    getPairs(path[i][j] + 1 , j - 1);
}

int solve(){
    cin >> s;
    n = (int)(s.size());

    initialize(&dp , n);
    initialize(&path , n);

    findOptimalPairing();
    
    int ans = dp[0][n - 1];
    pairs = (pair<int,int>*)malloc(sizeof(pair<int,int>) * ans);
    pos = 0;
    getPairs(0 , n - 1);
    sort(pairs , pairs + ans);

    cout << "Predicted pairings: " << ans << "\n";
    for(int i = 0; i < ans; i++)
        cout << pairs[i].first << "-" << pairs[i].second << " (" << s[pairs[i].first] << "-" << s[pairs[i].second] <<")\n";
    return 0;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}
