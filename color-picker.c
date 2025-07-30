#include <X11/Xlib.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * A simple X11 application that creates a window and displays a message.
 * - The application uses XDrawString to draw a string in the window.
 * - It also uses XDrawImageString to draw another string with a different color.
 * - The application exits when the ESC key is pressed.
 */
int main() {
    Display *display;
    Window window;
    XEvent event;

    char *msg1 = "XDrawString Hello, World!";       // Message to be displayed in XDrawString
    char *msg2 = "XDrawImageString Hello, World!";  // Message to be displayed in XDrawImageString
    char *msg3 = "XDrawString Hello, New Font!";    // Message to be displayed in XDrawString with changed font

    // Open a connection to the X server
    display = XOpenDisplay(NULL);
    if (display == NULL) {// Check if the display was opened successfully
        fprintf(stderr, "Cannot open display\n");
        exit(1); // generic failure exit code
    }

    // Create a simple window
    window = XCreateSimpleWindow(
        display,
        RootWindow(display, 0),
        0, 0, 1024, 768,          // Position and size of the window
        0,                       // Border width
        BlackPixel(display, 0),  // Border color
        BlackPixel(display, 0)); // Background color

    // Set window title
    XStoreName(display, window, "Hello World");

    // Map (show) the window
    XMapWindow(display, window);

    // Flush the display to ensure all requests are sent
    XFlush(display);

    // Select input events for the window
    XSelectInput(display, window, ExposureMask | KeyPressMask);

    // Event loop
    for (;;) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            // Use the default X11 font.
            XSetFont(display, DefaultGC(display, 0), XLoadFont(display, "fixed")); 
            // Draw the message when the window is exposed
            XSetForeground(display, DefaultGC(display, 0), 0x00FF00); // Set text color to green
            XDrawString(display, window, DefaultGC(display, 0), 10, 20, msg1, strlen(msg1));

            XSetForeground(display, DefaultGC(display, 0), 0x0000FF); // Set text color to blue
            XSetBackground(display, DefaultGC(display, 0), 0xFFCC00); // Set background color to a light orange. Will otherwise be white
            XDrawImageString(display, window, DefaultGC(display, 0), 10, 40, msg2, strlen(msg2));

            // Change font
            // Reference: https://www.x.org/releases/X11R7.7/doc/xorg-docs/xlfd/xlfd.html
            XSetFont(display, DefaultGC(display, 0), XLoadFont(display, "-*-liberation mono-medium-r-normal-*-48-*-*-*-*-*-*-*"));
            XSetForeground(display, DefaultGC(display, 0), 0xFF66FF); // Set text color to a light purple
            XDrawString(display, window, DefaultGC(display, 0), 10, 100, msg3, strlen(msg3));

            XFlush(display);
        } else if (event.type == KeyPress) {
            // exit on ESC key press
            if (event.xkey.keycode == 0x09)
                break;
        }
    }

    // Clean up and close the display
    XUnmapWindow(display, window);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    return 0; // success exit code
}
