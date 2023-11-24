QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editlistradio.cpp \
    main.cpp \
    mainwindow.cpp \
    playlistradio.cpp

HEADERS += \
    editlistradio.h \
    mainwindow.h \
    playlistradio.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

FORMS += \
    editlistradio.ui \
    playlistradio.ui



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./release/ -lbass
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./debug/ -lbass
else:unix:!macx: LIBS += -L$$PWD/./ -lbass

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: LIBS += -L$$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia/ -lgstreamermediaplugin

INCLUDEPATH += $$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia
DEPENDPATH += $$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia


unix:!macx: LIBS += -L$$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia/ -lffmpegmediaplugin

INCLUDEPATH += $$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia
DEPENDPATH += $$PWD/../../../Qt/6.5.3/gcc_64/plugins/multimedia
