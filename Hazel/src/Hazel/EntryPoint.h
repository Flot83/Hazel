#pragma once

extern Hazel::Application* Hazel::CreateApplication();

int main()
{

	auto app = Hazel::CreateApplication();
	app->run();
	delete app; 
}