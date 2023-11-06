#include <iostream>
#include <string>
using namespace std;

int max(int x, int y) {
    if (x > y) return x;
    else return y;
}

int main() {
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);
    int m = a.size(), n = b.size();
    int arr[m+1][n+1];
    for (int i = 0; i <= n; i++) {
        arr[0][i] = 0;
    }
    for (int i = 0; i <= m; i++) {
        arr[i][0] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++){
            if (a[i] == b[j]) {
                arr[i][j] = arr[i-1][j-1] + 1;
            } else {
                arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
            }
        }
    }
    string s = "";
    cout << arr[m][n] << endl;
    while (n >= 0 && m >= 0) {
        if (a[m] == b[n]) {
            s = a[m] + s;
            m--;
            n--;
        } else {
            if (arr[m][n-1] > arr[m-1][n]) {
                n--;
            }
            else m--;
        }
    }
    cout << s;
    return 0;
}

