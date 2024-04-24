#define NOTE_H

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

class Note {
private:
        int id; // -1 means not assigned
        std::string body;
        long timestamp;
        std::time_t creationTime;

public:
        Note();
        Note(const std::string& body);
        void setId(int id);
        int getId() const;
        void setBody(const std::string& body);
        const std::string& getBody() const;
    std::string getPreview() const;
    std::string getFormattedTime() const {
        std::ostringstream stream;
        stream << std::put_time(std::localtime(&creationTime), "%m-%d-%Y %H:%M");
        return stream.str();
};


#endif
