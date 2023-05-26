# swallow
X11 window "swallower"

Project goals:
- [X] Compile!
- [X] Convert to C!
- [X] Fork from C++ upstream!
- [WIP] Don't hide then change focus -- transfer focus (keep programs in the context/tag where you launched them, rather then when they finally load).
- [WIP] Do this for child (asynchronous) processes too using POSIX queues
- [WIP] If the program doesn't make an X window then keep the terminal open.

Goal:

Instantly open your program inside X11 even before it loads, even if it invisible, so the window manager can tag it immediately on opening.

Swallow can be a full X11

#### What is it?

When used to launch a GUI application from terminal it hides the terminal emulator from which the application was launched. The terminal will be restored after the launched application exits.

#### Usage
`swallow application_name [arguments]`

#### Future use case:
Use in a keyboard-based program launcher like `dmenu_run`, or in StumpWM etc. to instantly register launched programs in X.

#### Installation
```
git clone https://github.com/brownbishop/swallow
cd swallow
sudo(doas) make && make install
```

#### Removal
From the swallow directory run:
` sudo make uninstall`
