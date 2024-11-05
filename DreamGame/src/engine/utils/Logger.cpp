#include "Logger.hpp"

#include <sstream>

std::ostringstream Logger::logStream{};
std::ostringstream Logger::errorStream{};

bool Logger::isError = false;
bool Logger::hasError = false;
bool Logger::updated = false;

void Logger::BeginLog(const std::string& file, const int line) {
	logStream << "[LOG] - [" << file << " - " << line << "]: ";
}

void Logger::BeginError(const std::string& file, const int line) {
	errorStream << "[ERROR] - [" << file << " - " << line << "]: ";
	isError = true;
	hasError = true;
}

void Logger::Print() {
	if (!updated) return;
	std::cout << logStream.str();

	if (hasError) {
		std::cerr << errorStream.str();
		errorStream.clear();
		std::cout << std::endl;
	}

	logStream.clear();
	hasError = false;
	updated = false;
}

void Logger::End() {
	logStream << std::endl;
	updated = true;
	isError = false;
}

std::ostream& Logger::Log() {
	if (isError) {
		return errorStream;
	}
	return logStream;
}

