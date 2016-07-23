#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_resetBtn_clicked()
{
    data =
        {L"A", L"B", L"C",      // 0
         L"1", L"2", L"3",      // 3
         L"D", L"E", L"F",      // 6
         L"4", L"5", L"6",      // 9
         L"G", L"H", L"I" };    // 12

    ui->widget->showList(data);
}

void MainWindow::on_rotateBtn_clicked()
{
    // begin() + 3 ~ 6 : 1,2,3
    // begin() + 9 :
    rotate (data.begin() + 3, data.begin() + 6 , data.begin() + 9 );

    ui->widget->showList(data);
}

void MainWindow::on_stable_partition_Btn_clicked()
{
    data =
        {L"A", L"B",
         L"1",
         L"C", L"D",
         L"2", L"3",
         L"E", L"F", L"G" };

    ui->widget->showList(data);
}

void MainWindow::on_stablePartitionBtn_clicked()
{
    std::stable_partition(data.begin(), data.end(), [](const std::wstring& e){
        bool convertable = true;
        try {
            std::stol(e);
        } catch (std::invalid_argument & e) {
            convertable = false;
        }

        return convertable;
    });

    ui->widget->showList(data);
}

void MainWindow::on_negateStablePartitionBtn_clicked()
{
    // http://en.cppreference.com/w/cpp/algorithm/stable_partition
    // Return value
    // Iterator to the first element of the second group
    std::stable_partition(data.begin(), data.end(), [](const std::wstring& e){
        bool convertable = true;
        try {
            std::stol(e);
        } catch (const std::invalid_argument & ) {
            convertable = false;
        }

        return !convertable;
    });

    ui->widget->showList(data);
}
