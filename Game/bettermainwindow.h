#ifndef BETTERMAINWINDOW_H
#define BETTERMAINWINDOW_H
#include "player.h"
#include "basicprojectile.h"
#include "mainmenudialog.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QTimer>
#include <QPixmap>
#include <QPalette>
#include <QImage>
#include <QBrush>
#include <QPaintEvent>
#include <vector>

namespace Ui {
class BetterMainWindow;
}

class BetterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BetterMainWindow(QWidget *parent = nullptr);
    ~BetterMainWindow();

    void resizeEvent(QResizeEvent * event);
    void setPicture(QImage img);

    std::vector<int> getAvailableSize();
    MainMenuDialog *giveDialog() {return _mainMenu;};

    //Score * score;
    //Health * health;

    struct dimensions {
        int width = 800;
        int height = 600;
    };
    int interval = 500;
    QImage bkgndSmall = QImage(":/offlinedata/offlinedata/kartta_pieni_500x500.png");
    QImage bkgndBig = QImage(":/offlinedata/offlinedata/kartta_iso_1095x592.png");


public slots:
    void setPlayerNick(QString name);
    void setPlayerIcon(int type);
    void setMusicChoice(int choice);

    //void setProjectileIcon(int projectileType);

private:
    Ui::BetterMainWindow *ui;
    QTimer *timer;
    QGraphicsScene * _scene;
    Player * _player;
    //basicProjectile *_projectile;
    QPixmap _pixmapBg = QPixmap(":/offlinedata/offlinedata/kartta_iso_1095x592.png");
    bool _largeMode = false;
    MainMenuDialog *_mainMenu;

};

#endif // BETTERMAINWINDOW_H
