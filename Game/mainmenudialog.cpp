#include "mainmenudialog.h"
#include "ui_mainmenudialog.h"
#include "gamewindow.h"

#include <QDebug>
#include <QString>
#include <QSize>
#include <QSettings>



MainMenuDialog::MainMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenuDialog)
{
    ui->setupUi(this);
    _menuDialogSize = QSize(800, 600);
    this->setFixedSize(_menuDialogSize);


}

MainMenuDialog::~MainMenuDialog()
{
    delete ui;
}

void MainMenuDialog::setCorrectMusicState()
{
    QSettings setting;

    if(ui->musicsOn->isChecked() || _musicsOn){
        setting.setValue("music setting", musicStateOn);
    }else{
        setting.setValue("music setting", musicStateOff);
    }
}

void MainMenuDialog::on_startButton_clicked()
{
    if((_tank || _spaceShip  || _ufo) && (_fireball || _missile || _laser)
            && playerAlias != NULL){

        setCorrectMusicState();
        GameWindow *mainWin = new GameWindow();
        mainWin->show();

        this->close();

    } else if(playerAlias == NULL && (_tank || _spaceShip || _ufo) &&
              (_fireball || _missile || _laser)){

        ui->erronousInputLabel->setText("Remember to set player name!");
    }
    else if(!(_tank && _spaceShip && _ufo) && (_fireball || _missile || _laser)
            && playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set player type!");

    }else if((_fireball || _missile || _laser) && !(_tank && _spaceShip && _ufo)
             && playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set player type and"
                                        " player name!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && playerAlias != NULL){

        ui->erronousInputLabel->setText("Remember to set projectile type!");

    } else if((_tank || _spaceShip || _ufo) && !(_fireball && _missile && _laser)
              && playerAlias == NULL){
        ui->erronousInputLabel->setText("Remember to set projectile type"
                                        " and player name!");

    } else if(!(_tank && _spaceShip && _ufo) && !(_fireball && _missile && _laser)
              && playerAlias != NULL){
        ui->erronousInputLabel->setText("Remember to set projectile"
                                        " and player type!");

    }else {
        ui->erronousInputLabel->setText("Remember to set projectile type, "
                                        "player name and player type!");
    }
}

void MainMenuDialog::on_exitButton_clicked()
{
    this->close();
}

void MainMenuDialog::on_playerNameEdit_editingFinished()
{
    playerAlias = ui->playerNameEdit->text();
    QSettings playerSettings;
    playerSettings.setValue("player name setting", playerAlias);


}

void MainMenuDialog::on_spaceshipButton_clicked()
{
    //qDebug() <<"spaceship chosen";
    _spaceShip = true;
    _tank = false;
    _ufo = false;


    QSettings playerSettings;
    playerSettings.setValue("player type setting", spaceshipOption);

}

void MainMenuDialog::on_tankButton_clicked()
{
    //qDebug() <<"tank chosen";
    _tank = true;
    _spaceShip = false;
    _ufo = false;

    QSettings playerSettings;
    playerSettings.setValue("player type setting", tankOption);


}

void MainMenuDialog::on_ufoButton_clicked()
{
    //qDebug() <<"ufo chosen";
    _ufo = true;
    _tank = false;
    _spaceShip = false;

    QSettings playerSettings;
    playerSettings.setValue("player type setting", ufoOption);

}


void MainMenuDialog::on_fireballButton_clicked()
{
    //qDebug()<< "fireball clicked";
    _fireball = true;
    _missile = false;
    _laser = false;

    QSettings playerSettings;
    playerSettings.setValue("projectile type setting", fireballOption);
    playerSettings.setValue("projectile soundeffect setting", fireballSound);
}

void MainMenuDialog::on_missileButton_clicked()
{
    //qDebug()<< "missile clicked";
    _fireball = false;
    _missile = true;
    _laser = false;

    QSettings playerSettings;
    playerSettings.setValue("projectile type setting", missileOption);
    playerSettings.setValue("projectile soundeffect setting", missileSound);
}

void MainMenuDialog::on_laserButton_clicked()
{
    //qDebug()<< "laser clicked";
    _fireball = false;
    _missile = false;
    _laser = true;

    QSettings playerSettings;
    playerSettings.setValue("projectile type setting", laserOption);
    playerSettings.setValue("projectile soundeffect setting", blasterSound);
}

void MainMenuDialog::on_musicsOn_clicked()
{
    QSettings playerSettings;
    if(ui->musicsOn->isChecked()){
        qDebug()<<"musics on";
        _musicsOn = true;
        playerSettings.setValue("music setting", musicStateOn);
    }else if(!ui->musicsOn->isChecked()){
        _musicsOn = false;
        qDebug()<<"musics off";
        playerSettings.setValue("music setting", musicStateOff);
    }
}

void MainMenuDialog::on_settingsButton_clicked()
{
    settingsDialog *mainSettingsDialog = new settingsDialog(this);
    mainSettingsDialog->exec();
}

void MainMenuDialog::on_helpButton_clicked()
{
    helpDialog *gameHelpDialog = new helpDialog(this);
    gameHelpDialog->exec();
}
