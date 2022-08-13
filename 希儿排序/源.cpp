#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
//ֱ�Ӳ�������
void InsertSort(int* a, int len)
{
	assert(a);
	//����end�Ǵ�i+1��ʼ���������n,����iҪС��len-1
	for (int i = 0; i < len - 1; i++) {
		int end = i + 1;
		//ʹ����ʱ������¼end�±��ֵ
		int tmp = a[end];
		//���end�±��ֵС��i��ǰ�±��ֵ,�����Ԫ�غ���
		if (a[end] < a[i]) {
			//���������Ѿ�����õ��������Ԫ��,���Ժ��ƵĽ�������Ϊ
			//��end�ߵ������ʼ��λ�ú���ʱ������С��end-1�����Ԫ��ʱ
			while (end > 0 && tmp < a[end - 1]) {
				a[end] = a[end - 1];
				end--;
			}
		}
		//����ʱ�����ŵ�end���ߵ���λ��
		a[end] = tmp;
	}
}
//ϣ������(��С��������)
void ShellSort(int* a, int len)
{
	assert(a);
	int idx = len;
	while (idx > 1)
	{
		//idxΪÿ�β�����������Ҫ�ļ��
		idx = idx / 3 + 1;
		for (int i = 0; i < len - idx; i++) {
			int end = i + idx;
			int tmp = a[end];
			if (a[end] < a[i]) {
				//ע��:������ж�������ֱ�Ӳ��벻ͬ,����ϣ����������Ծʽ�Ĳ�������
				//��������end�Ľ�������������ʼ,����i
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
	//�Ƚ�ֱ�Ӳ��������ϣ�������Ч��
	printf("ֱ�Ӳ�����������Ҫ��ʱ�� : %d ms\n", end1 - begin1);
	printf("ϣ����������Ҫ��ʱ�� : %d ms\n", end2 - begin2);
	system("pause");
	return 0;
}