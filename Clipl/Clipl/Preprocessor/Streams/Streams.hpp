#pragma once

#include <stack>
#include <memory>
#include <fstream>
#include <functional>


namespace preprocessor {

class StreamStack {
public:
    using StreamScopeT = std::unique_ptr<std::ifstream>;
    using OnPushCallbackT = std::function<void(StreamScopeT&)>;
    using OnPopCallbackT = std::function<void(StreamScopeT&)>;
public:
    StreamStack(OnPushCallbackT pushCallback, OnPopCallbackT popCallback);

    bool empty() const { return m_Streams.empty(); }
    void pushStream(std::string filename, size_t line);
    std::pair<std::string, size_t> popStream();

private:
    std::stack<std::pair<StreamScopeT, std::pair<std::string, size_t>>> m_Streams;
    OnPushCallbackT m_PushCallback;
    OnPopCallbackT m_PopCallback;
};

}  // namespace preprocessor
