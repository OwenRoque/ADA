#include<iostream>
using namespace std;

int f1(int n) {
    int c = 0;
    c++; // Primera lectura bucle
    for (int i = 0; i < n; i++, c++) { // n+1
        c++;
        if (i % 2 == 0) {               // n
            c++;    
            cout << i << endl;          // n/2
        } 
    }
    return c;
}   // O(n)

int f2(int n) {
    int c = 0;
    c++; // Primera lectura bucle
    for (int i = 0; i < n; i++, c++) {  // n+1
        c++;
        if (i % 2 == 0) {               // n
            c++;
            cout << i << endl;          // n/2
        }
    }
    c++; // Primera lectura bucle
    for (int i = 0; i < n; i++, c++) {  // n+1
        c++;
        if (i % 2 != 0)  {              // n
            c++;
            cout << i << endl;          // n/2
        }
    }
    // Cuando n es impar, coincide
    // Cuando n es par, sale T-1
    return c;
}   // O(n)

int f3(int n) {
    int c = 0;
    c++; // Primera Lectura bucle
    for (int i = 0; i < n; i++, c++) {          // n+2
        c++;
        for (int j = i; j < n; j++, c++) {      // 
            c++;
            cout << i << ", " << j;             // n(n+1)/2
        }
    }
    return c;
}   // O(n^2)

int condition(int i,int n,int &c){
    c++;
    return i < n;
}

int f4(int n) {
    int i = 1, c = 0;               // 1
    c++;   
    while (condition(i, n, c)) {    // log2n +1
        cout << i;                  // log2n
        i = i * 2;                  // log2n
        c++;
    }
    return c;
}   // O(log n)

int f5(string a, string b) {
    int c = 0;
    c++;
    cout << a.length() << " " << b.length();
    for (int i = 0; i < a.length(); i++, c++) {         // a+1
        c++;
        for (int j = 0; j < b.length(); j++, c++) {     // a(b+1)
            cout << a[i] << ", " << b[j];               // ab
            c++;
        }
    }
    return c;
}   // O(ab)

int f6() {
    int c = 0;
    int n = 1000;           // 1
    c++;
    c++;
    if (n % 2 == 0)         // 1
        cout << "Par.";     // 1
    else    
        cout << "Impar.";   // No ingresa
    c++;
    return c;
}   // O(1)

int f7(int n) {
    int c = 0;
    c++;
    for (int i = 0; i < n; i++, c++) {  // n+1
        int j = 1;                      // n
        c++;                            
        while (condition(j, n, c)) {    // log2n +1
            cout << j;                  // log2n
            c++;
            j = j * 2;                  // log2n
            c++;
        }
    }
    return c;
}   // O(nlog2n)

int main() {
    int N = 4;
    int T = f7(N);
    cout << endl;
    cout << "N: " << N << endl; 
    cout << "T: " << T << endl; 
    return 0;
}