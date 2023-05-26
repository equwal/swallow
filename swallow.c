#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

void usage(void);
int main(int,char**);

void usage() {
    fputs("swallow app_name [arguments]\n", stderr);
    exit(1);
}

int main(int argc, char** argv) {
    if (argc <= 1)
        usage();

    // open current display
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
    XGetInputFocus(dis, &win, &(int){ 0 });
    XUnmapWindow(dis, win);
    XFlush(dis);

    // launch the application
    pid_t child;
    int res = 0;
    if (!posix_spawnp(&child, argv[1], NULL, NULL, argv + 1, environ))
        waitpid(child, &res, 0);

    if (WIFEXITED(res)) {
        if (WEXITSTATUS(res))
            printf("Application exited with %d\n", WEXITSTATUS(res));
    } else if (WIFSIGNALED(res)) {
        printf("Allication died with signal %d\n", WTERMSIG(res));
    }

    // the application exited
    // unhide the terminal emulator
    XMapWindow(dis, win);
    XCloseDisplay(dis);

    return 0;
}
