#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
//#include <memory>

namespace Hazel
{
	class HAZEL_API Log
	{ 
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GetAppLogger();
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_AppLogger;

	};
}


#define HZ_CORE_ERROR(...)     Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_WARN(...)      Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_CRITICAL(...)  Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HZ_CORE_DEBUG(...)     Hazel::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define HZ_CORE_INFO(...)      Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)


#define HZ_APP_ERROR(...)      Hazel::Log::GetAppLogger()->error(__VA_ARGS__)
#define HZ_APP_WARN(...)       Hazel::Log::GetAppLogger()->warn(__VA_ARGS__)
#define HZ_APP_CRITICAL(...)   Hazel::Log::GetAppLogger()->critical(__VA_ARGS__)
#define HZ_APP_DEBUG(...)      Hazel::Log::GetAppLogger()->debug(__VA_ARGS__)
#define HZ_APP_INFO(...)       Hazel::Log::GetAppLogger()->info(__VA_ARGS__)