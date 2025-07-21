#pragma once

#include <string>
#include <fstream>

namespace toolbox {

namespace logger {

enum StepmarkLevel {
    TRACE = 0,     // Detailed trace information
    DEBUG = 1,     // Debugging information
    INFO = 2,      // Informational messages
    NOTICE = 3,    // Normal but significant conditions
    WARNING = 4,   // Warning conditions (not an immediate problem)
    ERROR = 5,     // Error conditions (the operation can continue)
    CRITICAL = 6,  // Critical conditions (verging on a fatal error)
    FATAL = 7      // Fatal errors that will cause the program to abort
};

class StepMark {
 public:
    static void setLevel(StepmarkLevel level);
    static void setLogFile(const std::string& file);
    static void log(StepmarkLevel level, const std::string& message);

    static void trace(const std::string& message);
    static void debug(const std::string& message);
    static void info(const std::string& message);
    static void notice(const std::string& message);
    static void warning(const std::string& message);
    static void error(const std::string& message);
    static void critical(const std::string& message);
    static void fatal(const std::string& message);

 private:
    StepmarkLevel _level;
    std::string _logFileName;
    std::ofstream _logFile;

    static StepMark& getInstance();
    void openLogFile();

    StepMark();
    ~StepMark();
    StepMark(const StepMark&);
    StepMark& operator=(const StepMark&);
    std::string getTimeStamp();
};

}  // namespace logger

}  // namespace toolbox
