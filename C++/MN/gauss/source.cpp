//Yaroslav Kolesnik
#include "vectalg.h"

static void luFactorize(Matrix& A, int* perm, double* scale) {
    int n = (int)A.size();
    for (int i = 0; i < n; i++) perm[i] = i;

    for (int col = 0; col < n; col++) {
        int pivot = col;
        double best = 0.0;
        for (int row = col; row < n; row++) {
            double val = std::abs(A(perm[row], col));
            if (scale[perm[row]] > 0.0)
                val /= scale[perm[row]];
            if (val > best) { best = val; pivot = row; }
        }
        int tmp = perm[col]; perm[col] = perm[pivot]; perm[pivot] = tmp;

        double diag = A(perm[col], col);
        if (std::abs(diag) < 1e-300) continue;

        for (int row = col + 1; row < n; row++) {
            double factor = A(perm[row], col) / diag;
            A(perm[row], col) = factor;
            for (int k = col + 1; k < n; k++) {
                A(perm[row], k) -= factor * A(perm[col], k);
            }
        }
    }
}

static Vector forwardSolve(const Matrix& A, const int* perm, const Vector& b) {
    int n = (int)A.size();
    Vector y(n);
    for (int i = 0; i < n; i++) {
        double s = b[perm[i]];
        for (int j = 0; j < i; j++)
            s -= A(perm[i], j) * y[j];
        y[i] = s;
    }
    return y;
}

static Vector backSolve(const Matrix& A, const int* perm, const Vector& y) {
    int n = (int)A.size();
    Vector x(n);
    for (int i = n - 1; i >= 0; i--) {
        double s = y[i];
        for (int j = i + 1; j < n; j++)
            s -= A(perm[i], j) * x[j];
        x[i] = s / A(perm[i], i);
    }
    return x;
}

static Vector luSolve(const Matrix& LU, const int* perm, const Vector& b) {
    return backSolve(LU, perm, forwardSolve(LU, perm, b));
}

Vector solveEquations(const Matrix& A, const Vector& b, double eps) {
    int n = (int)A.size();

    double* scale = new double[n];
    for (int i = 0; i < n; i++) {
        scale[i] = 0.0;
        for (int j = 0; j < n; j++) {
            double v = std::abs(A(i, j));
            if (v > scale[i]) scale[i] = v;
        }
    }

    int* perm = new int[n];
    Matrix LU(A);
    luFactorize(LU, perm, scale);
    delete[] scale;

    Vector x = luSolve(LU, perm, b);

    for (int iter = 0; iter < 50; iter++) {
        Vector r = residual_vector(A, b, x);
        if (r.max_norm() < eps) break;
        Vector dx = luSolve(LU, perm, r);
        for (int i = 0; i < n; i++) x[i] += dx[i];
    }

    delete[] perm;
    return x;
}