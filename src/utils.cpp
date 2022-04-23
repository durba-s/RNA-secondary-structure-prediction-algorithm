#include "utils.hpp"

//the RNA sequence s
string s;

//The 2-D dp matrix ;dp[i][j] = maximum number of valid pairings possible between indices i and j
int** dp;

//The path matrix to get the pairings
int** path;

//length of the RNA sequence s
int n;

pair<int,int>* pairs;
int pos;

/**
* @brief Function to check if the bases at indices i and j in the sequence form a valid pairing. A vaild pairing is the pairing of bases (A and U) and (C and G)
*
* @param i index of the first base
* @param j index of the second base
* @return 1 if (seq[i],seq[j]) is (A,U) or (U,A) or (C,G) or (G,C) i.e the bases at indices i and j in the sequence form a valid pairing
* @return 0 otherwise
*/
int isValid(int i , int j){
    if((s[i] == 'A' and s[j] == 'U') or (s[i] == 'U' and s[j] == 'A'))
            return true;
    if((s[i] == 'G' and s[j] == 'C') or (s[i] == 'C' and s[j] == 'G'))
        return true;
    return false;
}

/**
* @brief Inititialize and allocate memory a two-dimensional matrix A of dimension n x n.
*
* @param a The pointer to the matrix A
* @param n The dimension of the matrix.
*/
void initialize(int*** a , int n){
    *a = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++)
        (*a)[i] = (int*)calloc(n , sizeof(int));
}

/**
* @brief Function to find the maximum number of pairings for the RNA sequence s.
*
*/
void findOptimalPairing(){

    //the difference between i and j ranges from 5 to n-1
    for(int diff = 5; diff < n; diff++)
    {
        for(int i = 0 , j = i + diff; i < n && j < n; i++ , j++){
            //implemeing the recurrence relation
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
        /*cout<<"diff: "<<diff<<endl;
        for(int i1=0;i1<n;i1++){
            for(int j1=0;j1<n;j1++){
                cout<<dp[i1][j1]<<" ";
            }
            cout<<endl;
        }*/
    }
}

/**
* @brief Function which prints the pairs (maximum number) between the indices i and j of the RNA sequence
*
* @param i The lower bound of the indices between which the pairs (max number) have to be printed
* @param j The upper bound of the indices between which the pairs (max number) have to be printed
*/
void getPairs(int i, int j){

    //no pairings between i and j
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

/**
* @brief Used to find the max number of pairings and print the pairs after scanning the RNA sequence s.
*
*/
int solve(){

    //file storing the statistics
    FILE* st = fopen("stats.csv", "a");
    cin >> s;
    n = (int)(s.size());

    fprintf(st,"%d,",n);

    //initialize the dp and path matrices
    initialize(&dp , n);
    initialize(&path , n);

    //get start time of the algorithm
    struct timespec strt = get_time();

    //find the maximum number of pairings
    findOptimalPairing();

    //get the end time and store the time difference
    struct timespec ed = get_time();
    double tdiff = get_time_diff(strt,ed);
    fprintf(st,"%lf,",tdiff);

    //ans has the maximum number of pairings
    int ans = dp[0][n - 1];
    pairs = (pair<int,int>*)malloc(sizeof(pair<int,int>) * ans);
    pos = 0;

    struct timespec pstrt = get_time();

    //get the pairings
    getPairs(0 , n - 1);

    sort(pairs , pairs + ans);

    //print the pairings
    cout << "Predicted pairings: " << ans << "\n";
    for(int i = 0; i < ans; i++)
        cout << pairs[i].first << "-" << pairs[i].second << " (" << s[pairs[i].first] << "-" << s[pairs[i].second] <<")\n";
    
    //get the end time and store the time difference of the entire algorithm
    ed = get_time();
    tdiff = get_time_diff(pstrt,ed);
    fprintf(st,"%lf,",tdiff);
    fprintf(st,"%d,",ans);
    tdiff = get_time_diff(strt,ed);
    fprintf(st,"%lf\n",tdiff);

    fclose(st);
    return 0;
}
