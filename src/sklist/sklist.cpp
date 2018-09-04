#include "sklist.h"


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
        m_head->m_next_nodes[0] = curr->m_next_nodes;
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
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes->m_key > key)
            update[i] = curr;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key < key) {
                curr = curr->m_next_nodes;
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key == key) {
                curr->m_next_nodes[i]->m_data = data;
                return;
            }
            update[i] = curr;
        }
    }

    //Generate node
    int level = ::RandomLevel();
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
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes->m_key > key)
            update[i] = curr;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key < key) {
                curr = curr->m_next_nodes;
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key == key) {
                curr->m_next_nodes[i]->m_data = data;
                return;
            }
            update[i] = curr;
        }
    }


}
void *SkList::Get(uint32_t key)
{
    SkListNode *curr = m_head;

    //Lookup location
    for (int i = m_max_level - 1; i >= 0; --i) {
        if (curr->m_next_nodes[i] == m_tail || curr->m_next_nodes->m_key > key)
            update[i] = curr;
        else {
            while(curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key < key) {
                curr = curr->m_next_nodes;
            }
            if (curr->m_next_nodes[i] != m_tail && curr->m_next_nodes->m_key == key) {
                return curr->m_next_nodes[i]->m_data;
            }
            update[i] = curr;
        }
    }
    return nullptr;
}

void SkList::Display(void)
{

}

int32_t SkList::RandomLevel(void)
{

}

