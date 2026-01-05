/***********************************************************************
 * Module:  Post.cpp
 * Author:  WhiteSweatShirt
 * Modified: niedziela, 4 stycznia 2026 15:27:46
 * Purpose: Implementation of the class Post
 ***********************************************************************/

#include "Post.h"

void Post::addPersonToMention(User *person)
{
   this->mentionList.push_back(person);
}

void Post::removePersonFromMentioned(User *person)

{
   mentionList.remove(person);
}
User *Post::givePostOwner(void)
{
   return this->postOwner;
}
bool Post::checkWheterPersonIsOwner(User *person)
{
   return person == this->postOwner ? true : false;
}
int Post::giveLikeToDislikeRatio(void)
{
   return this->likeToDislikeRatio;
}
std::string Post::givePostContents(void)
{
   return this->contents;
}
void Post::modifyContents(std::string newContents, User *editor)
{
   if (checkWheterPersonIsOwner(editor))
      this->contents = newContents;
}
Post::Post(User *owner, string contents)
{
   this->postOwner = owner;
   this->contents = contents;
}
Post::~Post()
{
   this->groupAscooscion;
}
bool Voteings::checkWheterUserVoted(User *user)
{
   for (auto w : this->usersWhoHadVoted)
   {
      if (w == user)
         return true;
   }
   return false;
}

void Voteings::voteByUser(User *user, bool forAvganist)
{
   if (oneUserOneVote)
   {
      if (!checkWheterUserVoted(user))
      {
         this->usersWhoHadVoted.push_back(user);
         this->currenamountOfLead += (forAvganist == 1 ? 1 : -1);
      }
   }
   else
      this->currenamountOfLead += (forAvganist == 1 ? 1 : -1);
}

void Voteings::setEndDate(string date)
{
   this->endDate = date;
}

int Voteings::giveResult(void)
{
   return this->result;
}