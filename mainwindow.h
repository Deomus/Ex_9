#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include <QPalette>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPalette backgroundPalette;

private slots:
    bool checkValue(bool flag, QColor color, QString typeName);

    void on_pushButton_answer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
