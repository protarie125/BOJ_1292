#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int a, b; cin >> a >> b;

	if (a == b) {
		auto ans = int{ 1 };
		auto sum = int{ 0 };
		while (sum < a) {
			sum += ans;
			++ans;
		}

		cout << ans - 1;

		return 0;
	}

	auto sums = vi(b, 0);
	sums[0] = 1;
	auto val = int{ 2 };
	auto ct = int{ 0 };
	for (auto i = 1; i < b; ++i) {
		sums[i] = sums[i - 1] + val;
		++ct;

		if (ct == val) {
			++val;
			ct = 0;
		}
	}

	if (1 == a) {
		cout << sums[b - 1];
	}
	else {
		cout << sums[b - 1] - sums[a - 2];
	}

	return 0;
}