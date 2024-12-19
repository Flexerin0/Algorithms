#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const double INF = numeric_limits<double>::infinity();

double optimalBST(const vector<double>& freq) {
    int n = freq.size();
    vector<vector<double>> A(n + 2, vector<double>(n + 1, 0.0));

    for (int i = 1; i <= n + 1; ++i) {
        A[i][i - 1] = 0;
    }

    for (int s = 0; s < n; ++s) {
        for (int i = 1; i <= n - s; ++i) {
            int j = i + s;
            A[i][j] = INF;

            double frequencySum = 0.0;
            for (int k = i; k <= j; ++k) {
                frequencySum += freq[k - 1];
            }

            for (int r = i; r <= j; ++r) {
                double cost = A[i][r - 1] + A[r + 1][j] + frequencySum;
                if (cost < A[i][j]) {
                    A[i][j] = cost;
                }
            }
        }
    }

    return A[1][n];
}

void testOptimalBST() {
    vector<double> frequency = { 0.15, 0.10, 0.05, 0.10, 0.20 };

    double result = optimalBST(frequency);

    cout << "Минимальное взвешенное время поиска: " << result << endl;

    cout << "\nТест с большим объемом данных...\n";
    vector<double> largeFreq(1000, 0.001);
    result = optimalBST(largeFreq);
    cout << "Минимальное взвешенное время поиска для 1000 ключей: " << result << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    testOptimalBST();

    return 0;
}
