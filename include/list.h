/*
** EPITECH PROJECT, 2026
** Corewar
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} list_t;

int add_node(list_t **list, void *data, void *(*data_dup)(void *));
int delete_node(list_t **list, list_t *prev_node, list_t *current_node,
    void (*free_data)(void *));
int display_list(list_t *const *list, void (*display_data)(void *));
void free_list(list_t *list, void (*free_data)(void *));
size_t list_len(list_t *const *begin);

#endif /* !LIST_H_ */
