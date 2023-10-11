#include <stdio.h>
#include <iostream>
#define START_FUNC {
#define END_FUNC }
void print(auto& text)
START_FUNC
	std::cout << text << std::endl;
END_FUNC
