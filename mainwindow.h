#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    bool checkValue(bool flag, QColor color, QString typeName);

    void on_pushButton_answer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
