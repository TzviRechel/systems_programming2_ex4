#include "TreeViewWidget.hpp"

TreeViewWidget::TreeViewWidget(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
}
