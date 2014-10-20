//Up to date as of Season 2 Episode 10
#include <pebble.h>
 
Window* window;
MenuLayer *menu_layer;
TextLayer *text_layer;

void draw_row_callback(GContext *ctx, Layer *cell_layer, MenuIndex *cell_index, void *callback_context)
{
	//Which row is it?
	switch(cell_index->row)
  {
  case 0:
		menu_cell_basic_draw(ctx, cell_layer, "Cresent Rose", "Ruby Rose", NULL);
		break;
	case 1:
		menu_cell_basic_draw(ctx, cell_layer, "Myrtenaster", "Weiss Schnee", NULL);
		break;
	case 2:
		menu_cell_basic_draw(ctx, cell_layer, "Gambol Shroud", "Blake Belladonna", NULL);
		break;
	case 3:
		menu_cell_basic_draw(ctx, cell_layer, "Ember Celica", "Yang Xiao Long", NULL);
		break;
	case 4:
		menu_cell_basic_draw(ctx, cell_layer, "Crocea Mors", "Jaune Arc", NULL);
		break;
	case 5:
		menu_cell_basic_draw(ctx, cell_layer, "Magnhild", "Nora Valkyrie", NULL);
		break;
	case 6:
		menu_cell_basic_draw(ctx, cell_layer, "Miló and Akoúo", "Pyrrha Nikos", NULL);
		break;
  case 7:
		menu_cell_basic_draw(ctx, cell_layer, "StormFlower", "Lie Ren", NULL);
		break;
	case 8:
		menu_cell_basic_draw(ctx, cell_layer, "Ozpin's Cane", "Professor Ozpin", NULL);
		break;
  case 9:
		menu_cell_basic_draw(ctx, cell_layer, "Glynda's crop", "Glynda Goodwitch", NULL);
		break;
  case 10:
		menu_cell_basic_draw(ctx, cell_layer, "Peter's Blunderbuss", "Peter Port", NULL);
		break;
  case 11:
		menu_cell_basic_draw(ctx, cell_layer, "Ruyi Bang and Jingu Bang", "Sun Wukong", NULL);
		break;
  case 12:
		menu_cell_basic_draw(ctx, cell_layer, "Neptune's Gun", "Neptune Vasilias", NULL);
		break;
  case 13:
		menu_cell_basic_draw(ctx, cell_layer, "Wilt and Blush", "Adam Taurus", NULL);
		break;
  case 14:
		menu_cell_basic_draw(ctx, cell_layer, "Emerald's Weapons", "Emerald Sustrai", NULL);
		break;
  case 15:
		menu_cell_basic_draw(ctx, cell_layer, "Mercury's Boots", "Mercury Black", NULL);
		break;
  case 16:
    menu_cell_basic_draw(ctx, cell_layer, "Cinder's Weapon", "Cinder Fall", NULL);
    break;
  case 17:
		menu_cell_basic_draw(ctx, cell_layer, "Melodic Cudgel", "Roman Torchwick", NULL);
		break;
  case 18:
    menu_cell_basic_draw(ctx,cell_layer, "Neopolitan's Umbrella", "Neopolitan", NULL);
  case 19:
		menu_cell_basic_draw(ctx, cell_layer, "Junior's Bazooka", "Hei 'Junior' Xiong", NULL);
		break;
  case 20:
		menu_cell_basic_draw(ctx, cell_layer, "Melanie's Heels", "Melanie Malachite", NULL);
		break;
  case 21:
		menu_cell_basic_draw(ctx, cell_layer, "Miltia's Claws", "Miltiades 'Miltia' Malachite", NULL);
		break;
  case 22:
		menu_cell_basic_draw(ctx, cell_layer, "Velvet's Weapon", "Velvet Scarlatina", NULL);
		break;
  case 23:
		menu_cell_basic_draw(ctx, cell_layer, "Fox's Weapon", "Fox", NULL);
		break;
  case 24:
		menu_cell_basic_draw(ctx, cell_layer, "Coco's Weapon", "Coco", NULL);
		break;
  case 25:
		menu_cell_basic_draw(ctx, cell_layer, "Yatsuhashi's Sword", "Yatsuhashi", NULL);
		break;
  case 26:
		menu_cell_basic_draw(ctx, cell_layer, "Cardin's Mace", "Cardin Winchester", NULL);
		break;
  case 27:
		menu_cell_basic_draw(ctx, cell_layer, "Russel's Daggers", "Russel Thrush", NULL);
		break;
  case 28:
		menu_cell_basic_draw(ctx, cell_layer, "Dove's Sword", "Dove Bronzewing", NULL);
		break;
  case 29:
		menu_cell_basic_draw(ctx, cell_layer, "Sky's Halberd", "Sky Lark", NULL);
		break;
	}
}

uint16_t num_rows_callback(MenuLayer *menu_layer, uint16_t section_index, void *callback_context)
{
	return 30;
}

void select_click_callback(MenuLayer *menu_layer, MenuIndex *cell_index, void *callback_context)
{
  
}
 
void window_load(Window *window)
{
  //Create it - 12 is approx height of the top bar
	menu_layer = menu_layer_create(GRect(0, 0, 144, 168 - 16));

	//Let it receive clicks
	menu_layer_set_click_config_onto_window(menu_layer, window);

	//Give it its callbacks
	MenuLayerCallbacks callbacks = {
		.draw_row = (MenuLayerDrawRowCallback) draw_row_callback,
		.get_num_rows = (MenuLayerGetNumberOfRowsInSectionsCallback) num_rows_callback,
		.select_click = (MenuLayerSelectCallback) select_click_callback
	};
	menu_layer_set_callbacks(menu_layer, NULL, callbacks);

	//Add to Window
  layer_add_child(window_get_root_layer(window), menu_layer_get_layer(menu_layer));
}
 
void window_unload(Window *window)
{
	menu_layer_destroy(menu_layer);
}
 
void init()
{
	window = window_create();
	WindowHandlers handlers = {
		.load = window_load,
		.unload = window_unload
	};
	window_set_window_handlers(window, (WindowHandlers) handlers);
	window_stack_push(window, true);
}
 
void deinit()
{
	window_destroy(window);
}
 
int main(void)
{
	init();
	app_event_loop();
	deinit();
}