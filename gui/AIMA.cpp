#include "../include/AIMAGUI.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto window = new MainWindow();
    window->show();

    return app.exec();
}
