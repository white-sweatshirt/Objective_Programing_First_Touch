/***********************************************************************
 * Module:  PlatformAdmin.h
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 13:10:15
 * Purpose: Declaration of the class PlatformAdmin
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_PlatformAdmin_h
#define __UMLClassDiagram_1_PlatformAdmin_h
class Post;
class User;
#include "Post.h"
#include "User.h"

class PlatformAdmin : public User
{
public:
   void lookThroughReports(void);
   void blockAccount(void);
   void removeAccount(void);
   void deleteActivity(Post *activity);
   void deleteActivity(Post *activity, UserGroup *groupOnWithIsPosted);
   int lookThroughStatistics(void);
   PlatformAdmin(string name);
   void show();
};

#endif