#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Set stores (start_index, number_value) of compressed blocks (0-based)
    set<pair<int, int>> st;

    // Pre-processing: Compression of duplicates
    for (int i = 0; i < n; i++) {
        int ind = i;
        while (i + 1 < n && a[i] == a[i + 1]) {
            i++;
        }
        st.insert({ind, a[i]});
    }

    int q;
    if (!(cin >> q)) return;
    
    while (q--) {
        int i, j;
        cin >> i >> j;
        int l = i - 1; 
        int r = j - 1;

        // Find the block containing the left boundary 'l'.
        auto it_start_block = st.upper_bound({l, 2000000000}); 
        if (it_start_block != st.begin()) {
            it_start_block = prev(it_start_block);
        }
        
        if (it_start_block == st.end()) {
             cout << "-1 -1\n";
             continue;
        }

        // Get the iterator for the block immediately following
        auto it_next_block = next(it_start_block);

        // Determine the start index of the block *following* the one containing 'l'.
        bool is_end_of_array = (it_next_block == st.end());
        int start_index_next_block = is_end_of_array ? n : it_next_block->first;

        // Monochromatic check: The range [l, r] is monochromatic if the next block starts *after* r.
        if (start_index_next_block > r) {
            cout << "-1 -1\n";
        }
        else {
            
            int index1 = l; 
            
            int index2 = it_next_block->first;
            

            cout << index1 + 1 << " " << index2 + 1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }
    
    return 0;
}