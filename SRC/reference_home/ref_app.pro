 HEADERS += \
         polledbuttons.h

 SOURCES += \
         main.cpp \
	 polledbuttons.cpp

 # install
 target.path = $$[QT_INSTALL_EXAMPLES]/graphicsview/collidingmice
 sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS collidingmice.pro images
 sources.path = $$[QT_INSTALL_EXAMPLES]/graphicsview/collidingmice
 INSTALLS += target sources
