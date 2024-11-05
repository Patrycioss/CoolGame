#pragma once

#include <iostream>

#define BEGIN_LOG() Logger::BeginLog(__FILE__, __LINE__)
#define BEGIN_ERROR() Logger::BeginError(__FILE__, __LINE__)
#define END() Logger::End()
#define LOG Logger::Log()

class Logger {
	private:
		static std::ostringstream logStream;
		static std::ostringstream errorStream;
		static bool updated;
		static bool isError;
		static bool hasError;

	public:
		static void BeginLog(const std::string& file, int line);
		static void BeginError(const std::string& file, int line);
		static void Print();
		static void End();

		static std::ostream& Log();
};
