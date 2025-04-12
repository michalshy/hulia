#pragma once

#ifdef HA_PLATFORM_WINDOWS

extern Hulia::Application* Hulia::CreateApplication();

int main(int argc, char** argv)
{
	Hulia::Log::Init();
	HA_CORE_WARN("LOGGER INITIALIZED");

	auto app = Hulia::CreateApplication();
	app->Run();
	delete app;
}
#endif