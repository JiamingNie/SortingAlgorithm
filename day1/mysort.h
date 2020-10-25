#pragma once
#include <vector>
#include<stack>
#include <iostream>
class MySort {
public:
	void BubbleSort(std::vector<int>& nums);//冒泡排序
	void BubbleSort1(std::vector<int>& nums);//改进冒泡排序
	void SelectSort(std::vector<int>& nums);//选择排序
	void InsertSort(std::vector<int>& nums);//直接插入排序
	//nothing is impossible!前面都是复杂度为O(n^2),
	void QuickSort(std::vector<int>& nums);//快速排序
	void QuickSortNotR(std::vector<int>& nums);//快速排序非递归
	void MergeSort(std::vector<int>& nums);//归并排序
	void MergeSortNotR(std::vector<int>& nums);//归并排序非递归
};