#ifndef IMAGE_H
#define IMAGE_H
#include <QtWidgets>
#include <string>

class Image
{
public:
    Image();

    //Sets
    void setImageByteArray(QByteArray& pictureByteArray);
    void setImageName(std::string& name);
    //Gets
    QByteArray getImageByteArray();
    std::string getName();

private:
    QByteArray _pictureByteArray;
    std::string _pictureName;
};

#endif // IMAGE_H
