#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <numeric>

using namespace std;

void solve() {
    long long n, x, y;
    if (!(cin >> n >> x >> y)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    map<pair<long long, long long>, long long> count_pairs;
    
    long long beautiful_pairs_count = 0;
    
    for (long long current_element : a) {
        long long r_j_x = current_element % x;
        long long r_j_y = current_element % y;
        

        long long required_r_i_x = (x - r_j_x) % x; 
        
        long long required_r_i_y = r_j_y;
        
        pair<long long, long long> required_pair = {required_r_i_x, required_r_i_y};
        

        beautiful_pairs_count += count_pairs[required_pair];
        

        pair<long long, long long> current_pair = {r_j_x, r_j_y};
        count_pairs[current_pair]++;
    }
    
    cout << beautiful_pairs_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}