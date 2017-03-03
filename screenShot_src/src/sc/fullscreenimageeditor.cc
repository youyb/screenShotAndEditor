#include "fullscreenimageeditor.h"
#include "ui_fullscreenimageeditor.h"
#include "commondef.h"
#include "configmanager.h"
#include <QtMath>
#include <QPainter>
#include <QFileDialog>
#include <QClipboard>
#include <QTime>
#include <QBitmap>
#include "penpaintingstep.h"
#include "rectpaintingstep.h"
#include "textpaintingstep.h"
#include "arrowpaintingstep.h"
#include "ovalpaintingstep.h"
#include "mosaicpaintingstep.h"

QString g_ImagePath;
QString g_ImageDir;
QString g_IconDir;
double g_dpr;
int g_count = 0;
int g_x = -100;
int g_y = -100;
//int g_len = 1;

FullScreenImageEditor::FullScreenImageEditor(QPixmap &image, QString imgDir, QString iconDir, double dpr, QWidget *parent) :
    QMainWindow(parent),
  ui(new Ui::FullScreenImageEditor)
{
    g_ImageDir = imgDir;
    g_dpr = dpr;
    g_IconDir = iconDir;

    ui->setupUi(this);
    selectedArea = QRect(-10000,-10000,0,0);
    screenImage = image.toImage();
    actualCanvas = screenImage;
    setCanvasMode(CanvasMode::IDLE);
    paintingStarted = false;
    currentPen = QPen(QColor(200,0,0,255));
    currentPen.setWidth(PenWidth::PEN_NORMAL);
    mosaicSize = MosaicSize::MOSAIC_NORMAL;

    textEdit = new QTextEdit(this);
    textEdit->setObjectName(QStringLiteral("textEdit"));
    textEdit->setGeometry(QRect(-100, -100, 30, 30));
    textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit->setVisible(false);

    connect(textEdit, SIGNAL(textChanged()), this, SLOT(adjustTextEditSize()));

    QObjectList list = ui->colorPanel->children();
    QObjectList::Iterator iter = list.begin();

    for (; iter != list.end(); ++iter) {
        if ((*iter)->inherits("QPushButton"))
            connect(*iter, SIGNAL(clicked()), this, SLOT(on_color_picked()));
    }
}

FullScreenImageEditor::~FullScreenImageEditor()
{
    delete ui;
    delete textEdit;
    QDBG<<"delete ui and textEdit...";
}

void FullScreenImageEditor::paintEvent(QPaintEvent *e)
{

    QPainter painter(&actualCanvas);
    painter.setBrush(QBrush(ConfigManager::instance()->maskColor()));
    painter.setPen(ConfigManager::instance()->maskColor());


    painter.drawImage(0, 0, screenImage);
    // paintingHistory should be drawn before the rectangle and the masks.
    painter.setBrush(QBrush());
    paintingHistory.paint(&painter);

    painter.fillRect(0, 0, selectedArea.left(), screenImage.height(), ConfigManager::instance()->maskColor());
    painter.fillRect(selectedArea.right() + 1, 0, screenImage.width() - selectedArea.right(), screenImage.height(), ConfigManager::instance()->maskColor());
    painter.fillRect(selectedArea.left(), 0, selectedArea.width(), selectedArea.top(), ConfigManager::instance()->maskColor());
    painter.fillRect(selectedArea.left(), selectedArea.bottom() + 1, selectedArea.width(), screenImage.height()-selectedArea.bottom(), ConfigManager::instance()->maskColor());


    painter.setPen(ConfigManager::instance()->selectedBoarderColor());


    // I found that drawRect funciton thinks the WIDTH is rect.right - rect.height, which means
    // this function will draw a rectangle whose width is N with actually N+1 pixels.
    // So is height, thus here we make width and height -1
    painter.drawRect(selectedArea.left(), selectedArea.top(), selectedArea.width() - 1, selectedArea.height() - 1);


    // hide comand buttons if necessay. This is a wourk around. SetVisible may cause mouseMoveEvent not working.
    if (getCanvasMode() == CanvasMode::MOVING || getCanvasMode() == CanvasMode::RESIZING
             || getCanvasMode() == CanvasMode::IDLE || getCanvasMode() == CanvasMode::SELECTING) {
        QRect geo(ui->cmdPanel->geometry());
        geo.moveTo(-100000,-100000);
        ui->cmdPanel->setGeometry(geo);
    } else {
        moveCmdPanelToProperPosition();
    }

    QPainter p(this);
    p.drawImage(0, 0, actualCanvas);
    QMainWindow::paintEvent(e);
}

void FullScreenImageEditor::moveCmdPanelToProperPosition()
{
    QWidget *cmdPanel = ui->cmdPanel;
    QRect geo(cmdPanel->geometry());

    int x = selectedArea.right() - cmdPanel->width();
    int y = selectedArea.bottom() + 10;
    if (x < 0) {
        x = 0;
    }
    if (y + cmdPanel->height() > screenImage.height()) {
        if (selectedArea.top() > 10 + cmdPanel->height())
            y = selectedArea.top() - 10 - cmdPanel->height();
        else if (selectedArea.top() <= screenImage.height() - selectedArea.bottom())
            y = screenImage.height() - cmdPanel->height();
        else
            y = 0;
    }
    geo.moveTo(x, y);
    ui->cmdPanel->setGeometry(geo);
}

void FullScreenImageEditor::mousePressEvent(QMouseEvent *e)
{
    mouseDownX = e->x();
    mouseDownY = e->y();
    if (e->button() == Qt::LeftButton) {
        if (getCanvasMode() == CanvasMode::IDLE) {
            selectedArea.setTop(e->y());
            selectedArea.setLeft(e->x());
            selectedArea.setBottom(e->y());
            selectedArea.setRight(e->x());
            setCanvasMode(CanvasMode::SELECTING);
            this->update();
        } else if (getCanvasMode() == CanvasMode::SELECTED) {
            if (mousePosition == MousePosition::Other) {
                if (isInSelectedArea(e->x(), e->y())) {
                    originalSelectLeft = selectedArea.left();
                    originalSelectTop = selectedArea.top();
                    setCanvasMode(CanvasMode::MOVING);
                } else {
                    canvasModeBackup = getCanvasMode();
                    setCanvasMode(CanvasMode::INVALID);
                }
            } else {
                // On selected area's boarder
                setCanvasMode(CanvasMode::RESIZING);
            }
        } else if (getCanvasMode() == CanvasMode::PAINTING) {
            if (isInSelectedArea(e->x(), e->y())) {
                paintingStarted = true;
                switch (paintingMode) {
                case PaintingMode::PEN: {
                    PenPaintingStep *penStep = new PenPaintingStep;
                    penStep->setPen(currentPen);
                    penStep->addPoint(e->pos());
                    paintingHistory.doStep(penStep);
                    break;
                }
                case PaintingMode::OVAL: {
                    OvalPaintingStep *ovalStep = new OvalPaintingStep;
                    ovalStep->setPen(currentPen);
                    ovalStep->setFirstPoint(e->pos());
                    paintingHistory.doStep(ovalStep);
                    break;
                }
                case PaintingMode::RECT: {
                    RectPaintingStep *rectStep = new RectPaintingStep;
                    rectStep->setPen(currentPen);
                    rectStep->setFirstPoint(e->pos());
                    paintingHistory.doStep(rectStep);
                    break;
                }
                case PaintingMode::TEXT: {
                    QDBG<<"TEXT: "<<g_count;
                    g_count++;
                    QString str;
                    if(g_count == 1) //first click
                    {
                        textEdit->setGeometry(QRect(e->pos().x(), e->pos().y(), 30, 30));
                        textEdit->setVisible(true);
                        textEdit->setStyleSheet("background-color: rgb(255, 255, 255, 60);");
                        textEdit->setStyleSheet("border: 1px solid red;");
                        textEdit->setFocus();
                        g_x = e->pos().x();
                        g_y = e->pos().y();
                    }
                    else if(g_count == 2) //second click
                    {
                        str = textEdit->toPlainText();
                        QDBG<<str.toStdString().data();
                        TextPaintingStep *textStep = new TextPaintingStep(str);
                        textStep->setPen(currentPen);
                        textStep->setFirstPoint(g_x, g_y);
                        paintingHistory.doStep(textStep);
                        clearTextEditStatus();
                    }
                    else
                    {
                        QDBG<<"other";
                    }
                    break;
                }
                case PaintingMode::ARROW: {
                    ArrowPaintingStep *arrowStep = new ArrowPaintingStep;
                    arrowStep->setPen(currentPen);
                    arrowStep->setFirstPoint(e->pos());
                    paintingHistory.doStep(arrowStep);
                    break;
                }
                case PaintingMode::MOSAIC:
                    MosaicPaintingStep *mosaicStep = new MosaicPaintingStep(&actualCanvas);
                    mosaicStep->setFirstPoint(e->pos());
                    mosaicStep->setBlockSize(mosaicSize);
                    paintingHistory.doStep(mosaicStep);
                    break;
                }
            } else {
                canvasModeBackup = getCanvasMode();
                setCanvasMode(CanvasMode::INVALID);
            }
        }
    } else if (e->button() == Qt::RightButton) {
        if (getCanvasMode() == CanvasMode::IDLE) {
            myDispose();
            return;
        } else if (getCanvasMode() == CanvasMode::SELECTED) {
            setCanvasMode(CanvasMode::IDLE);
            this->update();
        } else if (getCanvasMode() == CanvasMode::PAINTING) {
            if (!paintingStarted) {         // painting will not be interupted when performing painting
                setCanvasMode(CanvasMode::IDLE);
                this->update();
                clearTextEditStatus();
            }
        }
    }
}

void FullScreenImageEditor::mouseMoveEvent(QMouseEvent *e)
{
    if (getCanvasMode() == CanvasMode::SELECTING) {
        selectArea(e->x(), e->y());
        this->update();
    } else if (getCanvasMode() == CanvasMode::MOVING) {
        moveSelectedAreaLimitInScreen(e->x(), e->y());
        this->update();
    } else if (getCanvasMode() == CanvasMode::SELECTED) {
        changeCursorIfNessesary(e->x(), e->y());
    } else if (getCanvasMode() == CanvasMode::RESIZING) {
        resizingSelectedArea(e->x(), e->y());
        this->update();
    } else if (getCanvasMode() == CanvasMode::PAINTING && paintingStarted) {
        updateDrawing(e);
        this->update();
    }
//    else if (getCanvasMode() == CanvasMode::INVALID) {
//        // do nothing
//    }
}

void FullScreenImageEditor::updateDrawing(QMouseEvent *e)
{
    switch (paintingMode) {
    case PaintingMode::PEN:
        dynamic_cast<PenPaintingStep *>((paintingHistory.peekStep()))->addPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    case PaintingMode::OVAL:
        dynamic_cast<OvalPaintingStep *>((paintingHistory.peekStep()))->setSecondPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    case PaintingMode::RECT:
        dynamic_cast<RectPaintingStep *>((paintingHistory.peekStep()))->setSecondPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    case PaintingMode::TEXT:
//        dynamic_cast<TextPaintingStep *>((paintingHistory.peekStep()))->setSecondPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    case PaintingMode::ARROW:
        dynamic_cast<ArrowPaintingStep *>((paintingHistory.peekStep()))->setSecondPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    case PaintingMode::MOSAIC:
        dynamic_cast<MosaicPaintingStep *>((paintingHistory.peekStep()))->setSecondPoint(limitPointInSelectedArea(e->x(), e->y()));
        break;
    }
}

QPoint FullScreenImageEditor::limitPointInSelectedArea(int x, int y)
{
    if (x < selectedArea.left()) {
        x = selectedArea.left();
    } else if (x > selectedArea.right()) {
        x = selectedArea.right();
    }

    if (y < selectedArea.top()) {
        y = selectedArea.top();
    } else if (y > selectedArea.bottom()) {
        y = selectedArea.bottom();
    }
    return QPoint(x, y);
}

void FullScreenImageEditor::resizingSelectedArea(int mouseX, int mouseY) {
    switch (mousePosition) {
    case MousePosition::NorthWest:
        selectedArea.setTopLeft(
                    QPoint(mouseX < selectedArea.right() ? mouseX : selectedArea.right(),
                           mouseY < selectedArea.bottom() ? mouseY : selectedArea.bottom()));
        break;
    case MousePosition::NorthEast:
        selectedArea.setTopRight(
                    QPoint(mouseX > selectedArea.left() ? mouseX : selectedArea.left(),
                           mouseY < selectedArea.bottom() ? mouseY : selectedArea.bottom()));
        break;
    case MousePosition::SouthEast:
        selectedArea.setBottomRight(
                    QPoint(mouseX > selectedArea.left() ? mouseX : selectedArea.left(),
                           mouseY > selectedArea.top() ? mouseY : selectedArea.top()));
        break;
    case MousePosition::SouthWest:
        selectedArea.setBottomLeft(
                    QPoint(mouseX < selectedArea.right() ? mouseX : selectedArea.right(),
                           mouseY > selectedArea.top() ? mouseY : selectedArea.top()));
        break;
    case MousePosition::North:
        selectedArea.setTop(mouseY < selectedArea.bottom() ? mouseY : selectedArea.bottom());
        break;
    case MousePosition::East:
        selectedArea.setRight(mouseX > selectedArea.left() ? mouseX : selectedArea.left());
        break;
    case MousePosition::South:
        selectedArea.setBottom(mouseY > selectedArea.top() ? mouseY : selectedArea.top());
        break;
    case MousePosition::West:
        selectedArea.setLeft(mouseX < selectedArea.right() ? mouseX : selectedArea.right());
        break;
    default:
        QDBG << "Imposible, mouse is not on the boarder of Selected Area.";
    }
}

void FullScreenImageEditor::changeCursorIfNessesary(int mouseX, int mouseY)
{
    if (qAbs(mouseX-selectedArea.left()) < 2) {
        if (qAbs(mouseY - selectedArea.top()) < 2) {
            setCursor(Qt::SizeFDiagCursor);
            mousePosition = MousePosition::NorthWest;
        } else if (qAbs(mouseY - selectedArea.bottom()) < 2) {
            setCursor(Qt::SizeBDiagCursor);
            mousePosition = MousePosition::SouthWest;
        } else if (mouseY > selectedArea.top() && mouseY < selectedArea.bottom()) {
            setCursor(Qt::SizeHorCursor);
            mousePosition = MousePosition::West;
        } else {
            setCursor(Qt::ArrowCursor);
            mousePosition = MousePosition::Other;
        }
    } else if (qAbs(mouseX-selectedArea.right()) < 2) {
        if (qAbs(mouseY - selectedArea.top()) < 2) {
            setCursor(Qt::SizeBDiagCursor);
            mousePosition = MousePosition::NorthEast;
        } else if (qAbs(mouseY - selectedArea.bottom()) < 2) {
            setCursor(Qt::SizeFDiagCursor);
            mousePosition = MousePosition::SouthEast;
        } else if (mouseY > selectedArea.top() && mouseY < selectedArea.bottom()) {
            setCursor(Qt::SizeHorCursor);
            mousePosition = MousePosition::East;
        } else {
            setCursor(Qt::ArrowCursor);
            mousePosition = MousePosition::Other;
        }
    } else if (mouseX > selectedArea.left() && mouseX < selectedArea.right()) {
        if (qAbs(mouseY - selectedArea.top()) < 2) {
            setCursor(Qt::SizeVerCursor);
            mousePosition = MousePosition::North;
        } else if (qAbs(mouseY - selectedArea.bottom()) < 2) {
            setCursor(Qt::SizeVerCursor);
            mousePosition = MousePosition::South;
        } else if (mouseY > selectedArea.top() && mouseY < selectedArea.bottom()) {
            setCursor(Qt::ArrowCursor);
            mousePosition = MousePosition::Other;
        } else {
            setCursor(Qt::ArrowCursor);
            mousePosition = MousePosition::Other;
        }
    } else {
        setCursor(Qt::ArrowCursor);
        mousePosition = MousePosition::Other;
    }
}

void FullScreenImageEditor::moveSelectedAreaLimitInScreen(int mouseX, int mouseY)
{
    int offX = mouseX - mouseDownX;
    int offY = mouseY - mouseDownY;
    int toX = offX + originalSelectLeft;
    int toY = offY + originalSelectTop;
    if (toX < 0)
        toX = 0;
    else if (toX + selectedArea.width() > screenImage.width())
        toX = screenImage.width() - selectedArea.width() - 1;
    if (toY < 0)
        toY = 0;
    else if (toY + selectedArea.height() > screenImage.height())
        toY = screenImage.height() - selectedArea.height() - 1;
    selectedArea.moveTo(toX, toY);
}

void FullScreenImageEditor::selectArea(int mouseX, int mouseY)
{
    int x1, x2, y1, y2;
    if (mouseX > mouseDownX) {
        x1 = mouseDownX;
        x2 = mouseX;
    } else {
        x2 = mouseDownX;
        x1 = mouseX;
    }
    if (mouseY > mouseDownY) {
        y1 = mouseDownY;
        y2 = mouseY;
    } else {
        y2 = mouseDownY;
        y1 = mouseY;
    }

    selectedArea.setTop(y1);
    selectedArea.setLeft(x1);
    selectedArea.setBottom(y2);
    selectedArea.setRight(x2);
}


void FullScreenImageEditor::mouseReleaseEvent(QMouseEvent *e)
{
    if (getCanvasMode() == CanvasMode::INVALID) {
        setCanvasMode(canvasModeBackup);
        return;
    }
    if (e->button() == Qt::LeftButton) {
        if (getCanvasMode() == CanvasMode::SELECTING) {
            selectArea(e->x(), e->y());
            setCanvasMode(CanvasMode::SELECTED);
            this->update();
        } else if (getCanvasMode() == CanvasMode::MOVING) {
            moveSelectedAreaLimitInScreen(e->x(), e->y());
            setCanvasMode(CanvasMode::SELECTED);
            this->update();
        } else if (getCanvasMode() == CanvasMode::RESIZING) {
            resizingSelectedArea(e->x(), e->y());
            setCanvasMode(CanvasMode::SELECTED);
            this->update();
        } else if (getCanvasMode() == CanvasMode::PAINTING && paintingStarted) {
            // && paintingStarted is used to avoid some situations that trigger mouseRelease without mousePress
            updateDrawing(e);
            if (paintingMode == PaintingMode::MOSAIC) {
                dynamic_cast<MosaicPaintingStep *>(paintingHistory.peekStep())->endSelect();
            }
            paintingStarted = false;

            this->update();
        }
    }
}

void FullScreenImageEditor::mouseDoubleClickEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        on_okButton_clicked();
    }
}

void FullScreenImageEditor::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape) {
        myDispose();
    }
}

bool FullScreenImageEditor::isInSelectedArea(int x, int y)
{
    return x > selectedArea.left() && x < selectedArea.right() && y > selectedArea.top() && y < selectedArea.bottom();
}

void FullScreenImageEditor::myDispose()
{
    int ret;
    ret = this->close();
    QDBG<<"close ok: "<<ret;
}

void FullScreenImageEditor::setCanvasMode(CanvasMode m)
{
    switch (m) {
    case CanvasMode::IDLE:
        selectedArea.setTop(-10000);
        selectedArea.setLeft(0-10000);
        selectedArea.setBottom(0);
        selectedArea.setRight(0);
        paintingHistory.clear();
        break;
    case CanvasMode::PAINTING:
        paintingStarted = false;
        break;
    case CanvasMode::INVALID:
    case CanvasMode::SELECTING:
    case CanvasMode::SELECTED:
    case CanvasMode::RESIZING:
    case CanvasMode::MOVING:
        break;
    }
    _canvasMode = m;
//    ui->cmdPanel->setVisible(ui->cmdPanel->isVisible() == false);
}

CanvasMode FullScreenImageEditor::getCanvasMode()
{
    return _canvasMode;
}

void FullScreenImageEditor::on_okButton_clicked()
{
    QPainter painter(&screenImage);
    paintingHistory.paint(&painter);
    /*
     * for retina screen devicePixelRatio is 2.0
     * non-retina: (50,50) -> (150, 150)  and size: 100 x 100
     * retina:     (100, 100) -> (300, 300) and size: 200 x 200
     */
    QImage img;
    QDBG<<g_dpr;
    if(g_dpr == 2.0)
    {
        QRect newRect = QRect(selectedArea.left()*2, selectedArea.top()*2,
                              selectedArea.width()*2, selectedArea.height()*2);
        img = screenImage.copy(newRect);
    }
    else
    {
        img = screenImage.copy(selectedArea);
    }

    QApplication::clipboard()->clear();

    QApplication::clipboard()->setImage(img);
    QString defaultName = "Screenshot" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".png";
    g_ImagePath = g_ImageDir.append(defaultName);
    img.save(g_ImagePath, "png");
    myDispose();
}

void FullScreenImageEditor::on_saveButton_clicked()
{
    QString defaultName = "Screenshot" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".png";
    QString savePath = QFileDialog::getSaveFileName(0, "Save Image", "./" + defaultName);

    QDBG<<savePath;

    if(!savePath.isEmpty())
    {
        QPainter painter(&screenImage);
        paintingHistory.paint(&painter);
        /*
             * for retina screen devicePixelRatio is 2.0
             * non-retina: (50,50) -> (150, 150)  and size: 100 x 100
             * retina:     (100, 100) -> (300, 300) and size: 200 x 200
             */
        QImage img;
        QDBG<<g_dpr;
        if(g_dpr == 2.0)
        {
            QRect newRect = QRect(selectedArea.left()*2, selectedArea.top()*2,
                                  selectedArea.width()*2, selectedArea.height()*2);
            img = screenImage.copy(newRect);
        }
        else
        {
            img = screenImage.copy(selectedArea);
        }
        img.save(savePath, "png");
        g_ImagePath = savePath;
    }
    myDispose();
}

void FullScreenImageEditor::on_penButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::PEN;
}

void FullScreenImageEditor::on_undoButton_clicked()
{
    if (!paintingHistory.undoStep()) {
        setCanvasMode(CanvasMode::IDLE);
    }
    this->update();
}

void FullScreenImageEditor::on_ovalButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::OVAL;
}

void FullScreenImageEditor::on_rectButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::RECT;
}

void FullScreenImageEditor::on_textButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::TEXT;
}

void FullScreenImageEditor::on_arrowButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::ARROW;
}


void FullScreenImageEditor::on_color_picked()
{
    QWidget *widget = dynamic_cast<QWidget *>(sender());
    QString style = widget->styleSheet();
    ui->colorButton->setStyleSheet(style);
    currentPen.setColor(widget->palette().background().color());
}

void FullScreenImageEditor::on_colorButton_clicked()
{
    ui->colorPanel->setVisible(!ui->colorPanel->isVisible());
}

void FullScreenImageEditor::on_mosaicButton_clicked()
{
    setCanvasMode(CanvasMode::PAINTING);
    paintingMode = PaintingMode::MOSAIC;
}

void FullScreenImageEditor::on_sizeButtonLarge_clicked()
{
    currentPen.setWidth(PenWidth::PEN_LARGE);
    mosaicSize = MosaicSize::MOSAIC_LARGE;
}

void FullScreenImageEditor::on_sizeButtonNormal_clicked()
{
    currentPen.setWidth(PenWidth::PEN_NORMAL);
    mosaicSize = MosaicSize::MOSAIC_NORMAL;
}

void FullScreenImageEditor::on_sizeButtonSmall_clicked()
{
    currentPen.setWidth(PenWidth::PEN_SMALL);
    mosaicSize = MosaicSize::MOSAIC_SMALL;
}

void FullScreenImageEditor::adjustTextEditSize()
{
    int len = textEdit->toPlainText().length();
    QDBG<<textEdit->width()<<", "<<textEdit->height();
    //QDBG<<"g_len: "<<g_len<<", len: "<<len;

    int nLine = textEdit->document()->lineCount();
    QDBG<<nLine<<", "<<textEdit->document()->textWidth();

    if(len > 1)
    {
        textEdit->resize(16+8*len, 21+9*nLine);
        //g_len = len;
    }

//    QDBG<<textEdit->document()->lineCount();
//    int pos = textEdit->textCursor().position();
//    QChar ch = textEdit->document()->characterAt(pos-1);

//    QDBG<<pos<<": "<<ch;
//    if(nLine > 1)
//    {
//        textEdit->resize(textEdit->width(), 30+9*nLine);
//    }
}

void FullScreenImageEditor::clearTextEditStatus()
{
    textEdit->setVisible(false);
    textEdit->clearFocus();
    textEdit->clear();
    g_x = -100;
    g_y = -100;
    g_count = 0;
    //g_len = 0;
}
