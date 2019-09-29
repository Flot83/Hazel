#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Hazel
{
	class HAZEL_API Log
	{
	public:
		void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		static std::shared_ptr<spdlog::logger>& GeAppLogger();
	private:
		static std::shared_ptr<spdlog::logger> m_CoreLogger;
		static std::shared_ptr<spdlog::logger> m_AppLogger;

	};
}
