#pragma once
#include <vector>
#include<stack>
#include <iostream>
class MySort {
public:
	void BubbleSort(std::vector<int>& nums);//ð������
	void BubbleSort1(std::vector<int>& nums);//�Ľ�ð������
	void SelectSort(std::vector<int>& nums);//ѡ������
	void InsertSort(std::vector<int>& nums);//ֱ�Ӳ�������
	//nothing is impossible!ǰ�涼�Ǹ��Ӷ�ΪO(n^2),
	void QuickSort(std::vector<int>& nums);//��������
	void QuickSortNotR(std::vector<int>& nums);//��������ǵݹ�
	void MergeSort(std::vector<int>& nums);//�鲢����
	void MergeSortNotR(std::vector<int>& nums);//�鲢����ǵݹ�
};