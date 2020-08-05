//#pragma once	两种方式防止重定义
#ifndef PRINT_DATA_H
#define PRINT_DATA_H
#include <iostream>
#include <vector>
class print_data
{
public:
	print_data() = default;
	~print_data() = default;
	void printHello();
	void printNum(int num);
	void printVector(std::vector<int> nums);
private:
};


#endif // !PRINT_DATA_H
