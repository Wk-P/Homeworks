#include <iostream>
using namespace std;

void robot_move(int t_time, int(*map)[4], int _size) {
	int index = 0;
	while (1) {
		if (t_time > abs(map[index][2])) {
			t_time -= abs(map[index][2]);
			index = (index + 1) % _size;
		}
		else {
			if (map[index][3] == 1) {
				cout << map[index][0] << " " << (map[index][1] + (map[index][2] > 0 ? t_time : -t_time)) << endl;
			}
			else if (map[index][3] == 0) {
				cout << (map[index][0] + (map[index][2] > 0 ? t_time : -t_time)) << " " << map[index][1] << endl;
			}
			break;
		}
	}
}

int main() {
	int size = 0, i = 0, time = 0;
	int map_points[100][4] = { { 0, 0, 0, 0 }, };
	//int map_path_direction[100][2] = { { 0, 0 }, };  -> map_points[i][2], map_points[i][3]
	cin >> size;
	while (i < size) {
		cin >> map_points[i][0] >> map_points[i][1];
		if (i != 0) {
			map_points[i - 1][2] = map_points[i][0] - map_points[i - 1][0] == 0 ? map_points[i][1] - map_points[i - 1][1] : map_points[i][0] - map_points[i - 1][0];
			map_points[i - 1][3] = map_points[i][0] - map_points[i - 1][0] == 0 ? 1 : 0;
		}
		i++;
	}
	map_points[size - 1][2] = map_points[0][0] - map_points[size - 1][0] == 0 ? map_points[0][1] - map_points[size - 1][1] : map_points[0][0] - map_points[size - 1][0];
	map_points[size - 1][3] = map_points[0][0] - map_points[size - 1][0] == 0 ? 1 : 0;
	//while (cin >> time) 提交版
	while (1) {		// test 版
		cin >> time;
		if (time == -1) break;
		robot_move(time, map_points, size);
	}
	return 0;
}