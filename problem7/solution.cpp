#include <iostream>
#include <vector>

using namespace std;

void create_matrix(int **arr, int n) {
    int row_index = 0;
    while (row_index < n) {
        int input = 0;
        cin >> input;
        if (input != 0) {
            while (input != 0) {
                arr[row_index][input-1] = 1;
                cin >> input;
            }
            row_index++;
        }
        else {
            cin >> input;
            row_index += input;
        }
    }
}

void print_transfered_matrix(int **arr, int n) {
    cout << n << endl;
    int column_index = 0, empty_lines = 0;
    while (column_index < n) {
        int is_empty = 1;
        for (int j = 0; j < n; j++) {
            if (arr[j][column_index] == 1) {
                if (empty_lines) cout << "0 " << empty_lines << endl;
                cout << j + 1 << " ";
                is_empty = 0;
                empty_lines = 0;
            }
        }
        if (is_empty) empty_lines++;
        else cout << "0" << endl;
        column_index++;
    }
}

int main() {
    int size = 0;
    cin >> size;
    int** arr = new int* [size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }
    create_matrix(arr, size);
    print_transfered_matrix(arr, size);
    return 0;
}
