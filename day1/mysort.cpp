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
	std::cout << "比较次数：" << count1 << " 交换次数：" << count2 << std::endl;
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
	std::cout << "比较次数：" << count1 << " 交换次数：" << count2 << std::endl;
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
	std::cout << "比较次数：" << count1 << " 交换次数：" << count2 << std::endl;
}

void MySort::InsertSort(std::vector<int>& nums)//直接插入排序
{
	int count1 = 0, count2 = 0;
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; i++) {
		int j = i;
		int tmp = nums[i];//记录当前元素,也称为哨兵
		//如果是第一个元素直接插入，如果不是则看之前已经有序的元素是不是比当前的元素大
		while (j > 0 && tmp < nums[j - 1])
		{
			count1++;
			count2++;
			nums[j] = nums[j - 1];//元素后移
			j--;//再向前移动
		}
		count1++;
		nums[j] = tmp;//当前元素插入位置
	}
	std::cout << "比较次数：" << count1 << " 赋值次数：" << count2 << std::endl;
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
void MySort::QuickSort(std::vector<int>& nums)//快速排序
{
	int l = 0, r = nums.size()-1;
	QSort(nums, l, r);
}

void QSortNotR(std::vector<int>& nums, int left, int right)//快速排序的非递归版本
{
	std::stack<int> s;
	s.push(left);
	s.push(right);//后入的right，所以要先拿right
	while (!s.empty())//栈不为空
	{
		int right = s.top();
		s.pop();
		int left = s.top();
		s.pop();

		int index = AdjustPos(nums, left, right);
		//如果返回的index小于或等于left,那么左半边数组为空的就不用再排序,否则栈永远不会为空
		if ((index - 1) > left)//左子序列
		{
			s.push(left);
			s.push(index - 1);
		}
		if ((index + 1) < right)//右子序列
		{
			s.push(index + 1);
			s.push(right);
		}
	}
}

void MySort::QuickSortNotR(std::vector<int>& nums)//快速排序
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
		MSort(nums, first, mid);//左边有序
		MSort(nums, mid + 1, last);//右边有序
		merge(nums, first, mid, last);//将两个有序序列进行融合
	}
}

void MySort::MergeSort(std::vector<int>& nums)//归并排序
{
	int first = 0, last = nums.size() - 1;
	MSort(nums, first, last);
}


void MSortNotR(std::vector<int>& nums, int n)//参数和递归略不同，n代表数组中元素个数，即数组最大下标是n-1 
{//非递归实现 
	int size = 1, low, mid, high;
	while (size <= n - 1)
	{
		low = 0;
		while (low + size <= n - 1)
		{
			mid = low + size - 1;
			high = mid + size;
			if (high > n - 1)//第二个序列个数不足size 
				high = n - 1;
			merge(nums, low, mid, high);//调用归并子函数
			low = high + 1;//下一次归并时第一关序列的下界 
		}
		size *= 2;//范围扩大一倍 
	}
}

void MySort::MergeSortNotR(std::vector<int>& nums)//归并排序递归
{
	int size = nums.size();
	MSortNotR(nums, size);
}