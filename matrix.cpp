/*
Пример: ввод -> 3
==> Matrix A:
1 2 3
3 2 1
1 2 3

Ввести матрицу, как в пункте 2, вывести минимум, максимум и сумму элементов матрицы

*/
#include <iostream>

using namespace std;
int main()
  {
    int maximum = 0;
    int minimum = 0;
    int i, j, n, m, array[10][10], array2[10][10], array3[10][10], array4[10][10];
    // cin >> n; // строки матрицы
    // cin >> m; // столбцы матрицы
    n = 3;
    m = 3;

    srand(time(0));


    for (i = 0; i < n;i++) {
      for (j = 0; j < m; j++) {
        array[i][j] = 1 + rand() % 10;
      }

    }
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        array2[i][j] = 1 + rand() % 10;
      }
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        cout << array[i][j] << "\t";
      }
      cout << endl;
    }

    cout << endl;

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        cout << array2[i][j] << "\t";
      }
      cout << endl;
    }

    cout << endl;

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        array3[i][j] = array[i][j] + array2[i][j];
      }
      cout << endl;
    }

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        cout << array3[i][j] << "\t";
      }
      cout << endl;
    }

    cout << endl;

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        maximum = std::max(array2[i][j], maximum);
      }
      cout << endl;
    }

    cout << maximum;
    cout << endl;

    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
        minimum = std::min(array2[i][j], minimum);
      }
      cout << endl;
    }

    cout << minimum;
    cout << endl;
  }
