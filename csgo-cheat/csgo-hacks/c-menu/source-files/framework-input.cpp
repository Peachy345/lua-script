#include "../header-files/framework-input.h"

bool cheat_ui_input::clicked_in_bounds(Vector2D bounds, Vector2D bounds2, const char* input_type) {

	bool clicked = false; POINT p; GetCursorPos(&p); HWND hwnd = FindWindowA("Valve001", NULL); ScreenToClient(hwnd, &p);

	if (GetAsyncKeyState(VK_EXECUTE || VK_LBUTTON) && bounds.x < p.x > bounds2.x && bounds.y < p.y > bounds2.y) {
		if (input_type == "slider") {
			slider_drag_distance = fabsf(bounds.x - p.x);
		}
		else {
			clicked = !clicked;
		}
	}

	return clicked;
}