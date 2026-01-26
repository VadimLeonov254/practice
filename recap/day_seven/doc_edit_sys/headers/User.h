#ifndef USER_H
#define USER_H
#include<vector>
#include "EditorSession.h"
#include "Document.h"

class User{
private:
    std::vector<EditorSession> sessions;

public:
    void addSession(EditorSession& session);
};

#endif
