#ifndef
#define UNITTESTING_H

#include <vector> 

class UnitTesting
{
private:
  std::vector TestFixtures;
  
public:
  UnitTesting();
  ~UnitTesting();
  bool AddTestFixture(TestFixture *p);
  bool RunTests();
 
};
#endif