#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

namespace Utilities
{
	class Logger
	{
	public:
		enum class LogStatus
		{
			Info,
			Warning,
			Error
		};

	public:
		static void log(const std::string& message, LogStatus status = LogStatus::Info);

	private:
		static std::string logStatusToString(LogStatus status);
	};

	#define LogInfo(Message)     Utilities::Logger::log(Message, Utilities::Logger::LogStatus::Info)
	#define LogWarning(Message)  Utilities::Logger::log(Message, Utilities::Logger::LogStatus::Warning)
	#define LogError(Message)    Utilities::Logger::log(Message, Utilities::Logger::LogStatus::Error)
}


#endif
