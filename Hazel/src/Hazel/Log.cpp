#include "Log.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace Hazel
{
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_AppLogger;

	void Log::Init()
	{
		// change log pattern
		spdlog::set_pattern("%^[%T] %n: %v %$");

		m_CoreLogger = spdlog::stdout_color_mt("Hazel");
		m_CoreLogger->set_level(spdlog::level::trace);

		m_AppLogger = spdlog::stdout_color_mt("Sandbox");
		m_AppLogger->set_level(spdlog::level::trace);

        

	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return m_CoreLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetAppLogger()
	{
		return  m_AppLogger;

	}

}