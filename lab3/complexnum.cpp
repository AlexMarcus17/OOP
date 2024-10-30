#include <cmath>
enum DISPLAY_TYPE {
    RECTANGULAR_FORM,
    POLAR_FORM
};

class ComplexNumber {
private:
    double real;
    double imaginary;
    DISPLAY_TYPE displayType;
public:
    ComplexNumber(double real, double imaginary) {
        this->real = real;
        this->imaginary = imaginary;
        displayType = RECTANGULAR_FORM;
    }
    DISPLAY_TYPE getDisplayType() {
        return displayType;
    }
    void setDisplayType(DISPLAY_TYPE displayType1) {
        this->displayType = displayType1;
    }
    double getMagnitude() {
        return sqrt(
                (pow(this->real,2))+(pow(this->imaginary,2))
                );
    }

    double getPhase() {
        return asin(this->imaginary/sqrt(
                (pow(this->real,2))+(pow(this->imaginary,2))
        ));
    }


};