#include <QMainWindow>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class RemoteControl : public QMainWindow {

  const int delay = 10000;

  int volume = 20;
  int channel = 1;
  bool powerOn = false;
  bool mute = false;
  QTimer timer;

  void changeChannel(int ch);

public:
  QWidget *widget = nullptr;
  QLabel *label_1 = nullptr;
  QLabel *label_2 = nullptr;
  QLabel *label_3 = nullptr;
  QLabel *lbPower = nullptr;
  QLabel *lbChannel = nullptr;
  QLabel *lbVolume = nullptr;

  RemoteControl();

  void on_pbOnOff_clicked();

  void display() const;

  void displayOff() const;

  void on_pbMute_clicked();

  void on_pb_1_clicked();

  void on_pb_2_clicked();

  void on_pb_3_clicked();

  void on_pb_4_clicked();

  void on_pb_5_clicked();

  void on_pb_6_clicked();

  void on_pb_7_clicked();

  void on_pb_8_clicked();

  void on_pb_9_clicked();

  void on_pb_0_clicked();

  void on_pbUpVolume_clicked();

  void on_pbDownVolume_clicked();

  void on_pbPrevChannel_clicked();

  void on_pbNextChannel_clicked();
};