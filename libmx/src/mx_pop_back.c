#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *end = NULL;
    t_list *del = NULL;

    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {
        (*head)->data = NULL;
        free(*head);
        *head = NULL;
        return;
    }
    end = *head;
    while (end->next->next != NULL)
        end = end->next;
    del = end->next;
    del->data = NULL;
    free(del);
    end->next = NULL;
}
