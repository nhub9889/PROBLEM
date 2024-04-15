//http://www.upcoder.xyz/'index.php/dcd053f3400582517a0f1e7f467f21b9c735f2aa0e9fabddb5123e79ca518208/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'2:9~'FE369h49MA6hO7_K5:h:6F6e6e.a9CD6'WOY!SSgTt8/a0acc18b495994030f84cff5a5691504333d831ce902f5954fc79836516406e2
#include <iostream>
#include <string>
using namespace std;

class Robot
{
    protected:
    string Name;
    string UserName;
    int EnergyLevel;
    int LocationX;
    int LocationY;
    public:
    
    Robot()
    {
        Name = "Robot";
        UserName = "NoName";
        EnergyLevel = 100;
        LocationX  =0;
        LocationY = 0;
    }
    Robot(string name, string username, int x ,int y)
    {
        EnergyLevel =100;
        Name = name;
        UserName = username;
        LocationX =x;
        LocationY =y;
    }
    Robot(string name, string username, int e, int x ,int y)
    {
        EnergyLevel =e;
        Name = name;
        UserName = username;
        LocationX =x;
        LocationY =y;
    }
    Robot(string name, string username)
    {
        EnergyLevel =100;
        LocationX = LocationY = 0;
        Name =name;
        UserName =username;
    }

    Robot(const Robot& a)
    {
        *this = a;
    }
    Robot (int e)
    {
        EnergyLevel =e;
}
    void Charge()
    {
        EnergyLevel+=10;
    }
    virtual bool Move(int direction)
    {
        if (EnergyLevel<0||(direction!=1&&direction!=2&&direction!=0&&direction!=3))
        return false;
        else
        {
            switch (direction)
            {
                case 0: LocationX--;EnergyLevel-=5;break;
            case 1: LocationX++;EnergyLevel-=5;break;
            case 2: LocationY++;EnergyLevel-=5;break;
            case 3: LocationY--;EnergyLevel-=5;break;
            }
            return true;
            
        }
    }
    void Display()
    {
        cout<<"{"<<Name<<"}"<<":"<<"{"<<UserName<<"}"<<endl<<"("<<LocationX<<","<<LocationY<<")"<<endl<<EnergyLevel<<endl;
    }
    ~Robot(){};
};

class AdaptiveRobot : public Robot
{
    int level;
    public:
    bool Move (int direction) override
    { 
        if (EnergyLevel>50&&level==0)
            {
                EnergyLevel -=12;
                level =3;
            }
        else if (EnergyLevel>20&&level==0)
        {
            EnergyLevel =9;
            level = 2;
        }
        else if (level ==0)
        level =1;
        level --;
        if (EnergyLevel<0||(direction!=1&&direction!=2&&direction!=0&&direction!=3))
        return false;
        else
        {
           
            switch (direction)
            {
                case 0: LocationX--;break;
            case 1: LocationX++;break;
            case 2: LocationY++;break;
            case 3: LocationY--;break;
            }
            return true;
            
        }
      
       return true;
    }
    AdaptiveRobot():Robot("AdaptiveRobot","NoName"){}
     AdaptiveRobot(string name, string username, int e, int x ,int y)
    {
        level = 0;
        EnergyLevel =e;
        Name = name;
        UserName = username;
        LocationX =x;
        LocationY =y;
    }
    ~AdaptiveRobot(){};
};
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    {
        while (n--)
        {
            string name, user;
            int e , x ,y,m;
            
            getline(cin,name);
            getline(cin,user);
           
            cin>>e>>x>>y;
           
            
            AdaptiveRobot b;
            if (name[0]=='A')
            {
                AdaptiveRobot *b = new AdaptiveRobot(name,user,e,x,y);
                cin>>m;
            do
            {
                if (m!=4)
                b->Move(m);
                else b->Charge();
                cin>>m;
                
            } while (m!=-1);
            
            b->Display();
            delete b;
            cin.ignore();
            }
            else
            {
                Robot *a = new Robot(name,user,e,x,y);
                cin>>m;
            do
            {
                if (m!=4)
                a->Move(m);
                else a->Charge();
                cin>>m;
                
            } while (m!=-1);
            
            a->Display();
            delete a;
            cin.ignore();
            }
            

        }
    }
}