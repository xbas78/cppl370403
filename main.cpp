/*------------------------------------------------------------------------------
    Задача (37.4.) 3. Пульт дистанционного управления ТВ
--------------------------------------------------------------------------------
  Что нужно сделать
  Реализуйте простой симулятор управления телевизором с помощью пульта,
представленного в виде графического интерфейса с кнопками.
  Интерфейс представляет собой вертикальное окно (в портретной ориентации)
размером 240х680 пикселей. На пульте находятся кнопки переключения каналов
от 0 до 9, кнопки перехода к следующему и предыдущему каналу, кнопки увеличения
и уменьшения громкости с шагом в 10%.
  Снизу пульта находится мини-дисплей с отображением текущего статуса:
      текущий выбранный канал и текущий уровень громкости в процентах.

  Что оценивается
  Полнота графического интерфейса и корректность реализации логики программы и
всех кнопок.
------------------------------------------------------------------------------*/
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  RemoteControl window;
  MainWindow remoteControl{};
  remoteControl.setupUi(&window);
  window.widget = remoteControl.widget;
  window.label_1 = remoteControl.label_1;
  window.label_2 = remoteControl.label_2;
  window.label_3 = remoteControl.label_3;
  window.lbPower = remoteControl.lbPower;
  window.lbChannel = remoteControl.lbChannel;
  window.lbVolume = remoteControl.lbVolume;
  window.show();
  return QApplication::exec();
}