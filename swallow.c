#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

void usage() {
    printf("swallow app_name [arguments]\n");
}

int main(int argc, char** argv) {
    if (argc <= 1) {
        usage();
        return 1;
    }

    char *command;
    int maxsize,i,j;

    for(maxsize=0,i=1; argv[i]; i++)
      for(j=0; argv[i][j];j++)
        maxsize++;

    command = (char*)malloc(maxsize);
    char *c = command;

    for (int i = 1; argv[i]; i++) {
      for(int j=0; argv[i][j]; j++)
        *(command++) = argv[i][j];
     *(command++) = ' ';
    }
    command = c;
    printf("%s", command);

    // open current display
    int rev;
    Window win;
    Display* dis = XOpenDisplay(0);

    if (!dis) {
        printf("Failed to open display!\n");
        return 1;
    }

    /*
     * when this program runs the terminal emulator
     * is the current focused window
     */

    // hide the focused window
    XGetInputFocus(dis, &win, &rev);
    XUnmapWindow(dis, win);
    XFlush(dis);

    // launch the application
    int res = system(command);

    if (res) {
        printf("Application exited with %i\n", res);
    }

    // the application exited
    // unhide the terminal emulator
    XMapWindow(dis, win);
    XCloseDisplay(dis);

}

