#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <chrono>

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;

public:
    ThreadPool(size_t numThreads) : stop(false) {

        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this]() {

                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(queueMutex);

                        condition.wait(lock, [this]() {
                            return stop || !tasks.empty();
                        });

                        if (stop && tasks.empty()) {
                            return;
                        }

                        task = std::move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    template <typename F>
    void enqueue(F&& task) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            tasks.emplace(std::forward<F>(task));
        }

        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            stop = true;
        }

        condition.notify_all();

        for (std::thread& worker : workers) {
            worker.join();
        }
    }
};

int main() {

    ThreadPool pool(4);

    for (int i = 1; i <= 10; i++) {

        pool.enqueue([i]() {

            std::cout << "Task " << i
                      << " started on thread "
                      << std::this_thread::get_id()
                      << std::endl;

            std::this_thread::sleep_for(
                std::chrono::seconds(2)
            );

            std::cout << "Task " << i
                      << " completed\n";
        });
    }

    return 0;
}
