#include "Logger.h"

Logger* Logger::mInstance = NULL;

// Log file name
const char* const pcToBeScheduled = "LogFile.log";

pthread_mutex_t Logger:: mLock = PTHREAD_MUTEX_INITIALIZER;

Logger::Logger()
{
   // open the LogFile.log file in write and append mode
   mFile.open(pcToBeScheduled, ios::out|ios::app);
   
   // Initialize mutex
   pthread_mutex_init ( &mLock, NULL ); 
}

Logger::~Logger()
{
   mFile.close();   
   pthread_mutex_destroy(&mLock);
}

Logger* Logger::getInstance()
{
   if (mInstance == NULL) 
   {
      mInstance = new Logger();
   }
   return mInstance;
}


void Logger::logIntoFile(string loglevel,string data)
{
   // mutex lock
   pthread_mutex_lock ( &mLock ); 
   
   mFile << getCurrentTime() <<"  " <<loglevel << "  " << data << endl;
   
   // mutex unlock
   pthread_mutex_unlock ( &mLock );
}

string Logger::getCurrentTime()
{
   string currTime;
   
   //Current date/time based on current time  
   time_t now = time(0); 
   
   // Convert current time to string
   currTime.assign(ctime(&now));

   // Last charactor of currentTime is "\n", so remove it
   currTime.pop_back();
  
   return currTime;
}
