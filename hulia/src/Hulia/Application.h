#pragma once

#include "Core.h"

namespace Hulia {
	class HULIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();
}

