#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>  //
#include <QVector>      //
#include <QDebug>
// #ifdef __cplusplus                  //
extern "C" {  //
// #endif                              //
#include "calc.h"  //
// #ifdef __cplusplus                  //
}  //
// #endif                              //

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pB_2_clicked();

  void on_pB_18_clicked();

  void on_pB_29_clicked();

  void on_pB_16_clicked();

  void on_pB_15_clicked();

  void on_pB_10_clicked();

  void on_pB_12_clicked();

  void on_pB_11_clicked();

  void on_pB_6_clicked();

  void on_pB_8_clicked();

  void on_pB_7_clicked();

  void on_pB_20_clicked();

  void on_pB_1_clicked();

  void on_pB_17_clicked();

  void on_pB_13_clicked();

  void on_pB_9_clicked();

  void on_pB_5_clicked();

  void on_pB_4_clicked();

  void on_pB_3_clicked();

  void on_pB_33_clicked();

  void on_pB_31_clicked();

  void on_pB_32_clicked();

  void on_pB_14_clicked();

  void on_pB_21_clicked();

  void on_pB_22_clicked();

  void on_pB_23_clicked();

  void on_pB_24_clicked();

  void on_pB_25_clicked();

  void on_pB_26_clicked();

  void on_pB_27_clicked();

  void on_pB_28_clicked();

  void on_pB_34_clicked();

  void on_pB_35_clicked();

  void on_pB_30_clicked();

  void on_pB_19_clicked();

  void print();

  void on_pB_39_clicked();

  void on_spinBox_8_textChanged(const QString &arg1);

  void on_spinBox_7_textChanged(const QString &arg1);

  void on_spinBox_5_textChanged(const QString &arg1);

  void on_spinBox_6_textChanged(const QString &arg1);

  void on_spinBox_9_textChanged(const QString &arg1);

  void on_spinBox_10_textChanged(const QString &arg1);

  void on_spinBox_11_textChanged(const QString &arg1);

  void on_pB_36_clicked();

  void on_pB_38_clicked();

  void on_action_triggered();

private:
  Ui::MainWindow *ui;
  QVector<double> x, y;  //
};
#endif  // MAINWINDOW_H
