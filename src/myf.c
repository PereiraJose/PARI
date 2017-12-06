
#include "myf.h"


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
