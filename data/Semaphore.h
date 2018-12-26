//
// Created by Eldar on 12/22/2018.
//

#ifndef SIMULATOR_SEMAPHORE_H
#define SIMULATOR_SEMAPHORE_H
#include <mutex>
#include <condition_variable>

class Semaphore
{
private:
    std::mutex mutex_;
    std::condition_variable condition_;
    unsigned long count_ = 0; // Initialized as locked.

public:
    // Notify another thread
    void notify() {
        std::lock_guard<decltype(mutex_)> lock(mutex_);
        ++count_;
        condition_.notify_one();
    }

    // Wait for another thread to finish
    void wait() {
        std::unique_lock<decltype(mutex_)> lock(mutex_);
        while(!count_) // Handle spurious wake-ups.
            condition_.wait(lock);
        --count_;
    }

    // Try Wait for another thread to finish
    bool try_wait() {
        std::lock_guard<decltype(mutex_)> lock(mutex_);
        if(count_) {
            --count_;
            return true;
        }
        return false;
    }
};

#endif //SIMULATOR_SEMAPHORE_H
