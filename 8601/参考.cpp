 /*
 * 8601.cpp
 *
 *  Created on: 2018年11月3日
 *      Author: 20133
 *
 * 调用 m + m - 1 + ..+ 1 次MaxSum2, 调用n + n - 1 + .. + 1 次MaxSum
 * MaxSum2的大概步骤，假设n = 3,即有3行，每行p个，则计算第1行，计算第12行，计算第123行，计算第2行，计算第23行，计算第3行
 * MaxSum3同MaxSum2 ,假设 m = 3, 即有3个矩阵，则计算第1个矩阵，计算第12个矩阵，计算第123个矩阵，计算第2个矩阵，计算第23个矩阵，计算第3个矩阵
 */
#include<iostream>
using namespace std;
int MaxSum(int p, int* a);
int MaxSum2(int n, int p, int** a);
int MaxSum3(int m, int n, int p, int*** a);

int main(){
	int m, n, p, ***a;
	cin >> m >> n >> p;

	a = new int**[m + 1];
	for (int i = 1; i <= m; i++)
		a[i] = new int*[n + 1];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = new int[p + 1];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= p; k++)
				cin >> a[i][j][k];

    //以上是数据读入部分

	cout << MaxSum3(m, n, p, a);

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			delete[] a[i][j];
	for (int i = 1; i <= m; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}


int MaxSum(int p, int* a) {
	int sum = 0, b = 0;
	for (int i = 1; i <= p; i++) {
		if (b > 0)
			b += a[i];
		else
			b = a[i];
		if (b > sum)
			sum = b;
	}
	return sum;
}

int MaxSum2(int n, int p, int** a) {
	int sum = 0;
	int *b = new int[p + 1];
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= p; k++)
			b[k] = 0;
		for (int j = i; j <= n; j++) {//i,j 决定MaxSum被调用的次数,n = 3, 则3 + 2 + 1 = 6次
			for (int k = 1; k <= p; k++)
				b[k] += a[j][k];
			/*
			for (int k = 1; k <= p; k++)
				cout << "i " << i << " j " << j << " " << "[" <<  b[k] << "] ";
			cout << endl;
			*/
			int max = MaxSum(p, b);
			if (max > sum) {
				sum = max;
				//cout << "i " << i << " j " << j << " " << "sum " << sum << endl;
			}
		}
		//cout << endl;
	}
	delete[] b;
	return sum;
}

int MaxSum3(int m, int n, int p, int*** a) {
	int sum = 0;
	int** c = new int*[n + 1];
	for (int i = 1; i <= n; i++)
		c[i] = new int[p + 1];

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= p; k++)
				c[j][k] = 0;
		for (int l = i; l <= m; l++) {//i,l 决定MaxSum2被调用的次数, 如m = 3, 则3 + 2 + 1 = 6
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= p; k++)
					c[j][k] += a[l][j][k];
			int max = MaxSum2(n, p, c);
			//cout << endl;
			if (max > sum)
				sum = max;
		}
	}
	for (int i = 1; i <= n; i++)
		delete[] c[i];
	delete[] c;
	return sum;
}


/*
3 3 3
0 -1 2
1 2 2
1 1 -2
-2 -1 -1
-3 3 -2
-2 -3 1
-2 3 3
0 1 3
2 1 -3
*/
