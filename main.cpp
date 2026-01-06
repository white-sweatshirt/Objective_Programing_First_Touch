#include "Post.h"
#include "User.h"
#include "UserGroup.h"
#include "Event.h"
#include "MemberOfGroup.h"
#include "PlatformAdmin.h"
#include "TemplateLib.h"

void printSeparator()
{
    cout << "****************************" << endl;
}
int main()
{
    vector<User *> users;
    User *adminAsSheep = new PlatformAdmin("AdminSheep");
    PlatformAdmin *adminAsWolf = new PlatformAdmin("AdminWolf");
    int constexpr sampleSIze = 5;
    for (int i = 0; i < sampleSIze; i++)
        users.push_back(new User("User" + to_string(i)));

    users[0]->createGroup();
    users[0]->createPost("Hello World!");
    users[0]->addUserToFriendsList(users[1]);
    users[0]->addUserToGroup(users[0]->giveGroupLink(0), users[1]);
    users[1]->createPost(users[0]->giveGroupLink(0), "Hi User0!");
    users[1]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    users[0]->addUserToFriendsList(users[2]);
    users[2]->reportPostToAdmin(users[1]->givePostLink(0), adminAsSheep);
    printSeparator();

    cout << "After reporting post to admin as sheep:" << endl;
    users[0]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    printSeparator();

    users[2]->joinGroup(users[0]->giveGroupLink(0));
    users[2]->createEvent(users[0]->giveGroupLink(0), new Event(users[2], "Event at Park"));
    users[0]->showAllEventsInGroup(users[0]->giveGroupLink(0));
    printSeparator();

    killVectorOfPointers(users);
    delete adminAsSheep;
    delete adminAsWolf;

    return 0;
}