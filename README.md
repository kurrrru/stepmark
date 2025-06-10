[Japanese version](README.ja.md)

# StepMark Logger

StepMark is a simple and lightweight file logging library compliant with C++98. It is designed not to throw exceptions and is not thread-safe, intended for easy logging in single-threaded environments.

## Features

* **C++98 Compliant**: Does not use any features from C++11 or later.
* **Singleton Pattern**: Provides a single, global logger instance through the `getInstance()` method.
* **Static API**: All public methods are static, allowing them to be called directly without creating an instance.
* **8 Log Levels**: Offers eight distinct log levels, from `TRACE` to `FATAL`.
* **File-based Logging**: Log messages are output to a specified file.
* **Dynamic Configuration**: The log level and output file path can be changed at runtime.
* **Exception-Free Design**: The class does not throw exceptions, so no additional error handling is required.
* **Not Thread-Safe**: Designed for use in single-threaded environments only.

## How to Use

To use this library, add `stepmark.hpp` and `stepmark.cpp` to your project and compile them.

### Basic Example

Below is a basic usage example.

```cpp
#include "stepmark.hpp"

int main() {
    // Set the minimum log level to INFO. Levels below this will not be logged.
    toolbox::logger::StepMark::setLevel(toolbox::logger::INFO);

    // Set the output log file.
    toolbox::logger::StepMark::setLogFile("application.log");

    // Log various messages.
    toolbox::logger::StepMark::trace("This is a trace message."); // Will not be logged.
    toolbox::logger::StepMark::debug("This is a debug message."); // Will not be logged.
    toolbox::logger::StepMark::info("Application started.");      // Will be logged.
    toolbox::logger::StepMark::warning("This is a warning.");     // Will be logged.
    toolbox::logger::StepMark::error("An error occurred.");       // Will be logged.

    return 0;
}
```

### Output File (`application.log`)

Running the code above will produce the following content in `application.log`:

```log
[2025-06-10 13:45:00] Log file opened: application.log
2025-06-10 13:45:00 [INFO] Application started.
2025-06-10 13:45:00 [WARNING] This is a warning.
2025-06-10 13:45:00 [ERROR] An error occurred.
```
*Note: The timestamp will reflect the actual time of execution.*

## API Reference

### Configuration

* `static void setLevel(StepmarkLevel level);`
    Sets the minimum log level to record.
* `static void setLogFile(const std::string& file);`
    Sets the name of the file to output logs to.

### Logging Messages

Static methods are provided for each log level.

* `static void trace(const std::string& message);`
* `static void debug(const std::string& message);`
* `static void info(const std::string& message);`
* `static void notice(const std::string& message);`
* `static void warning(const std::string& message);`
* `static void error(const std::string& message);`
* `static void critical(const std::string& message);`
* `static void fatal(const std::string& message);`

A general-purpose logging method is also available:

* `static void log(StepmarkLevel level, const std::string& message);`

## Log Levels

The library defines the following eight log levels:

| Level Name | Enum Value | Description |
| :--- | :---: | :--- |
| `TRACE` | 0 | Most detailed debug information. |
| `DEBUG` | 1 | Debug information. |
| `INFO` | 2 | Normal operational information. |
| `NOTICE` | 3 | Normal but noteworthy events. |
| `WARNING` | 4 | Warning, but not an immediate problem. |
| `ERROR` | 5 | An error occurred, but execution can continue. |
| `CRITICAL` | 6 | A critical error is imminent. |
| `FATAL` | 7 | A fatal error where execution cannot continue. |

## Important Notes

* **Not Thread-Safe**: This library does not guarantee safe operation in a multi-threaded environment. Concurrent calls from multiple threads may result in race conditions when writing to the log file.

<!-- ## License

This project is released under the MIT License. -->
