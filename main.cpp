#pragma clang diagnostic push

#include <gtk/gtk.h>
#include <memory>
#include "gtk/ServerControlWindow.h"


int main(int argc, char **argv)
{

    GtkApplication *app;
    int status;

    app = gtk_application_new(NULL, G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(createServerControlWindow), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv); // blocks
    g_object_unref(app);

    return status;
}

#pragma clang diagnostic pop