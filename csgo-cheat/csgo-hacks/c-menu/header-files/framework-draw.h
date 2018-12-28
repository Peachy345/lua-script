#pragma once
#include "../../c-sdk/Vector.h"
#include "../../c-sdk/ISurface.h"

enum draw_flags {
	GLOW_EFFECT = (1 << 0),
	TITLE_BAR = (1 << 1),
	COLOR_BAR = (1 << 2),
	ANIMATE = (1 << 3),
	AUTO_SCALE = (1 << 4),
	DRAG = (1 << 5),
	SCROLLBAR = (1 << 6),
	AUTO_PLACE = (1 << 7),
	SAME_LINE = (1 << 8)
};
class cheat_ui {
public:
	Vector2D last_pos;
	Vector2D center_text(const char* name, Vector2D pos);
	void draw_main_window(const char* name, Vector2D pos, Vector2D size, draw_flags i, Color color); \
	void draw_groupbox(const char* name, Vector2D pos, Vector2D size, draw_flags i, Color color);
	void draw_button(const char* name, bool& var, draw_flags i, Color color);
	void draw_image_button(const char* name, BYTE pic_in_bytes, draw_flags i, Color color);
	void draw_slider(const char* name, float& var, draw_flags i, Color color);
	void draw_checkbox(const char* name, bool& var, draw_flags i, Color color);
	void draw_select_box(const char* name, bool& var, draw_flags i, Color color);
	void draw_combobox(const char* name, size_t var, draw_flags i);
	void draw_color_picker(const char* name,Color& color, draw_flags i);
private:
	Vector2D get_last_pos(Vector2D xy);
	void get_pos_on_auto_place(Vector2D& last_pos, draw_flags last_flags);
	void get_new_pos(Vector2D& xy);
	void animate(Vector2D start_pos, Vector2D& endpos);
	void draw_scrollbar(Vector2D xy);
	void draw_color_bar(float col_gradient[8]);
	void auto_scale_menu_size(Vector2D& menu_size, Vector2D screen_size); 
};