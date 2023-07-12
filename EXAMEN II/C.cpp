#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int coin = 1;
        int biggest = arr[0];

        for (int i = 1; i < N-1; i++) {
            // Si el valor actual es mayor que la suma del valor más grande hasta ahora y el valor actual
            if (arr[i+1] > biggest + arr[i]) {
                coin++;
                biggest += arr[i - 1];
            }
        }
        coin++;
        cout << coin << endl;
    }

    return 0;
}
