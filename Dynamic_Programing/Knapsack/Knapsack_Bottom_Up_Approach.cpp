#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(n * W)
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
/*
4
2 3 4 5
1 3 5 3
8

--> 8
*/

//_______________________________________________________________________________________________
 
 
int main(){
    fast_read();
    ll n; cin >> n;
    ll weight[n+5], value[n+5];

    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }
    for(int i=0; i<n; i++) {
        cin >> value[i];
    }

    ll W; cin >> W; // Knapsack Weight

    ll DP[n+5][n+5];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=W; j++) {
            if(i == 0 || j == 0) {
                DP[i][j] = 0;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(weight[i-1] <= j) {
                ll option_1 = DP[i-1][j - weight[i-1]] + value[i-1];
                ll option_2 = DP[i-1][j];
                DP[i][j] = max(option_1, option_2);
            } else {
                ll option_2 = DP[i-1][j];
                DP[i][j] = option_2;
            }
        }
    }


    cout << DP[n][W] << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________