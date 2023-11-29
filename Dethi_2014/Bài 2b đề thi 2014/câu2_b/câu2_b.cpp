#include <iostream>
#include <string>

using namespace std;

class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {}
};

class Face : public IFace {
private:
    string shape;

protected:
    string getShape();

public:
    Face(string sh) : shape(sh) {}

    virtual void show() {
        cout << "Shape: " << shape << endl;
    }

    IFace* clone() {
        return new Face(shape);
    }
};

class EyedFace : public Face {
private:
    int eyes;

public:
    EyedFace(string sh, int eye) : Face(sh), eyes(eye) {}

    void show() {
        cout << "Shape: " << getShape() << ", Eyes: " << eyes << endl;
    }

    IFace* clone() {
        return new EyedFace(getShape(), eyes);