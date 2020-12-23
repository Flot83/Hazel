#pragma once  
#include "Core.h"

namespace Hazel {


	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void run() 
		{
			while (true);
		}

	};

	// To be provided by client
	Application* CreateApplication();


}
