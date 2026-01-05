/*
* https://usaco.org/index.php?page=viewproblem2&cpid=807
* USACO 2018 February Contest, Bronze
* Problem 1. Teleportation
*/
#include <iostream>
#include <algorithm> // std::min 사용
#include <cmath> // std::abs 사용

#define endl "\n"

using ll = long long;

using namespace std;

int main() {
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);

	long long a, b, x, y; // start, end, teleport1, teleport2
	cin >> a >> b >> x >> y;

	// Direct walking distance
	long long direct_distance = abs(b - a);
	// Walking to teleport1, teleporting to teleport2, then walking to destination
	long long via_teleport_distance = abs(x - a) + abs(b - y);
	// Walking to teleport2, teleporting to teleport1, then walking to destination
	long long via_teleport_distance_reverse = abs(y - a) + abs(b - x);
	// Find the minimum distance
	long long min_distance = min({ direct_distance, via_teleport_distance, via_teleport_distance_reverse });

	cout << min_distance << endl;

	return 0;
}