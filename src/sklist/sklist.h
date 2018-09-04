#ifndef __SKLIST__
#define __SKLIST__

#include <stdint.h>

typedef struct SkListNode {
    uint32_t m_key;
    uint32_t m_level;
    void *m_data;
    SkListNode **m_next_nodes;
} SkListNode;


class SkList {
    public:
        SkList(uint32_t level);
        ~SkList(void);
        void Insert(uint32_t key, void *data);
        void Delete(uint32_t key);
        void *Get(uint32_t key);
        void Display(void);
    private:
        int32_t m_max_level;
        int32_t RandomLevel(void);
        SkListNode *m_head;
        SkListNode *m_tail;
};


#endif // __SKLIST__

