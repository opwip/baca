//Yaroslav Kolesnik
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<double>> bands(M + 1);

    for (int d = M; d >= 1; d--) {
        int size = N - d;
        bands[d].resize(size);
        for (int i = 0; i < size; i++)
            cin >> bands[d][i];
    }

    bands[0].resize(N);
    for (int i = 0; i < N; i++)
        cin >> bands[0][i];

    vector<double> y(N), x(N);
    for (int i = 0; i < N; i++) cin >> y[i];
    for (int i = 0; i < N; i++) cin >> x[i];

    double omega;
    int L;
    cin >> omega >> L;

    for (int iter = 0; iter < L; iter++) {
        for (int i = 0; i < N; i++) {
            double sigma = 0.0;
            for (int d = 1; d <= M; d++) {
                if (i - d >= 0)
                    sigma += bands[d][i - d] * x[i - d];
                if (i + d < N)
                    sigma += bands[d][i] * x[i + d];
            }
            double x_gs = (y[i] - sigma) / bands[0][i];
            x[i] = (1.0 - omega) * x[i] + omega * x_gs;
        }
    }

    cout << scientific << setprecision(16);
    for (int i = 0; i < N; i++)
        std::cout << x[i] << "\n";

    return 0;
}