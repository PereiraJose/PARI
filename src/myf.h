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

#include <gtk/gtk.h>

#define MAXFFBUFFER 1000

#if defined (_MAIN_C_)
	#ifndef GLOBALS_DECLARED
	#define GLOBALS_DECLARED

        GtkBuilder *builderG;
        double xoffG=100;
        double yoffG=120;
    #endif
#else
        extern GtkBuilder *builderG;
        extern double xoffG;
        extern double yoffG;
#endif

gboolean pari_delete_event(GtkWidget * window, GdkEvent * event, gpointer data);

