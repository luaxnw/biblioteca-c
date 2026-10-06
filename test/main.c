#include <gtk/gtk.h>

static int counter = 0;

void greet(GtkWidget *widget, gpointer data)
{
    GtkWidget *dialog;
    
    dialog = gtk_message_dialog_new(
        GTK_WINDOW(data),
        GTK_DIALOG_MODAL,
        GTK_MESSAGE_INFO,
        GTK_BUTTONS_OK,
        "Clicou botão"
    );

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    g_print("%s clicked %d times\n",
            (char *)data, ++counter);
}

void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *popup;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    popup = gtk_window_new(GTK_WINDOW_POPUP);

    g_signal_connect(window, "destroy",
                     G_CALLBACK(destroy), NULL);
    /* Let's set the border width of the window to 20.
     * You may play with the value and see the
     * difference. */
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);
    gtk_container_set_border_width(GTK_CONTAINER(popup), 20);

    button = gtk_button_new_with_label("Click Me!");

    g_signal_connect(button,
                     "clicked", 
                     G_CALLBACK(greet),
                     window);

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}