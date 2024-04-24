#include "note.h"
#include <time.h>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

Note::Note() { }

Note::Note(const std::string& body) {
        this->id = -1;
        this->body = body;
        // get unix time
        this->timestamp = time(0);
        this->timestamp = std::chrono::system_clock::to_time_t(std::chrono::system_clock::note());
}

void Note::setId(int id) {
        this->id = id;
}

int Note::getId() const {
        return this->id;
}

void Note::setBody(const std::string& body) {
        this->body = body;
}
const std::string& Note::getBody() const {
        return this->body;
}

std::string Note::getPreview() const {
    // find the first occurrence of \n
    size_t pos = this->body.find("\n");
    if (pos == std::string::npos) {
        return this->body;
    } else {
        return this->body.substr(0, pos) + " ...";
    }
}
