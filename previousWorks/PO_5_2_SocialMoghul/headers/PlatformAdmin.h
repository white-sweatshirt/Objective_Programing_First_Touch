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
   bool deleteActivity(Post *activity);
   bool deleteActivity(Post *activity, UserGroup *groupOnWithIsPosted);
   void removeUserFromGroup(User *userToRemove, User *requestingUser, UserGroup *group);
   int lookThroughStatistics(void);
   void deleteGroup(UserGroup *GroupToDelete);
   PlatformAdmin(string name);
   void show();
};

#endif