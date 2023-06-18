#ifndef BUILDDIR_SERVERCONTROLWINDOW_H
#define BUILDDIR_SERVERCONTROLWINDOW_H


#include <gtk/gtk.h>
#include <memory>
#include <cstdlib>
#include "server/CustomLogger.h"
#include "server/CrosswordExample.h"
#include <restbed>
#include "gtk/ServerControlWindow.h"
#include "openapi/server/api/DefaultApi.h"
#include "openapi/server/model/CellQuestions.h"
#include "openapi/server/model/CellLetter.h"

using namespace std;
using namespace restbed;


using namespace org;
using namespace openapitools;
using namespace server;
using namespace api;
using namespace DefaultApiResources;



std::unique_ptr<DefaultApi> openApi;
std::unique_ptr<std::thread> openApiThread;

void startServer (GtkWidget *widget,
                  gpointer   data)
{
    // starting the restbed server is a blocking call, so it has to be done in a separate thread
    openApiThread = std::make_unique<std::thread>([]{

        auto resource = make_shared< Resource >( );
        auto settings = make_shared< Settings >( );

        settings->set_port( 1984 );
        settings->set_default_header( "Connection", "close" );

        shared_ptr<Service> service = make_shared<Service>();
        service->set_logger( make_shared< CustomLogger >( ) );

        openApi = std::make_unique<DefaultApi>(service);

        // this is the callback function when a GET /api/crossword request comes in
        openApi->getCrosswordResource()->handler_GET_func =
                []() -> std::pair<int, Crossword>
                {

                    return std::make_pair(200 /* http status */, getCrosswordExample());

                    // for testing:
                    // throw DefaultApiException(501, "Not implemented");
                };

        // this starts the restbed server with the definitions that were created
        // by openapi-generator from crosswords.yml
        openApi->service()->start( settings );
    });
    openApiThread->detach();

    // update start/stop button status
    GtkWidget *parent = gtk_widget_get_parent(widget);
    gtk_container_foreach(GTK_CONTAINER(parent), [](
            GtkWidget* widget,
            gpointer data){
        if (GTK_IS_BUTTON(widget))
        {
            if (strcmp(gtk_button_get_label(GTK_BUTTON(widget)), "Start") == 0)
            {
                gtk_widget_set_sensitive (widget, FALSE);
            }
            if (strcmp(gtk_button_get_label(GTK_BUTTON(widget)), "Stop") == 0)
            {
                gtk_widget_set_sensitive (widget, TRUE);
            }
        }
    }, nullptr);
}


void stopServer (GtkWidget *widget,
                 gpointer   data)
{
    openApi->service()->stop();

    // update start/stop button status
    GtkWidget *parent = gtk_widget_get_parent(widget);
    gtk_container_foreach(GTK_CONTAINER(parent), [](
            GtkWidget* widget,
            gpointer data){
        if (GTK_IS_BUTTON(widget))
        {
            if (strcmp(gtk_button_get_label(GTK_BUTTON(widget)), "Start") == 0)
            {
                gtk_widget_set_sensitive (widget, TRUE);
            }
            if (strcmp(gtk_button_get_label(GTK_BUTTON(widget)), "Stop") == 0)
            {
                gtk_widget_set_sensitive (widget, FALSE);
            }
        }
    }, nullptr);
}

// Generate ServerControlWindow (GTK window) to control the server start/stop
static void createServerControlWindow(GtkApplication* app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *label2;
    GtkWidget *startButton;
    GtkWidget *stopButton;

    window = gtk_application_window_new (app);

    box = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);

    gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
    gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

    label = gtk_label_new("Server");
    label2 = gtk_label_new("http://localhost:1984/api/crossword");
    gtk_label_set_selectable(GTK_LABEL(label2), true);
    startButton = gtk_button_new_with_label("Start");
    g_signal_connect (startButton, "clicked", G_CALLBACK (startServer), NULL);
    stopButton = gtk_button_new_with_label("Stop");
    g_signal_connect (stopButton, "clicked", G_CALLBACK (stopServer), NULL);
    gtk_widget_set_sensitive (stopButton, FALSE);

    gtk_container_add (GTK_CONTAINER (window), box);
    gtk_container_add (GTK_CONTAINER (box), label);
    gtk_container_add (GTK_CONTAINER (box), startButton);
    gtk_container_add (GTK_CONTAINER (box), stopButton);
    gtk_container_add (GTK_CONTAINER (box), label2);
    gtk_window_set_title(GTK_WINDOW (window), "Crosswords");
    gtk_window_set_default_size(GTK_WINDOW (window), 400, 200);
    gtk_widget_show_all(window);
}


#endif //BUILDDIR_SERVERCONTROLWINDOW_H
