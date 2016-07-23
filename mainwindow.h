#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_resetBtn_clicked();

    void on_rotateBtn_clicked();

    void on_stable_partition_Btn_clicked();

    void on_stablePartitionBtn_clicked();

    void on_negateStablePartitionBtn_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<std::wstring> data;
};

#endif // MAINWINDOW_H
