#include "plugin.h"

enum plugin_status plugin_start(const void* parameter){
    (void)parameter;
    bool quit = false;
    int button;

    while(!quit){
        rb->lcd_clear_display();
        rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
        rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
	rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
	rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
        rb->lcd_set_foreground(LCD_RGBPACK(0,0,0));
	int distance = 1;
	for(int i=1; i<((LCD_HEIGHT/10)*4.5);i++){
	    if(i%3 == 0){
		distance++;
	    }
	    int strip_width = 25*5/distance;
	    int x = (LCD_WIDTH/2) - (strip_width/2);
	    rb->lcd_fillrect(x,LCD_HEIGHT-i,strip_width,1);
	}
	rb->lcd_update();

        button=rb->button_get(false);
	if(button ==  BUTTON_POWER){
	    break;
	}
    }
    return PLUGIN_OK;
}
