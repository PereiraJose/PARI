/**
 *      @file   myf.h
 *      @brief  
 *
 *
 *     @author  José Pereira, email@ua.pt
 *
 *   @internal
 *     Created  25-Oct-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Jose
 *
 * =====================================================================================
 */

#ifndef _MYF_H
#define _MYF_H

#include <gtk/gtk.h>
#include <cairo.h>

#include "math.h"

#include <cv.h>
#include <highgui.h>
#include "opencv2/videoio/videoio_c.h"

#if defined (_MAIN_C_)
	GtkBuilder *builderG;
	IplImage *dst_imageG , *src_imageG;
	CvCapture *captureG;
#else
	extern GtkBuilder *builderG;
	extern IplImage *dst_imageG , *src_imageG;
	extern CvCapture *captureG;
#endif

gboolean pari_delete_event(GtkWidget * window, GdkEvent * event, gpointer data);
CvCapture *pari_StartImageAcquisition();
void pari_PerformImageAcquisition(CvCapture *capture);
GdkPixbuf *pari_ConvertOpenCv2Gtk(IplImage * image, int dst_w, int dst_h);
void pari_RefreshDrawingArea( char * widgetName, IplImage *img);

void pari_UserOperationN(IplImage *src, IplImage *dst, GtkBuilder *gb, gpointer udata1, gpointer udata2);
void pari_ProcessUserOperations(IplImage *src, IplImage *dst);

// https://stackoverflow.com/questions/42918747/yolo-c-compilation-failure-with-debug-1
int cvRound(double value);

/* prototypes should be within the last lines of header */
//#include "prototypes.h"

#endif /* _MYF_H */


