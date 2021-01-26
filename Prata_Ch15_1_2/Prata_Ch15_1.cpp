
#include <iostream>
#include "Remote.h"


int main()
{
    Tv tv;
    Remote remote;
    
    remote.get_InteractionMode();
    tv.change_remote_interaction_mode(remote);
    remote.get_InteractionMode();
    tv.onoff();
    tv.change_remote_interaction_mode(remote);
    remote.get_InteractionMode();
}
