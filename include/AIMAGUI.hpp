#ifndef AIMAGUI_HPP_
#define AIMAGUI_HPP_

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QtWidgets>

namespace Ui {
  class MainWindow;
}

/**
 * This class represents the main window with the main menu. This is the first
 * thing the user sees. */
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
private slots:
    void showANNPage();
    void showDecTreePage();
private:
    QVBoxLayout* m_menuLayout; // the button layout for the main menu
    QWidget* m_mainMenu; // the menu for the buttons to be displayed
};

class NeuralNetworkWindow : public QMainWindow
{
};

#endif // AIMAGUI_HPP
