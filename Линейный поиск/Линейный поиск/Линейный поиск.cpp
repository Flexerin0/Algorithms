#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int lineSearch(const vector<int>& arr, int num) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return 0;
}

void testLineSearch(int size, int num) {
    srand(time(NULL));
    vector<int> arr(size);

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << "|" << arr[i] << "| ";
    }
    cout << endl;

    int result = lineSearch(arr, num);

    if (result != 0) {
        cout << "Индекс числа " << num << " равен: " << result << endl;
    }
    else {
        cout << "В массиве нет числа " << num << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int size, target;

    cout << "Введите размер массива: ";
    cin >> size;

    cout << "Введите число для поиска: ";
    cin >> target;

    testLineSearch(size, target);

    system("pause");
    return 0;
}
