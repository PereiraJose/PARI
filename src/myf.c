#include "myf.h"

int cvRound(double value) {return(ceil(value));}

/**
 * @brief  Callback to process the delete_event (usually, window kill request)
 *
 * @param  window - The widget that generated the event (not used here)
 * @param  event - The event description (not used here)
 * @param  data - generic user data (not used here)
 * @return FALSE - destroy window but does not leave gtk_main loop, and generates a "destroy" event that you can intersect with another callback.
 * @return TRUE - ignore this delete_event request and does nothing. This can be used to give a second chance to user before closing window!
 * The same effect of <b>TRUE</b> is obtained by returning no value, that is using a <b>void</b> type of function.
 */

gboolean pari_delete_event(GtkWidget * window, GdkEvent * event, gpointer data){
	puts("Interface gráfica fechada.");
	gtk_main_quit();
    
	puts("Pedido de delete event");
	return FALSE; //destroy window but does not leave gtk_main loop, and generates a "destroy" event
           
	//return TRUE; //ignore this delete_event request and does nothing. Same effect as returning 'void'
}


CvCapture *pari_StartImageAcquisition(){
        CvCapture *capture = cvCaptureFromCAM(0);              //Capture using 1st camera: i.e., no. 0
        IplImage *frame=cvQueryFrame(capture);                 //Update frame. Pointer does not change.
        src_imageG = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);//create image for color (8 bits, 3 channels)
        dst_imageG = cvClone(src_imageG);                       //create clone of source image
        return capture;
}


void pari_PerformImageAcquisition(CvCapture *capt){
        static IplImage *frame;
        frame=cvQueryFrame(capt);               //Update frame pointer.
        cvCopy(frame, src_imageG, NULL);        //copy frame as it is (preserve color)
        cvCopy(src_imageG, dst_imageG, NULL);   //copy src into dst and ready to process (admitt similar image structure)
}


// Exemplo de código de uma função que converte
// uma IplImage num pixbuf para inserir numa interface GTK
// e ajusta-a com certas dimensões passadas como argumentos
GdkPixbuf *pari_ConvertOpenCv2Gtk(IplImage * image, int dst_w, int dst_h){
    IplImage *gtkMask=image;
    GdkPixbuf *pix, *rpix;
    cvCvtColor(image, gtkMask, CV_BGR2RGB);
    pix = gdk_pixbuf_new_from_data((guchar *) gtkMask->imageData,
                       GDK_COLORSPACE_RGB,
                       FALSE,
                       gtkMask->depth,
                       gtkMask->width,
                       gtkMask->height,
                       gtkMask->widthStep, NULL, NULL);
    rpix = gdk_pixbuf_scale_simple(pix, dst_w, dst_h, GDK_INTERP_BILINEAR); //rescale image
    g_object_unref(pix);  //free the intermediate pixbuf...
    return rpix;
}


//copy from IplImage to pixbuf and paint DA
void pari_RefreshDrawingArea( char * widgetName, IplImage *img){
        GtkWidget *da=GTK_WIDGET(gtk_builder_get_object (builderG, widgetName));
        if( ! da )
        {
          printf("failed\n");
          return;
        }
        //GdkPixbuf *pix=pari_ConvertOpenCv2Gtk(img, da->allocation.width, da->allocation.height );
        GdkPixbuf *pix=pari_ConvertOpenCv2Gtk(img, gtk_widget_get_allocated_width (da), gtk_widget_get_allocated_height (da) );
        cairo_t *cr = gdk_cairo_create (gtk_widget_get_window(da));
        gdk_cairo_set_source_pixbuf(cr, pix, 0, 0);
        cairo_paint(cr);
        cairo_fill(cr);
        cairo_destroy(cr);
        g_object_unref(pix);  //free the pixbuf...
}

/**
 * @brief  Function to perform some specific operation.
 *
 * @param  src Source image to process
 * @param  dst Image to put the processed result
 * @param  gb  GtkBuilder pointer for the currently loaded GUI.
 * @param  udata1 gpointer for generic data for the operation. Normally the widget name. Return if NULL.
 * @param  udata2 gpointer for generic data for the operation. Normally the widget name for auxiliary parameter. May be ignored.
 */
void pari_UserOperationN(IplImage *src, IplImage *dst, GtkBuilder *gb, gpointer udata1, gpointer udata2);

void pari_ProcessUserOperations(IplImage *src, IplImage *dst){
        /*If nothing is to be done at least the dst is the same as src*/
        cvCopy( src, dst, NULL);

        //Now operate all functions accumulated (one after one)
        /*
        pari_UserOperation1(dst, dst, builderG, (gpointer)"checkbutton1", ...);
        pari_UserOperation2(dst, dst, builderG, (gpointer)"checkbutton2", ...);
        pari_UserOperation3(dst, dst, builderG, (gpointer)"checkbutton3", ...);
        pari_UserOperation4(dst, dst, builderG, (gpointer)"checkbutton4", ...);
        pari_UserOperation5(dst, dst, builderG, (gpointer)"checkbutton5", ...);
        pari_UserOperation6(dst, dst, builderG, (gpointer)"checkbutton6", ...);
        */
}
