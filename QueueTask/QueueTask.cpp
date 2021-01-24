#include <iostream>
#include "Queue.h"

#include <cstdlib>
#include <ctime>

bool newcustomer(double x);

// examplary queue simulation

int main()
{
    std::srand(std::time(0));

    int queue_max_size = 10;
    int minutes_of_simulation = 600;
    int minutes_per_customer = 2;
    Queue queue(queue_max_size);

    Item temp; // new customer data
    long turnaways = 0; // turned away by full queue
    long customers = 0; // joined the queue
    long served = 0; // served during the simulation
    long sum_line = 0; // cumulative line length
    unsigned int wait_time = 0; // time until autoteller is free
    long line_wait = 0; // cumulative time in line

    for (int cycle = 0; cycle < minutes_of_simulation; cycle++)
    {
        if (newcustomer(minutes_per_customer))
        {
            if (queue.isFull())
            {
                turnaways++;
            }
            else
            {
                customers++;
                temp.set(cycle);
                queue.addToQueue(temp);
            }
        }
        if (wait_time == 0 && !queue.isEmpty())
        {
            queue.removeFromQueue(); // attend next customer
            wait_time = temp.get_processing_time(); // for wait_time minutes
            line_wait += cycle - temp.when_arrived();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += queue.queueCount();
    }
    if (customers > 0)
    {
        std::cout << "customers accepted: " << customers << std::endl;
        std::cout << " customers served: " << served << std::endl;
        std::cout << " turnaways: " << turnaways << std::endl;
        std::cout << "average queue size: ";
        std::cout.precision(2);
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::cout << (double)sum_line / minutes_of_simulation << std::endl;
        std::cout << " average wait time: "
            << (double)line_wait / served << " minutes\n";
    }
    else
    {
        std::cout << "No customers!\n";
    }
    std::cout << "Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}