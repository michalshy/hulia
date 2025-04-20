#include "hapch.h"
#include "Application.h"
#include "Hulia/Events/AppEvent.h"
#include "Hulia/Log.h"
#include <GLFW/glfw3.h>

namespace Hulia {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		HA_CORE_INFO("Entering main loop");
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}