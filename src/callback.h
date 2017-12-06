
#include <cairo.h>

#include "myf.h"

#if defined (_MAIN_C_)

#else
typedef struct {
  int count;
  double x[MAXFFBUFFER];
  double y[MAXFFBUFFER];
} free_form;

//GLOBAL
free_form ffG={0};   //init count to zero. Do not affect x and y.
double fontSizeFactorG = 1;
#define FONT_INC 0.5;

#endif



void on_drawingarea1_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data);
void on_mouse_button_on(GtkWidget *widget, GdkEventButton *event, gpointer user_data);
void on_drawingarea1_scroll_event(GtkWidget *widget, GdkEventScroll *event, gpointer user_data);
void on_drawingarea1_motion_notify_event(GtkWidget *widget, GdkEventMotion *event, gpointer user_data);
void p_RedrawText(cairo_t *cr);
void p_RedrawFreeForm(cairo_t * cr);
void p_InitTimer(void);
gboolean p_ForceRefreshDA(gpointer user_data);

