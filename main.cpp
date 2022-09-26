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

  void changeChannel(const int ch) {
    timer.start(delay);
    QString strTmp = QString::number(channel) + QString::number(ch);
    if(strTmp.toInt() <= 50) {
      channel = strTmp.toInt();
    } else if(ch != 0)
      channel = ch;
    powerOn = true;
    display();
  }

public:
  QWidget *widget = nullptr;
  QLabel *label_1 = nullptr;
  QLabel *label_2 = nullptr;
  QLabel *label_3 = nullptr;
  QLabel *lbPower = nullptr;
  QLabel *lbChannel = nullptr;
  QLabel *lbVolume = nullptr;

  RemoteControl() {
    QObject::connect(&timer, &QTimer::timeout,
                     this, &RemoteControl::displayOff);
  }

  void on_pbOnOff_clicked() {
    powerOn = !powerOn;
    timer.start(delay);
    display();
  }

  void display() const {
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

  void displayOff() const {
    label_1->clear();
    label_2->clear();
    label_3->clear();
    lbPower->clear();
    lbChannel->clear();
    lbVolume->clear();
    widget->setStyleSheet("background: rgb(64, 64, 64);");
  }

  void on_pbMute_clicked() {
    timer.start(delay);
    if(powerOn) mute = !mute;
    display();
  }

  void on_pb_1_clicked() {
    changeChannel(1);
  }

  void on_pb_2_clicked() {
    changeChannel(2);
  }

  void on_pb_3_clicked() {
    changeChannel(3);
  }

  void on_pb_4_clicked() {
    changeChannel(4);
  }

  void on_pb_5_clicked() {
    changeChannel(5);
  }

  void on_pb_6_clicked() {
    changeChannel(6);
  }

  void on_pb_7_clicked() {
    changeChannel(7);
  }

  void on_pb_8_clicked() {
    changeChannel(8);
  }

  void on_pb_9_clicked() {
    changeChannel(9);
  }

  void on_pb_0_clicked() {
    changeChannel(0);
  }

  void on_pbUpVolume_clicked() {
    timer.start(delay);
    mute = false;
    if(powerOn && volume < 100) volume += 10;
    display();
  }

  void on_pbDownVolume_clicked() {
    timer.start(delay);
    mute = false;
    if(powerOn && volume > 0) volume -= 10;
    display();
  }

  void on_pbPrevChannel_clicked() {
    timer.start(delay);
    if(powerOn && --channel < 1) channel = 50;
    display();
  }

  void on_pbNextChannel_clicked() {
    timer.start(delay);
    if(powerOn && ++channel > 50) channel = 1;
    display();
  }
};

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

  void setupUi(RemoteControl *window) {

    QFont font;
    font.setPointSize(24);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    window->setFixedSize(240, 680);

    centralWidget = new QWidget;

    gridLayout = new QGridLayout(centralWidget);

    QString a = "QPushButton {"
                "  min-width: 64px;"
                "  min-height: 48px;"
                "  border: 2px solid rgb(128, 128, 128);"
                "  border-radius: 4px;"
                "  background-color: rgb(248, 248, 248);"
                "  }"
                "  QPushButton:pressed {"
                "  background-color: rgb(185, 185, 185);"
                "  }"
                "  QPushButton:hover:!pressed {"
                "  background-color: rgb(205 ,205, 205);"
                "}";

    QString b = "QPushButton {"
                "  min-width: 64px;"
                "  min-height: 48px;"
                "  color: rgb(180, 64, 64);"
                "  border: 2px solid rgb(128, 128, 128);"
                "  border-radius: 4px;"
                "  background-color: rgb(248, 248, 248);"
                "  }"
                "  QPushButton:pressed {"
                "  background-color: rgb(185, 185, 185);"
                "  }"
                "  QPushButton:hover:!pressed {"
                "  background-color: rgb(205 ,205, 205);"
                "}";

    pbPower = new QPushButton(centralWidget);
    pbPower->setText("⏻");
    pbPower->setSizePolicy(sizePolicy);
    pbPower->setFont(font);
    pbPower->setStyleSheet(b);

    verticalSpacer_1 = new QSpacerItem(
      20, 24, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalSpacer_2 = new QSpacerItem(
      20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

    font.setPointSize(18);

    pbMute = new QPushButton(centralWidget);
    pbMute->setText("Mute");
    pbMute->setSizePolicy(sizePolicy);
    pbMute->setFont(font);
    pbMute->setStyleSheet(a);

    pb_0 = new QPushButton(centralWidget);
    pb_0->setText("0");
    pb_0->setSizePolicy(sizePolicy);
    pb_0->setFont(font);
    pb_0->setStyleSheet(a);

    pb_1 = new QPushButton(centralWidget);
    pb_1->setText("1");
    pb_1->setSizePolicy(sizePolicy);
    pb_1->setFont(font);
    pb_1->setStyleSheet(a);

    pb_2 = new QPushButton(centralWidget);
    pb_2->setText("2");
    pb_2->setSizePolicy(sizePolicy);
    pb_2->setFont(font);
    pb_2->setStyleSheet(a);

    pb_3 = new QPushButton(centralWidget);
    pb_3->setText("3");
    pb_3->setSizePolicy(sizePolicy);
    pb_3->setFont(font);
    pb_3->setStyleSheet(a);

    pb_4 = new QPushButton(centralWidget);
    pb_4->setText("4");
    pb_4->setSizePolicy(sizePolicy);
    pb_4->setFont(font);
    pb_4->setStyleSheet(a);

    pb_5 = new QPushButton(centralWidget);
    pb_5->setText("5");
    pb_5->setSizePolicy(sizePolicy);
    pb_5->setFont(font);
    pb_5->setStyleSheet(a);

    pb_6 = new QPushButton(centralWidget);
    pb_6->setText("6");
    pb_6->setSizePolicy(sizePolicy);
    pb_6->setFont(font);
    pb_6->setStyleSheet(a);

    pb_7 = new QPushButton(centralWidget);
    pb_7->setText("7");
    pb_7->setSizePolicy(sizePolicy);
    pb_7->setFont(font);
    pb_7->setStyleSheet(a);

    pb_8 = new QPushButton(centralWidget);
    pb_8->setText("8");
    pb_8->setSizePolicy(sizePolicy);
    pb_8->setFont(font);
    pb_8->setStyleSheet(a);

    pb_9 = new QPushButton(centralWidget);
    pb_9->setText("9");
    pb_9->setSizePolicy(sizePolicy);
    pb_9->setFont(font);
    pb_9->setStyleSheet(a);

    pbUpVolume = new QPushButton(centralWidget);
    pbUpVolume->setText("Vol+");
    pbUpVolume->setSizePolicy(sizePolicy);
    pbUpVolume->setFont(font);
    pbUpVolume->setStyleSheet(a);

    pbNextChannel = new QPushButton(centralWidget);
    pbNextChannel->setText("Ch+");
    pbNextChannel->setSizePolicy(sizePolicy);
    pbNextChannel->setFont(font);
    pbNextChannel->setStyleSheet(a);

    pbDownVolume = new QPushButton(centralWidget);
    pbDownVolume->setText("Vol-");
    pbDownVolume->setSizePolicy(sizePolicy);
    pbDownVolume->setFont(font);
    pbDownVolume->setStyleSheet(a);

    pbPrevChannel = new QPushButton(centralWidget);
    pbPrevChannel->setText("Ch-");
    pbPrevChannel->setSizePolicy(sizePolicy);
    pbPrevChannel->setFont(font);
    pbPrevChannel->setStyleSheet(a);

    widget = new QWidget;
    widget->setMinimumSize(QSize(0, 80));
    widget->setStyleSheet("background: rgb(64, 64, 64);");

    label_1 = new QLabel(widget);
    label_1->setGeometry(QRect(10, 10, 50, 14));
    label_1->setStyleSheet("color: rgb(255, 255, 255);");

    label_2 = new QLabel(widget);
    label_2->setGeometry(QRect(10, 30, 50, 14));
    label_2->setStyleSheet("color: rgb(255, 255, 255);");

    label_3 = new QLabel(widget);
    label_3->setGeometry(QRect(10, 50, 50, 14));
    label_3->setStyleSheet("color: rgb(255, 255, 255);");

    lbPower = new QLabel(widget);
    lbPower->setGeometry(QRect(60, 10, 50, 14));
    lbPower->setStyleSheet("color: rgb(255, 255, 255);");

    lbChannel = new QLabel(widget);
    lbChannel->setGeometry(QRect(60, 30, 50, 14));
    lbChannel->setStyleSheet("color: rgb(255, 255, 255);");

    lbVolume = new QLabel(widget);
    lbVolume->setGeometry(QRect(60, 50, 50, 14));
    lbVolume->setStyleSheet("color: rgb(255, 255, 255);");

    gridLayout->addItem(verticalSpacer_1, 0, 0, 1, 6);
    gridLayout->addWidget(pbPower, 1, 2, 1, 2);
    gridLayout->addItem(verticalSpacer_1, 2, 0, 1, 6);
    gridLayout->addWidget(pbPrevChannel, 3, 0, 1, 3);
    gridLayout->addWidget(pbNextChannel, 3, 3, 1, 3);
    gridLayout->addWidget(pbDownVolume, 4, 0, 1, 2);
    gridLayout->addWidget(pbMute, 4, 2, 1, 2);
    gridLayout->addWidget(pbUpVolume, 4, 4, 1, 2);
    gridLayout->addItem(verticalSpacer_1, 5, 0, 1, 6);
    gridLayout->addWidget(pb_1, 6, 0, 1, 2);
    gridLayout->addWidget(pb_2, 6, 2, 1, 2);
    gridLayout->addWidget(pb_3, 6, 4, 1, 2);
    gridLayout->addWidget(pb_4, 7, 0, 1, 2);
    gridLayout->addWidget(pb_5, 7, 2, 1, 2);
    gridLayout->addWidget(pb_6, 7, 4, 1, 2);
    gridLayout->addWidget(pb_7, 8, 0, 1, 2);
    gridLayout->addWidget(pb_8, 8, 2, 1, 2);
    gridLayout->addWidget(pb_9, 8, 4, 1, 2);
    gridLayout->addWidget(pb_0, 9, 2, 1, 2);
    gridLayout->addItem(verticalSpacer_2, 10, 0, 1, 6);
    gridLayout->addWidget(widget, 11, 0, 1, 6);
    gridLayout->addItem(verticalSpacer_2, 12, 0, 1, 6);

    window->setCentralWidget(centralWidget);
    window->setWindowTitle("Remote Control");
    window->setStyleSheet("background-color: rgb(240, 240, 240);");

    QObject::connect(pbMute, &QPushButton::clicked,
                     window, &RemoteControl::on_pbMute_clicked);
    QObject::connect(pb_0, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_0_clicked);
    QObject::connect(pbPower, &QPushButton::clicked,
                     window, &RemoteControl::on_pbOnOff_clicked);
    QObject::connect(pb_1, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_1_clicked);
    QObject::connect(pb_2, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_2_clicked);
    QObject::connect(pb_3, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_3_clicked);
    QObject::connect(pb_4, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_4_clicked);
    QObject::connect(pb_5, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_5_clicked);
    QObject::connect(pb_6, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_6_clicked);
    QObject::connect(pb_7, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_7_clicked);
    QObject::connect(pb_8, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_8_clicked);
    QObject::connect(pb_9, &QPushButton::clicked,
                     window, &RemoteControl::on_pb_9_clicked);
    QObject::connect(pbUpVolume, &QPushButton::clicked,
                     window, &RemoteControl::on_pbUpVolume_clicked);
    QObject::connect(pbNextChannel, &QPushButton::clicked,
                     window, &RemoteControl::on_pbNextChannel_clicked);
    QObject::connect(pbPrevChannel, &QPushButton::clicked,
                     window, &RemoteControl::on_pbPrevChannel_clicked);
    QObject::connect(pbDownVolume, &QPushButton::clicked,
                     window, &RemoteControl::on_pbDownVolume_clicked);
  }
};

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