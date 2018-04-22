#pragma once
#include <iostream>

//TODO: Запись логов в файл
//TODO: Время с запуска программы в милисекундах
namespace core {
	namespace util {
		class logger
		{
			static int count_of_calls;

			static void break_recursion();
			static void error() {
				break_recursion();
			}
			static void info() {
				break_recursion();
			}
			static void debug() {
				break_recursion();
			}
			logger() {}
		public:

			template <typename T, typename... Args>
			static void debug(T first, Args... args) {
				if (count_of_calls == 0) {
					std::cout << "[DEBUG] ";
				}
				std::cout << first;
				count_of_calls++;
				debug(args ...);
			}

			template <typename T, typename... Args>
			static void info(T first, Args... args) {
				if (count_of_calls == 0) {
					std::cout << "[INFO] ";
				}
				std::cout << first;
				count_of_calls++;
				debug(args ...);
			}

			template <typename T, typename... Args>
			static void error(T first, Args... args) {
				if (count_of_calls == 0) {
					std::cout << "[ERROR] ";
				}
				std::cout << first;
				count_of_calls++;
				debug(args ...);
			}
		};
	}
}

