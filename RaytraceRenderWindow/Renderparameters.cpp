#include "RenderParameters.h"

void RenderParameters::findLights(std::vector<ThreeDModel> objects)
{
    for(ThreeDModel obj: objects)
    {
        //find objects that have a "light" material
        if(obj.material->isLight())
        {
            //if the object has exactly 2 triangles, its a rectangular area light.
            if(obj.faceVertices.size()== 2)
            {
                std::cout << "Exercise #3, replace this with the code!" << std::endl;
            }
            else
            {
                std::cout << "Exercise #3, replace this with the code!" << std::endl;
            }
        }
    }
}
