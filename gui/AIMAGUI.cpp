#include "../include/AIMAGUI.hpp"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_ANNButton = new QPushButton("Artificial Neural Network", this);
    m_ANNButton->setGeometry(QRect(QPoint(100,100), QSize(200, 50)));
    m_DecisionTreeButton = new QPushButton("Decision Tree", this);
    m_ANNButton->setGeometry(QRect(QPoint(100,200), QSize(200, 50)));

    connect(m_ANNButton, &QPushButton::released, this, &MainWindow::handleButton);

}

void MainWindow::handleButton()
{
    m_ANNButton->setText("This worked!");
    m_ANNButton->resize(100,100);
}
