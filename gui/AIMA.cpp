#include "../include/AIMAGUI.hpp"
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QVBoxLayout>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.addToolBar(new QToolBar);
    auto ANNButton = new QPushButton("Artificial Neural Network");
    ANNButton->setVisible(true);
    ANNButton->setObjectName("ANN Button");
    window.show();

    return app.exec();
}
