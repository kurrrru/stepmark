#pragma once

#include <string>
#include <fstream>

namespace toolbox {

namespace logger {

enum StepmarkLevel {
    TRACE = 0,    // 最も詳細なデバッグ情報
    DEBUG = 1,    // デバッグ情報
    INFO = 2,     // 通常の動作情報
    NOTICE = 3,   // 注意を引くべき正常イベント
    WARNING = 4,  // 警告 (すぐに問題にはならない)
    ERROR = 5,    // エラー (処理は続行可能)
    CRITICAL = 6, // 致命的なエラー寸前
    FATAL = 7     // 処理続行不可能な致命的エラー
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
