FabView
=======

proof-of-concept webview for Sketchfab

FabView points to http://artlensdev.clevelandart.org/static/sketchfab.html

Requirements
------------
Depends on Cinder-CEF: https://github.com/codeoncanvas/Cinder-CEF

Follow the steps to build Cinder-CEF for Windows: https://github.com/codeoncanvas/Cinder-CEF/blob/master/win_notes.md

Expected structure:

    Cinder/
        blocks/Cinder-CEF
    FabView/

You also need to set your PATH to include:

    Cinder/blocks/Cinder-CEF/libs/cef/export/vs/x64

Otherwise, the application will fail to locate libcef.dll

The application console window can be removed by commenting out lines 87-95 from Cinder-CEF/src/ciCEF.cpp (https://github.com/codeoncanvas/Cinder-CEF/blob/master/src/ciCEF.cpp#L87-L95)
