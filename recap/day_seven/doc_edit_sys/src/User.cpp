#include<iostream>
#include <vector>
#include "User.h"
#include "EditorSession.h"

void User::addSession(EditorSession& session){
    sessions.push_back(session);  
};
