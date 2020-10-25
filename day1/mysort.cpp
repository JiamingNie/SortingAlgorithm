#include "mysort.h"
void MySort::BubbleSort(std::vector<int>& nums) {
	int count1 = 0, count2 = 0;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = 0; j < numsSize -1 - i; j++) {
			count1++;
			if (nums[j] > nums[j+1]){
				count2++;
				int tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
	}
	std::cout << "�Ƚϴ�����" << count1 << " ����������" << count2 << std::endl;
}

void MySort::BubbleSort1(std::vector<int>& nums) {
	int count1 = 0, count2 = 0;
	int numsSize = nums.size();
	bool flag = true;
	for (int i = 0; (i < numsSize - 1) && flag; i++) {
		flag = false;
		for (int j = 0; j < numsSize - 1 - i; j++) {
			count1++;
			if (nums[j] > nums[j + 1]) {
				count2++;
				flag = true;
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
	std::cout << "�Ƚϴ�����" << count1 << " ����������" << count2 << std::endl;
}

void MySort::SelectSort(std::vector<int>& nums) 
{
	int count1 = 0, count2 = 0;
	int min = 0;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize ; i++) {
		min = i;
		for (int j = i + 1; j < numsSize; j++) {
			count1++;
			if (nums[min] > nums[j]) {	
				min = j;
			}
		}
		if (min != i)
		{
			count2++;
			int tmp = nums[i];
			nums[i] = nums[min];
			nums[min] = tmp;
		}
		
	}
	std::cout << "�Ƚϴ�����" << count1 << " ����������" << count2 << std::endl;
}

void MySort::InsertSort(std::vector<int>& nums)//ֱ�Ӳ�������
{
	int count1 = 0, count2 = 0;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; i++) {
		int j = i;
		int tmp = nums[i];//��¼��ǰԪ��,Ҳ��Ϊ�ڱ�
		//����ǵ�һ��Ԫ��ֱ�Ӳ��룬���������֮ǰ�Ѿ������Ԫ���ǲ��Ǳȵ�ǰ��Ԫ�ش�
		while (j > 0 && tmp < nums[j - 1])
		{
			count1++;
			count2++;
			nums[j] = nums[j - 1];//Ԫ�غ���
			j--;//����ǰ�ƶ�
		}
		count1++;
		nums[j] = tmp;//��ǰԪ�ز���λ��
	}
	std::cout << "�Ƚϴ�����" << count1 << " ��ֵ������" << count2 << std::endl;
}

int AdjustPos(std::vector<int>& nums, int left, int right)
{
	int tmp = nums[left];
	while (left < right)
	{
		while (left < right&&nums[right] >= tmp)
		{
			right--;
		}
		if (left < right)
		{
			nums[left] = nums[right];
			left++;
		}
		while (left < right&&nums[left] <= tmp)
		{
			left++;
		}
		if (left < right)
		{
			nums[right] = nums[left];
			right--;
		}
	}
	nums[left] = tmp;
	return left;
}
void QSort(std::vector<int>& nums, int left, int right)
{
	if (left < right) 
	{
		int pos = AdjustPos(nums, left, right);
		QSort(nums, left, pos - 1);
		QSort(nums, pos + 1, right);
	}
}
void MySort::QuickSort(std::vector<int>& nums)//��������
{
	int l = 0, r = nums.size()-1;
	QSort(nums, l, r);
}

void QSortNotR(std::vector<int>& nums, int left, int right)//��������ķǵݹ�汾
{
	std::stack<int> s;
	s.push(left);
	s.push(right);//�����right������Ҫ����right
	while (!s.empty())//ջ��Ϊ��
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		int index = AdjustPos(nums, left, right);
		//������ص�indexС�ڻ����left,��ô��������Ϊ�յľͲ���������,����ջ��Զ����Ϊ��
		if ((index - 1) > left)//��������
		{
			s.push(left);
			s.push(index - 1);
		}
		if ((index + 1) < right)//��������
		{
			s.push(index + 1);
			s.push(right);
		}
	}
}

void MySort::QuickSortNotR(std::vector<int>& nums)//��������
{
	int l = 0, r = nums.size()-1;
	QSortNotR(nums, l, r);
}

void merge(std::vector<int>& nums, int first, int mid, int last)
{
	std::vector<int> tmp(last - first + 1, 0);
	int left = first;
	int right = mid + 1;
	int k = 0;
	while (left <= mid && right <= last)
	{
		if (nums[left] < nums[right])
			tmp[k++] = nums[left++];
		else
			tmp[k++] = nums[right++];
	}
	while (left <= mid)
	{
		tmp[k++] = nums[left++];
	}
	while (right <= last)
	{
		tmp[k++] = nums[right++];
	}
	for (int i = 0; i < k; i++)
	{
		nums[first + i] = tmp[i];
	}
}

void MSort(std::vector<int>& nums, int first, int last)
{
	if (first < last)
	{
		int mid = first + (last - first) / 2;
		MSort(nums, first, mid);//�������
		MSort(nums, mid + 1, last);//�ұ�����
		merge(nums, first, mid, last);//�������������н����ں�
	}
}

void MySort::MergeSort(std::vector<int>& nums)//�鲢����
{
	int first = 0, last = nums.size() - 1;
	MSort(nums, first, last);
}


void MSortNotR(std::vector<int>& nums, int n)//�����͵ݹ��Բ�ͬ��n����������Ԫ�ظ���������������±���n-1 
{//�ǵݹ�ʵ�� 
	int size = 1, low, mid, high;
	while (size <= n - 1)
	{
		low = 0;
		while (low + size <= n - 1)
		{
			mid = low + size - 1;
			high = mid + size;
			if (high > n - 1)//�ڶ������и�������size 
				high = n - 1;
			merge(nums, low, mid, high);//���ù鲢�Ӻ���
			low = high + 1;//��һ�ι鲢ʱ��һ�����е��½� 
		}
		size *= 2;//��Χ����һ�� 
	}
}

void MySort::MergeSortNotR(std::vector<int>& nums)//�鲢����ݹ�
{
	int size = nums.size();
	MSortNotR(nums, size);
}