#include "plugin.h"

// enum plugin_status plugin_start(const void* parameter){
//     (void)parameter;
//     bool quit = false;
//     int button;
// 	int offset=0;

//     while(!quit){
//         rb->lcd_clear_display();
//         rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
//         rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
// 	    rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
// 	    rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
// 	    for(int i=25; i<((LCD_HEIGHT/10)*4.5)+25;i++){
// 		    int strip_width = 130*40/i;
// 	        int x = (LCD_WIDTH/2) - (strip_width/2);
// 			if((i+offset)%20 < 10){
// 				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
// 			}
// 			else{
// 				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
// 			}
// 	        rb->lcd_fillrect(x,LCD_HEIGHT-i+25,strip_width,1);
// 			offset++;
// 		}
// 	rb->lcd_update();

//     button=rb->button_get(false);
// 	if(button ==  BUTTON_POWER){
// 	    break;
// 	}
//     }
//     return PLUGIN_OK;
// }

enum plugin_status plugin_start(const void* parameter){
    (void)parameter;
    bool quit = false;
    int button;
	int offset=0;
	int horizon_y = (LCD_HEIGHT/10)*5.5; //121

    while(!quit){
        rb->lcd_clear_display();
        rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
        rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
	    rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
	    rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
	    for(int i=25; i<((LCD_HEIGHT/10)*4.5)+25;i++){
		    int strip_width = 130*40/i;
	        int x = (LCD_WIDTH/2) - (strip_width/2);
			if((i+offset)%20 < 10){
				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
			}
			else{
				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
			}
	        rb->lcd_fillrect(x,LCD_HEIGHT-i+25,strip_width,1);
			offset++;
		}
	rb->lcd_update();

    button=rb->button_get(false);
	if(button ==  BUTTON_POWER){
	    break;
	}
    }
    return PLUGIN_OK;
}