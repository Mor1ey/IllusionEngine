#ifndef __IEMANAGER_H__
#define __IEMANAGER_H__

namespace IESystem
{
	enum {OFF,FAIL,WARNING,ON};
class Manager
{
public:
	Manager() // nothing
	{state = 0;}
	virtual ~Manager() // nothing
	{}

	virtual VOID startUp() = 0; 
	virtual VOID shutDown() = 0;
private:
	U8 state;
};
};


#endif // MANAGER