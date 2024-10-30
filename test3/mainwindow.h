#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QStringList>
#include <QListWidget>>

QT_BEGIN_NAMESPACE

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addf();
    void removef();
    void clearf();

private:
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *clear;
    void setUpUI();


};
#endif // MAINWINDOW_H
