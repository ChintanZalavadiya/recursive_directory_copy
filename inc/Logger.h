#ifndef _LOGGER_H_
#define _LOGGER_H_

// C++ Header Files
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LOG_ERROR           "Error"        // error with impact to correct functionality
#define LOG_WARN            "Warn"         // warning, correct behaviour could not be ensured
#define LOG_INFO            "Info"         // informational
#define LOG_DEBUG           "Debug"        // debug
#define LOG_VERBOSE         "Verbose"      // highest grade of information
#define LOG(x, y)            Logger::getInstance()->logIntoFile(x,y)


   class Logger
   {
      public:
         Logger();
         ~Logger(); 
         
         static Logger* getInstance();         
         void logIntoFile(string loglevel, string data);
         string getCurrentTime();

      private:
      
         static Logger*          mInstance;
         ofstream                mFile;
         static pthread_mutex_t  mLock;
   };

#endif // End of _LOGGER_H_
