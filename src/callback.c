/**
 *       @file  callback.c
 *      @brief  Breve Descrição
 *
 * Descrição mais detalhada do ficheiro que até poderiam incluir links para imagens etc.
 *
 *     @author  Jose, email@ua.pt
 *
 *   @internal
 *     Created  29-Nov-2017
 *     Company  University of Aveiro
 *   Copyright  Copyright (c) 2017, Jose
 *
 * =====================================================================================
 */

// Funções ligadas a interface gráfica
#include "callback.h"

gboolean pari_UpdateImageAreas(gpointer data){
	//generate an expose event (draw event) on drawingarea1
	GtkWidget *da1 = GTK_WIDGET(gtk_builder_get_object(builderG, "drawingarea1"));
	if (da1 == NULL){
		printf("\nNão existe");
		fflush(stdout);
		return 0;
	}
	gtk_widget_queue_draw(da1);
	return TRUE;
}

gboolean on_drawingarea1_expose_event(GtkWidget * widget, GdkEvent * event, gpointer user_data){
	pari_PerformImageAcquisition(captureG);             //acquire new image
	// pari_ProcessUserOperations(src_imageG, dst_imageG); // Perform here the openCV transformations

	//update the drawing area displays
	pari_RefreshDrawingArea("drawingarea1", src_imageG);
	pari_RefreshDrawingArea("drawingarea2", dst_imageG);
	return TRUE;
}

