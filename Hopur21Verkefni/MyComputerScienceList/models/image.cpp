#include "image.h"

Image::Image()
{

}
void Image::setImageValues(QByteArray& pictureByteArray, std::string& name, int& pictureID)
{
    _pictureByteArray = pictureByteArray;
    _pictureName = name;
    _pictureID = pictureID;
}
//Gets
QByteArray Image::getImageByteArray()
{
    return _pictureByteArray;
}
std::string Image::getName()
{
    return _pictureName;
}
