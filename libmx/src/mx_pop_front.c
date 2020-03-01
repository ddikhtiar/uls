#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *temp = NULL;

    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    else {
        temp = (*head)->next;
        (*head)->data = NULL;
        free(*head);
        *head = temp;
    }
}
