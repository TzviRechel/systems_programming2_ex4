// tzvirechel@gmail.com
#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include "Tree.hpp"

class TreeViewWidget : public QGraphicsView {

public:
    TreeViewWidget(QWidget *parent = nullptr) : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    setScene(scene);
    setRenderHint(QPainter::Antialiasing);
}

    template <typename T, int k>
    void displayTree(const Tree<T, k>& tree);

private:
    QGraphicsScene *scene;

    template <typename T>
    void drawNode(QGraphicsScene *scene, Node<T> *node, int x, int y, int dx, int dy);
};


template <typename T, int k>
void TreeViewWidget::displayTree(const Tree<T, k>& tree) {
    scene->clear();  // Clear the scene before drawing the tree
    if (tree.getRoot()) {
        drawNode(scene, tree.getRoot(), width() / 2, 50, width() / 4, 50);  // Start drawing from the root node
    }
}

template <typename T>
void TreeViewWidget::drawNode(QGraphicsScene *scene, Node<T> *node, int x, int y, int dx, int dy) {
    if (!node) return;

    // Draw a circle for the node
    int radius = 20;
    QGraphicsEllipseItem *ellipse = scene->addEllipse(x - radius, y - radius, 2 * radius, 2 * radius);
    ellipse->setBrush(Qt::white);

    // Draw the node value inside the circle
    QGraphicsTextItem *textItem = scene->addText(node->toString());
    textItem->setPos(x - textItem->boundingRect().width() / 2, y - textItem->boundingRect().height() / 2);

    int numChildren = node->childrenSize();
    int startX = x - (numChildren - 1) * dx / 2;

    for (int i = 0; i < numChildren; ++i) {
        Node<T>* child = node->getChildren()[i];
        int childX = startX + i * dx;
        int childY = y + dy;

        // Draw a line connecting the parent node to the child node
        scene->addLine(x, y + radius, childX, childY - radius);

        // Recursively draw the child node
        drawNode(scene, child, childX, childY, dx / 2, dy);
    }
}



