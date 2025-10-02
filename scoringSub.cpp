#include <bits/stdc++.h>
using namespace std;

int main() {
	// Optimize input and output operations
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t; // Read the number of test cases

	while (t--) {
		int n;
		cin >> n; // Read the length of the sequence for the current test case

		vector<int> a(n);
		// Read the sequence of integers
		for (int i = 0; i < n; i++) { // O(n)
			cin >> a[i];
		}

		vector<int> res; // To store the result for each k

		// Calculate the cost for each k
		for (int i = 0; i < n; i++) { // O(nlogn)
			int l = 1, r = i + 1;
			// Perform binary search to find the maximum length of subsequence
			while (l <= r) {
				int m = (l + r) / 2;
				// Check if the subsequence of length m can have the maximum score
				if (a[i - m + 1] >= m) {
					l = m + 1; // Try to find a longer subsequence
				} else {
					r = m - 1; // Reduce the length of the subsequence
				}
			}
			res.push_back(r); // Store the result for the current k
		}

		// Output the results for the current test case
		for (auto i : res) { // O(n)
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}

// Time Complexity (TC): O(nlogn)
// Space Complexity (SC): O(n)
