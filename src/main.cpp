#include "util.h"

int main() {
    vector<vector<pair<char, int>>> matrix;
    vector<tuple<string, int, int>> query;
    int comp, n, m;

    // Load Matris dan Query
    readInput(&matrix, &query);

    auto start = high_resolution_clock::now();

    // Cek Matriks dan Query
    check(matrix, query, comp);

    // Print Matrix Berwarna sesuai Query
    printResult(matrix, query);

    auto duration = high_resolution_clock::now() - start;
    long long ms = duration_cast<microseconds>(duration).count();
    
    cout << "Durasi eksekusi >> " << YELLOW << ms << NORMAL << " ms" << endl;
    cout << "Banyak komparasi huruf >> " << YELLOW << comp << NORMAL << " kali" << endl;

    return 0;
}