#include "stdafx.h"

#include <cstdlib>
#include "Torque.h"

static void MyFunction(DWORD* obj, int argc, const char** argv)
{
	if (!_stricmp(argv[1], "true") || !_stricmp(argv[1], "1") || (0 != atoi(argv[1])))
	{
		Printf("MyFunction called with true");
	}
	else
	{
		Printf("MyFunction called with false");
	}
}

DWORD WINAPI Init(LPVOID args)
{
	if (!InitTorqueStuff())
		return 0;

	ConsoleFunction(NULL, "MyFunction", MyFunction, "MyFunction(bool enabled) - Do fun stuff.", 2, 2);
	Printf("this is displayed with Printf from C");
	Eval("echo(\"this is displayed with Eval in TorqueScript from C\");");

	return 0;
}

//Entry point
int WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Init, NULL, 0, NULL);

	return true;
}