# POL_POM_QT
Proof of concept project to see whether it is feasible to have a plugin based PlayOnLinux implementation based on Qt.

The idea is to use Qt based plugin libraries to manage a specific part of the application. The UI part provides the signals and slots to which plugins can register.

This makes for good separation of conserns since the UI parts -such as the main widget- only have logic to update their UI elements and provide signals and slots to send and receive data.

The plugin system also makes it easier for others to develop a new feature without having to change the main application. If -for instance- someone wants to do something with the list of virtual drives in the main widget the only thing the developer needs to do is register to the signal that is triggered at the event that needs to be intercepted, work on the list of items and send a signal back containing the updated list.

The following rules should be kept in mind when developing this application.
The main application dictates what can be done with it. When a plugin should be allowed to add a button to the main widget then the main widget should provide a signal to do so. There is no direct interaction with the main applications UI elements from a plugin.

Currently the structure is as follows.

POL_POM_QT 
  (basic application)
  Main Widget
  
POL_POM_QT_LIB_COMMON
  (a common library for sharing data types and common methods between application, libraries and plugins)

POL_POM_QT_LIB_VIRTUALDRIVE 
  (a common library which provides basic tasks for handline virtual drives)

POL_POM_QT_PLUGINS_STEAM
  (a study which demonstrates the use of a plugin system, comlete with UI to present to the user)
  
POL_POM_QT_PLUGINS_VIRTUALDRIVEMANAGER
  (A plugin that registers to the main widget's show event signal, populates a list of available virtual drives, and sends them back to the main widget's onvirtualdrivelistchange slot)

A little disclaimer. This project isn't in any way a replacement of the original PlayOnLinux implementation. See this as a study into alternative technologies which is shared in good open source tradition. Full credits for the original idea of PlayOnLinux go to the original PlayOnLinux developers. 
