# swallow
X11 window "swallower"

Project goals:
- [X] Compile!
- [X] Convert to C!
- [X] Fork from C++ upstream!
- [WIP] Don't hide then change focus -- transfer focus (keep programs in the context/tag where you launched them, rather then when they finally load).

#### What it does? 

When used to launch a GUI application from terminal it hides the terminal emulator from which the application was launched. The terminal will be restored after the launched application exits. 

#### Usage
`swallow application_name [arguments]`

#### Installation
```  
git clone https://github.com/brownbishop/swallow
cd swallow  
sudo(doas) make install
```  

#### Removal
From the swallow directory run: 
` sudo make uninstall` 

