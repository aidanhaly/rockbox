#include "plugin.h"

enum plugin_status plugin_start(const void* parameter){
    (void)parameter;
    bool quit = false;
    int button;
	int offset=0;
	int horizon_y = (LCD_HEIGHT/10)*5.5; //121
	int focal = 3000;

    while(!quit){
        rb->lcd_clear_display();
        rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
        rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
	    rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
	    rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
	    for(int i=25; i<((LCD_HEIGHT/10)*4.5)+25;i++){
			if(((LCD_HEIGHT-i+25)-horizon_y)<=0){
				continue;
			}
			int distance = focal/((LCD_HEIGHT-i+25)-horizon_y);
		    int strip_width = focal*10/distance;
	        int x = (LCD_WIDTH/2) - (strip_width/2);
			if((distance+offset)%40 < 20){
				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
			}
			else{
				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
			}
	        rb->lcd_fillrect(x,LCD_HEIGHT-i+25,strip_width,1);
		}
		rb->lcd_update();
		offset++;

		button=rb->button_get(false);
		if(button ==  BUTTON_POWER){
			break;
		}
    }
    return PLUGIN_OK;
}

// enum plugin_status plugin_start(const void* parameter){
//     (void)parameter;
//     bool quit = false;
//     int button;
// 	int offset=0;
// 	int horizon_y = (LCD_HEIGHT/10)*5.5; //121
// 	int height;
// 	int strip_width;
// 	int x;
// 	int screen_y1, screen_y2;
// 	int focal = 130;

//     while(!quit){
//         rb->lcd_clear_display();
//         rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
//         rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
// 	    rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
// 	    rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
// 		for(int distance=1;distance<focal+1;distance++){
// 			screen_y1 = horizon_y + (focal/distance);
// 			screen_y2 = horizon_y + (focal/(distance+1));
// 			height = screen_y1-screen_y2 + 1;

// 			if(screen_y1 >= LCD_HEIGHT) continue;
// 			if(height <= 0) continue;

// 			strip_width = focal*3/distance;
// 			x = (LCD_WIDTH/2) - (strip_width/2);

// 			if((distance+offset)%20 < 10){
// 				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
// 			}
// 			else{
// 				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
// 			}

// 			rb->lcd_fillrect(x,screen_y1,strip_width,height);
// 		}
// 		rb->lcd_update();

// 		offset++;

// 		button=rb->button_get(false);
// 		if(button ==  BUTTON_POWER){
// 			break;
// 		}
//     }
//     return PLUGIN_OK;
// }