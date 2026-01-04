/***********************************************************************
 * Module:  User.h
 * Author:  franc
 * Modified: niedziela, 4 stycznia 2026 15:16:58
 * Purpose: Declaration of the class User
 ***********************************************************************/

#ifndef __UMLClassDiagram_1_User_h
#define __UMLClassDiagram_1_User_h

class Events;
class Post;
class Votings;

class User
{
   
private:

   protected:
   short photos;
   short friends;
   int favoritePosts;
   int amountOfLogins;
   
   Post** ownsPost;


public:
   void createGroup(void);
   void createPost(void);
   void postToo(void);
   void readNotification(void);
   bool setVisbiltyForPost(void);
   void addPictureToAlbum(void);
   void flirtPostsBy(void);
   void setNotificationsPrefences(void);
   void deletePost(void);
   int removeUserFromGroup(void);
   void voteInPoll(void);
   bool deleteGroup(void);
   char addUserToGroup(void);

   Events** events;
   Votings** votings;


};

#endif