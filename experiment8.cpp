#include <iostream>

using namespace std;

int sumOfSeries(int n) {
    int seriesSum = 0;

    for (int i = 1; i <= n; i++) {
      
        int termSum = (i * (i + 1)) / 2;
          seriesSum += termSum;
    }

    return seriesSum;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
    } else {
        int result = sumOfSeries(n);
        cout << "Sum of the series: " << result << endl;
    }

    return 0;
}

