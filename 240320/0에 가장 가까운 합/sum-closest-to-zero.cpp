#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;

	vector<int> liquid;
	for (int i = 0; i < n; i++) {
		int value; cin >> value;
		liquid.push_back(value);
	}

	sort(liquid.begin(), liquid.end());

	pair<int, int> ans;
	int min_val = 1000000001;
	for (int i = 0; i < n; i++) {
		int left = i + 1, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (abs(liquid[i] + liquid[mid]) < min_val) {
				ans = make_pair(liquid[i], liquid[mid]);
				min_val = abs(liquid[i] + liquid[mid]);
			}

			if (liquid[i] + liquid[mid] > 0) {
				right = mid - 1;
			}
			else if (liquid[i] + liquid[mid] < 0) {
				left = mid + 1;
			}
			else {
				break;
			}
		}
	}

	//cout << ans.first << ' ' << ans.second;
	cout << min_val;
}