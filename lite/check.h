/*******************************************************************************
Copyright (c) 2001-2010 by Text Analysis International, Inc.
All rights reserved.
********************************************************************************
*
* NAME:	CHECK.H
* FILE:	lite\check.h
* CR:		11/27/98 AM.
* SUBJ:	Check actions for Pat pass.
*
*******************************************************************************/

#ifndef CHECK_H_
#define CHECK_H_
//#include <iostream>											// Upgrade.	// 01/24/01 AM.
//using namespace std;											// Upgrade.	// 01/24/01 AM.
#include <assert.h>


// Forward references
class RFASem;				// 11/22/99 AM.

/********************************************
* CLASS:	CHECK
* CR:		11/27/98 AM.
* SUBJ:	Convenience class for check actions.
********************************************/

class Check
{
	//friend ostream &operator<<(ostream &, Check &);

public:
	Check();										// Default constructor.
	~Check();									// Destructor.

	// Access

	// Modify

	// General.

	// Class-wide
	static bool Check::checkOr(
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXlt(	// 08/06/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXgt(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXeq(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXne(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXge(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkXle(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNlt(	// 08/07/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNgt(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNeq(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNne(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNge(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkNle(	// 09/14/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGlt(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGgt(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGeq(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGne(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGge(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);
	static bool Check::checkGle(	// 09/20/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp				// 11/19/99 AM.
		);

	static bool Check::checkDebug(							// 11/22/99 AM.
		Delt<Iarg> *args,			// Action's arguments.
		Nlppp *nlppp
		);

	static bool Check::checkTrue(RFASem *val);			// 11/22/99 AM.

protected:

// When code is well debugged and stable, can remove the stuff below.
#ifndef STABLE_
public:
	static int getCount();
	static void prettyCount(_t_ofstream* =0);				// Pretty-print the count.
private:
	static int count_;						// Count nodes currently allocated.
#endif
};



#endif
/*************************      END OF FILE      ******************************/
