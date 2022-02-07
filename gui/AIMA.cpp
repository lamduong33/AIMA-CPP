#include "../include/AIMAGUI.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton button;
    button.setText("Get Started!");
    button.setToolTip("This will start the program");
    QFont font("Iosevka");
    button.setFont(font);

    button.show();

    return app.exec();
}
