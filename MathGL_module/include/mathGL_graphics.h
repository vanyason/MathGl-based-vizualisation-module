//
// Created by ivan on 5/10/18.
//

#ifndef MATHGL_MODULE_MGLGRAPHICS_H
#define MATHGL_MODULE_MGLGRAPHICS_H
#include <mgl2/qt.h>
#include "mathGL_graphics_object.h"
#include "mathGL_graphics_frame_properties.h"
#include <list>
#include <string>

/**
 * Visualisation module based on MathGl library.
 * This class is a wrapper for the most common MathGl functions.
 *
 * All the functions can be divided into 3 types:
 * 1) adding objects : funcs to create frames and add graphics to the result image
 * 2) visualisation : func to output image using QT windows or save to file
 * 3) properties : setting axis, ranges, origins, etc...
 *
 * HOWTO use this class:
 * 1)   Create an object that is going to be visualised (instance of MathGLGraphicsObject)
 * 2)   Set properties using properties()->setters
 * 3)   Add an object to the graph using the "link" function.
 * 4)   Plot or save image using appropriate methods
 */
class MathGLGraphics : public mglDraw
{
public:
    MathGLGraphics();
    ~MathGLGraphics();

    //  Methods to link objects to graphics
    /**
     * Creates new blank frame. All the objects added before stays on the previous frame.
     * All the graph properties resets
     */
    void newFrame();
    /**
     * @param obj pointer to an MathGLGraphicsObject object.
     *
     * Links graphic to a current frame.
     * MathGLGraphics class doesn`t track the memory allocation and doesn`t provide
     * getters to access data.
     *
     * So DO NOT allocate memory via argument add(new(...)) because of the loss of a pointer.
     */
    void link(const MathGLGraphicsObject *obj);

    //  Methods to visualize graphics
    /**
     * @param windowName Window title
     *
     * Creates QT window with data;
     */
    int plotQT(const char *windowName);
    /**
     * Save image to a bmp file named "'frame_count'_frame.bmp"
     */
    void saveBMP();
    /**
     * @return current frame`s properites
     *
     * Getter of the last element in the properties list
     */
    MathGLGraphicsFrameParametres *parametres();


private:
    int Draw(mglGraph *gr) override;

    /**
     *  List of lists,  where
     *  outer list for frames,
     *  inner list for graphic objects
     */
    std::list<std::list<const MathGLGraphicsObject *>> objectsList;
    /**
     *  List of frames parameters.
     */
    std::list<MathGLGraphicsFrameParametres *> frameParameters;
    /**
     *  Save to bmp;
     */
    bool saveImageBMP = false;
};

#endif //MATHGL_MODULE_MGLGRAPHICS_H
