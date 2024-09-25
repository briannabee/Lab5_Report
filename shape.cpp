#include <iostream>

using namespace std;

class Shape
{
private:
    double x;  //instance data members --> when an object is created, the object will have its own RAM addresses / memory.
    //all member functions can access, including static.
    double y;  //instance data members
    static int num_objects;  //static data members exists in the global/static variable section of the virtual address space.
    //only static member functions can access.
public:
    Shape(); //instance member function --> this keyword
    Shape(double, double);  //instance member function 
    ~Shape();  //instance member function
    double get_x();
    double get_y();
    void set_coord(double,double);
    static int get_num_objects(); //static member function, count the number of objects that have been created
};

int Shape::num_objects = 0; //outside any member function with a scope and data type

Shape::Shape() //purpose: initializing x,y
{
    cout << "Shape(): " << this << endl;
    //this: the address of the object that has just been created.
    //x and y in the body in the Shape(): whose x and y? this
    x = 0;
    y = 0;
    //num_objects = 0; reset the static member EVERY time when an object is created
    num_objects++;
}

Shape::Shape(double x, double y)
{
    cout << "Shape(double,double): " << this << endl;
    this->x = x;
    this->y = y;
    num_objects++;
}

Shape::~Shape() //instance member functions
{
    cout << "~Shape(): " << this << endl;
    num_objects--; //acess the static data member
    cout << "Number of Objects: " << num_objects << endl;
}

double Shape::get_x()
{
    return x;
}

double Shape::get_y()
{
    return y;
}

void Shape::set_coord(double x,double y)
{
    this->x = x;
    this->y = y;
}

int Shape::get_num_objects()
{
    cout << "Inside get_num_objects()" << endl;
    //cout << this->x << makes no sense
    return num_objects;
}

int main()
{
    cout << "Number of Objects: " << Shape::get_num_objects() << endl;
    //create an object of Shape
    Shape s; //implicitly call Shape()
    //call only public member functions because main() is outside the class
    //object.member_funct(); the dot is called the access operator
     cout << "Number of Objects: " << Shape::get_num_objects() << endl;
    cout << "(x,y) = " << s.get_x() << "," << s.get_y() << endl;
    s.set_coord(10,20);
    cout << "(x,y) = " << s.get_x() << "," << s.get_y() << endl;
    
    Shape* p = new Shape(30,50); //arg-construct
     cout << "Number of Objects: " << Shape::get_num_objects() << endl;
    cout << "(x,y) = " << p->get_x() << "," << p->get_y() << endl;
    delete p;
    return 0;
}

