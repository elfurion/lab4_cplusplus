#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
//I've deleted class with position, because in this project it was no necessary


class Figure3D
{
    public:
        virtual int getdata()//get data, such as sides or radius
        {
            return 0;
        }
        virtual double square()
        {
            return 0;
        }
        virtual double extend()
        {
            return 0;
        }
    
};



class Spheric : public Figure3D
{
    public:
        int radius,height;

};



class Polyhedra : public Figure3D
{
    
    public:
        int a,b,c;//sides of figure

};


class Cone : public Spheric
{
    public:
        int getdata()
        {
            cout << "EnterRadius: ";
            cin >> radius;
            cout << "EnterHeight: ";
            cin >> height;
            return 0;
        }
        double square()
        {
            return 3.14*radius*radius;
        }
        double extend()
        {
            return 3.14/3*radius*radius*height;
        }
};
class Elipsoid : public Spheric
    {
        public:
            int getdata()
            {
                cout << "Enter axle (radius), a: ";
                cin >> a;
                cout << "Enter axle (radius), b: ";
                cin >> b;
                cout << "Enter axle (radius), c: ";
                cin >> c;
                return 0;
            }
            double square()
            {
                return 2*3.14*a*(a+pow(b,2)/pow((pow(a,2)-pow(b,2)),1/2)*log((a+pow((pow(a,2)- pow(b,2)),1/2))/b));
            }
            double extend()
            {
                return 4/3*3.14*a*b*c;
            }

    };
    



class Sphere : public spheric
{

    public:
        int getdata()
        {
            cout << "Enter radius: ";
            cin >> radius;
            return 0;
        }
        double square()
        {
            return 4*3.14*radius*radius;
        }
    
    
        double extend()
        {
            return 4 / 3 * 3.14*radius*radius*radius;
        }
};

class Cylinder : public Spheric
{

    public:
        int getdata()
            {
                cout << "Enter Radius: ";
                cin >> radius;
                cout << "Enter Height: ";
                cin >> height;
                return 0;
            }
            double square()
            {
                return 3.14*radius*radius;
            }
            double extend()
            {
                return 3.14*radius*radius*height;
            }
};


class Parallelepiped : public Polyhedra
{
    public:
        int getdata()
            {
                cout << "Enter Side a: ";
                cin >> a;
                cout << "Enter Side b: ";
                cin >> b;
                cout << "Enter Side c: ";
                cin >> c;
                return 0;
            }
        double square()
            {
                return  2*(a*b+b*c+a*c);
            }
        double extend()
            {
                return a*b*c;
            }
};




class Cube : public Polyhedra
{

    public:
        int getdata()
            {
                cout << "Enter Side : ";
                cin >> a;
                return 0;
            }
            double square()
            {
                return  6*a*a;
            }
            double extend()
            {
                return a*a*a;
            }

    };


int main()
{

    cout << "EnterFigure:" << endl;
    cout << "1. Cone" << endl;
    cout << "2. Parallelepiped" << endl;
    cout << "3. Cube" << endl;
    cout << "4. Sphera" << endl;
    cout << "5. Elipsoid" << endl;
    cout << "6. Cylinder" << endl;
    int choise;
    cin >> choise;
    
    switch (choise)
    {
        case '1':
        {
            Spheric *ptr1 = new Cone;
            ptr1->getdata();
            cout << "Square = " << (ptr1->square()) << endl;
            cout << "Extend = " <<(ptr1->extend()) << endl;
            break;
        }
        case '2':
        {
            Polyhedra *ptr2 = new Parallelepiped;
            ptr2->getdata();
            cout << "Square = " << (ptr2->square()) << endl;
            cout << "Extend = " << (ptr2->extend()) << endl;
            break;
        }
        case '3':
        {
            Polyhedra *ptr3 = new Cube;
            ptr3->getdata();
            cout << "Square = " << (ptr3->square()) << endl;
            cout << "Extend = " << (ptr3->extend())<<endl;
            break;
        }
        case '4':
        {
            Spheric *ptr4 = new Sphere;
            ptr4->getdata();
            cout << "Square = " << (ptr4->square()) << endl;
            cout << "Extend = " << (ptr4->extend()) << endl;
            break;
        }
        case '5':
        {
            Spheric *ptr5 = new Elipsoid;
            ptr5->getdata();
            cout << "Square = " << (ptr5->square()) << endl;
            cout << "Extend = " <<(ptr5->extend()) << endl;
            break;
        }
        case '6':
        {
            Spheric *ptr6 = new Cylinder;
            ptr6->getdata();
            cout << "Square = " << (ptr6->square()) << endl;
            cout << "Extend = " << (ptr6->extend())<<endl;
            break;
        }
            
        default:
        cout << "Wrong" <<endl;
            
    return 0;
    }



}
