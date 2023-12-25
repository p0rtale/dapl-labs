#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>


namespace clipl {

class Logger {
public:
    static void init();

    static std::shared_ptr<spdlog::logger> getLogger() {
        return s_Logger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_Logger;
};

}  // namespace clipl


#define CLIPL_TRACE(...)    ::clipl::Logger::getLogger()->trace(__VA_ARGS__)
#define CLIPL_INFO(...)     ::clipl::Logger::getLogger()->info(__VA_ARGS__)
#define CLIPL_WARN(...)     ::clipl::Logger::getLogger()->warn(__VA_ARGS__)
#define CLIPL_ERROR(...)    ::clipl::Logger::getLogger()->error(__VA_ARGS__)
#define CLIPL_CRITICAL(...) ::clipl::Logger::getLogger()->critical(__VA_ARGS__)
