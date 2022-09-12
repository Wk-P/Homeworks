#include <iostream>
using namespace std;
int map_points[100][2] = { { 0, 0 }, };			 
int map_path_direction[100][2] = { { 0, 0 }, };  
int direction_judgement(int x1, int x2, int y1, int y2) {
	if (x1 > x2) {
		return 3;
	} else if (x1 < x2) {
		return 4;
	} else if (y1 > y2) {
		return 2;
	} else if (y1 < y2) {
		return 1;
	} else {
		return 0;
	}
}

void robot_move(int t_time, int(* map)[2], int _size, int (*path_len)[2]) {		
	int index = 0;								
	while (1) {									
		if (t_time > path_len[index][0]) {
			t_time -= path_len[index][0];
			index = (index + 1) % _size;
		}
		else {
			if (path_len[index][1] == 1) {
				map_points[index][1] += t_time;
			}
			else if (path_len[index][1] == 2) {
				map_points[index][1] -= t_time;
			}
			else if (path_len[index][1] == 3) {
				map_points[index][0] -= t_time;
			}
			else if (path_len[index][1] == 4) {
				map_points[index][0] += t_time;
			}
			cout << map_points[index][0] << " " << map_points[index][1] << endl;
		}
	}
}

int main() {
	int size = 0, i = 0, time = 0;
	cin >> size;
	while (i < size) {
		cin >> map_points[i][0] >> map_points[i][1];
		if (i != 0) {
			map_path_direction[i - 1][0] = abs(map_points[i][0] - map_points[i - 1][0]) + abs(map_points[i][1] - map_points[i - 1][1]);
			map_path_direction[i - 1][1] = direction_judgement(map_points[i - 1][0], map_points[i][0], map_points[i - 1][1], map_points[i][1]);
		}
		i++;
	}
	map_path_direction[size - 1][0] = abs(map_points[0][0] - map_points[size - 1][0]) + abs(map_points[0][1] - map_points[size - 1][1]);
	map_path_direction[size - 1][1] = direction_judgement(map_points[0][0], map_points[size - 1][0], map_points[0][1], map_points[size - 1][1]);
	//while (cin >> time) 
	while (1) {
		cin >> time;
		if (time == -1) break;
		robot_move(time, map_points, size, map_path_direction);
	}
	return 0;
}