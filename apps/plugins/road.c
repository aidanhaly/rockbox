#include "plugin.h"
#include "pluginbitmaps/road_car.h"

#define PLAYER_LEFT BUTTON_SCROLL_BACK
#define PLAYER_RIGHT BUTTON_SCROLL_FWD

enum plugin_status plugin_start(const void* parameter){
    (void)parameter;
    bool quit = false;
    int button;
	int offset=0;
	int horizon_y = (LCD_HEIGHT/10)*5.5; //121
	int focal = 121;
	int distance;
	int strip_width;
	int x_offset [focal+1];
	int road_length = 1000;
	int road_1 [road_length];
	int index;
	int current_track_position = 0;
	int player_x_position = 0;

	for(int j=0;j<focal+1;j++){
		x_offset[j] = 0;
	}
	for(int i=0; i < road_length;i++){
		if(i<road_length/4){
			road_1[i] = 5;
		}
		else if(i<road_length/2){
			road_1[i]=0;
		}
		else if(i<3*(road_length/4)){
			road_1[i]= -5;
		}
		else{
			road_1[i]=10;
		}
	}

    while(!quit){
		int ddx=0;
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
			index = (current_track_position + distance) % road_length;
			ddx += road_1[index];
			current_x += ddx;

			// if(i == ((LCD_HEIGHT/10)*4.5)+24){
			// 	rb->splashf(HZ*2,"end offset being added to x : %d, distance delta: %d, ddx: %d, middle x = %d",current_x/10000,distanceDelta,ddx,x);
			// }

			x_offset[distance]  =  current_x/50 - player_x_position;
		}
	    for(int y = horizon_y + 2; y < LCD_HEIGHT; y++){
			distance = focal/(y-horizon_y);
			
		    //int strip_width = focal*2/distance;
			strip_width = 3 * (y - horizon_y) + 20;

	        int x = (LCD_WIDTH/2) - (strip_width/2) + x_offset[distance];

			if((distance+offset)%26 < 13){
				rb->lcd_set_foreground(LCD_RGBPACK(4,179,10));
				rb->lcd_fillrect(0,y,LCD_WIDTH,1);
				rb->lcd_set_foreground(LCD_RGBPACK(30,30,30));
				rb->lcd_fillrect(x,y,strip_width,1);
				rb->lcd_set_foreground(LCD_RGBPACK(227,2,2));
				if(strip_width > 25){
					rb->lcd_fillrect(x,y,(strip_width/8),1);
					rb->lcd_fillrect(x+strip_width-(strip_width/8),y,(strip_width/8),1);
				}
			}
			else{
				rb->lcd_set_foreground(LCD_RGBPACK(70,70,70));
				rb->lcd_fillrect(x,y,strip_width,1);
				rb->lcd_set_foreground(LCD_RGBPACK(255,255,255));
				if(strip_width > 25){
					rb->lcd_fillrect(x,y,(strip_width/8),1);
					rb->lcd_fillrect(x+strip_width-(strip_width/8),y,(strip_width/8),1);
				}
			}
		}

		rb->lcd_bitmap_transparent(road_car,(LCD_WIDTH/2)-36,LCD_HEIGHT-58,72,48);

		rb->lcd_update();
		offset++;
		current_track_position++;
		if(current_track_position>= road_length){
			current_track_position = 0;
		}

		button=rb->button_get(false);
		switch(button){
			case BUTTON_POWER:
				quit = true;
				break;
			case PLAYER_LEFT:
				player_x_position -= 5;
				break;
			case PLAYER_RIGHT:
				player_x_position += 5;
				break;
		}
		// if(button ==  BUTTON_POWER){
		// 	break;
		// }
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