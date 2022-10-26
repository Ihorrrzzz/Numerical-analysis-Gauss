#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fin;
	int n = 4;
	double a[n][n], b[n] , x[n], sum, d;
	fin.open("system.txt");
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) fin >> a[i][j];
        fin >> b[i];
	}

	// Прямий хiд 
	for (int k = 0; k < n; k++) {
		for (int i = k + 1; i < n; i++) {
			d = a[i][k] / a[k][k];
			for (int j = k; j < n; j++) {
				a[i][j] -= d * a[k][j];
			}
			b[i] = b[i] - d * b[k];
		}
	}
    
	// Обернений хiд 
	for (int k = n - 1; k >= 0; k--) {
		d = 0;
		for (int j = k + 1; j < n; j++) {
			sum = a[k][j] * x[j];
			d += sum;
		}
		x[k] = (b[k] - d) / a[k][k];
	}

	cout << "Roots" << endl;
	for (int i = 0; i < n; i++) cout << "x[" << i << "]=" << x[i] << endl;
}
