#include "../../include/AIMAGUI.hpp"
//#include "../../include/moc_AIMAGUI.cpp" // CMake needs to know the moc for Qt6

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_mainMenu = new QWidget;
    QPushButton *button1 = new QPushButton("Artificial Neural Network");
    QPushButton *button2 = new QPushButton("Decision Tree");
    m_menuLayout = new QVBoxLayout(m_mainMenu);
    m_menuLayout->addWidget(button1);
    m_menuLayout->addWidget(button2);
    setCentralWidget(m_mainMenu);
}

void MainWindow::showDecTreePage()
{
}

void MainWindow::showANNPage()
{
}
