#include <iostream>
#include <vector>

class Point {
public:
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }

private:
    double x;
    double y;
};

class Polyline {
public:
    int size() const {
        return points.size();
    }

    Point& operator[](int index) {
        return points[index];
    }

    const Point& operator[](int index) const {
        return points[index];
    }
    
    void operator+=(const Point& point) {
        points.push_back(point);
    }

private:
    std::vector<Point> points;
};

int main() {
    Polyline polyline;
    
    polyline += Point(1.0, 1.0);
    polyline += Point(2.0, 3.0);
    polyline += Point(4.0, 2.0);

    for (int i = 0; i < polyline.size(); ++i) {
        std::cout << "Point " << i + 1 << ": (" << polyline[i].getX() << ", " << polyline[i].getY() << ")" << std::endl;
    }

    return 0;
}