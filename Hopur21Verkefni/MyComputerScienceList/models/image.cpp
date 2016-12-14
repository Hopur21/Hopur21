#include "image.h"

Image::Image()
{

}
void Image::setImageByteArray(QByteArray& pictureByteArray)
{
    _pictureByteArray = pictureByteArray;
}
void Image::setImageName(std::string& name)
{
    _pictureName = name;
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
