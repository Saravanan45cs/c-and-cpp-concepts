#include <iostream>
#include <immintrin.h>
#include <chrono>
#include <vector>

using namespace std;

const int m = 400;

void avx_d(vector<vector<double>>& a, vector<vector<double>>& b, int m, vector<vector<double>>& c) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j += 4) {
            __m256d sum = _mm256_setzero_pd();
            for (int k = 0; k < m; k++) {
                __m256d veca = _mm256_set1_pd(a[i][k]);
                __m256d vecb = _mm256_loadu_pd(&b[k][j]);
                __m256d mul = _mm256_mul_pd(veca, vecb);
                sum = _mm256_add_pd(sum, mul);
            }
            _mm256_storeu_pd(&c[i][j], sum);
        }
    }
}

void normal(vector<vector<double>>& a, vector<vector<double>>& b, int m, vector<vector<double>>& c) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    vector<vector<double>> a(m, vector<double>(m)), b(m, vector<double>(m)), c(m, vector<double>(m, 0)), d(m, vector<double>(m, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = static_cast<double>(rand()) / RAND_MAX * 100.0;
            b[i][j] = static_cast<double>(rand()) / RAND_MAX * 100.0;
        }
    }

   auto start = chrono::high_resolution_clock::now();
    normal(a, b, m, d);
    auto end = chrono::high_resolution_clock::now();
    auto durationNormal = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Normal time: " << durationNormal.count() << " seconds" << endl;//0.983

    auto start1 = chrono::high_resolution_clock::now();
    avx_d(a, b, m, c);
    auto end1 = chrono::high_resolution_clock::now();
    auto durationAVX1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1);
    cout << "AVX time: " << durationAVX1.count() << " seconds" << endl;//0.18


    return 0;
}
