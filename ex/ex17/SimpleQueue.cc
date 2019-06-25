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
 * This C program implements the functionality of a simple queue including
 * Enqueue(), dequeue(), size() and isEmpty()
 */

#include "SimpleQueue.h"
#include <pthread.h>
// declare lock
static pthread_mutex_t queue_lock;

SimpleQueue::SimpleQueue() {
  // add lock
  // initialize all locks
  pthread_mutex_init(&queue_lock, NULL);
  size = 0;
  front = nullptr;
  end = nullptr;
  // remove lock
}

SimpleQueue::~SimpleQueue() {
  // add lock
  while (front != nullptr) {
    node *next = front->next;
    delete front;
    front = next;
  }
  // remove lock
  pthread_mutex_destroy(&queue_lock);
}

void SimpleQueue::Enqueue(string item) {
  // add lock
  pthread_mutex_lock(&queue_lock);
  node *new_node = new node();
  new_node->next = nullptr;
  new_node->item = item;
  if (end != nullptr) {
    end->next = new_node;
  } else  {
    front = new_node;
  }
  end = new_node;
  size++;
  // remove lock
  pthread_mutex_unlock(&queue_lock);
}

bool SimpleQueue::Dequeue(string *result) {
  // add lock
  pthread_mutex_lock(&queue_lock);
  if (size == 0) {
    pthread_mutex_unlock(&queue_lock);
    return false;
  }
  *result = front->item;
  node *next = front->next;
  delete front;
  if (end == front) {
    end = front = next;
  } else {
    front = next;
  }
  size--;
  // remove lock
  pthread_mutex_unlock(&queue_lock);
  return true;
}

int SimpleQueue::Size() const {
  return size;
}

bool SimpleQueue::IsEmpty() const {
  return size == 0;
}

