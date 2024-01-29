#pragma once

#include <functional>
#include <unordered_map>
#include <vector>

struct Event {};

struct UpArrowPressedEvent : Event {};
struct DownArrowPressedEvent : Event {};
struct RightArrowPressedEvent : Event {};
struct LeftArrowPressedEvent : Event {};
struct UKeyPressedEvent : Event {};

template <typename EventType>
class EventBus {
public:
    using Callback = std::function<void(const EventType&)>;

    static void Subscribe(Callback callback) {
        callbacks_.emplace_back(std::move(callback));
    }

    static void Unsubscribe(const Callback& callback) {
        callbacks_.erase(std::remove(callbacks_.begin(), callbacks_.end(), callback), callbacks_.end());
    }

    static void Publish(const EventType& event) {
        for (const auto& callback : callbacks_) {
            callback(event);
        }
    }

private:
    static std::vector<Callback> callbacks_;
};

template <typename EventType>
std::vector<typename EventBus<EventType>::Callback> EventBus<EventType>::callbacks_;
