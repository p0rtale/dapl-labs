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
    void pushStream(TStreamScope stream);
    void popStream();

private:
    std::stack<TStreamScope> m_Streams;
    TOnPushCallback m_PushCallback;
    TOnPopCallback m_PopCallback;
};

}  // namespace preprocessor
