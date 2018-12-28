#include "..\header-files\framework-draw.h"
#include "../../c-utils/DrawManager.h"
#include "../header-files/framework-input.h"
cheat_ui_input cuii;
void cheat_ui::draw_main_window(const char* name, Vector2D pos, Vector2D size, draw_flags flags, Color color) {

	g_Render.RectFilled(pos.x, pos.y, pos.x + size.x, pos.y + size.y, color);
	if (flags & TITLE_BAR) {
		g_Render.RectFilled(pos.x, pos.y, pos.x + size.x, pos.y + 15, Color(255, 0 ,0));
		g_Render.String(pos.x + 10, pos.y + fabs(15 / 2), CD3DFONT_CENTERED_X | CD3DFONT_CENTERED_Y | CD3DFONT_DROPSHADOW, Color(255, 255, 255), g_Fonts.pFontTahoma10.get(), name);
	}
	if (last_pos == NULL) {
		last_pos = Vector2D(pos.x + 155, pos.y + 20);
	}
}
Vector2D cheat_ui::get_last_pos(Vector2D xy)
{


}
void cheat_ui::draw_checkbox(const char* name, bool& var, draw_flags i, Color color) {
	if (i & SAME_LINE) {

		g_Render.RectFilled((last_pos.x + 5), (last_pos.y), (last_pos.x + 5 + 12), (last_pos.y + 12), Color(24, 24, 24));

		Vector2D rect_pos = Vector2D(last_pos.x + 17, (last_pos.y + 12));

		g_Render.String(rect_pos.x + 5, rect_pos.y, CD3DFONT_CENTERED_Y | CD3DFONT_DROPSHADOW, Color(255, 255, 255), g_Fonts.pFontTahoma10.get(), name);

		if (cuii.clicked_in_bounds(Vector2D((last_pos.x + 5), (last_pos.y)), Vector2D((last_pos.x + 5 + 12), (last_pos.y + 12)), "checkbox")) {
			g_Render.RectFilled((last_pos.x + 5) + 1, (last_pos.y) + 1, (last_pos.x + 5 + 12) - 1, (last_pos.y + 12) - 1, Color(24, 24, 24));
			var = !var;
		}

		last_pos = Vector2D(last_pos.x + 17, (last_pos.y + 12));
	}
	else {
		g_Render.RectFilled(last_pos.x, last_pos.y + 5, last_pos.x + 12, (last_pos.y + 5) + 12, Color(24, 24, 24));

		Vector2D rect_pos = Vector2D(last_pos.x + 17, (last_pos.y + 5) + 12);

		g_Render.String(rect_pos.x + 5, rect_pos.y, CD3DFONT_CENTERED_Y | CD3DFONT_DROPSHADOW, Color(255, 255, 255), g_Fonts.pFontTahoma10.get(), name);

		if (cuii.clicked_in_bounds(Vector2D(last_pos.x, last_pos.y + 5), Vector2D(last_pos.x + 12, (last_pos.y + 5) + 12), "checkbox")) {
			g_Render.RectFilled(last_pos.x + 1, last_pos.y + 5 + 1, last_pos.x + 12 - 1, (last_pos.y + 5) + 12 - 1, Color(0, 255, 51));
		    var = !var;
		}

		last_pos = Vector2D(last_pos.x + 12, (last_pos.y + 5) + 12);
	}
}
void cheat_ui::draw_slider(const char* name, float& var, draw_flags i, Color color) {



}
