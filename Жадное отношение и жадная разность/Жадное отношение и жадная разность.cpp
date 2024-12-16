#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    int weight;
    int time;
    int i;

    Task(int w, int t, int i) : weight(w), time(t), i(i) {}
};

void printTasks(const vector<Task>& tasks) {
    cout << "Порядок выполнения заданий: " << endl;
    for (const auto& task : tasks) {
        cout << "Задание " << task.i << " \n";
    }
    cout << endl;
}

void difference(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return (a.weight - a.time) > (b.weight - b.time);
        });

    cout << "\nЖадная разность:" << endl;
    printTasks(tasks);
}

void ratio(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return (double)a.weight / a.time > (double)b.weight / b.time;
        });

    cout << "\nЖадное отношение:" << endl;
    printTasks(tasks);
}

void testGreedyAlgorithms() {
    cout << "1-й список заданий: " << endl;
    vector<Task> tasks1 = {
        {10, 5, 1},
        {20, 2, 2},
        {5, 1, 3},
        {8, 3, 4}
    };
    vector<Task> tasksD1 = tasks1;
    vector<Task> tasksR1 = tasks1;
    difference(tasksD1);
    ratio(tasksR1);

    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "2-й список заданий: " << endl;
    vector<Task> tasks2 = {
        {15, 3, 1},
        {30, 10, 2},
        {25, 7, 3},
        {10, 2, 4},
        {18, 5, 5}
    };
    vector<Task> tasksD2 = tasks2;
    vector<Task> tasksR2 = tasks2;
    difference(tasksD2);
    ratio(tasksR2);

    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "3-й список заданий: " << endl;
    vector<Task> tasks3 = {
        {50, 25, 1},
        {40, 10, 2},
        {30, 20, 3},
        {20, 15, 4},
        {10, 5, 5}
    };
    vector<Task> tasksD3 = tasks3;
    vector<Task> tasksR3 = tasks3;
    difference(tasksD3);
    ratio(tasksR3);
}

int main() {
    setlocale(LC_ALL, "ru");

    testGreedyAlgorithms();

    return 0;
}
