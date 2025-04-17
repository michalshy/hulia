#include "hapch.h"
#include "Application.h"
#include "Hulia/Events/AppEvent.h"
#include "Hulia/Log.h"
namespace Hulia {
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		HA_TRACE(e.ToString());

		while (true);
	}
}