//------------------------------------------------------------------------------
//  video.c - simple DOS VGA graphics routines
//------------------------------------------------------------------------------

#include "video.h"

#include <dos.h>
#include <stdlib.h>

typedef unsigned char t_pixel;

t_pixel far *vram = (unsigned char far *)0xA0000000L;

#ifdef DOUBLE_BUFFER
t_pixel far *frame_buffer = NULL;
#endif

//------------------------------------------------------------------------------
void video_init(void)
{
#ifdef DOUBLE_BUFFER
	if (frame_buffer != NULL)
	{
		farfree(frame_buffer);
	}
	frame_buffer = farmalloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(t_pixel));
#endif
	video_clear();
}

//------------------------------------------------------------------------------
void video_fin(void)
{
#ifdef DOUBLE_BUFFER
	farfree(frame_buffer);
#endif
}

//------------------------------------------------------------------------------
void set_video_mode(unsigned char mode)
{
	union REGS in, out;
	in.h.ah = 0x0; // 0 = set video mode
	in.h.al = mode;
	int86(0x10, &in, &out);
}

//------------------------------------------------------------------------------
void set_video_page(unsigned char page)
{
	union REGS in, out;
	in.h.ah = 0x05; // 5 = select active page
	in.h.al = page;
	int86(0x10, &in, &out);
}

//------------------------------------------------------------------------------
void plot_pixel(unsigned int x, unsigned int y, unsigned char color)
{
#ifdef DOUBLE_BUFFER
	t_pixel far *target = frame_buffer;
#else
	t_pixel far *target = vram;
#endif

	target[((y<<8)+(y<<6))+x] = color;
}

//------------------------------------------------------------------------------
void plot_hline(unsigned int x, unsigned int y, unsigned int length, unsigned char color)
{
#ifdef DOUBLE_BUFFER
	t_pixel far *target = frame_buffer;
#else
	t_pixel far *target = vram;
#endif

	target = target + ((y<<8)+(y<<6)) + x;
	memset(target, color, length * sizeof(t_pixel));
}

//------------------------------------------------------------------------------
void video_clear(void)
{
#ifdef DOUBLE_BUFFER
	t_pixel far *target = frame_buffer;
#else
	t_pixel far *target = vram;
#endif

	memset(target, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(t_pixel));
}

//------------------------------------------------------------------------------
void video_swap(void)
{
#ifdef VSYNC
	while ( (inp(INPUT_STATUS_1) & VRETRACE)) {}
	while (!(inp(INPUT_STATUS_1) & VRETRACE)) {}
#endif

#ifdef DOUBLE_BUFFER
	memmove(vram, frame_buffer, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(t_pixel));
#endif
}
