#include <iostream>
using namespace std;

void robot_move(int t_time, int(*map)[2], int _size, int(*path_len)[2]) {
	int index = 0;
	while (1) {
		if (t_time > abs(path_len[index][0])) {
			t_time -= abs(path_len[index][0]);
			index = (index + 1) % _size;
		}
		else {
			if (path_len[index][1] == 1) {
				cout << map[index][0] << " " << (map[index][1] + (path_len[index][0] > 0 ? t_time : -t_time)) << endl;
			}
			else if (path_len[index][1] == 0) {
				cout << (map[index][0] + (path_len[index][0] > 0 ? t_time : -t_time)) << " " << map[index][1] << endl;
			}
			break;
		}
	}
}

int main() {
	int size = 0, i = 0, time = 0;
	int map_points[100][2] = { { 0, 0 }, };
	int map_path_direction[100][2] = { { 0, 0 }, };
	cin >> size;
	while (i < size) {
		cin >> map_points[i][0] >> map_points[i][1];
		if (i != 0) {
			map_path_direction[i - 1][0] = map_points[i][0] - map_points[i - 1][0] == 0 ? map_points[i][1] - map_points[i - 1][1] : map_points[i][0] - map_points[i - 1][0];
			map_path_direction[i - 1][1] = map_points[i][0] - map_points[i - 1][0] == 0 ? 1 : 0;
		}
		i++;
	}
	map_path_direction[size - 1][0] = map_points[0][0] - map_points[size - 1][0] == 0 ? map_points[0][1] - map_points[size - 1][1] : map_points[0][0] - map_points[size - 1][0];
	map_path_direction[size - 1][1] = map_points[0][0] - map_points[size - 1][0] == 0 ? 1 : 0;
	//while (cin >> time) 提交版
	while (1) {		// test 版
		cin >> time;
		if (time == -1) break;
		robot_move(time, map_points, size, map_path_direction);
	}
	return 0;
}