#include <iostream>
#include <vector>
#include <cstdlib>//rand(),srand
#include <ctime>//time()
#include "print_data.h"
#include "mysort.h"

using namespace std;
int main()
{
	srand((int)time(NULL));//随机种子
	vector<int> nums,nums1,nums2;
	print_data printTest;
	MySort sortTest;
	for (int i = 0; i < 9; i++)
	{
		nums.push_back(rand() % 100);//生成0-99之间的随机数
	}
	//nums.push_back(1);
	//nums.push_back(0);
	//nums.push_back(2);
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(6);
	//nums.push_back(7);
	//nums.push_back(8);
	//nums.push_back(9);


	nums1 = nums;
	nums2 = nums;
	vector<int> numsk = nums;
	vector<int> numskNotR = nums;
	vector<int> numsM = nums;
	vector<int> numsMNotR = nums;

	//经典冒泡排序
	/*printTest.printVector(nums);
	sortTest.BubbleSort(nums);
	printTest.printVector(nums);
	cout << endl;*/
	//cout << "改进的冒泡排序："<<endl;
	////改进冒泡排序
	//printTest.printVector(nums1);
	//sortTest.BubbleSort1(nums1);
	//printTest.printVector(nums1);
	//cout << "选择排序：" << endl;
	////选择排序
	//printTest.printVector(nums);
	//sortTest.SelectSort(nums);
	//printTest.printVector(nums);
	//cout << "直接插入排序：" << endl;
	////直接插入排序
	//printTest.printVector(nums2);
	//sortTest.InsertSort(nums2);
	//printTest.printVector(nums2);


	//cout << "快速排序：" << endl;
	////快速排序递归
	//printTest.printVector(numsk);
	//sortTest.QuickSort(numsk);
	//printTest.printVector(numsk);

	//cout << "快速排序非递归：" << endl;
	////快速排序非递归
	//printTest.printVector(numskNotR);
	//sortTest.QuickSortNotR(numskNotR);
	//printTest.printVector(numskNotR);

	cout << "归并排序递归：" << endl;
	//归并排序
	printTest.printVector(numsM);
	sortTest.MergeSort(numsM);
	printTest.printVector(numsM);

	cout << "归并排序非递归：" << endl;
	//归并排序
	printTest.printVector(numsMNotR);
	sortTest.MergeSortNotR(numsMNotR);
	printTest.printVector(numsMNotR);

	system("pause");
	return 0;
}