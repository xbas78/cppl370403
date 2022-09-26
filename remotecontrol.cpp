#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "remotecontrol.h"


void RemoteControl::changeChannel(const int ch) {
  timer.start(delay);
  QString strTmp = QString::number(channel) + QString::number(ch);
  if(strTmp.toInt() <= 50) {
    channel = strTmp.toInt();
  } else if(ch != 0)
    channel = ch;
  powerOn = true;
  display();
}

RemoteControl::RemoteControl() {
  QObject::connect(&timer, &QTimer::timeout,
                   this, &RemoteControl::displayOff);
}

void RemoteControl::on_pbOnOff_clicked() {
  powerOn = !powerOn;
  timer.start(delay);
  display();
}

void RemoteControl::display() const {
  widget->setStyleSheet("background: rgb(128, 128, 128);");
  label_1->setText("Power:");
  label_2->setText("Channel:");
  label_3->setText("Volume:");

  if (powerOn) lbPower->setText("On");
  else lbPower->setText("Off");

  lbChannel->setText(QString::number(channel));

  if (mute) lbVolume->setText("mute");
  else lbVolume->setText(QString::number(volume));
}

void RemoteControl::displayOff() const {
  label_1->clear();
  label_2->clear();
  label_3->clear();
  lbPower->clear();
  lbChannel->clear();
  lbVolume->clear();
  widget->setStyleSheet("background: rgb(64, 64, 64);");
}

void RemoteControl::on_pbMute_clicked() {
  timer.start(delay);
  if(powerOn) mute = !mute;
  display();
}

void RemoteControl::on_pb_1_clicked() {
  changeChannel(1);
}

void RemoteControl::on_pb_2_clicked() {
  changeChannel(2);
}

void RemoteControl::on_pb_3_clicked() {
  changeChannel(3);
}

void RemoteControl::on_pb_4_clicked() {
  changeChannel(4);
}

void RemoteControl::on_pb_5_clicked() {
  changeChannel(5);
}

void RemoteControl::on_pb_6_clicked() {
  changeChannel(6);
}

void RemoteControl::on_pb_7_clicked() {
  changeChannel(7);
}

void RemoteControl::on_pb_8_clicked() {
  changeChannel(8);
}

void RemoteControl::on_pb_9_clicked() {
  changeChannel(9);
}

void RemoteControl::on_pb_0_clicked() {
  changeChannel(0);
}

void RemoteControl::on_pbUpVolume_clicked() {
  timer.start(delay);
  mute = false;
  if(powerOn && volume < 100) volume += 10;
  display();
}

void RemoteControl::on_pbDownVolume_clicked() {
  timer.start(delay);
  mute = false;
  if(powerOn && volume > 0) volume -= 10;
  display();
}

void RemoteControl::on_pbPrevChannel_clicked() {
  timer.start(delay);
  if(powerOn && --channel < 1) channel = 50;
  display();
}

void RemoteControl::on_pbNextChannel_clicked() {
  timer.start(delay);
  if(powerOn && ++channel > 50) channel = 1;
  display();
}