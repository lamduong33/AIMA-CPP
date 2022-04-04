#ifndef AIMAGUI_HPP_
#define AIMAGUI_HPP_

#include <QApplication>
#include <QGraphicsItem>
#include <QIcon>
#include <QPushButton>
#include <QtWidgets>
#include <vector>

#include "ANN.hpp"

class Window : public QWidget
{
    vector<int> h;
    NeuralNetwork n;
};

class G_Neuron
{

};


#endif
