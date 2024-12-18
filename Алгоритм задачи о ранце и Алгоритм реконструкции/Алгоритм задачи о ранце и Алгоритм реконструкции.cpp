#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int backpack(const vector<int>& values, const vector<int>& sizes, int capacity, vector<vector<int>>& A) {
    int n = values.size();
    A.assign(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (sizes[i - 1] > j) {
                A[i][j] = A[i - 1][j];
            }
            else {
                A[i][j] = max(A[i - 1][j], A[i - 1][j - sizes[i - 1]] + values[i - 1]);
            }
        }
    }

    return A[n][capacity];
}

vector<int> reconstructBackpack(const vector<vector<int>>& A, const vector<int>& sizes, const vector<int>& values, int capacity) {
    vector<int> S;
    int c = capacity;
    int n = sizes.size();

    for (int i = n; i > 0; --i) {
        if (sizes[i - 1] <= c && A[i - 1][c - sizes[i - 1]] + values[i - 1] >= A[i - 1][c]) {
            S.push_back(i - 1);
            c -= sizes[i - 1];
        }
    }

    return S;
}

void testBackpack() {
    int n = 1000;
    int capacity = 5000;

    vector<int> values(n);
    vector<int> sizes(n);

    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < n; ++i) {
        values[i] = rand() % 100 + 1;
        sizes[i] = rand() % 50 + 1;
    }

    vector<vector<int>> A;

    int maxValue = backpack(values, sizes, capacity, A);

    vector<int> selectedItems = reconstructBackpack(A, sizes, values, capacity);

    cout << "Количество предметов: " << n << endl;
    cout << "Емкость ранца: " << capacity << endl;
    cout << "Максимальная стоимость: " << maxValue << endl;
    cout << "Выбранные предметы: " << selectedItems.size() << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    testBackpack();

    return 0;
}
