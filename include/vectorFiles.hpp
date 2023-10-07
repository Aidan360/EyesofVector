#include "spac.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Vector filesystem, will manage log creation mostly managing SPACs and Bacs and soon AIACs. 
// Everything here is specfically made for SSD functions alexis you have any questions on how this works let me know 
using namespace vectorR; 

/*  Database Organization, all files will be organized like this to be read and wrote by the code 

For every run that is generated 2 files will be made and one file will be edited. 
The first file will be the "runList" this file will save the name, variation, and the runData for quick selection when booting up. 
The name will be put onto the start menu 

The second file will be the "blacklist" this consists of all failed routes for given parameters and gives the total possible points for a given parameter.
In all black list files it will show list of parameters locations with F being a seperator 
the order of parameters are: alliance speed, alliance size, alliance starting point, all locations they visit 


The third file will be the "log" this will create a notebook file that has just each run data and points per line with extra formatting for easy reading.
all Code LOG files are to be put into the notebook

Example of all files made for one match 
runList.txt
bL11111AV1FF200FF15FF18FF3FF19FF15FF32.txt
log11111AV1.txt
*/


void saveToRunList(std::string fileName, std::vector<int> runData); // saves succesful run to quickrun list 
void saveBlackList(std::string fileName, std::vector<int> runData);
void saveLog(std::string filename, std::vector<int> runData); 
int readRunList(int line); // reads off a runs data from the line it is saved on
int readBlackList(std::string fileName); // returns blacklisted values for currect decision with current parameters 



