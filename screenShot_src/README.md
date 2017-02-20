1. deps:
   mac-x64: Depends on Qt5.7.0 (x64) dynamic lib such as Qt5Core, Qt5Gui etc
   win-32:  Depends on Qt5.7.0 (x86) dynamic lib such as Qt5Core.dll, Qt5Gui.dll etc

2. res: icon files
3. src: c++ code wrapped with node v8
4. binding.gyp: compile configuration for mac and win
5. hello.js: called by nodejs
