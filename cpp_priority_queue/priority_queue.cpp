#include <stdio.h>
#include <iostream>
#include <cstdint>
#include <queue>
#include <vector>

#define SIM_NAMESPACE demo_space

namespace SIM_NAMESPACE {
    class event {
        public:
            uint32_t getSimTime() const;
            event(uint32_t sim_time, uint32_t node_id, uint32_t local_event_version, uint32_t local_event_id);
        private:
            uint32_t sim_time;
            uint32_t node_id;
            uint32_t local_event_version;
            uint32_t local_event_id;
    };
}

namespace SIM_NAMESPACE {
    event::event(uint32_t sim_time, uint32_t node_id, uint32_t local_event_version, uint32_t local_event_id) {
        this->sim_time = sim_time;
        this->node_id = node_id;
        this->local_event_version = local_event_version;
        this->local_event_id = local_event_id;
    }

    uint32_t event::getSimTime() const {
        return this->sim_time;
    }

    bool operator < (const event& lhs, const event& rhs) {
        return lhs.getSimTime() < rhs.getSimTime();
    }
    
    bool operator > (const event& lhs, const event& rhs) {
        return lhs.getSimTime() > rhs.getSimTime();
    }
}

template<class T>
void printQueue(T& q)
{
    while (!q.empty())
    {
        std::cout << q.top().getSimTime() << std::endl;
        q.pop();
    }
}

int main()
{
    SIM_NAMESPACE::event e1(1,2,3,4);
    SIM_NAMESPACE::event e2(2,3,4,5);
    SIM_NAMESPACE::event e3(200,1,1,1);

    std::cout << e1.getSimTime() << std::endl;
    std::cout << e2.getSimTime() << std::endl;
    std::cout << e3.getSimTime() << std::endl;

    std::cout << (e1<e2) << std::endl;
    std::cout << (e1>e3) << std::endl;
    std::cout << (e3<e1) << std::endl;
    std::cout << (e3>e1) << std::endl;
    std::cout << (e1<e1) << std::endl;

    std::priority_queue<SIM_NAMESPACE::event, std::vector<SIM_NAMESPACE::event>, std::less<std::vector<SIM_NAMESPACE::event>::value_type>> equeue_less;
    equeue_less.push(e1);
    equeue_less.push(e2);
    equeue_less.push(e3);
    printQueue(equeue_less);

    std::priority_queue<SIM_NAMESPACE::event, std::vector<SIM_NAMESPACE::event>, std::greater<std::vector<SIM_NAMESPACE::event>::value_type>> equeue_;
    equeue_.push(e1);
    equeue_.push(e2);
    equeue_.push(e3);
    printQueue(equeue_);

    return 0;
}

