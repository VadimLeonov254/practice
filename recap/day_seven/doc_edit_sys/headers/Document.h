#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document{
private:
    std::string title;
    std::string content;
    bool isLocked = false;
public:
    Document(std::string title);
    void read();
    void write(std::string text);
    void toggleLock();
    bool getLocked();
};

#endif
