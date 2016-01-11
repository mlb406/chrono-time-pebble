#include <pebble.h>

static Window *window;
static Layer *bg_layer;

static void bg_draw_proc(Layer *layer, GContext *ctx) {
	graphics_context_set_fill_color(ctx, GColorBlack);
  graphics_fill_rect(ctx, GRect(1, 1, 142, 166), 24, GCornersAll);
}

static void main_window_load() {
	bg_layer = layer_create(GRect(0, 0, 144, 168));
	layer_set_update_proc(bg_layer, bg_draw_proc);
	layer_add_child(window_get_root_layer(window), bg_layer);
}

static void main_window_unload() {
	layer_destroy(bg_layer);
}

static void init() {
	window = window_create();

	window_set_background_color(window, GColorLightGray);

	window_set_window_handlers(window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload,
	});

	window_stack_push(window, true);
}

static void deinit() {
	window_destroy(window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}
