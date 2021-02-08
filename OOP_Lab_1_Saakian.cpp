#include <iostream>

using namespace std;

void Read(int** A, int n, int m) {

    cout << "Fill the array: " << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)         // Filling array
            cin >> A[i][j];

}

void Output(int** A, int n, int m) {

    cout << endl << "Array A:" << endl;

    for (int i = 0; i < n; cout << endl, i++)
        for (int j = 0; j < m; j++)                 // Output of array A
            cout << A[i][j] << '\t';
    cout << endl;

}

void WZE(int** A, int n, int m) {
    
    int ze = m;

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (A[i][j] == 0) {             // Counting non-zero culumns 
                ze--;
                i += n;
            }


    cout << endl << "The number of columns without a zero element " << ze << endl;

}

void Sort(int** A, int n, int m, int* B, int r, int* T, int t) {

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (A[i][j] >= 0)                        // Sum of positive even numbers
                if ((A[i][j] % 2) == 0)
                    B[i] += A[i][j];
        }

    cout << "\nSum of even elements:\n";
    for (int i = 0; i < n; i++) {                   // Output array B
        cout << "Rows #" << i + 1 << ": " << " " << B[i] << endl;
    }
    for (int i = 0; i < n + n; i++) {
        for (int i = 0; i < n - 1; i++)
            if (B[i] > B[i + 1]) {              // Sorting of rows in array A
                for (int j = 0; j < m; j++) {
                    T[i] = A[i][j];
                    A[i][j] = A[i + 1][j];
                    A[i + 1][j] = T[i];
                }
                T[i] = B[i];
                B[i] = B[i + 1];
                B[i + 1] = T[i]; 
            }
    }
    

    Output(A, n, m);

}

int main()
{
    int n, m;
    int** A;
    int* T;
    int* B;

    cout << "Enter a number of the rows: ";
    cin >> n;
    cout << "Enter a number of the column: ";
    cin >> m;

    A = new int* [n];
    for (int i = 0; i < n; i++)             
        A[i] = new int[m];
    
    
    Read(A, n, m);
    
    B = new int [n];
    for (int i = 0; i < n; i++)                 // Memory allocation of arrays
        B[i] = 0;

    T = new int[n];
    for (int i = 0; i < n; i++)               
        T[i] = 0;

    
    Output(A, n, m);

    WZE(A, n, m);

    Sort(A, n, m, B, n, T, n);

    delete[]A;
    delete[]B;                  // Deleting memory of arrays
    delete[]T;

    system("PAUSE");
    return 0;

}