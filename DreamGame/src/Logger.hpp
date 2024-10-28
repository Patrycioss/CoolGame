#pragma once

#include <iostream>

class Logger {
	public:
		static void Log(const std::string& message) {
			std::cout << message << std::endl;
		}

		static void LogError(const std::string& message) {
			std::cerr << message << std::endl;
		}
};
