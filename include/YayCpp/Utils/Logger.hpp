#include <iostream>
#include <iomanip>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

class YCPLogger {
private:
    std::shared_ptr<spdlog::logger> _logger;
    bool _debugMode;
    bool _disableLog;

    void log(std::string& level, std::string& message);

public:
    YCPLogger(bool debugMode = false, bool disableLog = false);

    void info(std::string& message);

    void warn(std::string& message);

    void error(std::string& message);

    void debug(std::string& message);

    void setDebugMode(bool debugMode);

    void setDisableLog(bool disableLog);

    spdlog::level::level_enum getColor(spdlog::level::level_enum level);
};