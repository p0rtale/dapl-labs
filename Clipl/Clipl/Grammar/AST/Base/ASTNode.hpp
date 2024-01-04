#pragma once

#include <memory>

#include <Clipl/Visitor/Visitor.hpp>

#include <Clipl/Logger/Logger.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>


namespace ast {

class ASTNode {
public:
    virtual ~ASTNode() = default;

    virtual void Accept(Visitor& visitor) = 0;
};

}  // namespace ast
