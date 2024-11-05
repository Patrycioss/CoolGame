#pragma once

#include <iostream>

class Logger {
	private:
		static std::string currentLog;
		static bool updated;

	public:
		static void Log(const std::string& message, const std::string& file, int line);
		static void LogError(const std::string& message, const std::string& file, int line);
		static void Print();
};