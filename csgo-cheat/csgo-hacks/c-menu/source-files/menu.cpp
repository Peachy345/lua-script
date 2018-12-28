#include "..\header-files\menu.h"
#include "../../Settings.h"

void c_menu::draw() {
	cheat_ui cui;
	if (g_Settings.bMenuOpened) {
		cui.draw_main_window("menu-test", Vector2D(500, 500), Vector2D(500, 500), TITLE_BAR, Color(7, 7, 7));
		bool var;
		cui.draw_checkbox("checkbox-test", var, SAME_LINE, Color(0, 0, 0));
	}
}
