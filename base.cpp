#include <gtk/gtk.h>

/* This is a callback function. The data arguments are ignored
 * in this example. More on callbacks below. */
static void callback( GtkWidget *widget,
        gpointer   data )
{
    g_print ("Hello World from %s!!!\n", (gchar*) data);
}

static gboolean delete_event( GtkWidget *widget,
        GdkEvent  *event,
        gpointer   data )
{
    gtk_main_quit();

    return FALSE;
}

/* Another callback */
static void destroy( GtkWidget *widget,
        gpointer   data )
{
    gtk_main_quit ();
}

int main( int   argc,
        char *argv[] )
{
    /* GtkWidget is the storage type for widgets */
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button2;
    GtkWidget *box1;

    /* This is called in all GTK applications. Arguments are parsed
     * from the command line and are returned to the application. */
    gtk_init (&argc, &argv);

    /* create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_set_decorated(GTK_WINDOW(window), false);

    gtk_window_set_opacity(GTK_WINDOW(window), 0.5f);

    /* When the window is given the "delete-event" signal (this is given
     * by the window manager, usually by the "close" option, or on the
     * titlebar), we ask it to call the delete_event () function
     * as defined above. The data passed to the callback
     * function is NULL and is ignored in the callback function. */
    g_signal_connect (window, "delete-event",
            G_CALLBACK (delete_event), NULL);

    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);


    // Make a box to help packing the gui elements
    box1 = gtk_hbox_new(FALSE, 0);

    // put the box into the main window
    gtk_container_add (GTK_CONTAINER(window), box1);

    /* Creates a new button with the label "Hello World". */
    button = gtk_button_new_with_label ("Button 1");

    /* When the button receives the "clicked" signal, it will call the
     * function hello() passing it NULL as its argument.  The hello()
     * function is defined above. */
    g_signal_connect (button, "clicked",
            G_CALLBACK (callback), (gpointer)"button 1");


    //
    //
    // now for the second button 
    //
    //
    button2 = gtk_button_new_with_label("Close button!");

    g_signal_connect(button2, "clicked", G_CALLBACK(delete_event), 
            NULL);

    //g_signal_connect_swapped(button2, "clicked", G_CALLBACK(gtk_widget_destroy), window);


    //
    // pack the buttons
    // pack the box (note this is not the same as gtk_widget_show
    gtk_box_pack_start(GTK_BOX(box1), button, true, true, 0);
    gtk_box_pack_start(GTK_BOX(box1), button2, true, true, 0);


    /* The final step is to display this newly created widget. */
    gtk_widget_show (button);
    gtk_widget_show (button2);


    gtk_widget_show(box1);

    /* and the window */
    gtk_widget_show (window);

    /* All GTK applications must have a gtk_main(). Control ends here
     * and waits for an event to occur (like a key press or
     * mouse event). */
    gtk_main ();

    return 0;
}
