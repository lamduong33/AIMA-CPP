#include "../include/AIMAGUI.hpp"

// Hello
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(100, 50);

    auto button = new QPushButton("Get Started", &window);
    button->setGeometry(10, 10, 80, 30);

    window.show();

    return app.exec();
}
