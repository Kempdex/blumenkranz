#include "logger.h"

using namespace core::util;

int logger::count_of_calls = 0;

void logger::break_recursion() {
	std::cout << '\n';
	count_of_calls = 0;
}