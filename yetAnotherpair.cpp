#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n; // Read the length of the array for the current test case
	int a[n];
	for (int i = 0; i < n; i++) { // O(n) - Read the elements of the array
		cin >> a[i];
	}
	long long res = 0; // Initialize result to store the count of valid pairs
	vector<int> v; // Vector to store indices where a[i] < i
	for (int i = 0; i < n; i++) { // O(nlogn) - Iterate over the array
		// Check if the current element satisfies the condition a[i] < i+1
		if (a[i] >= i + 1) {
			continue; // Skip if the condition is not met
		}
		// Count how many elements in v are less than a[i]
		res += (long long)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
		// Add the current index (i+1) to the vector v
		v.push_back(i + 1);
	}
	cout << res << '\n'; // Output the result for the current test case
}

int main() {
	int t;
	cin >> t; // Read the number of test cases
	for (int i = 1; i <= t; i++)
		solve(); // Solve each test case
	return 0;
}

// Time Complexity (TC): O(nlogn)
// Space Complexity (SC): O(n)
