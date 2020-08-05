#include "print_data.h"

void print_data::printHello() {
	std::cout << "print_data function!" << std::endl;
}
void print_data::printNum(int num){
	std::cout << num << std::endl;
}

void print_data::printVector(std::vector<int> nums) {
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
}
