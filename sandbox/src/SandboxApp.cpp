#include <Hulia.h>

class Sandbox : public Hulia::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Hulia::Application* Hulia::CreateApplication()
{
	return new Sandbox();
}
