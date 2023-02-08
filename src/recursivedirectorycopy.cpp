#include <filesystem>
#include "Logger.h"

namespace fs = filesystem;

int main(int argc, char **argv)
{
   // Command line argument Count should be >= 3       
   //  ex - ./a.out srcdirpath desdirpath   
    if ( argc >= 3)
    {
	     try
	     {     
	       // argv[1] is srcdirpath and argv[2] is desdirpath	
		     fs:: copy(argv[1], argv[2] , fs::copy_options::overwrite_existing|fs::copy_options::recursive);
		     LOG(LOG_INFO,"copy successful");
	     }
       catch(exception& e)
	     {
		      LOG(LOG_ERROR,e.what());
	     }  
    }
    return 0;
}
