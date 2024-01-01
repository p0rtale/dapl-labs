#pragma once

#include <stack>
#include <memory>
#include <fstream>
#include <functional>


namespace preprocessor {

class StreamStack {
public:
    using TStreamScope = std::unique_ptr<std::ifstream>;
    using TOnPushCallback = std::function<void(TStreamScope&)>;
    using TOnPopCallback = std::function<void(TStreamScope&)>;
public:
    StreamStack(TOnPushCallback pushCallback, TOnPopCallback popCallback);

    bool empty() const { return m_Streams.empty(); }
    void pushStream(std::string filename, size_t line);
    std::pair<std::string, size_t> popStream();

private:
    std::stack<std::pair<TStreamScope, std::pair<std::string, size_t>>> m_Streams;
    TOnPushCallback m_PushCallback;
    TOnPopCallback m_PopCallback;
};

}  // namespace preprocessor
