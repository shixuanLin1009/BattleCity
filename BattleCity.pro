QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Base.cpp \
    Bullet.cpp \
    BulletAbility.cpp \
    Enemy.cpp \
    GameOn.cpp \
    History.cpp \
    Obstacle.cpp \
    Scene.cpp \
    Tank.cpp \
    main.cpp \
    widget.cpp

HEADERS += \
    Base.h \
    Bullet.h \
    BulletAbility.h \
    Enemy.h \
    GameOn.h \
    History.h \
    Obstacle.h \
    Scene.h \
    Tank.h \
    widget.h

FORMS += \
    GameOn.ui \
    History.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Enemy/Enemy.qrc \
    History.qrc \
    Obstacles/Obstacles.qrc \
    image.qrc
-v

DISTFILES += \
    History \
    History.txt
