#include "Post.h"
#include "User.h"
#include "PlatformAdmin.h"
int main()
{
    vector<User *> users;
    User *adminAsSheep = new PlatformAdmin("AdminSheep");
    PlatformAdmin *adminAsWolf = new PlatformAdmin("AdminWolf");
    return 0;
}