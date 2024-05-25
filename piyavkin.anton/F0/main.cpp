#include <iostream>
#include <functional>
#include <tree.hpp>

int main()
{
  using namespace piyavkin;
  using dic_t = Tree< std::string, Tree< std::string, size_t > >;
  dic_t dicts;
  Tree< std::string, std::function< void(std::ostream&, const std::string&, const dic_t&) > > cmdsForOutput;
  // cmdsForOutput["printdictionary"] = print;
  // Tree< std::string, std::function< void(map_t&, const std::string&, const std::string&, const std::string&) > > cmdsForCreate;
  std::string name = "";
  std::string nameDict = "";
  while (std::cin >> name)
  {
    std::cin >> nameDict;
    try
    {
      cmdsForOutput.at(name)(std::cout, nameDict, dicts);
    }
    catch (const std::out_of_range&)
    {
      try
      {
        // cmdsForCreate.at(name)(map, nameDict, lhsName, rhsName);
      }
      catch (const std::out_of_range&)
      {
        std::cout << "<INVALID COMMAND>\n";
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << '\n';
        return 1;
      }
    }
  }
}
