//////////////////////////////////////////////////////////////////////
//
//  University of Leeds
//  COMP 5812M Foundations of Modelling & Rendering
//  User Interface for Coursework
////////////////////////////////////////////////////////////////////////


#include <math.h>
#include <random>
#include <QDebug>
#include <QTimer>
// include the header file
#include "RaytraceRenderWidget.h"

#define N_THREADS 16
#define N_LOOPS 100
#define N_BOUNCES 5
#define TERMINATION_FACTOR 0.35f

// constructor
RaytraceRenderWidget::RaytraceRenderWidget
        (   
        // the geometric object to show
        std::vector<ThreeDModel>      *newTexturedObject,
        // the render parameters to use
        RenderParameters    *newRenderParameters,
        // parent widget in visual hierarchy
        QWidget             *parent
        )
    // the : indicates variable instantiation rather than arbitrary code
    // it is considered good style to use it where possible
    : 
    // start by calling inherited constructor with parent widget's pointer
    QOpenGLWidget(parent),
    // then store the pointers that were passed in
    texturedObjects(newTexturedObject),
    renderParameters(newRenderParameters)
    { // constructor
    } // constructor


// destructor
RaytraceRenderWidget::~RaytraceRenderWidget()
    { // destructor
    // empty (for now)
    // all of our pointers are to data owned by another class
    // so we have no responsibility for destruction
    // and OpenGL cleanup is taken care of by Qt
    } // destructor                                                                 

// mouse-handling
void RaytraceRenderWidget::mousePressEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mousePressEvent()
    // store the button for future reference
    int whichButton = int(event->button());
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;

    
    // and we want to force mouse buttons to allow shift-click to be the same as right-click
    unsigned int modifiers = event->modifiers();
    
    // shift-click (any) counts as right click
    if (modifiers & Qt::ShiftModifier)
        whichButton = Qt::RightButton;
    
    // send signal to the controller for detailed processing
    emit BeginScaledDrag(whichButton, x,y);
    } // RaytraceRenderWidget::mousePressEvent()
    
void RaytraceRenderWidget::mouseMoveEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mouseMoveEvent()
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;
    
    // send signal to the controller for detailed processing
    emit ContinueScaledDrag(x,y);
    } // RaytraceRenderWidget::mouseMoveEvent()
    
void RaytraceRenderWidget::mouseReleaseEvent(QMouseEvent *event)
    { // RaytraceRenderWidget::mouseReleaseEvent()
    // scale the event to the nominal unit sphere in the widget:
    // find the minimum of height & width   
    float size = (width() > height()) ? height() : width();
    // scale both coordinates from that
    float x = (2.0f * event->x() - size) / size;
    float y = (size - 2.0f * event->y() ) / size;
    
    // send signal to the controller for detailed processing
    emit EndScaledDrag(x,y);
    } // RaytraceRenderWidget::mouseReleaseEvent()

// called when OpenGL context is set up
void RaytraceRenderWidget::initializeGL()
    { // RaytraceRenderWidget::initializeGL()
	// this should remain empty
    } // RaytraceRenderWidget::initializeGL()

// called every time the widget is resized
void RaytraceRenderWidget::resizeGL(int w, int h)
    { // RaytraceRenderWidget::resizeGL()
    // resize the render image
    frameBuffer.Resize(w, h);
    } // RaytraceRenderWidget::resizeGL()
    
// called every time the widget needs painting
void RaytraceRenderWidget::paintGL()
    { // RaytraceRenderWidget::paintGL()
    // set background colour to white
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // and display the image
    glDrawPixels(frameBuffer.width, frameBuffer.height, GL_RGBA, GL_UNSIGNED_BYTE, frameBuffer.block);
    } // RaytraceRenderWidget::paintGL()

    void RaytraceRenderWidget::Raytrace()
    {
    qDebug() << "Raytrace() is called.";
    std::cout <<"One day I will raytrace." << std::endl;
    }
