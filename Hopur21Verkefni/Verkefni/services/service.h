#ifndef SERVICE_H
#define SERVICE_H
#include "services/computerservice.h"
#include "services/cspersonservice.h"

class Service
{
private:
    ComputerService _computerService;
    CSPersonService _cSPersonService;
public:
    Service();
};

#endif // SERVICE_H
