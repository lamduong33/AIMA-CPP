#ifndef AIMAGUI_HPP_
#define AIMAGUI_HPP_

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

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
    QVBoxLayout* m_menuLayout;
};

#endif // AIMAGUI_HPP
