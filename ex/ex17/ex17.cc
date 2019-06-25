/*
 * Copyright ©2019 Justin Hsia.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 333 for use solely during Spring Quarter 2019 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 *
 * Jichun Li 1531264 jichunli@uw.edu
 *
 * This C programs designs Producer-Consumer pattern using concurrent,
 * where producer produces two types of pies concurrently and consumer
 * eats it when there is pie in waiting queue.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <ctime>

#include "SimpleQueue.h"
#define NUM_THREADS 3
using std::cout;
using std::endl;
using std::string;
using std::thread;
using std::cerr;

const int NUM_PIES = 6;
static SimpleQueue queue;
static unsigned int seed = time(NULL);
static pthread_mutex_t write_lock;

// Thread safe print that prints the given str on a line
void thread_safe_print(string str) {
  pthread_mutex_lock(&write_lock);
  // Only one thread can hold the lock at a time, making it safe to
  // use cout. If we didn't lock before using cout, the order of things
  // put into the stream could be mixed up.
  cout << str << endl;
  pthread_mutex_unlock(&write_lock);
}

// Produces NUM_PIES pies of the given type
// You should NOT modify this method at all
void producer(string pie_type) {
  for (int i = 0; i < NUM_PIES; i++) {
    queue.Enqueue(pie_type);
    thread_safe_print(pie_type + " pie ready!");
    int sleep_time = rand_r(&seed) % 500 + 1;
    std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
  }
}

// Eats 2 * NUM_PIES pies
// You should NOT modify this method at all
void consumer() {
  for (int i = 0; i < NUM_PIES * 2; i++) {
    bool successful = false;
    string pie_type;
    while (!successful) {
      while (queue.IsEmpty()) {
        // Sleep for a bit and then check again
        int sleep_time = rand_r(&seed) % 800 + 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
      }
      successful = queue.Dequeue(&pie_type);
    }
    thread_safe_print(pie_type + " pie eaten!");
  }
}

// wrapper function for producer
void* ProducerWrapper(void* pie_type) {
  string* pie = reinterpret_cast<string*>(pie_type);
  producer(*pie);
  return NULL;
}

// wrapper function for consumer
void* ConsumerWrapper(void* arg) {
  consumer();
  return NULL;
}

int main(int argc, char **argv) {
  pthread_mutex_init(&write_lock, NULL);
  // Your task: Make the two producers and the single consumer
  // all run concurrently (hint: use pthreads)
  // declare threads
  pthread_t thds[NUM_THREADS];
  // initialize the queue
  pthread_mutex_init(&write_lock, NULL);
  // Your task: Make the two producers and the single consumer
  // all run concurrently (hint: use pthreads)
  string* apple = new string("Apple");
  string* blackberry = new string("Blackberry");
  // create three threads
  if (pthread_create(&thds[0], NULL, &ProducerWrapper, apple) != 0) {
    cerr << "pthread_create failed" << endl;
  }
  if (pthread_create(&thds[1], NULL, &ProducerWrapper, blackberry) != 0) {
    cerr << "pthread_create failed" << endl;
  }
  if (pthread_create(&thds[2], NULL, &ConsumerWrapper, NULL) != 0) {
    cerr << "pthread_create failed" << endl;
  }
  // join
  for (int i = 0; i < NUM_THREADS; i++) {
    if (pthread_join(thds[i], NULL) != 0) {
      cerr << "pthread_join failed" << endl;
    }
  }
  // destory the lock
  pthread_mutex_destroy(&write_lock);
  // delete
  delete(blackberry);
  delete(apple);
  return 0;
}
