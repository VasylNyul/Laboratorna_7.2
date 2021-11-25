// Lab_7_2_1.cpp
// Нюл Василь
// Лабораторна робота No 7.2
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** Q, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i=0; i<rowCount; i++)
        for (int j=0; j<colCount; j++)
            Q[i][j] = Low + rand() % (High-Low+1);
}

void Print(int** Q, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0; j<colCount; j++)
            cout << setw(4) << Q[i][j];
        cout << endl;
    }
    cout << endl;
}

bool SearchMaxEven(int** Q, const int k, const int n, int& MaxEven)
{
    int MinInRow = 0;
    int t = -1;
    for (int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (Q[i][j]< Q[i][MinInRow])
            {
                t = i;
                MinInRow = j;
            }
        }
        MaxEven =  Q[i][MinInRow];
        break;
    }
    if (t == -1)
        return false;
    
    for (int i=0; i<k; i++)
    {
        MinInRow = 0;
        for(int j=0; j<n; j++)
        {
            if (Q[i][j]< Q[i][MinInRow])
                MinInRow = j;
        }
        if(Q[i][MinInRow] > MaxEven)
            MaxEven = Q[i][MinInRow];
    }
    return true;
}
int main()
{
    srand((unsigned)time(NULL));
    int k, n;
    cout <<  "k = "; cin >> k;
    cout <<  "n = "; cin >> n;
    
    int Low = -10;
    int High = 10;
    int rowCount = k;
    int colCount = n;
    int **Q = new int*[rowCount];
    for (int i=0; i<rowCount; i++)
        Q[i] = new int[colCount];
    
    Create(Q, rowCount, colCount, Low, High);
    Print(Q, rowCount, colCount);
    
    int MaxEven;
    SearchMaxEven(Q, k, n, MaxEven);
    cout <<  "MaxEven = "<< MaxEven << endl;
    
    
    for (int i=0; i<rowCount; i++)
        delete [] Q[i];
    delete [] Q;
    
    return 0;
}
