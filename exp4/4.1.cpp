#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;
template <class T>
void SelectSort(T A[], int n)
{
	int small;
	for(int i = 0 ; i < n; ++i) {
		small = i;
		for(int j = i + 1; j < n; ++j)
			if(A[j] < A[small]) small = j;
		swap(A[i], A[small]);
	}
}
template <class T>
void InsertSort(T A[], int n)
{
	for(int i = 1; i < n; ++i) {
		int j = i;
		T tmp = A[j];
		while(j > 0 && tmp < A[j - 1]) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tmp;
	}
}
template <class T>
void BubbleSort(T A[], int n)
{
	int i = n - 1, j, last;
	while(i > 0) {
		last = 0;
		for(int j = 0; j < i; ++j)
			if(A[j + 1] < A[j]) {
				swap(A[j], A[j + 1]);
				last = j;
			}
		i = last;
	}
}
template <class T>
void QSort(T A[], int left, int right)
{
	int i, j;
	if(left < right) {
		i = left, j = right + 1;
		do {
			do i++; while(A[i] < A[left]);
			do j--; while(A[j] > A[left]);
			if(i < j) swap(A[i], A[j]);
		}while(i < j);
		swap(A[left], A[j]);
		QSort(A, left, j - 1);
		QSort(A, j + 1, right);
	}
}
template <class T>
void QuickSort(T A[], int n)
{
	QSort(A, 0, n - 1);
}
template <class T>
void MagicQSort(T A[], int left, int right)
{
	int i, j;
	if(right >= 9) {
		if(left < right) {
			i = left, j = right + 1;
			do {
				do i++; while(A[i] < A[left]);
				do j--; while(A[j] > A[left]);
				if(i < j) swap(A[i], A[j]);
			}while(i < j);
			swap(A[left], A[j]);
			MagicQSort(A, left, j - 1);
			MagicQSort(A, j + 1, right);
		}
	}
	else {
		InsertSort(A, right - left + 1);
		return;
	}
}
template <class T>
void MagicQuickSort(T A[], int n)
{
	MagicQSort(A, 0, n - 1);
}
template <class T>
void Merge(T A[], int i1, int j1, int i2, int j2)
{
	T *tmp = new T[j2 - i1 + 1];
	int i = i1, j = i2, k = 0;
	while(i <= j1 && j <= j2) {
		if(A[i] <= A[j]) tmp[k++] = A[i++];
		else tmp[k++] = A[j++];
	}
	while(i <= j1) tmp[k++] = A[i++];
	while(j <= j2) tmp[k++] = A[j++];
	for(int i = 0; i < k; ++i)
		A[i1++] = tmp[i];
	delete []tmp;
}
template <class T>
void MergeSort(T A[], int n)
{
	int i1, j1, i2, j2, size = 1;
	while(size < 1) {
		i2 = i1 + size;
		j1 = i2 - 1;
		if(i2 + size - 1 > n - 1) j2 = n - 1;
		else j2 = i2 + size - 1;
		Merge(A, i1, j1, i2, j2);
		i1 = j2 + 1;
	}
	size *= 2;
}
int main(int argc, char const *argv[])
{
	clock_t start, finish;
	srand(time(NULL));  
	int n = 100000, i;
	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];
	int *d = new int[n];
	int *e = new int[n];
	int *f = new int[n];
	//cout  <<  "待排序序列为:"  <<  endl;
	for(int i = 0; i < n; ++i)
	{
		a[i] = rand()%91;
		//cout  <<  a[i]  <<  " ";
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
		e[i] = a[i];
		f[i] = a[i];
	}
	//cout  <<  endl;
	start = clock();	
	SelectSort(a, n);
	//cout  <<  "经过简单选择排序后的序列为:"  <<  endl;
    //for(i = 0; i < n; ++i)
	//	cout  <<  a[i]  <<  " ";
	//cout  <<  endl;
	finish = clock();
	cout  <<  "简单选择排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	start = clock();
	InsertSort(b, n);
	//cout << "经过直接插入排序后的序列为:" << endl;
	//for(i = 0; i < n; ++i)
	//	cout << b[i] << " ";
	//cout << endl;
	finish = clock();
	cout << "直接插入排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	start = clock();
	BubbleSort(c, n);
	//cout << "经过冒泡排序后的序列为:" << endl;
	//for(i = 0; i < n; ++i)
	//	cout << c[i] << " ";
	//cout << endl;
	finish = clock();
	cout << "冒泡排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	start = clock();
	QuickSort(d, n);
	//cout << "经过快速排序后的序列为:" << endl;
	//for(i = 0; i < n; i++)
	//	cout << d[i] << " ";
	//cout << endl;
	finish = clock();
	cout << "快速排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	start = clock();
	MergeSort(e, n);
	//cout << "经过两路合并排序后的序列为:" << endl;
	//for(i = 0; i < n; i++)
	//	cout << e[i] << " ";
	//cout << endl;
	finish = clock();
	cout << "两路合并排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	start = clock();
	MagicQuickSort(f, n);
	//cout << "经过改进后的快速排序后的序列为:" << endl;
	//for(i = 0; i < n; ++i)
	//	cout << f[i] << " ";
	//cout << endl;
	finish = clock();
	cout << "过改进后的快速排序开始时间为:" << start << "	" << "结束时间为:" << finish << "   " << "持续时间为:" << (double)(finish - start)/ CLOCKS_PER_SEC << endl;
	return 0;
}
