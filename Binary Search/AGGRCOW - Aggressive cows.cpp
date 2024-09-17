#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define Speed ios_base::sync_with_stdio(false);
#define Up cin.tie(NULL);
#define Code cout.tie(NULL);



// Code-----------------------------------------------------------------------------------------------
bool predicate_minimise_handshakes_adj_cows(int m, int v[], int n, int c){
    int i = 1;
    int prev = v[0];
    int count  = 1; // we can always place a cow at the first
    while(i<n){
        if(v[i]-prev>=m){
            count++; //place the cow
            prev = v[i];
            if(count==c){
                return true;
            }
        }
        i++;
    }
    return false;
}

void aggrcow(int v[], int n, int c){
    sort(v, v + n);

    int l = 1; // min distance betweeen 2 adj cows

    int r = v[n-1]-v[0]; // max dist between cows 

    while(l<r){
        int m = (l+r+1)/2; // use this in reverse predicate solutions
        if(predicate_minimise_handshakes_adj_cows(m,v,n,c)){
            l = m; // since question is to maxximise the minimum distance
            // and the if predicate r = m else l = m+1 logic guarantees minimum elt in maximal solution set
            // but the question wants maximum elt in minimum solution set
            // i reverse the logic for this to work
            // note the (l+r+1)/2
        }
        else{
            r = m-1;
        }
    }
    cout<<l;

}


// Main-----------------------------------------------------------------------------------------------
int main()
{
    Speed Up Code

    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;

        int v[n];

        for(int i = 0; i<n; i++){
            cin>>v[i];
        }

        aggrcow(v,n,c);
    }

    return 0;
}
