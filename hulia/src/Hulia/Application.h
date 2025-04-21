#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Hulia {
	class HULIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in client
	Application* CreateApplication();
}

