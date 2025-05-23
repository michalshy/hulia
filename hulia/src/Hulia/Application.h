#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hulia/Events/AppEvent.h"
#include "Hulia/Window.h"
#include "Hulia/LayerStack.h"

namespace Hulia {
	class HULIA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PopLayer(Layer* layer);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	//To be defined in client
	Application* CreateApplication();
}

