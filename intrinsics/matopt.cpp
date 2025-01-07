#include <iostream>
#include <immintrin.h>
#include <chrono>
#include <vector>

using namespace std;

const int m = 400;

void avx(vector<vector<float>>& a, vector<vector<float>>& b, int m, vector<vector<float>>& c) {
    for (int i = 0; i < m; i++) {
        for (int j=0;j<m; j+=8) {
            __m256 sum = _mm256_setzero_ps();
            for (int k = 0; k < m; k++) {
                __m256 veca = _mm256_set1_ps(a[i][k]);
                __m256 vecb = _mm256_loadu_ps(&b[k][j]);
                __m256 mul = _mm256_mul_ps(veca, vecb);
                sum = _mm256_add_ps(sum, mul);
            }
            _mm256_storeu_ps(&c[i][j], sum);
        }
    }
}

void normal(vector<vector<float>>& a, vector<vector<float>>& b, int m, vector<vector<float>>& c) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            for (int k = 0; k<m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    vector<vector<float>> a(m, vector<float>(m)), b(m, vector<float>(m)), c(m, vector<float>(m, 0)), d(m, vector<float>(m, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = static_cast<float>(rand()) / RAND_MAX * 100.0f;
            b[i][j] = static_cast<float>(rand()) / RAND_MAX * 100.0f;
        }
    }

    auto start = chrono::high_resolution_clock::now();
    normal(a, b, m, d);
    auto end = chrono::high_resolution_clock::now();
    auto durationNormal = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Normal time: " << durationNormal.count() << " seconds" << endl;//0.97

    auto start1 = chrono::high_resolution_clock::now();
    avx(a, b, m, c);
    auto end1 = chrono::high_resolution_clock::now();
    auto durationAVX1 = chrono::duration_cast<chrono::duration<double>>(end1 - start1);
    cout << "AVX time: " << durationAVX1.count() << " seconds" << endl;//0.094


    return 0;
}
