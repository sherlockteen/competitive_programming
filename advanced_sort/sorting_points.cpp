#include <iostream>
#include <algorithm>
#include <vector>

struct Point {
	int x;
	int y;

};

bool cmp(Point p, Point q) {
	return p.x * p.x + p.y * p.y < q.x * q.x + q.y * q.y; // посчитаем расстояние до начала координат. Сравниваем квадраты расстояний
}

bool cmp2(Point p, Point q) {
	return p.x < q.x;
}

bool cmp3(Point p, Point q) {
	if (p.x != q.x) {
		return p.x < q.x;
	}
	return p.y < q.y;
}


void solve() {
	std::vector<Point> points_coord = {
		{1,3},
		{2,4},
		{1,2},
		{2, -3}
	};

	std::sort(points_coord.begin(), points_coord.end(), cmp);

	for (const auto& point : points_coord)
	{
		std::cout << "Point(" << point.x << ", " << point.y << ")\n";
	}
	

}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int tt = 1;
	//std::cin >> tt;
	while (tt-- > 0) {
		solve();
	}



	return 0;
}