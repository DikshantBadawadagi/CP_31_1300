#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cnt; // global counter for balanced subtrees

// DFS function to return balance value of subtree rooted at 'u'
int dfs(int u, const vector<vector<int>>& tree, const string& s) {
    int balance = (s[u - 1] == 'W') ? 1 : -1;

    for (int v : tree[u]) {
        balance += dfs(v, tree, s);
    }

    if (balance == 0) cnt++;

    return balance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n + 1); // 1-based indexing

        for (int i = 2; i <= n; ++i) {
            int parent;
            cin >> parent;
            tree[parent].push_back(i);
        }

        string s;
        cin >> s;

        cnt = 0;
        dfs(1, tree, s);

        cout << cnt << '\n';
    }

    return 0;
}
