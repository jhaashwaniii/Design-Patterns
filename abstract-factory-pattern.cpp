#include<bits/stdc++.h>
using namespace std;

enum NotificationType {SMS, EMAIL};
enum LogType {SMS_LOG, EMAIL_LOG};
//Product Interface
class Notification
{
    public:
    virtual void notifyUser()=0;
    virtual ~Notification(){};
};

class Logger
{
    public:
    virtual void logMessage()=0;
    virtual ~Logger(){};
};

//Concrete Product
class EmailNotification: public Notification{
public:
    void notifyUser()
    {
        cout<<"Email notification sent"<<endl;
    }
    ~EmailNotification()
    {
        cout<<"EmailNotification destroyed"<<endl;
    }
};

class SMSNotification: public Notification{
    public:
    void notifyUser()
    {
        cout<<"SMS notification sent"<<endl;
    }
    ~SMSNotification(){
        cout<<"SMSNotification destroyed "<<endl;
    }
    
};

class EmailLogger: public Logger{
    public:
    void logMessage()
    {
        cout<<"Logging Email Notification"<<endl;
    }
    ~EmailLogger()
    {
        cout<<"EmailLogger Destroyed"<<endl;
    }
};

class SMSLogger: public Logger{
    public:
    void logMessage()
    {
        cout<<"Logging SMS Notification"<<endl;
    }
    ~SMSLogger()
    {
        cout<<"SMS Logger Destroyed"<<endl;
    }
};
//Factory Interface
class AbstractFactory
{
  public:
  virtual Notification* createNotification()=0;
  virtual Logger* createLogger()=0;
  ~AbstractFactory(){}
};


//concrete Factory

class ConfigFactory: public AbstractFactory{
    private:
    NotificationType notificationType;
    LogType logType;
    
    public:
    ConfigFactory( NotificationType nType, LogType lType)
    {
        notificationType=nType;
        logType=lType;
    }
     Notification* createNotification()
     {
         if(notificationType== SMS) return new SMSNotification();
         else return new EmailNotification();
     }
     
     Logger* createLogger()
     {
         if(logType==SMS_LOG) return new SMSLogger();
         else return new EmailLogger();
     }
     
     ~ConfigFactory(){
         cout<<"Factory destroyed"<<endl;
     }
};


int main()
{
    ConfigFactory *cf;
    Notification* n;
    Logger* l;
     cf=new ConfigFactory(SMS,EMAIL_LOG);
     n=cf->createNotification();
     l=cf->createLogger();
    n->notifyUser();
    l->logMessage();
    
    delete l;
    delete n;
    delete cf;
    return 0;
    
}
