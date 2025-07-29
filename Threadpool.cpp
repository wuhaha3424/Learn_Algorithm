#include<iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <future>

class ThreadPool {
public:
	explicit ThreadPool(size_t numThreads):stop(false){
		for (size_t i = 0; i < numThreads; i++)
		{
			workers.emplace_back([this] {
				while (true) {
					std::function<void()> task;
					{
						std::unique_lock<std::mutex> lock(this->mutex_);
						this->condition.wait(lock, [this] {
							return this->stop || !this->tasks.empty();
						});
						if (this->stop && this->tasks.empty())
							return;
						task = std::move(this->tasks.front());
						this->tasks.pop();
					}
					task();
				}
			});
		}
	}

	~ThreadPool() {
		{
			std::unique_lock<std::mutex> lock(mutex_);
			stop = true;
		}
		condition.notify_all();
		for (std::thread& worker : workers)
			worker.join();
	}

	void addTask(std::function<void()> task) {
		{
			std::unique_lock<std::mutex> lock(mutex_);
			tasks.push(std::move(task));
		}
		condition.notify_one();
	}

private:
	std::vector<std::thread> workers;	//工作线程集合
	std::queue<std::function<void()>> tasks;	//任务队列

	std::mutex mutex_;
	std::condition_variable condition;

	std::atomic<bool> stop;
};

int main()
{
	ThreadPool tp(8);
	for (int i = 0; i < 1000; i++)
	{
		int taskid = i;
		tp.addTask([taskid]() {
			std::cout << "Task " << taskid << " started" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			std::cout << "Task " << taskid << " finished" << std::endl;
		});
	}
	std::cout << "Main thread continues to run..." << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(3));
}