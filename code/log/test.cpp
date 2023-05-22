#include<iostream>
#include<deque>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<atomic>
std::mutex mtx;
std::deque<int> q{1,2,3,4,5,6};
std::condition_variable producer;
std::condition_variable consumer;
std::atomic<int> capacity(1);

void mypush(int c){
     std::unique_lock<std::mutex> locker(mtx);
     while(q.size() >= capacity){
        producer.wait(locker);
     }
     q.push_back(c);
     std::cout << "入队：" << c << std::endl;
     consumer.notify_one();
}

void mypop(int& d){
     std::unique_lock<std::mutex> locker(mtx);
     while(q.empty()){
        consumer.wait(locker);
     }
     d = q.front();
     std::cout << "从队列中出队：" << d << std::endl;
     q.pop_front();
     producer.notify_one();
}

int main(){
    int push_data = 4;
    int pop_data;
    std::thread t1(mypush,4);
    std::thread t2(mypop,std::ref(pop_data));
    t1.join();
    t2.join();
    return 0;
}