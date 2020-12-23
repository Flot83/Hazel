#pragma once
#include "Hazel/Log.h"
extern Hazel::Application* Hazel::CreateApplication();

int main()
{
	Hazel::Log::Init();
	HZ_APP_CRITICAL("Critical");
	HZ_APP_INFO("Info");
	HZ_APP_DEBUG("Debug");
	HZ_APP_WARN("Warn");
	HZ_APP_ERROR("Error");
	HZ_CORE_CRITICAL("Critical");
	HZ_CORE_INFO("Info");
	HZ_CORE_DEBUG("Debug");
	HZ_CORE_WARN("Warn");
	HZ_CORE_ERROR("Error");

	auto app = Hazel::CreateApplication();
	app->run();
	delete app; 
}