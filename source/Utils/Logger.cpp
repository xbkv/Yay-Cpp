#include <include/YayCpp/Utils/Logger.hpp>


YCPLogger::YCPLogger(bool debugMode, bool disableLog) : _debugMode(debugMode), _disableLog(disableLog) {
    spdlog::set_level(spdlog::level::info);
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    _logger = spdlog::stdout_color_mt("console");
    _logger->set_level(debugMode ? spdlog::level::debug : spdlog::level::info);
}

void YCPLogger::info(std::string& message) {
    _logger->info(message);
}

void YCPLogger::warn(std::string& message) {
    _logger->warn(message);
}

void YCPLogger::error(std::string& message) {
    _logger->error(message);
}

void YCPLogger::debug(std::string& message) {
    _logger->debug(message);
}

void YCPLogger::setDebugMode(bool debugMode) {
    this->_debugMode = debugMode;
    _logger->set_level(debugMode ? spdlog::level::debug : spdlog::level::info);
}

void YCPLogger::setDisableLog(bool disableLog) {
    this->_disableLog = disableLog;
}

spdlog::level::level_enum getColor(spdlog::level::level_enum level) {
    switch (level) {
        case spdlog::level::trace:
            return spdlog::level::info;
        case spdlog::level::debug:
            return spdlog::level::warn;
        case spdlog::level::info:
            return spdlog::level::err;
        case spdlog::level::warn:
            return spdlog::level::critical;
        case spdlog::level::err:
            return spdlog::level::critical;
        default:
            return spdlog::level::info;
    }
}