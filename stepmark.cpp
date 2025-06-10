/*
This implementation is besed on C++98 and does not use any C++11 or later features.
StepMark class does not throw exceptions
because the log is not critical to the program's execution and
throwing exceptions would require additional error handling
which is not needed in this case.
The class is designed to be simple and lightweight,
allowing for easy logging without the overhead of exception handling.
The class uses a singleton pattern to ensure that only one instance of the logger exists.
The class is not thread-safe, so it should not be used in a multi-threaded environment.
*/

#include "stepmark.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>

namespace toolbox {

/*
 * @brief StepMark constructor.
 * @note The reason for not opening the log file in the constructor is to allow
 *       the user to set the log file name before opening it.
 */
logger::StepMark::StepMark() : _level(INFO), _logFileName("stepmark.log") {
}

logger::StepMark::~StepMark() {
    if (_logFile.is_open()) {
        _logFile.close();
    }
}

void logger::StepMark::setLevel(StepmarkLevel level) {
    logger::StepMark& instance = getInstance();
    instance._level = level;
}

void logger::StepMark::setLogFile(const std::string& file) {
    logger::StepMark& instance = getInstance();
    if (instance._logFile.is_open()) {
        instance._logFile.close();
    }
    instance._logFileName = file;
    instance.openLogFile();
}

logger::StepMark& logger::StepMark::getInstance() {
    static StepMark instance;
    return instance;
}

/*
 * @brief Logs a message to the log file.
 * @param level The log level.
 * @param message The message to log.
 * @note This function will create the log file if it does not exist.
 */
void logger::StepMark::log(StepmarkLevel level, const std::string& message) {
    const char* levelStr[] = {
        "TRACE",
        "DEBUG",
        "INFO",
        "NOTICE",
        "WARNING",
        "ERROR",
        "CRITICAL",
        "FATAL"
    };

    logger::StepMark& instance = getInstance();
    if (!instance._logFile.is_open()) {
        instance.openLogFile();
    }
    if (instance._logFile.is_open()) {
        if (level >= instance._level) {
            instance._logFile << instance.getTimeStamp()
                << " [" << levelStr[level] << "] " << message << std::endl;
        }
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}

void logger::StepMark::trace(const std::string& message) {
    log(TRACE, message);
}

void logger::StepMark::debug(const std::string& message) {
    log(DEBUG, message);
}

void logger::StepMark::info(const std::string& message) {
    log(INFO, message);
}

void logger::StepMark::warning(const std::string& message) {
    log(WARNING, message);
}

void logger::StepMark::notice(const std::string& message) {
    log(NOTICE, message);
}

void logger::StepMark::error(const std::string& message) {
    log(ERROR, message);
}

void logger::StepMark::critical(const std::string& message) {
    log(CRITICAL, message);
}

void logger::StepMark::fatal(const std::string& message) {
    log(FATAL, message);
}

std::string logger::StepMark::getTimeStamp() {
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    return std::string(buffer);
}

void logger::StepMark::openLogFile() {
    _logFile.open(_logFileName.c_str(), std::ios::app);
    if (!_logFile.is_open()) {
        std::cerr << "Error opening log file: " << _logFileName
            << ". Defaulting to stepmark.log." << std::endl;
        _logFileName = "stepmark.log";
        _logFile.open(_logFileName.c_str(), std::ios::app);
    }
    if (_logFile.is_open()) {
        _logFile << "[" << getTimeStamp() << "] "
            << "Log file opened: " << _logFileName
            << std::endl;
    }
}

}  // namespace toolbox
