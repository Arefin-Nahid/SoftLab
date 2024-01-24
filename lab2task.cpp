#include<bits/stdc++.h>
using namespace std;

class shape{
public:
 virtual void draw()=0;
};

class rectangle : public shape{
    public:
    void draw()
    {
        cout<<"Inside Rectangle"<<endl;
    }
};



class shapefactory{
    private:
        static shapefactory *ins;
        shapefactory(){}

    public:
    static shapefactory* getinstance()
    {
        if(ins==nullptr)
        {
            ins=new shapefactory();
        }
        return ins;
    }
    shape* getshape(string shapetype)
    {

      if(shapetype=="rectangle")
      {
          return new rectangle();
      }
      else return nullptr;
    }
};
shapefactory* shapefactory::ins=nullptr;

int main(){

    shapefactory* shapefactory1 = shapefactory::getinstance();
    shapefactory* shapefactory2 = shapefactory::getinstance();
    cout<<shapefactory1<<endl;
    cout<<shapefactory2<<endl;
    shape *shape1 = shapefactory1->getshape("rectangle");
    shape1->draw();
}



