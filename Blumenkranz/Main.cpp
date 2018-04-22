#include <iostream>
#include <util/logger.h>
#include <Windows.h>
#include <tchar.h>
#include <renderer/window.h>

using namespace core::util;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {

	

	window *wnd = new window(hInstance, nCmdShow, 800, 600, PFD_TYPE_RGBA, 0);
	wnd->update_window();

	getchar();
	delete wnd;
	return 0;
}