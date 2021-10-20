#include <iostream>
#include<regex>
#include<sstream>
using namespace std;

bool
isNumber (std::string token)
{
  return std::regex_match (token,
			   std::regex (("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?")));
}

void
split (string s, string * v1, string * v2)
{

  int flag = 1, x = 0;

  for (int i = 0; i < s.length (); i++)
    {
      if (s[i] == '/')
	{
	  flag = 0;
	  continue;
	}
      if (flag == 1)
	{
	  v1->push_back (s[i]);
	}
      else
	{
	  v2->push_back (s[i]);
	}


    }


}


int
main (int argc, char **argv)
{


  if (argc == 1)
    {
      std::cout << "Pls input numbers x/y format" << endl;
      return 0;
    }
  string box = argv[1];


  string value1 = "";
  string value2 = "";
  split (box, &value1, &value2);
  if (isNumber (value1) && isNumber (value2))
    {
      stringstream geek1 (value1);
      stringstream geek2 (value2);
      float x1 = 0, x2 = 0;
      geek1 >> x1;
      geek2 >> x2;
      std::cout << x1 / x2 << endl;


    }
  else
    {
      std::cout << "Pls input numbers x/y format" << endl;

    }
}
