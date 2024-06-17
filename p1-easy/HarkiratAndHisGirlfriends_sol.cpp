#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t; // o. of tc
    while(t--){
        int n,q; cin >> n >> q; // Number of girlfriends and number of queries

        map<string,int> mp;// // HashMap to store gifts sum for each girlfriend

        for (int i = 0; i < n; ++i)
        {
            string gf_name; cin >> gf_name;
            int no_of_gifts; cin >> no_of_gifts;
            int sum=0;

            for (int j = 0; j < no_of_gifts; ++j)
            {
                int price; cin >> price;
                sum+=price;
            }
            mp[gf_name]=sum;
        }

        while(q--){
            string query_gf; cin >> query_gf;
            cout << mp[query_gf] << endl;
        }
    }
    return 0;
}

