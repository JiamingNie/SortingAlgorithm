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