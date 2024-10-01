#include <bits/stdc++.h>
using namespace std;

// Time Complexity O(2^n)
//_______________________________________________________________________________________________

#define ll long long int
#define all(x) x.begin(),x.end()
#define fast_read() (ios_base :: sync_with_stdio(false), cin.tie(NULL));

//_______________________________________________________________________________________________
/*
https://quanticdev.com/tools/recursion-visualization/

4
2 3 4 5
1 3 5 3
8

--> 8
*/
//_______________________________________________________________________________________________

ll Knapsack(ll n, ll W, ll weight[], ll value[]);

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

    cout << Knapsack(n - 1, W, weight, value) << endl;
    return 0;
}
 
 
//_______________________________________________________________________________________________

ll Knapsack(ll n, ll W, ll weight[], ll value[]) {
    if(n < 0 || W == 0) {
        return 0;
    }

    if(weight[n] <= W) {
        ll option_1 = Knapsack(n-1, W-weight[n], weight, value) + value[n];   // Element ta Nie Dekhbo
        ll option_2 = Knapsack(n-1, W, weight, value);                        // Element ta Na Nie Dekhbo

        return max(option_1, option_2);
    } else {
        ll option_2 = Knapsack(n-1, W, weight, value);
        return option_2;
    }
}

//_______________________________________________________________________________________________