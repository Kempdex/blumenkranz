#pragma once
#include <Windows.h>
#include <tchar.h>
#include <stdint.h>

//Окно с помощью WinAPI
//Для теста и знаний
class window
{
	WNDCLASSEX win_decl_info;
	HWND win_handle;
	HDC draw_context;
	MSG msg;
	PIXELFORMATDESCRIPTOR pixel_format_desc;

	const char *szWindowClass = "blumenkranz";
	const char *winTitle = "Blumenkranz";
	uint32_t width;
	uint32_t height;

	DWORD dw_flags;
	BYTE i_pixel_type;

	static LRESULT CALLBACK wnd_proc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);
public:
	window();
	window(HINSTANCE hInstance, int nCmdShow, int width, int height, DWORD dw_flags, BYTE i_pixel_type); //default ctor
	~window(); 

	void update_window();
	uint32_t get_width() const;
	uint32_t get_height() const;
	HWND get_hwnd() const;
};

