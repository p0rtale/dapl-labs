#include <Clipl/Preprocessor/Streams/Streams.hpp>

#include <Clipl/Logger/Logger.hpp>


namespace preprocessor {

StreamStack::StreamStack(TOnPushCallback pushCallback, TOnPopCallback popCallback)
    : m_PushCallback(std::move(pushCallback)), m_PopCallback(std::move(popCallback)) {}

void StreamStack::pushStream(TStreamScope stream) {
    m_PushCallback(stream);
    m_Streams.push(std::move(stream));
}

void StreamStack::popStream() {
    auto streamsSize = m_Streams.size();
    if (streamsSize == 0) {
        return;
    }
    m_Streams.pop();
    if (streamsSize == 1) {
        return;
    }
    m_PopCallback(m_Streams.top());
}

}  // namespace preprocessor
