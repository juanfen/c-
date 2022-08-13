#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
//直接插如排序
void InsertSort(int* a, int len)
{
	assert(a);
	//由于end是从i+1开始进行排序的n,所以i要小于len-1
	for (int i = 0; i < len - 1; i++) {
		int end = i + 1;
		//使用临时变量记录end下标的值
		int tmp = a[end];
		//如果end下标的值小于i当前下标的值,则进行元素后移
		if (a[end] < a[i]) {
			//由于是在已经排序好的数组插入元素,所以后移的结束条件为
			//当end走到数组最开始的位置和临时变量不小于end-1代表的元素时
			while (end > 0 && tmp < a[end - 1]) {
				a[end] = a[end - 1];
				end--;
			}
		}
		//将临时变量放到end所走到的位置
		a[end] = tmp;
	}
}
//希尔排序(缩小增量排序)
void ShellSort(int* a, int len)
{
	assert(a);
	int idx = len;
	while (idx > 1)
	{
		//idx为每次插入排序所需要的间隔
		idx = idx / 3 + 1;
		for (int i = 0; i < len - idx; i++) {
			int end = i + idx;
			int tmp = a[end];
			if (a[end] < a[i]) {
				//注意:这里的判断条件和直接插入不同,由于希尔排序是跳跃式的插入排序
				//所以这里end的结束不是数组的最开始,而是i
				while (end > i && tmp < a[end - idx]) {
					a[end] = a[end - idx];
					end -= idx;
				}
			}
			a[end] = tmp;
		}
	}
}
void Printf(int* a, int len)
{
	assert(a);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int main()
{
	int a[100000] = { 0 };
	int b[100000] = { 0 };
	srand(time(0));
	for (int i = 0; i < 100000; i++) {
		b[i] = a[i] = rand();
	}
	int begin1 = clock();
	InsertSort(a, sizeof(a) / sizeof(int));
	int end1 = clock();
	int begin2 = clock();
	ShellSort(b, sizeof(b) / sizeof(int));
	int end2 = clock();
	//比较直接插入排序和希尔排序的效率
	printf("直接插入排序所需要的时间 : %d ms\n", end1 - begin1);
	printf("希尔排序所需要的时间 : %d ms\n", end2 - begin2);
	system("pause");
	return 0;
}