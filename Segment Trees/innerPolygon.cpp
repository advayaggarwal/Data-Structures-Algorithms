#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    double x;
    double y;

    Point()
    {
        this->x = -1;
        this->y = -1;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    void getPoint()
    {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }

    bool hasSameX(Point p)
    {
        return this->x == p.x;
    }

    bool hasSameY(Point p)
    {
        return this->y == p.y;
    }

    // Computes the Euclidean distance between two points.
    double distance(Point p)
    {
        double dx = this->x - p.x;
        double dy = this->y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Line {
public:
    Point p1;
    Point p2;
    double slope;
    double intercept;

    Line()
    {
        p1 = Point();
        p2 = Point();
        slope = INT_MAX;
        intercept = INT_MAX;
    }

    Line(Point p1, Point p2)
    {
        this->p1 = p1;
        this->p2 = p2;
        slope = getSlope();
        intercept = getIntercept();
    }

    double getSlope()
    {
        if (this->p1.hasSameX(p2)) return INT_MAX;
        if (this->p1.hasSameY(p2))   return 0;
        return (this->p1.y - this->p2.y) / (this->p1.x - this->p2.x);
    }

    double getIntercept()
    {
        if (this->slope == INT_MAX)    intercept = INT_MAX;
        return (this->p1.y - slope * (this->p1.x));
    }

    pair<double, double> getNewIntercept(double d)
    {
        if (this->slope == INT_MAX)  return {INT_MAX, INT_MAX};
        double c1 = this->intercept + d * sqrt(1 + (this->slope * this->slope));
        double c2 = this->intercept - d * sqrt(1 + (this->slope * this->slope));
        return {c1, c2};
    }

    Point getIntersection(double m, double c1, double c2)
    {
        double x = this->p1.x;
        if (this->slope != INT_MAX)  x = (c2 - c1) / (this->slope - m);
        double y = this->p1.y;
        if (this->slope != INT_MAX)  y = (this->slope * c2 - m * c1) / (this->slope - m);
        return Point(x, y);
    }
};


// Computes the normal vector of a line segment.
Point normal(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double length = p1.distance(p2);
    return { -dy / length, dx / length };
}

// Computes the inner polygon with parallel sides.
vector<Point> inner_polygon(vector<Point> polygon, double d) {
    int n = polygon.size();
    vector<Point> inner(n);
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        Point nvec = normal(polygon[i], polygon[j]);
        Point offset = { nvec.x * d, nvec.y * d };
        inner[i] = { polygon[i].x + offset.x, polygon[i].y + offset.y };
    }
    return inner;
}


int main()
{
    int n;
    cin >> n;
    vector<Point> polygon;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        Point p(x, y);
        polygon.push_back(p);
    }

    double d;
    cin >> d;

    Line l1(polygon[2], polygon[3]);
    Line l2(polygon[3], polygon[0]);

    double slope1 = l1.slope;
    double slope2 = l2.slope;

    double intercept1 = l1.intercept;
    double intercept2 = l2.intercept;

    pair<double, double> newI1 = l1.getNewIntercept(d);
    pair<double, double> newI2 = l2.getNewIntercept(d);


    Point n1 = l1.getIntersection(slope2, newI1.first, newI2.first);
    Point n2 = l1.getIntersection(slope2, newI1.first, newI2.second);
    Point n3 = l1.getIntersection(slope2, newI1.second, newI2.first);
    Point n4 = l1.getIntersection(slope2, newI1.second, newI2.second);


    Point n5 = l2.getIntersection(slope1, newI2.first, newI1.first);
    Point n6 = l2.getIntersection(slope1, newI2.first, newI1.second);
    Point n7 = l2.getIntersection(slope1, newI2.second, newI1.first);
    Point n8 = l2.getIntersection(slope1, newI2.second, newI1.second);

    n1.getPoint();
    n2.getPoint();
    n3.getPoint();
    n4.getPoint();
    n5.getPoint();
    n6.getPoint();
    n7.getPoint();
    n8.getPoint();

    return 0;
}