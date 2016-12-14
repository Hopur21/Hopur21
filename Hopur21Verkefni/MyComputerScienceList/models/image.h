#ifndef IMAGE_H
#define IMAGE_H
#include <QtWidgets>
#include <string>

class Image
{
public:
    Image();

    //Sets
    void setImageValues(QByteArray& pictureByteArray, std::string& name, int& pictureID);
    //Gets
    QByteArray getImageByteArray();
    std::string getName();
    int getID(){return _pictureID;}

private:
    QByteArray _pictureByteArray;
    std::string _pictureName;
    int _pictureID;
};

#endif // IMAGE_H
