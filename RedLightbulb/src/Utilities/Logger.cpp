#include "pch.h"
#include "Logger.hpp"
#include "rang/rang.hpp"

namespace Utilities
{
	void Logger::log(const std::string& message, LogStatus status)
	{
		switch (status)
		{
			case LogStatus::Info:
				std::cout << rang::fg::gray;
				break;
			case LogStatus::Warning:
				std::cout << rang::fg::yellow;
				break;
			case LogStatus::Error:
				std::cout << rang::fg::red;
				break;
		}
		std::cout << "[" << logStatusToString(status) << "] " << message << std::endl;

		std::cout << rang::fg::reset;
	}

	std::string Logger::logStatusToString(LogStatus status)
	{
		switch (status)
		{
			default:
				return "";
			case LogStatus::Info:
				return "Info";
			case LogStatus::Warning:
				return "Warning";
			case LogStatus::Error:
				return "Error";
		}
	}
}
