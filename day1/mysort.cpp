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