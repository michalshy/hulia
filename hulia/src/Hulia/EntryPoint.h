#pragma once

#ifdef HA_PLATFORM_WINDOWS

extern Hulia::Application* Hulia::CreateApplication();

int main(int argc, char** argv)
{
	printf("Hulia Engine\n");
	auto app = Hulia::CreateApplication();
	app->Run();
	delete app;
}
#endif