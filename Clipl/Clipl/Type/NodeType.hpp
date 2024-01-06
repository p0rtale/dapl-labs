#pragma once

#include <Clipl/Base.hpp>
#include <Clipl/Type/Type.hpp>


namespace clipl::type {

class NodeType: public Type {
public:
    NodeType() = default;

    virtual void AttachType(RefT<NodeType> type) = 0;
};

}  // namespace clipl::type
