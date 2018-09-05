#include <iostream>
#include "sklist.h"


using namespace std;

SkList::SkList(uint32_t level)
{
    m_max_level = level > 0 ? level : 1;
    m_head = new SkListNode;
    m_tail = new SkListNode;

    m_head->m_next_nodes = new SkListNode *[m_max_level];
    for (int i = 0; i < m_max_level; i++) {
        m_head->m_next_nodes[i] = m_tail;
    }
}

SkList::~SkList(void)
{
    SkListNode *curr = nullptr;
    while (m_head->m_next_nodes[0] != m_tail) {
        curr = m_head->m_next_nodes[0];
        m_head->m_next_nodes[0] = curr->m_next_nodes[0];
        delete curr->m_next_nodes;
        delete curr;
    }

    delete m_head->m_next_nodes;
    delete m_head;
    delete m_tail;
}

void SkList::Insert(uint32_t key, void *data)
{
    SkListNode *curr = m_head;
    SkListNode *update[m_max_level];

    //Lookup location
    for (int i = m_max_level - 1; i >= 0; --i) {
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes[i]->m_key > key)
            update[i] = curr;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key < key) {
                curr = curr->m_next_nodes[i];
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key == key) {
                curr->m_next_nodes[i]->m_data = data;
                return;
            }
            update[i] = curr;
        }
    }

    //Generate node
    int level = RandomLevel();
    SkListNode *temp = new SkListNode;
    temp->m_key = key;
    temp->m_data = data;
    temp->m_level = level;
    temp->m_next_nodes = new SkListNode *[level + 1];

    //Insert node on every level
    for (int i = 0; i <= level; i++) {
        temp->m_next_nodes[i] = update[i]->m_next_nodes[i];
        update[i]->m_next_nodes[i] = temp;
    }

    return;
}

void SkList::Delete(uint32_t key)
{
    SkListNode *curr = m_head;
    SkListNode *update[m_max_level];

    //Lookup location
    for (int i = m_max_level - 1; i >= 0; --i) {
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes[i]->m_key > key)
            update[i] = curr;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key < key) {
                curr = curr->m_next_nodes[i];
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key == key) {
                update[i] = curr;
            } else {
                update[i] = nullptr;
            }
        }
    }

    SkListNode *temp = nullptr;

    for (int i = 0; i < m_max_level; ++i) {
       if (update[i]) {
            temp = update[i]->m_next_nodes[i];
            update[i]->m_next_nodes[i] = temp->m_next_nodes[i];
       }
    }

    if (temp) {
        delete temp->m_next_nodes;
        delete temp;
    }
    return;
}

void *SkList::Get(uint32_t key)
{
    SkListNode *curr = m_head;

    //Lookup location
    for (int i = m_max_level - 1; i >= 0; --i) {
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes[i]->m_key > key)
            continue;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key < key) {
                curr = curr->m_next_nodes[i];
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes[i]->m_key == key) {
                return curr->m_next_nodes[i]->m_data;
            }
        }
    }
    return nullptr;
}

void SkList::Display(void)
{
    SkListNode *curr = m_head;

    for (int i = m_max_level - 1; i >= 0; --i) {
        curr = m_head;
        while (curr->m_next_nodes[i] != m_tail) {
            curr = curr->m_next_nodes[i];
            cout << "curr level[" << i << "] key[ " << curr->m_key << "]" << endl;
        }
    }
}

int32_t SkList::RandomLevel(void)
{
    int level = 0;
    while (rand() % 2 && level < m_max_level - 1)
        ++level;

    return level;
}

