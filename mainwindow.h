#include "remotecontrol.h"

class MainWindow {
public:
  QWidget *centralWidget;
  QSpacerItem *verticalSpacer_1;
  QSpacerItem *verticalSpacer_2;
  QGridLayout *gridLayout;
  QPushButton *pb_0;
  QPushButton *pb_1;
  QPushButton *pb_2;
  QPushButton *pb_3;
  QPushButton *pb_4;
  QPushButton *pb_5;
  QPushButton *pb_6;
  QPushButton *pb_7;
  QPushButton *pb_8;
  QPushButton *pb_9;
  QPushButton *pbUpVolume;
  QPushButton *pbDownVolume;
  QPushButton *pbPrevChannel;
  QPushButton *pbNextChannel;
  QPushButton *pbPower;
  QPushButton *pbMute;
  QWidget *widget;
  QLabel *label_1;
  QLabel *label_2;
  QLabel *label_3;
  QLabel *lbPower;
  QLabel *lbChannel;
  QLabel *lbVolume;

  void setupUi(RemoteControl *window);
};