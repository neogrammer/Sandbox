#include <SFML/Graphics.hpp>
#include "SandboxError.h"
#include "SandboxApp.h"
#include <iostream>
#include "Cfg.h"

int main()
{
	Cfg::Initialize();

	try
	{
		SandboxApp game{1600u, 900u, "Sandbox"};
		game.run();
	}
	catch (const sbx::SandboxError& e)
	{
		std::cout << e.what() << std::endl;
	}


	return 69;
}