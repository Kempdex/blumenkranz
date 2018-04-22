#include "window.h"

window::window() {
	
}

window::window(HINSTANCE hInstance, int nCmdShow, int width, int height, DWORD dw_flags, BYTE i_pixel_type)
{
	this->dw_flags = dw_flags;
	this->i_pixel_type = i_pixel_type;

	win_decl_info.cbSize = sizeof(WNDCLASSEX);
	win_decl_info.style = CS_HREDRAW | CS_VREDRAW;
	win_decl_info.lpfnWndProc = window::wnd_proc;
	win_decl_info.cbClsExtra = 0;
	win_decl_info.cbWndExtra = 0;
	win_decl_info.hInstance = hInstance;
	win_decl_info.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	win_decl_info.hCursor = LoadCursor(NULL, IDC_ARROW);
	win_decl_info.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	win_decl_info.lpszMenuName = NULL;
	win_decl_info.lpszClassName = szWindowClass;
	win_decl_info.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&win_decl_info)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), winTitle, NULL);
		return;
	}

	win_handle = CreateWindow(szWindowClass, winTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, NULL);
	if (!win_handle) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), winTitle, NULL);
		return;
	}

	draw_context = GetDC(win_handle);

	//Обнуляем pixel_format_desc
	memset(&pixel_format_desc, 0, sizeof(pixel_format_desc));
	pixel_format_desc.nSize = sizeof(pixel_format_desc);
	pixel_format_desc.nVersion = 1;
	pixel_format_desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | dw_flags;
	pixel_format_desc.iPixelType = i_pixel_type;
	pixel_format_desc.cColorBits = 32;

	uint32_t pixel_format = ChoosePixelFormat(draw_context, &pixel_format_desc);

	if (pixel_format == 0) {
		MessageBox(NULL, "ChoosePixelFormat() failed: Cannot find a suitable pixel format. ", "Error", MB_OK);
		return;
	}

	DescribePixelFormat(draw_context, pixel_format, sizeof(PIXELFORMATDESCRIPTOR), &pixel_format_desc);

	ReleaseDC(win_handle, draw_context);

	ShowWindow(win_handle, nCmdShow);
}


window::~window()
{
	//
}

void window::update_window()
{
	//TODO: Вынести это за пределы класса окна
	UpdateWindow(win_handle);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

uint32_t window::get_width() const
{
	return this->width;
}

uint32_t window::get_height() const
{
	return this->height;
}

HWND window::get_hwnd() const
{
	return this->win_handle;
}

//Обрабатываем события
LRESULT window::wnd_proc(_In_ HWND hwnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;

	switch (uMsg) {
	case WM_SIZE:
		//Изменение размеров контекста для отрисовки вместе с размера окна
		//glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
		//PostMessage(hwnd, WM_PAINT, 0, 0);
		break;

	case WM_KEYDOWN:
		//Получаем данные с клавиатуры
		//TODO: Запаковать это в отдельный класс, занимающийся клавиатурой
		switch (wParam) {
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		}
		break;

	case WM_PAINT:
		//Отрисовываем картинку
		hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}
