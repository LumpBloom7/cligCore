#include "clig.hpp"
bool cligCore::filesystem::fileExists(
    const std::string &fileName ) // Used to check if a certain file exists with a certain directory
{
  struct stat buffer;
  return ( stat( fileName.c_str(), &buffer ) == 0 );
}