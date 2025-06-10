#include "../stepmark.hpp"

void testLogging() {
    toolbox::logger::StepMark::trace("This is a trace message.");
    toolbox::logger::StepMark::debug("This is a debug message.");
    toolbox::logger::StepMark::info("This is an info message.");
    toolbox::logger::StepMark::notice("This is a notice message.");
    toolbox::logger::StepMark::warning("This is a warning message.");
    toolbox::logger::StepMark::error("This is an error message.");
    toolbox::logger::StepMark::critical("This is a critical message.");
    toolbox::logger::StepMark::fatal("This is a fatal message.");
}

int main() {
    const char *logLevels[] = {
        "TRACE",
        "DEBUG",
        "INFO",
        "NOTICE",
        "WARNING",
        "ERROR",
        "CRITICAL",
        "FATAL"
    };
    for (int i = 0; i < 8; ++i) {
        toolbox::logger::StepMark::setLevel(static_cast<toolbox::logger::StepmarkLevel>(i));
        toolbox::logger::StepMark::setLogFile(std::string("log_") + logLevels[i] + ".log");
        testLogging();
    }
}
