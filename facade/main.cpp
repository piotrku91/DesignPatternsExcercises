
#include <iostream>
#include "console_table_maker.hpp"

int main() 
{
auto hm = ConsoleTableMaker::get();


std::cout << hm.getHeader("MAIN MENU", '*') 
          << hm.getEntries({"Settings", "Exit"}, '*')
          << hm.getFooter('*')
          << std::endl;

}
