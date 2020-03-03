//------------------------------------------------------------------------------
//  video.h - simple DOS VGA graphics routines
//------------------------------------------------------------------------------

#ifndef __VIDEO_H__
#define __VIDEO_H__

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 200
#define MAX_COLOR 256

#define DOUBLE_BUFFER
#define VSYNC

#ifndef INPUT_STATUS_1
#define INPUT_STATUS_1      0x03da
#endif

#ifndef VRETRACE
#define VRETRACE            0x08
#endif

void set_video_mode(unsigned char mode);
void set_video_page(unsigned char page);
void plot_pixel(unsigned int x, unsigned int y, unsigned char color);
void video_clear(void);
void video_swap(void);

// useful colors
#define COLOR_BLACK			0
#define COLOR_BLUE			1
#define COLOR_GREEN			2
#define COLOR_CYAN			3
#define COLOR_RED			4
#define COLOR_MAGENTA		5
#define COLOR_ORANGE		6
#define COLOR_LIGHT_GREY	7
#define COLOR_DARK_GREY		8
#define COLOR_WHITE			15

#endif // __VIDEO_H__
