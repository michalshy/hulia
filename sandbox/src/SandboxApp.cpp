#include <Hulia.h>

class ExampleLayer : public Hulia::Layer
{
public:
	ExampleLayer()
		: Layer("Example") { }

	void OnUpdate() override
	{
		HA_INFO("Update");
	}
	void OnEvent(Hulia::Event& event) override
	{
		HA_TRACE("{0}", event.ToString());
	}
};

class Sandbox : public Hulia::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer()); 
	}
	~Sandbox()
	{

	}
};

Hulia::Application* Hulia::CreateApplication()
{
	return new Sandbox();
}
