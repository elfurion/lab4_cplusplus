#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Point3D
{
public:
	int x, y, z;

	Point3D() { }
	Point3D(int X, int Y, int Z):
		x(X), y(Y), z(Z)
	{ }
};



class Figure3D
{
public:
    Point3D position;
    
};



class Spheric : public Figure3D
{
public:
    int r,h;
    virtual int GetData()
    {
        return 0;
    }
    virtual double Square()
    {
        return 0;
    }
    virtual double Extend()
    {
        return 0;
    }
};



class Polyhedra : public Figure3D
{
    public:
        virtual double Square()
        {
            return 0;
        }

        virtual double Extend()
        {
            return 0;
        }
        virtual int GetSides()
        {
            return 0;
        }
};


class Cone : public Spheric
{
    private:
        int h;
    public:
    int GetData()
    {
        cout << "EnterRadius: ";
        cin >> r;
        cout << "EnterHeight: ";
        cin >> h;
        return 0;
    }
    double Square()
    {
        return 3.14*r*r;
    }
    double Extend()
    {
        return 3.14/3*r*r*h;
    }
};
    class Elipsoid : public Spheric
    {
    public:
        int GetData()
        {
            cout << "Enter axle (radius), a: ";
            cin >> a;
            cout << "Enter axle (radius), b: ";
            cin >> b;
            cout << "Enter axle (radius), c: ";
            cin >> c;
            return 0;
        }
        double Square()
        {
            return 2*3.14*a*(a+pow(b,2)/pow((pow(a,2)-pow(b,2)),1/2)*log((a+pow((pow(a,2)- pow(b,2)),1/2))/b));
        }
        double Extend()
        {
            return 4/3*3.14*a*b*c;
        }
    private:
        int a, b, c;
    };
    



class Sphere : public Spheric
{

    public:
    int GetData()
    {
        cout << "Enter radius: ";
        cin >> r;
        return 0;
    }
    double Square()
    {
        return 4*3.14*r*r;
    }
    
    
    double Extend()
    {
        return 4 / 3 * 3.14*r*r*r;
    }
};

class Cylinder : public Spheric
{
    private:
    int h;
    public:
	string name()
	{
        cout << "Enter Radius: ";
        cin >> r;
        cout << "Enter Height: ";
        cin >> h;
        return 0;
	}
    double Square()
    {
        return 3.14*r*r;
    }
    double Extend()
    {
        return 3.14*r*r*h;
    }
};


class Parallelepiped : public Polyhedra
{
    public:
    int GetSide()
    {
        cout << "Enter Side a: ";
        cin >> a;
        cout << "Enter Side b: ";
        cin >> b;
        cout << "Enter Side c: ";
        cin >> c;
        return 0;
    }
    double Square()
    {
        return  2*(a*b+b*c+a*c);
    }
    double Extend()
    {
        return a*b*c;
    }
    private:
    int a, b, c;

};




class Cube : public Polyhedra
{

    public:
        int GetData()
        {
            cout << "Enter Side : ";
            cin >> a;
            return 0;
        }
        double Square()
        {
            return  6*a*a;
        }
        double Extend()
        {
            return a*a*a;
        }
    private:
        int a;
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
    
    switch (choise){
    case '1':
    {
        Spheric *ptr1 = new Cone;
        ptr1->GetData();
        cout << "Square = " << (ptr1->Square()) << endl;
        cout << "Extend = " <<(ptr1->Extend()) << endl;
        break;
    }
    case '2':
    {
        Polyhedra *ptr2 = new Parallelepiped;
        ptr2->GetSides();
        cout << "Square = " << (ptr2->Square()) << endl;
        cout << "Extend = " << (ptr2->Extend()) << endl;
        break;
    }
    case '3':
    {
        Polyhedra *ptr3 = new Cube;
        ptr3->GetSides();
        cout << "Square = " << (ptr3->Square()) << endl;
        cout << "Extend = " << (ptr3->Extend())<<endl;
        break;
    }
    case '4':
    {
        Spheric *ptr4 = new Sphere;
        ptr4->GetData();
        cout << "Square = " << (ptr4->Square()) << endl;
        cout << "Extend = " << (ptr4->Extend()) << endl;
        break;
    }
    case '5':
    {
        Spheric *ptr5 = new Elipsoid;
        ptr5->GetData();
        cout << "Square = " << (ptr5->Square()) << endl;
        cout << "Extend = " <<(ptr5->Extend()) << endl;
        break;
    }
    case '6':
    {
        Spheric *ptr6 = new Cylinder;
        ptr6->GetData();
        cout << "Square = " << (ptr6->Square()) << endl;
        cout << "Extend = " << (ptr6->Extend())<<endl;
        break;
    }
        default:
        cout << "Worng" <<endl;
    return 0;
}



}
