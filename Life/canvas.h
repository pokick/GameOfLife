#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <qpainter.h>
#include "board.h"
#include <QTimer>

class Canvas : public QWidget
{
    Q_OBJECT
public:

    explicit Canvas(QWidget *parent = 0);
    board t;
    int tilesWidth;
    int tilesHeight;

    QTimer tim1;

signals:

public slots:

private slots:

private:


protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CANVAS_H
