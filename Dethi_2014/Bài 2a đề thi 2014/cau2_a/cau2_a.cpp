// cau2_a.cppclass EyedFace : public Face {
private:
    int eyes;

public:
    EyedFace(string sh, int eye) : Face(sh), eyes(eye) {
    }

    void show() {
        cout << "Shape: " << getShape() << ", Eyes: " << eyes << endl;
    }

    EyedFace* clone() {
        return new EyedFace(getShape(), eyes);
    }
};