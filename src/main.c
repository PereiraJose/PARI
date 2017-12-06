/**
 *       @file  main.c
 *      @brief  Main aula 9b PARI
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

#include <gtk/gtk.h>

#define _MAIN_C_

#include "myf.h"
#include "callback.h"


int main(int argc, char *argv[]){
	gtk_init(&argc, &argv);

	/* load the interface after a configuration file*/
	builderG = gtk_builder_new();
	gtk_builder_add_from_file(builderG, "mydr2.glade", NULL);

	/* connect the signals in the interface */
	gtk_builder_connect_signals(builderG, NULL);
	
	/* get main window Widget ID and connect special signals */
	GtkWidget *t = GTK_WIDGET(gtk_builder_get_object(builderG, "window1"));
	if(t){
		g_signal_connect(G_OBJECT(t), "delete_event", G_CALLBACK(pari_delete_event), NULL);
	}
	
	captureG = pari_StartImageAcquisition();
	
	g_timeout_add(30, (GSourceFunc) pari_UpdateImageAreas, (gpointer) NULL);
	

	/* start the event loop */
	gtk_main();

	cvReleaseCapture(&captureG);             //Release capture device.
	cvReleaseImage(&dst_imageG);             //Release image (free pointer when no longer used)
	cvReleaseImage(&src_imageG);             //Release image (free pointer when no longer used).

	return 0;
}


