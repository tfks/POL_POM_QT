# POL_POM_QT
Proof of concept project to see whether it is feasible to have a plugin based PlayOnLinux implementation based on Qt.

The idea is to use Qt based plugin libraries to manage a specific part of the application. The UI part provides the signals and slots to which plugins can register.

This makes for a good separation of concern principle since the UI parts -such as the main widget- only have logic to update their UI elements and provide signals and slots to send and receive data.

The plugin system also makes it easier for others to develop a new feature without having to change the main application. If -for instance- someone wants to do something with the list of virtual drives in the main widget the only thing the developer needs to do is register to the signal that is triggered at the event that needs to be intercepted, then work on the list of items and finally send a signal back containing the updated list. The event can be the main widget showing or a button being pressed.

The following rules should be kept in mind when developing this application.

1. The main application dictates what can be done with it. When a plugin should be allowed to add a button to the main widget then the main widget should provide a slot to do so. There is no direct interaction with the main applications UI elements from a plugin. Thus the main application provides an API for the plugin developers to use.

2. Libraries should not cross reference. For instance. The common library is used by the virtual drive library. Therefore the methods in the common library should be of a lower level type than the methods in the virtual drive library. In other words, the common library should hold methods that handle very basic functionality which can be used in all layers of the application, the virtual drive library handles solely virtual drive functionality. The virtual drive library can use the basic functionality of the common library but never vice versa.

# Project structure
Currently the structure is as follows.

	<project-root>
		POL_POM_QT 
			(basic application containing Main Widget and other base elements)
		
  
		POL_POM_QT_LIB_COMMON
			(a common library for sharing data types and common methods between application, libraries and plugins)

		POL_POM_QT_LIB_VIRTUALDRIVE 
			(a common library which provides basic tasks for handling virtual drives)

		POL_POM_QT_PLUGINS_STEAM
			(a study which demonstrates the use of a plugin system, comlete with UI to present to the user)
  
		POL_POM_QT_PLUGINS_VIRTUALDRIVEMANAGER
			(A plugin that registers to the main widget's show event signal, populates a list of available virtual drives, and sends them back to the main widget's onvirtualdrivelistchange slot)

# Build directory structure
Since the application uses libraries which require debugging, a system of auto deployment of the libraries at build time has been set-up. This deployes every library to a lib directory under the main application's build directory. 

	<main-build-directory>
		POL_POM_QT/
			/bin (location for executables)
			/lib (location for storing the built libraries)
			/plugins (location for storing the built plugins)

		POL_POM_QT_LIB_COMMON/
			(all build files for the common library)
			(*.so files are copied to /lib on build)

		POL_POM_QT_LIB_VIRTUALDRIVE/
			(all build files for the virtual drive library)
			(*.so files are copied to /lib on build)

		POL_POM_QT_PLUGINS_STEAM/
			(all build files for the steam installer plugin library)
			(*.so files are copied to /plugins on build)

		POL_POM_QT_PLUGINS_VIRTUALDRIVEMANAGER/
			(all build files for the virtual drive manager plugin library)
			(*.so files are copied to /plugins on build)

This structure has been set-up to being able to directly debug both main application and libraries / plugins without having to manually deploy all needed libraries.

To make the above system work please use the POL_POM_QT_SOLUTION.pro file to open the complete project structure.

# Qt version
This project has been built on Qt5. It should compile on Qt4 but this has not yet been tested.

# Disclaimer
A little disclaimer. This project isn't in any way a replacement of the original PlayOnLinux implementation. See this as a study into alternative technologies which is shared in good open source tradition. Full credits for the original idea of PlayOnLinux go to the original PlayOnLinux developers. 
