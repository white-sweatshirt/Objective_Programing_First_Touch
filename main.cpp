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

    cout << " Initial state: " << endl;
    users[0]->createGroup();
    users[0]->post(new Post(users[0], "Hello World!"));
    users[0]->addUserToFriendsList(users[1]);
    users[0]->addUserToGroup(users[0]->giveGroupLink(0), users[1]);
    users[1]->post(users[0]->giveGroupLink(0), new Post(users[1], "This is a post in User0's group."));
    users[1]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    users[0]->addUserToFriendsList(users[2]);
    users[2]->reportPostToAdmin(users[1]->givePostLink(0), adminAsSheep);

    printSeparator();
    cout << "After reporting post to admin as sheep:" << endl;
    users[0]->showAllPostsInGroup(users[0]->giveGroupLink(0));

    printSeparator();
    users[2]->joinGroup(users[0]->giveGroupLink(0));
    users[2]->createEvent(users[0]->giveGroupLink(0), new Event(users[2], "Event at Park", "Central Park"));
    users[2]->post(users[0]->giveGroupLink(0), new Event(users[2], "Looking forward to the event!", "New York"));
    users[0]->showAllEventsInGroup(users[0]->giveGroupLink(0));
    users[0]->showAllPostsInGroup(users[0]->giveGroupLink(0));

    printSeparator();
    users[1]->deleteGroup( users[0]->giveGroupLink(0));
    cout << "After User1 deleting User0's group:(no effect User 1 is not authorised)" << endl;
    users[0]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    printSeparator();

    users[0]->reportPostToAdmin(users[2]->givePostLink(1), adminAsWolf);
    cout << "After reporting post to admin as wolf:" << endl;
    users[2]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    printSeparator();
    cout<<"Admin as sheap forcfully takes down User 0 group"<<endl;
    adminAsSheep->deleteGroup(users[0]->giveGroupLink(0));
    users[0]->showAllPostsInGroup(users[0]->giveGroupLink(0));
    // custom deconstructor in User class ensures deletion of User 0's group
    killVectorOfPointers(users);
    delete adminAsSheep;
    delete adminAsWolf;

    return 0;
}