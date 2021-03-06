//------------------------------------------------------------------------------
//  paddle.h - logic for the player's paddle
//------------------------------------------------------------------------------

#ifndef __PADDLE_H__
#define __PADDLE_H__

void paddle_get_pos(int* x_out, int* y_out, int* width_out);
void paddle_clear(void);
void paddle_update(void);
void paddle_draw(void);

#endif // __PADDLE_H__

