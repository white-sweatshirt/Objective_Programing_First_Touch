/***********************************************************************
 * Module:  PlatformAdmin.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 13:10:15
 * Purpose: Declaration of the class PlatformAdmin
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_PlatformAdmin_h
#define __UMLClassDiagram_1_PlatformAdmin_h

#include <User.h>

class PlatformAdmin : public User
{
public:
   void lookThroughReports(void);
   bool removePost(void);
   bool blockAccount(void);
   bool removeAccount(void);
   void deletePost(void);
   int lookThroughStatistics(void);

protected:
private:
   short listOfReports;
   char notifications;


};

#endif