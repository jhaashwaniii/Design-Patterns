#include<bits/stdc++.h>
using namespace std;

//Product Interface
class Notification
{
    public:
    virtual void notifyUser()=0;
    virtual ~Notification(){};
};

//Concrete Product
class EmailNotification: public Notification{
public:
    void notifyUser()
    {
        cout<<"Email notification sent";
    }
    ~EmailNotification()
    {
        cout<<"EmailNotification destroyed /n";
    }
};

class SMSNotification: public Notification{
    public:
    void notifyUser()
    {
        cout<<"SMS notification sent";
    }
    ~SMSNotification(){
        cout<<"SMSNotification destroyed /n";
    }
    
};

//Factory Interface
class NotificationFactory
{
  public:
  virtual Notification* createNotification()=0;
  ~NotificationFactory(){}
};


//concrete Factory
class SMSFactory: public NotificationFactory
{
    public:
    Notification* createNotification()
    {
        return new SMSNotification();
    }
    ~SMSFactory(){}
};

class EmailFactory: public NotificationFactory
{
    public:
    Notification* createNotification()
    {
        return new EmailNotification();
    }
    ~EmailFactory(){}
};

//concrete Factories
int main()
{
    NotificationFactory *nf;
    Notification* n;
    nf=new SMSFactory();
    n=nf->createNotification();
    n->notifyUser();
    
    delete n;
    delete nf;
    return 0;
    
}
