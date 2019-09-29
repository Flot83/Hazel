#include "Log.h"

namespace Hazel
{
	std::shared_ptr<spdlog::logger> Log::m_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::m_AppLogger;

	void Log::Init()
	{

	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
	{
		return m_CoreLogger;
		// TODO: tu wstawiæ instrukcjê return
	}

	std::shared_ptr<spdlog::logger>& Log::GeAppLogger()
	{
		return  m_AppLogger;
		// TODO: tu wstawiæ instrukcjê return
	}

}