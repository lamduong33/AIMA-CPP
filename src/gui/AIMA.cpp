#include "../../include/AIMAGUI.hpp"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow n;
    auto window = new MainWindow();

    return app.exec();
}
