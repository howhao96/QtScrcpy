#ifndef VIDEOFORM_H
#define VIDEOFORM_H

#include <QWidget>
#include <QPointer>

#include "server.h"
#include "decoder.h"
#include "frames.h"
#include "inputconvertnormal.h"
#include "inputconvertgame.h"

namespace Ui {
class videoForm;
}

class ToolForm;
class VideoForm : public QWidget
{
    Q_OBJECT

public:
    explicit VideoForm(const QString& serial, quint16 maxSize = 720, quint32 bitRate = 8000000, QWidget *parent = 0);
    ~VideoForm();

    void switchFullScreen();
    void postGoMenu();
    void postGoHome();
    void postGoBack();
    void postAppSwitch();
    void postPower();
    void postVolumeUp();
    void postVolumeDown();
    // turn the screen on if it was off, press BACK otherwise
    void postTurnOn();

private:
    void updateShowSize(const QSize &newSize);
    void updateStyleSheet(bool vertical);
    void initUI();
    void showToolFrom(bool show = true);
    void postKeyCodeClick(AndroidKeycode keycode);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *event);

private:
    Ui::videoForm *ui;
    QSize frameSize;
    Server* m_server = Q_NULLPTR;
    Decoder m_decoder;
    Frames m_frames;
    //InputConvertNormal m_inputConvert;
    InputConvertGame m_inputConvert;
    QString m_serial = "";
    quint16 m_maxSize = 720;
    quint32 m_bitRate = 8000000;
    QPoint m_dragPosition;
    float m_widthHeightRatio = 0.5f;
    QPointer<ToolForm> m_toolForm;
};

#endif // VIDEOFORM_H
