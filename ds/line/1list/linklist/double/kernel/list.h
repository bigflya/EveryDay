#include <stdbool.h>

#ifndef LINUX_LIST_H__
#define LINUX_LIST_H__

struct list_head
{

	struct list_head *prev;
	struct list_head *next;
};

#define LIST_HEAD_INIT(name) {&(name),&(name)}
#define LIST_HEAD(name) struct list_head name = LIST_HEAD_INIT(name)


# define __compiletime_assert(condition, msg, prefix, suffix) do { } while (0)
#define _compiletime_assert(condition, msg, prefix, suffix) \
        __compiletime_assert(condition, msg, prefix, suffix)
/**
 * compiletime_assert - break build and emit msg if condition is false
 * @condition: a compile-time constant condition to check
 * @msg:       a message to emit if condition is false
 *
 * In tradition of POSIX assert, this macro will break the build if the
 * supplied condition is *false*, emitting the supplied error message if the
 * compiler has support to do so.
 */
#define compiletime_assert(condition, msg) \
        _compiletime_assert(condition, msg, __compiletime_assert_, __COUNTER__)

#define compiletime_assert_rwonce_type(t)                                       \
        compiletime_assert(__native_word(t) || sizeof(t) == sizeof(long long),  \
                "Unsupported access size for {READ,WRITE}_ONCE().")

#define __WRITE_ONCE(x, val)                                            \
do {                                                                    \
        *(volatile typeof(x) *)&(x) = (val);                            \
} while (0)

#define WRITE_ONCE(x, val)                                              \
do {                                                                    \
        compiletime_assert_rwonce_type(x);                              \
        __WRITE_ONCE(x, val);                                           \
} while (0)


static inline bool __list_add_valid(struct list_head *new,
                                struct list_head *prev,
                                struct list_head *next)
{
        return true;
}


/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(struct list_head *new,
                              struct list_head *prev,
                              struct list_head *next)
{
        if (!__list_add_valid(new, prev, next))
                return;

        next->prev = new;
        new->next = next;
        new->prev = prev;
        WRITE_ONCE(prev->next, new);
}



/**
 * list_add - add a new entry
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void list_add(struct list_head *new, struct list_head *head)
{
        __list_add(new, head, head->next);
}

/**
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
        __list_add(new, head->prev, head);
}



/**
 * list_is_head - tests whether @list is the list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int list_is_head(const struct list_head *list, const struct list_head *head)
{
        return list == head;
}

/**
 * list_for_each        -       iterate over a list
 * @pos:        the &struct list_head to use as a loop cursor.
 * @head:       the head for your list.
 */
#define list_for_each(pos, head) \
        for (pos = (head)->next; !list_is_head(pos, (head)); pos = pos->next)






#define offsetof(TYPE, MEMBER)  ((size_t)&((TYPE *)0)->MEMBER)

/**
 * BUILD_BUG_ON_MSG - break compile if a condition is true & emit supplied
 *                    error message.
 * @condition: the condition which the compiler should know is false.
 *
 * See BUILD_BUG_ON for description.
 */
#define BUILD_BUG_ON_MSG(cond, msg) compiletime_assert(!(cond), msg)
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:        the pointer to the member.
 * @type:       the type of the container struct this is embedded in.
 * @member:     the name of the member within the struct.
 *
 */
#define container_of(ptr, type, member) ({                              \
        void *__mptr = (void *)(ptr);                                   \
        BUILD_BUG_ON_MSG(!__same_type(*(ptr), ((type *)0)->member) &&   \
                         !__same_type(*(ptr), void),                    \
                         "pointer type mismatch in container_of()");    \
        ((type *)(__mptr - offsetof(type, member))); })
/**
 * list_entry - get the struct for this entry
 * @ptr:        the &struct list_head pointer.
 * @type:       the type of the struct this is embedded in.
 * @member:     the name of the list_head within the struct.
 */
#define list_entry(ptr, type, member) \
        container_of(ptr, type, member)






#endif
