#ifndef PLAYER_H
#define PLAYER_H
#include "mainmenudialog.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QSoundEffect>
#include <QTimer>
#include <QPixmap>
#include <QUrl>
#include <QString>



class Player:  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent= 0);
    ~Player();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent * event);
    void movePlayer();
    void setDimensions();
    void changePlayerSpeed(int delta);
    void addPlayerSprite();
    void initMusic(QUrl blasterSoundEffect);
    void setMusic();


    int playerHeight;
    int playerWidth;

    int screenWidth = 800;
    int screenHeight = 600;
    const QPixmap spaceshipPic = QPixmap(":/images/spaceship_45x31.png");
    const QPixmap tankPic = QPixmap(":/images/tank_sprite_26x50.png");
    const QPixmap ufoPic = QPixmap(":/images/ufo_sprite_50x50.png");

    const QUrl blasterSound = QUrl("qrc:/sounds/blaster_sound.wav");

    int interval = 25;

    int xCoord;
    int yCoord;

    QString playerName;
    bool tankChosen = false;
    bool spaceshipChosen = false;
    bool ufoChosen = false;
    bool musicsOn = false;


private:

    double _spaceshipVelocity = 20.0;
    double _projectileVelocity = 8.0;
    QSoundEffect *_projectileSound;
    QTimer *_moveTimer;

    bool _keyLeft = false;
    bool _keyRight = false;
    bool _keyUp = false;
    bool _keyDown = false;
    bool _keySpace = false;




};

#endif // PLAYER_H
