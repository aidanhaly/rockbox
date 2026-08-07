#include "plugin.h"

enum plugin_status plugin_start(const void* parameter){
    (void)parameter;
    bool quit = false;
    int button;
	int offset=0;
	int horizon_y = (LCD_HEIGHT/10)*5.5; //121
	int focal = 121;
	int distance;
	int screen_y1, screen_y2;
	int nextDistance;
	int distanceDelta=0;
	int strip_width;
	int height;
	int x;
	int x_offset [focal+1];

	for(int j=0;j<focal+1;j++){
		x_offset[j] = 0;
	}

    while(!quit){
		int dx=0,ddx=0;
		int current_x = 0;
        rb->lcd_clear_display();
        rb->lcd_set_foreground(LCD_RGBPACK(3,219,252));
        rb->lcd_fillrect(0,0,LCD_WIDTH,LCD_HEIGHT);
	    rb->lcd_set_foreground(LCD_RGBPACK(3,252,11));
	    rb->lcd_fillrect(0,(LCD_HEIGHT/10)*5.5,LCD_WIDTH,(LCD_HEIGHT/10)*4.5);
		// for (int distance = 1; distance< focal;distance++){
		// 	screen_y1 = focal/distance + horizon_y;
		// 	screen_y2 = focal/(distance+1) + horizon_y;
			
		// 	height = screen_y1-screen_y2 + 1;

		// 	if(screen_y1 >= LCD_HEIGHT) continue;
		// 	if(height <= 0) continue;

		// 	strip_width = focal*3/distance;
		// 	x = (LCD_WIDTH/2) - (strip_width/2);

		// 	if((distance+offset)%20 < 10){
		// 		rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
		// 	}
		// 	else{
		// 		rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
		// 	}

		// 	rb->lcd_fillrect(x,screen_y1,strip_width,height);
		// }
		for(int distance=1;distance<focal;distance++){
			distanceDelta = nextDistance - distance ;

			dx = 1*distanceDelta;
			ddx += dx;
			current_x += ddx*distanceDelta;

			// if(i == ((LCD_HEIGHT/10)*4.5)+24){
			// 	rb->splashf(HZ*2,"end offset being added to x : %d, distance delta: %d, ddx: %d, middle x = %d",current_x/10000,distanceDelta,ddx,x);
			// }

			x += current_x/8000;
		}
	    for(int y = horizon_y + 1; y < LCD_HEIGHT; y++){
			distance = focal/(y-horizon_y);
			
		    //int strip_width = focal*2/distance;
			strip_width = 4 * (y - horizon_y);

			if(strip_width < 5){
				continue;
			}

	        int x = (LCD_WIDTH/2) - (strip_width/2);

			if((distance+offset)%20 < 10){
				rb->lcd_set_foreground(LCD_RGBPACK(4,179,10));
				rb->lcd_fillrect(0,y,LCD_WIDTH,1);
				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
				rb->lcd_fillrect(x,y,strip_width,1);
				rb->lcd_set_foreground(LCD_RGBPACK(227,2,2));
				rb->lcd_fillrect(x,y,(strip_width/8),1);
				rb->lcd_fillrect(x+strip_width-(strip_width/8),y,(strip_width/8),1);
			}
			else{
				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
				rb->lcd_fillrect(x,y,strip_width,1);
				rb->lcd_set_foreground(LCD_RGBPACK(255,255,255));
				rb->lcd_fillrect(x,y,(strip_width/8),1);
				rb->lcd_fillrect(x+strip_width-(strip_width/8),y,(strip_width/8),1);
			}

	        
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