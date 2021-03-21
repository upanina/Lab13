#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//формирование матрицы

int** MakeMatr(int m, int n)
{
	int** t; //вспомогательная матрица
	t=new int*[n]; //выделяем память
	for (int i=0;i<m;i++)
	{
		t[i]=new int[n];
		for (int j=0;j<n;j++) //заполняем случайными числами
		    t[i][j]=rand()%10;
	}
	return t;
}
//печать матрицы
void PrintMatr(int m,int n,int** matr) 
{
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cout.width(4);
			cout<<matr[i][j];
		}
		cout<<endl;
	}
}
//формирование массива результата
int* MakeArray (int m, int n, int** matr)
{
	{
    // в начале примем, что max и min элемент - это A[0][0]
    int maxI = 0, maxJ = 0, minI = 0, minJ = 0;
    // перебираем все элементы цикла и ищем максимальный и минимальный элементы
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matr[maxI][maxJ] < matr[i][j])
            {
                maxI = i;
                maxJ = j;
            }
 
            if (matr[minI][minJ] > matr[i][j])
            {
                minI = i;
                minJ = j;
            }
        }
 
    // меняем их местами
    int tmp = matr[maxI][maxJ];
    matr[maxI][maxJ] = matr[minI][minJ];
    matr[minI][minJ] = tmp;
	}
	 return 0;
}
void main()
{
	setlocale(LC_ALL, "RUS");
	int M,N;
	cout<<"Введите размерность матрицы: ";
	cin>>M>>N;
	int** A;
	A=MakeMatr(M,N);
	PrintMatr(M,N,A);
	int* B = MakeArray(M,N,A); 
    cout<<"Результат:\n"; 
    PrintMatr(M,N,A); 
        delete[] A; 
        delete[] B; 
	system("pause");
} 




