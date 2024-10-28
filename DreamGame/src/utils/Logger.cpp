#include "Logger.hpp"

std::string Logger::currentLog{};
bool Logger::updated = false;

void Logger::Log(const std::string& message, const std::string& file, const int line) {
	currentLog += "[LOG] - [" + file + " - " + std::to_string(line) + "]: " + message + "\n";
	updated = true;
}

void Logger::LogError(const std::string& message, const std::string& file, const int line) {
	currentLog += "[ERROR] - [" + file + " - " + std::to_string(line) + "]: " + message + "\n";
	updated = true;
}

void Logger::Print() {
	if (!updated) return;
	std::cout << currentLog;
	currentLog.clear();
	updated = false;
}